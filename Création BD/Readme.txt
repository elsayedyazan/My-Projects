# 🏪 SAÉ 2‑04 – Exploitation statistique d’une base de données (Supérette de Caen)

## 📖 Introduction
Cette SAÉ a pour but de **croiser les compétences en bases de données relationnelles et en statistiques descriptives**.  
À partir de tickets de caisse réels d’une supérette située à **Caen**, il faut :

1. **Modéliser** les données (MCD) et envisager leurs extensions futures ;  
2. **Exploiter** le jeu de données au moyen de requêtes SQL et d’analyses statistiques (Python / Excel).

Le travail est évalué dans le cadre du **DST de la ressource R2.06 (semaine du 3 juin 2025)**.  
Il faudra rendre **une feuille recto‑verso** résumant la production (MCD + requêtes) à la fin de l’épreuve.

---

## 🎯 Objectifs pédagogiques
- **R2.06 — Exploitation d’une base de données** : modélisation, SQL, QBE.  
- **R2.08 — Outils numériques pour les statistiques descriptives** : Python (pandas, matplotlib) et/ou Excel.

---

## 🗂️ Jeu de données fourni
| Fichier | Contenu principal | Rôle |
|---------|------------------|------|
| `ClasseurTickets2025.xlsx` | 3 feuilles (Produits, Tickets, CartesFidélité) | Source unique pour la modélisation **et** l’analyse statistique |

> 🔍 **Première étape** : analyser chaque colonne, identifier les clés candidates, repérer les dépendances fonctionnelles et comprendre les liens métier.

---

## 🛠️ Approche « Base de données »
1. **Modélisation initiale** : créer le **MCD complet** correspondant au classeur Excel à l’aide de **Looping**.  
2. **Extensions** : faire évoluer le MCD pour intégrer **trois axes stratégiques** :
   - **Axe 1 – Programme fidélité** : statuts (Silver ≥ 50 pts, Gold ≥ 100 pts, Diamond ≥ 200 pts), événements dédiés, bons promotionnels.
   - **Axe 2 – Livraison en points de dépôt** : dépôts, tournées journalières, créneaux horaires, suivi des retraits.
   - **Axe 3 – Ateliers dégustation** : séances planifiées, inscriptions, bons de réduction et échantillons.
3. **Livrable** : **un unique MCD** intégrant les trois axes, imprimé sur la feuille de synthèse.

---

## 📈 Approche « Statistique »
- Préparation des données (Python / Excel).  
- Analyses croisées, indicateurs, visualisations.

### Exemples de requêtes / analyses à proposer
| Axe | Exemple d’indicateur | Finalité métier |
|-----|----------------------|-----------------|
| Fidélité | Répartition des ventes par statut sur un mois | Évaluer l’impact du programme |
| Livraisons | Nombre de colis livrés par dépôt et par jour | Optimiser la tournée quotidienne |
| Ateliers | Taux de conversion des bons de réduction | Mesurer le ROI des ateliers |

> 💡 **Conseil** : se concentrer sur des KPIs parlants (CA, nombre de tickets, panier moyen, etc.) et sur des périodes pertinentes (jour de la semaine, heure, mois).

---

## 🚀 Organisation du travail
| Sprint | Période *(indicative)* | Livrables internes |
|--------|-----------------------|--------------------|
| 1 | Découverte des données | Diagramme conceptuel v0 |
| 2 | MCD complet + Axe 1 | Diagramme v1, premiers KPIs fidélité |
| 3 | Axes 2 & 3 intégrés | Diagramme v2, requêtes supplémentaires |
| 4 | Consolidation & synthèse | Feuille recto‑verso prête pour le DST |

Le projet peut être réalisé en binôme ou seul·e, mais chacun·e doit maîtriser les trois axes et venir au DST avec sa feuille personnelle.

---

## ✅ Évaluation
| Critère | Pondération |
|---------|------------|
| Qualité du MCD (complétude, justesse, clarté) | 40 % |
| Pertinence des requêtes / analyses | 40 % |
| Qualité de la feuille de synthèse (structure, lisibilité, rigueur) | 20 % |

⚠️ **Durée du DST : 30 min.** Aucune ressource numérique n’est autorisée ; la feuille sera le seul support.

---

## 🖇️ Structure recommandée du dépôt Git
```
SAE2-04/
├── data/                 # Classeur Excel + éventuels CSV dérivés
├── mcd/                  # Fichiers Looping (.MLD, .MLI, exports PNG)
├── sql/                  # Requêtes SQL et jeux de test
├── analysis/             # Notebooks Python ou classeurs Excel
├── docs/                 # Feuille de synthèse, slides, etc.
└── README.md             # Ce fichier
```

---

## 🚧 Mise en route rapide
```bash
# 1. Cloner le dépôt
git clone <url_du_projet>
cd SAE2-04

# 2. Créer un environnement Python
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt  # pandas, openpyxl, matplotlib, jupyter, ...

# 3. Lancer Jupyter pour l'analyse
jupyter notebook
```

---

## 👥 Auteurs / Encadrant·es
- **Étudiant·e(s)** : *Nom, Groupe*  
- **Encadrant·es** : Florence Mesatfa‑Fessy, Jérôme Fessy, Anne Estrade (IUT de Caen).

---

## 📝 Licence
Ce travail académique est distribué sous licence **MIT**, sauf indication contraire.

---

## 🔚 Conclusion
Cette SAÉ permet de développer une vision **transversale** : passer de la **donnée brute** à des **décisions éclairées** grâce à la modélisation et à l’analyse statistique.  
Une attention particulière est portée à la qualité de la modélisation, à la pertinence des analyses et à la clarté de la restitution.  
Bonne exploration et **place aux requêtes !** 🚀
