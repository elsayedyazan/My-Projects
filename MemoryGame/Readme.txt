# 🧠 SAÉ 2.01 – Variante numérique du jeu Memory

## 🎯 Objectif du projet
Cette application VB.NET propose une adaptation solitaire et chronométrée du jeu **Memory**. Elle met à l’épreuve la mémoire visuelle et la rapidité : le joueur dispose d’un temps limité pour retrouver le plus grand nombre possible de « carrés » (groupes de quatre cartes identiques).

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
git clone <url_du_projet>
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
