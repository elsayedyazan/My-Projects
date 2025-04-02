# 🎓 Projet de Gestion des Absences - BUT

## 📌 Introduction
Ce projet consiste à développer un **système de gestion des absences** pour les étudiants inscrits en **Bachelor Universitaire de Technologie (BUT)**. 

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

