*Jeu développé par Tanguy DEPRAZ et Danny VU*

# Instructions

Si vous souhaitez directement avoir une version executable du jeu, celle-ci peut être téléchargée via le tag [Console Application (v1.0) - Snake](https://github.com/geegaz/ConsoleGameProject/releases/tag/v1.0) (https://github.com/geegaz/ConsoleGameProject/releases/tag/v1.0) du [repository **GitHub** du projet](https://github.com/geegaz/ConsoleGameProject/).

## Ouverture du projet

Le projet peut être ouvert sur **Visual Studio**.  
Il a été développé sur **Visual Studio 2019 (v142)**, avec la version **10.0** du **SDK Windows**.  
La norme C++ utilisée est la norme **ISO C++14**.

## Compilation/Execution sur Visual Studio

La compilation du projet doit se faire sur Visual Studio et fonctionne en mode Release et Debug (**x64**).  
L'execution du projet se fait directement sur Visual Studio après 
compilation du projet.

## Execution hors de Visual Studio

Une fois le projet compilé sur Visual Studio, l'executable **`GameConsole.exe`** se trouve dans le répertoire `\x64\Release\` (mode Release) ou dans `\x64\Debug\` (mode Debug).

Pour pouvoir executer le `.exe`, il faut copier-coller le répertoire `\resources\`, se trouvant dans `\ConsoleApplication1\`, dans le même répertoire que le fichier `.exe` (**exemple** : `\x64\Release\resources\` ).

Une fois le répertoire de ressources placé, double-cliquer sur **`GameConsole.exe`** pour lancer le jeu.

## Diagrammes de classes

L'ouverture des diagrammes de classes format `.cd` requiert l'installation du module **Concepteur de Classes** (**Class Designer**) de Visual Studio. Des versions `.png` des diagrammes sont également disponibles à la racine du projet.

# Contrôles

Le jeu peut être joué au **clavier** et à la **manette** (Xinput).
## Clavier

**Se déplacer :** ZQSD ou flèches directionnelles

**Avancer dans les menus :** ENTRER

## Manette

**Se déplacer :** Croix directionnelle (D-pad)

**Avancer dans les menus :** START

# Phases de développement

## Projet initial

Au départ, nous avons commencé par créer un jeu **Snake**. Avec toutes les mécaniques de jeu fonctionnelles.

## Transformation

Une fois **Snake** terminé, nous avons essayé de faire un jeu de plate-formes à la **Super Mario Bros. / Super Mario Land**.
Lors de cette phase, nous avons ajouté OpenAL au projet, amélioré le système de contrôles, et ajouté un moyen de faire des animations, des collisions, une caméra.

## Retour aux sources

Après avoir avancé sur le jeu de plate-formes, nous avons réalisé que le projet était trop ambitieux vu notre avancement et le temps qu'il nous restait. Nous avons donc décidé de s'arrêter et de plutôt améliorer le **Snake** en y incorporant des éléments créés lors de la phase précédente (contrôles, animations, son, ...).

# Description des sources
Ne seront présentés ici que les sources que nous avons développés.  
Sauf si précisé, tous les fichiers marqués ".[h,cpp]" ne contiennent qu'une seule classe ou structure.

Nous avons essayé de respecter la [convention de nommage **idSoftware**](https://cours.guillaumelevieux.xyz/seances/cppprojet/IdCodeStyleConventions.pdf).   
A noter que certains paramètres de constructeurs ont pour nom `_nomAttribut` quand `nomAttribut` est un attribut de la classe.

## Main.cpp

Point d'entrée du logiciel, contenant la fonction `int main()`.

## GameConstants.h

Définitions d'`enum` utilisés dans plusieurs classes, et de 

## Snake.[h,cpp]

Classe correspondant au jeu.  
Elle gère le noyau logique/fonctionnel du jeu et les boucles de jeu.

## Display.[h,cpp]

Intermédiaire entre le programme et la console Windows. Permet de placer des pixels colorés.

## InputManager.[h,cpp]

Gestionnaire d'**entrées** (Clavier ou Xinput) pures, permet de savoir quelle **touche** ou **bouton** est appuyée.

## ControlsManager.[h,cpp]

Intermediaire entre les **entrées** joueur et les **actions** du jeu. Indique quelle **action** est effectuée par le joueur à partir des entrées enregistrées par l'**InputManager**.

## SoundManager.[h,cpp]

Gestionnaire de son, permet de jouer des sons et de lancer des musiques.

## Vector2D.[h,cpp]

### **intVector2**

vecteur d'**entiers** de 2 dimensions (x,y).

### **floatVector2**

vecteur de **flottants** de 2 dimensions (x,y).

## Sprite.[h,cpp]

Objet affichable consititué de plusieurs pixels.

L'image d'un sprite peut être une **image unique**, ou une **feuille de sprite**.

Format d'une **image unique** :
```
<taille_x> <taille_y>
---
<pixel 0,0> <pixel 1,0> <...> 
<pixel 0,1> <pixel 1,1> <...>
<...> <...> <...>

```

Format d'une **feuille de sprite** :
```
<taille_x_1_sprite> <taille_y_1_sprite>
<nombre_sprite_x> <nombre_sprite_y>
---
<pixel 0,0> <pixel 1,0> <...> 
<pixel 0,1> <pixel 1,1> <...>
<...> <...> <...>

```

## Animation.[h,cpp]

Contient toutes les structures et classes liées aux **animations** de Sprite.

### **frameAnimation_t**
Animation constituée d'une **succession d'images** (frames) sous forme d'indices, et indiquant si l'animation boucle ou non.

### **positionAnimation_t**
Animation constituée d'une **succession de hauteurs** (coordonnées relatives sur l'axe y), et indiquant si une symétrie sur l'axe y doit être appliquée sur le **Sprite**.

### **idAnimationState**
Classe contenant l'état courant de l'animation d'un **Sprite** (image courante de `frameAnimation_t` et hauteur courante de `positionAnimation_t`).

### **idAnimationRegister**
Classe statique qui charge l'ensemble des animations de position (`positionAnimation_t`) et d'images (`frameAnimation_t`) à partir de fichiers texte présents dans `resources\animations\`.

Format de `.txt` pour `positionAnimation_t` :
```
<titre> <symétrie y (0 ou 1)> <longueur> <hauteur_1>,<hauteur_2>,...
```

Format de `.txt` pour `frameAnimation_t` :
```
<titre> <boucler (0 ou 1)> <longueur> <indice_image_1>,<indice_image_2>,...
```

## SpriteRenderer.[h,cpp]

Contenaire de Sprite avec une position. Le SpriteRenderer permet d'appliquer des animations (`positionAnimation` et des `frameAnimation`) et des transformations (symétrie axe x et y) sur le Sprite et de l'afficher.

## NumberDisplay.[h,cpp]

Affiche un nombre à l'écran avec un nombre de chiffres fixe et à une position fixe.

*(Utilisé pour afficher le score)*

## Particle.[h,cpp]

Classe abstraite affichable à l'écran avec une position et un comportement définissable dans les classes enfant.

## EffectParticle.[h,cpp]

Particule animée utilisant un `SpriteRenderer`.

*(**Exemple** : particule animée lors de la collecte de pomme)*

## DeathParticle.[h,cpp]

Particule utilisée lors de l'animation de mort.  
Correspond à 1 morceau de l'explosion de mort du Snake.

## ParticlesManager.[h,cpp]

Instancie et met à jour les **particules** affichées à l'écran.

## png_to_console_txt.py
*(situé dans `resources\sprites\` )*  
Script **python** permettant de convertir une image `.png` (avec canal alpha) en fichier `.txt` traitable par la classe `idSprite` de **Sprite.[h,cpp]**.

*(A noter que pour les **feuilles de sprite**, il est necessaire de modifier le `.txt` résultant.)*

# Crédits visuels
## Sprites
### Tanguy DEPRAZ
**GameOver.png**  
**Numbers.png**  
**SnakeSprites.png**  
**title_screen.png**  
**GameOverBackground.png**  
**shatter_particles.png**
### Danny VU
**apple_pop.png** (inspiré de Celeste)  
**press_space_start.png** (edited by Tanguy)  
**SnakeBackground.png**  

# Crédits externes

## Bibliothèques

### **OpenAL**

Bibliothèque permettant le chargement et l'utilisation de **sons** dans le jeu. Nous l'avons choisie car elle est beaucoup utilisée dans le jeu vidéo et parce qu'elle est fiable et simple à utiliser.

## Fichiers Sources

### **SoundUtils (.h, .cpp)**

Classe permettant de traiter des fichiers wav, développée par **VU Alex**.

## Audio

### **Celeste**

**apple_get.wav** : Strawberry 1000  
**death_sfx.wav** : Death Goldenberry  
**shatter_1.wav** : Diamond Touch 01  
**shatter_2.wav** : Diamond Touch 02  
**shatter_3.wav** : Diamond Touch 03  

### **Metal Gear Solid**

**snake_scream.wav** : Game Over

### **Super Mario 64**

**game_start.wav** : Entering a Course  
**title_theme.wav** : File Select

### **Super Mario Odyssey**

**music_ingame.wav** : Another World

### **Undertale**

**death_jingle.wav** : Determination

