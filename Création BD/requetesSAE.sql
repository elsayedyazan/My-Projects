------------------------AX1-------------------------------
SELECT 
    S.Libelle AS Type_Client_Fidelite,
    COUNT(F.No_Facture) AS Nb_Tickets
FROM 
    Client C
JOIN Statut_AXE1_ S ON C.Id_Statut = S.Id_Statut
JOIN AchatEnMagasin A ON C.Code_CLI = A.Code_CLI
JOIN Facture F ON A.No_Facture = F.No_Facture
WHERE 
    MONTH(F.DateEtHeure_Facture) = 6  -- Mois de juin par exemple
    YEAR(F.DateEtHeure_Facture) = 2025
GROUP BY 
    S.Libelle
ORDER BY 
    Nb_Tickets DESC;
	
----V2 avec analyse croisé ----	
	
TRANSFORM COUNT(F.No_Facture)
SELECT 
    MONTH(F.DateEtHeure_Facture) AS Mois
FROM 
    Client AS C
    INNER JOIN Statut_AXE1_ AS S ON C.Id_Statut = S.Id_Statut
    INNER JOIN AchatEnMagasin AS A ON C.Code_CLI = A.Code_CLI
    INNER JOIN Facture AS F ON A.No_Facture = F.No_Facture
WHERE 
    YEAR(F.DateEtHeure_Facture) = 2025
GROUP BY 
    MONTH(F.DateEtHeure_Facture)
PIVOT S.Libelle;


-- "lister les moments de la journée avec le plus de clients fidélité présents."
SELECT 
    DatePart("h", f.DateEtHeure_Facture) AS Heure,
    COUNT(DISTINCT c.Code_CLI) AS Nb_Clients_Fidelite
FROM 
    Facture AS f
    INNER JOIN AchatEnMagasin AS a ON a.No_Facture = f.No_Facture
    INNER JOIN Client AS c ON c.Code_CLI = a.Code_CLI
GROUP BY 
    DatePart("h", f.DateEtHeure_Facture)
ORDER BY 
    Nb_Clients_Fidelite;
------------------------AX2-------------------------------
SELECT 
    bl.Id_point,
    Format(bl.DateReception, "dddd") AS Jour_Semaine,
    SUM(f.MontantTotal) AS Montant_Total_Livre
FROM 
    BonLivraison AS bl
    INNER JOIN GestionnaireRetraits_AXE2_ AS gr ON bl.Id_retrait = gr.Id_retrait
    INNER JOIN retraitCommande AS r ON gr.Id_retrait = r.Id_retrait
    INNER JOIN Commande_AXE2_ AS c ON r.Id_commande = c.Id_commande
    INNER JOIN Facture AS f ON c.No_Facture = f.No_Facture
GROUP BY 
    bl.Id_point,
    Format(bl.DateReception, "dddd")
ORDER BY 
    bl.Id_point,
    Jour_Semaine;
----V2 avec analyse croisé ----	
TRANSFORM SUM(f.MontantTotal) AS Montant_Total_Livre
SELECT 
    bl.Id_point
FROM 
    BonLivraison AS bl
    INNER JOIN GestionnaireRetraits_AXE2_ AS gr ON bl.Id_retrait = gr.Id_retrait
    INNER JOIN retraitCommande AS r ON gr.Id_retrait = r.Id_retrait
    INNER JOIN Commande_AXE2_ AS c ON r.Id_commande = c.Id_commande
    INNER JOIN Facture AS f ON c.No_Facture = f.No_Facture
WHERE 
    gr.Statut = "retrait effectué"
GROUP BY 
    bl.Id_point
PIVOT Format(bl.DateReception, "dddd");

--"le nombre de livraison par jour pour chaque dépôt"

TRANSFORM COUNT(b.IdBon) AS Nb_Livraisons
SELECT 
    p.Id_point
FROM 
    PointDepots_AXE2_ AS p
    INNER JOIN BonLivraison AS b ON b.Id_point = p.Id_point
GROUP BY 
    p.Id_point
PIVOT Format(b.DateReception, "dddd");

------------------------AX3-------------------------------
--"Nombre de personnes inscrites par atelier"

SELECT 
    a.Id_Atelier_,
    COUNT(ins.Id_Participant) AS Nb_Inscrits
FROM 
    Atelier_AXE3_ AS a
    INNER JOIN Seance AS s ON s.Id_Atelier_ = a.Id_Atelier_
    INNER JOIN Sinscrit AS ins ON ins.IdSeance = s.IdSeance
GROUP BY 
    a.Id_Atelier_;
	
--"total des bons de réduction passés en caisse par mois / montant tickets correspondants" 
SELECT 
    Format(f.DateEtHeure_Facture, "mmmm yyyy") AS Mois,
    COUNT(a.Id_BonReduction) AS Nb_Bons_Réduction_Utilisés,
    SUM(f.MontantTotal) AS Montant_Total_Tickets
	ROUND(SUM((f.MontantTotal)) / COUNT(a.Id_BonReduction), 2) AS Montant_Moyen_Par_Bon
FROM 
    AchatEnMagasin AS a
    INNER JOIN Facture AS f ON a.No_Facture = f.No_Facture
WHERE 
    a.Id_BonReduction IS NOT NULL
GROUP BY 
    Format(f.DateEtHeure_Facture, "mmmm yyyy")
ORDER BY 
    f.DateEtHeure_Facture;


