# CESI-Projet-POO-25-26 — Conway's Game of Life

## English
### Overview
Object-oriented C++ implementation of Conway's Game of Life. Two modes: console (exports each iteration to files) and SFML GUI (interactive controls). The grid is toroidal, supports immutable obstacle cells, and reads simple text files for initial states.

### Features
- Toroidal grid: edges wrap around.
- Console mode writes each iteration in `<input>_out/iteration_<n>.txt`.
- GUI mode with adjustable speed, pause, reset, and single-step.
- Obstacle cells (values 2/3) remain fixed between generations.
- Dynamic window sizing to fit the desktop; bundled font fallback.

### Input format
Plain text file:
```
<rows> <cols>
v11 v12 v13 ...
v21 v22 v23 ...
...
```
Values: `0` dead, `1` alive, `2` obstacle (dead), `3` obstacle (alive).

### Build
```
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```
Requires C++20, CMake ≥ 3.31, SFML 2.6.

### Run
From the build directory:
```
./CESI-Projet-POO-25-26
```
The program asks for mode (`c` console, `g` GUI) and the input file path.

#### Console mode
- Generates `<input>_out/iteration_<n>.txt` until stabilization or the chosen limit.
- Prints stabilization info on stdout.

#### GUI mode
Controls:
- Space: pause/play
- Up / Down: speed -/+ (seconds per step)
- Right: single step when paused
- R: reset to initial grid (pauses)

Window clamps to ~90% of the desktop; HUD shows status and speed.

### Project structure
- `src/core`: game logic (grid, rules, cell states, serialization)
- `src/gui`: SFML interface
- `src/console`: console runner and file exports
- `resources/fonts`: bundled font fallback

### Spec coverage
- OOP separation of grid, rules, and GUI.
- Rules encapsulated in `Rule` hierarchy (`ClassicLifeRule`).
- Toroidal neighborhood implemented.
- Obstacle cells preserved across iterations.
- Console output per iteration in dedicated folder.
- SFML GUI with adjustable simulation speed.
- Core unit tests (`core-tests`) covering serializer, toroidal behavior, oscillator, obstacles, and multi-step runs.

### Tests
- Build: `cmake --build cmake-build-debug --target core-tests`
- Run: `cd cmake-build-debug && ./core-tests`

### Authors
CESI 2025/2026 — student project.

---

## Français
### Aperçu
Implémentation orientée objet du Jeu de la vie en C++. Deux modes : console (exporte chaque itération) et interface graphique SFML (contrôles interactifs). La grille est toroïdale, gère des cellules obstacles immuables et lit des fichiers texte simples pour l’état initial.

### Fonctionnalités
- Grille toroïdale : les bords sont reliés.
- Mode console : écrit chaque itération dans `<input>_out/iteration_<n>.txt`.
- Mode GUI : vitesse ajustable, pause, reset, pas à pas.
- Cellules obstacles (valeurs 2/3) conservées entre générations.
- Fenêtre redimensionnée pour tenir dans l’écran ; police embarquée en secours.

### Format d'entrée
Fichier texte :
```
<lignes> <colonnes>
v11 v12 v13 ...
v21 v22 v23 ...
...
```
Valeurs : `0` mort, `1` vivant, `2` obstacle mort, `3` obstacle vivant.

### Compilation
```
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```
Nécessite C++20, CMake ≥ 3.31, SFML 2.6.

### Exécution
Depuis le dossier de build :
```
./CESI-Projet-POO-25-26
```
Le programme demande le mode (`c` console, `g` GUI) et le chemin du fichier d’entrée.

#### Mode console
- Produit `<input>_out/iteration_<n>.txt` jusqu’à stabilisation ou limite choisie.
- Affiche la stabilisation sur stdout.

#### Mode GUI
Contrôles :
- Espace : pause/lecture
- Haut / Bas : vitesse -/+
- Droite : un pas quand en pause
- R : réinitialise la grille (et met en pause)

La fenêtre est limitée à ~90 % de l’écran ; le HUD montre l’état et la vitesse.

### Structure du projet
- `src/core` : logique (grille, règles, états de cellule, sérialisation)
- `src/gui` : interface SFML
- `src/console` : exécution console et export des fichiers
- `resources/fonts` : police fournie en secours

### Couverture des spécifications
- Séparation POO entre grille, règles et GUI.
- Règles encapsulées dans la hiérarchie `Rule` (`ClassicLifeRule`).
- Voisinage toroïdal implémenté.
- Obstacles conservés d’une itération à l’autre.
- Export console des itérations dans un dossier dédié.
- GUI SFML avec vitesse ajustable.
- Tests unitaires cœur (`core-tests`) couvrant sérialisation, comportement toroïdal, oscillateur, obstacles et exécution multi-pas.

### Tests
- Compilation : `cmake --build cmake-build-debug --target core-tests`
- Exécution : `cd cmake-build-debug && ./core-tests`

### Auteurs
CESI 2025/2026 — projet étudiant.
