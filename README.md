*Jeu développé par Tanguy DEPRAZ et Danny VU*

# Instructions de compilation

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
Ne seront présentés ici que les sources que nous avons développés. Sauf si précisé, tous les fichiers marqués ".[h,cpp]" ne contiennent qu'une seule classe ou structure.

Nous avons essayé de respecter la [convention de nommage **idSoftware**](https://cours.guillaumelevieux.xyz/seances/cppprojet/IdCodeStyleConventions.pdf).   
A noter que certains paramètres de constructeurs ont pour nom `_nomAttribut` quand `nomAttribut` est un attribut de la classe.

## Main.cpp

Point d'entrée du logiciel, contenant la fonction `int main()`.

## GameConstants.h

## Snake.[h,cpp]

## Display.[h,cpp]

Intermédiaire entre le programme et la console Windows. Permet de placer des pixels colorés.

## InputManager.[h,cpp]

Gestionnaire d'**entrées** (Clavier ou Xinput) pures, permet de savoir quelle **touche** ou **bouton** est appuyée.

## ControlsManager.[h,cpp]

Intermediaire entre les **entrées** joueur et les **actions** du jeu. Indique quelle **action** est effectuée par le joueur à partir des entrées enregistrées par l'**InputManager**.

## SoundManager.[h,cpp]

Gestionnaire de son, permet de jouer des sons et de lancer des musiques.

## Vector2D.[h,cpp]

### intVector2

vecteur d'**entiers** de 2 dimensions (x,y).

### floatVector2

vecteur de **flottants** de 2 dimensions (x,y).

## Sprite.[h,cpp]

Objet affichable consititué de plusieurs pixels.

L'image d'un sprite peut être une **image unique**, ou une **feuille de sprite**.

## Animation.[h,cpp]



## SpriteRenderer.[h,cpp]



## NumberDisplay.[h,cpp]

Affiche un nombre à l'écran avec un nombre de chiffres fixe et à une position fixe.

*(Utilisé pour afficher le score)*

## Animation.[h,cpp]



## Particle.[h,cpp]

Classe abstraite affichable à l'écran avec une position et un comportement définissable dans les classes enfant.

## EffectParticle.[h,cpp]

Particule animée utilisant des `positionAnimation` et des `frameAnimation`.

*(**Exemple** : particule animée lors de la collecte de pomme)*

## ParticlesManager.[h,cpp]

Instancie et met à jour les **particules** affichées à l'écran.

## png_to_console_txt.py

Script **python** permettant de convertir une image `.png` (avec canal alpha) en fichier `.txt` traitable par la classe `idSprite` de **Sprite.[h,cpp]**.

# Crédits visuels
## Sprites
### Tanguy DEPRAZ
**GameOver.png**  
**Numbers.png**  
**SnakeSprites.png**  
**title_screen.png**  
**GameOverBackground.png**  
### Danny VU
**apple_pop.png** (inspiré de Celeste)  
**press_space_start.png** (edited by Tanguy)  
**SnakeBackground.png**  

# Crédits externes

## Bibliothèques

### OpenAL

Bibliothèque permettant le chargement et l'utilisation de **sons** dans le jeu. Nous l'avons choisie car elle est beaucoup utilisée dans le jeu vidéo et parce qu'elle est fiable et simple à utiliser.

## Fichiers Sources

### SoundUtils (.h, .cpp)

Classe permettant de traiter des fichiers wav, développée par **VU Alex**.

## Audio

### Celeste

**apple_get.wav** : Strawberry 1000  
**death_sfx.wav** : Death Goldenberry

### Undertale

**death_jingle.wav** : Determination

