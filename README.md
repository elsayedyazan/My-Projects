# Mes Projets

Téléchargez chaque projet individuellement ou consultez sa description :

## Liste des projets

### Création BD

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/Création_BD.zip)
- [Voir le dossier sur GitHub](./Création BD)

**Résumé du projet :**
# 🏪 SAÉ 2‑04 – Exploitation statistique d’une base de données (Supérette de Caen)

## 📖 Introduction
Cette SAÉ a pour but de **croiser les compétences en bases de données relationnelles et en statistiques descriptives**.  
À partir de tickets de caisse réels d’une supérette située à **Caen**, il faut :

<details><summary>Voir le README complet</summary>


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
</details>

<hr style="height:4px;border-width:0;color:red;background-color:red">

### Implémentation d'un besoin client

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/Implémentation_d'un_besoin_client.zip)
- [Voir le dossier sur GitHub](./Implémentation d'un besoin client)

**Résumé du projet :**
# 🎓 Projet de Gestion des Absences - BUT

## 📌 Introduction
Ce projet consiste à développer un **système de gestion des absences** pour les étudiants inscrits en **Bachelor Universitaire de Technologie (BUT)**. 


<details><summary>Voir le README complet</summary>

**Objectif :**
- Surveiller et gérer les absences des étudiants.
- Assurer un suivi rigoureux des absences non justifiées.
- Maintenir l'intégrité académique.

---

## 🎯 Objectifs du Projet
- **📊 Suivi des Absences** : Assurer un suivi précis des absences des étudiants.
- **📑 Gestion des Justificatifs** : Permettre aux étudiants de soumettre des justificatifs.
- **✅ Validation des Justificatifs** : Permettre au directeur d'études de valider/invalider les justificatifs.
- **🚨 Identification des Étudiants Défaillants** : Repérer les étudiants dépassant la limite d'absences non justifiées.

---

## 📜 Règles de Gestion
- **📌 Limite d'Absences Non Justifiées** :
  - Pas plus de **5 demi-journées** d'absences non justifiées par semestre.
  - Dépassement = **invalidation de toutes les UE** du semestre.
- **📄 Justification des Absences** :
  - **Délai de 3 jours** pour soumettre un justificatif.
  - Validation obligatoire par le directeur d'études.
- **⛔ Absences Non Justifiées** :
  - Toute absence sans justificatif valide dans les délais reste **non justifiée**.

---

## ⚙️ Fonctionnalités du Programme
Le programme doit interpréter **9 commandes** pour gérer les absences :

- **C0 - Sortie du Programme** : `exit` → Quitte l'application.
- **C1 - Inscription** : `inscription <nom> <numéro_groupe>` → Ajoute un étudiant.
- **C2 - Enregistrement d'une Absence** : `absence <id_étudiant> <numéro_jour> <demi-journée>`.
- **C3 - Liste des Étudiants** : `etudiants <numéro_jour_courant>`.
- **C4 - Dépôt d'un Justificatif** : `justificatif <id_absence> <numéro_jour> <texte>`.
- **C5 - Absences en Attente de Validation** : `validations`.
- **C6 - Validation/Invalisation d'un Justificatif** : `validation <id_absence> <code_validation>`.
- **C7 - Situation d'un Étudiant** : `etudiant <id_étudiant> <numéro_jour_courant>`.
- **C8 - Liste des Étudiants Défaillants** : `defaillants <numéro_jour_courant>`.

---

## 🏗️ Développement et Méthodologie
- **🔄 Méthode Agile** :
  - Développement en **4 sprints**.
  - Ajout progressif des fonctionnalités.
- **🛠️ Tests et Validation** :
  - Utilisation de **Jeux de Données de Test (JDT)**.
  - Comparaison des résultats avec des références.
- **📊 Évaluation** :
  - Recette du projet.
  - Dossier de développement logiciel.
  - Une partie du devoir sur table.

---

## 📦 Livrables
- **📂 Dossier de Développement Logiciel** :
  - Page de garde (noms, groupes, objet, sommaire).
  - Présentation du projet (fonctionnalités, entrées/sorties).
  - Moyens mis en œuvre.
  - Bilan du projet (difficultés, réussites, améliorations).
  - Annexes (code source commenté, traces d'exécution).
- **💻 Code Source** :
  - Commenté et bien indenté.
  - Suivi des conventions de nommage.
  - Documentation des préconditions et assertions.

---

## 📅 Planning et Rendu
| Sprint | Date de rendu |
|--------|--------------|
| Sprint 1 | À définir |
| Sprint 2 | À définir |
| Sprint 3 | À définir |
| Sprint 4 | À définir |

---

## 🏁 Conclusion
Ce projet vise à créer une **application robuste** pour la **gestion des absences** des étudiants en BUT. 
Le respect des **spécifications** et des **délais** sera crucial pour la réussite du projet. Une attention particulière sera portée à la **qualité du code** et à la **documentation** pour l'évaluation finale.

</details>

<hr style="height:4px;border-width:0;color:red;background-color:red">

### Installation d'un poste pour le développement

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/Installation_d'un_poste_pour_le_développement.zip)
- [Voir le dossier sur GitHub](./Installation d'un poste pour le développement)

**Résumé du projet :**
# sae_system_A1S1P2
Repo de la SAE System Linux + HTML/CSS

![PROGRESS BAR](https://github.com/rp-hkzo/sae_system_A1S1P2/blob/751c30d9757d89775341cfa2c23adf8de4c74dc1/PROGRESS%20BAR.png)


<details><summary>Voir le README complet</summary>

Architecture du site :

📁assets                 (source files)  
  |--------> 📁img       (png,jpg files)  
  |--------> 📁vid       (video files)  
  |--------> 📁svg       (vector files)  
  |--------> 📁fonts     (font files)  

📁css                    (style files)  
  |--------> 📁main      (main style)  
  |--------> 📁aux       (auxiliar style)  
  |--------> 📁bootstrap (bootstrap5 css files)  

📁js                     (javascript files)  
  |--------> 📁bootstrap (bootstrap5 js files)  
  |--------> 📁main      (main js files)  

 index.html  
 home.html  
 report.html   
 timeline.html  



![Website Map](https://github.com/user-attachments/assets/d42d3860-856f-4ae6-87d8-40b07a788ce0)
</details>

<hr style="height:4px;border-width:0;color:red;background-color:red">

### MemoryGame

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/MemoryGame.zip)
- [Voir le dossier sur GitHub](./MemoryGame)

**Résumé du projet :**
# 🧠 SAÉ 2.01 – Variante numérique du jeu Memory

## 🎯 Objectif du projet
Cette application VB.NET propose une adaptation solitaire et chronométrée du jeu **Memory**. Elle met à l’épreuve la mémoire visuelle et la rapidité : le joueur dispose d’un temps limité pour retrouver le plus grand nombre possible de « carrés » (groupes de quatre cartes identiques).


<details><summary>Voir le README complet</summary>

---

## 🗺️ Fonctionnalités principales
| Domaine | Fonctionnalités | Détails |
|---------|----------------|---------|
| **Interface** | Accueil, Jeu, Scores, Paramètres | Navigation fluide entre formulaires ; ergonomie pensée pour un usage rapide. |
| **Gameplay** | Trois niveaux de difficulté | <br>• **Facile** : grille 4×4, 60 s.<br>• **Normal** : grille 5×4, 90 s.<br>• **Difficile** : grille 8×4, 105 s.|
| | Gestion des cartes | Placement aléatoire, détection de correspondances, mise en gris des cartes validées.|
| | Chronomètre & bouton d’abandon | Compte à rebours en temps réel ; confirmation avant abandon.|
| **Personnalisation** | Thèmes visuels | Fonds d’écran (Europe, Sahara, Asie, Afrique, Amérique du Sud).|
| | Ambiances sonores | Boucles musicales culturelles (française, américaine, brésilienne, marocaine, espagnole).|
| **Statistiques** | Sauvegarde automatique | Fichier binaire `scores.dat` : score maximum, temps minimum, temps cumulé, nombre de parties.|
| | Tableau des scores | Tri croissant/décroissant, recherche par joueur, réinitialisation sécurisée.|

---

## 🏗️ Architecture technique
```text
MemoryGame/
├── Forms/
│   ├── Acceuil.vb          # menu principal, choix joueur & difficulté
│   ├── FormMemory.vb       # logique de jeu (cartes, chrono, gestion thème)
│   ├── Scores.vb           # visualisation & tri des statistiques
│   └── FormParametres.vb   # thèmes, musique, volume, effets sonores
├── Modules/
│   └── Data.vb             # sérialisation des statistiques (BinaryFormatter)
├── Resources/
│   ├── Flags*              # sprites des drapeaux (×N)
│   ├── *_Theme             # fonds d’écran
│   └── *_Song.wav          # musiques de fond
└── README.md               # ce fichier
```

---

## ⚙️ Installation rapide
1. **Pré‑requis** : Windows 10 +, .NET Framework ≥ 4.8, Visual Studio 2022.  
2. **Cloner le dépôt** :
```bash
git clone https://github.com/elsayedyazan/My-Projects.git
cd MemoryGame
```
3. **Ouvrir `MemoryGame.sln`** dans Visual Studio.  
4. **Lancer** (`F5`) ou **compiler** (`Ctrl + Shift + B`).

> Astuce : pour tester rapidement les niveaux, modifier la constante `tempsRestant` dans `FormMemory.vb`.

---

## 🕹️ Utilisation
1. **Saisir un nom de joueur** (min. 3 caractères).  
2. **Choisir la difficulté** puis **Jouer**.  
3. Cliquer pour retourner les cartes ; former des carrés de **4 cartes identiques**.  
4. Le chronomètre s’arrête lorsque toutes les cartes sont validées ou que le temps est écoulé.  
5. Les statistiques sont enregistrées et visibles depuis le menu **Scores**.

---

## 🗄️ Persistance des données
Le module `Data.vb` sérialise un dictionnaire `Nom → StatistiquesJoueur` dans `scores.dat` :
- **Serialisation** : `BinaryFormatter` (stockage binaire local).  
- **Mises à jour** : déclenchées à la fin de chaque partie.  
- **Réinitialisation** : bouton *Supprimer stats* (avec confirmation).

---

## 🔍 Points forts techniques
- **Gestion dynamique des grilles** : génération et adaptation des contrôles selon la difficulté.
- **Synchronisation d’interface** : sélection croisée des listes dans `Scores.vb` pour une lecture cohérente.
- **Personnalisation utilisateur** : paramètres persistants (`My.Settings`) pour thèmes, musique, volume, effets.
- **Robustesse** : validations (longueur du nom, confirmation des actions destructrices) et timers contrôlés.

---

## 🚧 Pistes d’amélioration
- Passage du fichier binaire à un stockage JSON ou SQLite pour faciliter l’export et la portabilité.
- Ajout d’un mode *multijoueur local* (scores comparés en direct).
- Refactorisation vers le pattern **MVVM** pour isoler la logique de l’interface.

---

## 📄 Licence
Ce projet est distribué sous licence **MIT**.

---

## ✉️ Contact
Pour toute question technique, contacter l’étudiant responsable du projet via : *<adresse‑mail académique>*.

---

*Dernière mise à jour : 16 juin 2025*
</details>

<hr style="height:4px;border-width:0;color:red;background-color:red">

### MiniProj_SimulationChenille

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/MiniProj_SimulationChenille.zip)
- [Voir le dossier sur GitHub](./MiniProj_SimulationChenille)

_Pas de README spécifique pour ce projet._

<hr style="height:4px;border-width:0;color:red;background-color:red">

### SAE Exploiatation BD

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/SAE_Exploiatation_BD.zip)
- [Voir le dossier sur GitHub](./SAE Exploiatation BD)

**Résumé du projet :**
# 📊 Projet d'Exploitation de Base de Données - KDou

## 📌 Présentation du Projet
Ce projet vise à exploiter les données de l'entreprise **KDou** pour produire des analyses et des indicateurs pertinents. 


<details><summary>Voir le README complet</summary>

**À propos de KDou :**
KDou est une entreprise commerciale spécialisée dans la vente de produits alimentaires d'épicerie fine ou typiques, achetés à des fournisseurs du monde entier. 

**Objectif :**
- Aider KDou à mieux comprendre ses données
- Améliorer sa rentabilité
- Se positionner de manière plus éco-friendly

---

## 🔍 Contexte
KDou souhaite analyser ses données pour optimiser son fonctionnement et proposer des solutions pour renforcer son image écologique tout en augmentant son bénéfice. 

Le projet est structuré en plusieurs missions, chacune avec des objectifs spécifiques.

---

## 🚀 Missions

### 🏁 Mission 1: Prise en main des données
**🎯 Objectif:** Comprendre le contenu des tables et les liens entre elles.

**📝 Tâches:**
- Identifier les clés primaires et étrangères dans chaque table.
- Répondre à des questions spécifiques pour s'entraîner à naviguer dans les données.
- Analyser les données pour relever des incohérences ou des choix discutables.

---

### 🖥️ Mission 2: Exploitation de la base de données avec QBE
**🎯 Objectif:** Utiliser le mode de création graphique (QBE) pour produire des résultats/indicateurs.

**📝 Tâches:**
- Répondre à des questions spécifiques en utilisant QBE.
- Tester les requêtes et vérifier les résultats.
- Analyser les données pour relever des problèmes potentiels.

---

### 🛠️ Mission 3: Analyse des données avec SQL
**🎯 Objectif:** Produire des analyses et indicateurs pertinents en utilisant le langage SQL.

**📝 Tâches:**
- Répondre à des questions spécifiques en utilisant SQL.
- Proposer des requêtes intéressantes pour la problématique de KDou.
- Analyser les résultats et les présenter de manière lisible.

---

### 🌐 Mission 4: Création d'une interface web
**🎯 Objectif:** Présenter les résultats des analyses sous forme de documents web.

**📝 Tâches:**
- Créer des pages HTML/CSS pour présenter les résultats.
- Utiliser des tableaux, des listes à puces et des images pour illustrer les données.
- Assurer la responsivité et l’accessibilité des pages.

---

## ⚙️ Contraintes
- Les pages HTML/CSS doivent être créées **sans** outils WYSIWYG ou générateurs de pages web.
- Les documents doivent respecter le standard **HTML5** et utiliser des balises sémantiques.
- Les pages doivent être **responsives** et adaptées aux ordinateurs de bureau et portables.
- Les feuilles de styles doivent être **cohérentes** avec les consignes et contraintes.

---

## 💡 Conseils
- Utiliser des **media-queries** pour adapter l'affichage en fonction de la taille de l'écran.
- Redimensionner les images et utiliser des **textes alternatifs** pour améliorer l'accessibilité.
- Vérifier la conformité du code avec un **validateur HTML/CSS**.

---

## 🗓️ Planning et Rendu
| Mission | Date de rendu |
|---------|--------------|
| Mission 1 | 27/09/2024 |
| Mission 2 | 04/10/2024 |
| Mission 3 | 18/10/2024 |
| Mission 4 | 18/10/2024 |

---

## 📌 Conclusion
Ce projet aidera **KDou** à mieux comprendre ses données et à prendre des décisions stratégiques pour améliorer sa rentabilité et son image écologique. Les analyses et indicateurs produits seront présentés sous forme de documents web, facilitant leur consultation et leur compréhension.

📢 **Prêt à optimiser les données de KDou !** 🚀
</details>

<hr style="height:4px;border-width:0;color:red;background-color:red">

### octo_verso

- [Télécharger le ZIP](https://github.com/elsayedyazan/My-Projects/releases/latest/download/octo_verso.zip)
- [Voir le dossier sur GitHub](./octo_verso)

_Pas de README spécifique pour ce projet._

<hr style="height:4px;border-width:0;color:red;background-color:red">

