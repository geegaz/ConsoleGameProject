*Jeu développé par Tanguy DEPRAZ et Danny VU*

Le repository GitHub du projet est accessible [ici](https://github.com/geegaz/ConsoleGameProject/) *(https://github.com/geegaz/ConsoleGameProject/)*.

# Description

Le jeu développé est basé sur le jeu "Snake" et porte le même nom.

Le but du jeu est de collecter le plus de pommes possibles avant de mourir.

Plus il y a de pommes collectées, plus le jeu avance vite.

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

Au départ, nous avons commencé par créer un **Snake**.

## Transformation

Une fois **Snake** terminé, nous avons essayé de faire un jeu de plate-formes à la **Super Mario Bros. / Super Mario Land**.
Lors de cette phase, nous avons ajouté OpenAL au projet, amélioré le système de contrôles, et ajouté un moyen de faire des animations, des collisions, une caméra.

## Retour aux sources

Après avoir avancé sur le jeu de plate-formes, nous avons réalisé que le projet était trop ambitieux vu notre avancement et le temps qu'il nous restait. Nous avons donc décidé de s'arrêter et de plutôt améliorer le **Snake** en y incorporant des éléments créés lors de la phase précédente (contrôles, animations, son, ...).

# Description des sources
Ne seront présentés ici que les sources que nous avons développés. Sauf si précisé, tous les fichiers marqués ".[h,cpp]" ne contiennent qu'une seule classe ou structure.

## Main.cpp

Point d'entrée du logiciel, contenant la fonction `int main()`.

## GameConstants.h

## Snake.[h,cpp]

## Display.[h,cpp]

## InputManager.[h,cpp]

## ControlsManager.[h,cpp]

## SoundManager.[h,cpp]

## Vector2D.[h,cpp]

## Sprite.[h,cpp]

## Animation.[h,cpp]

## SpriteRenderer.[h,cpp]

## NumberDisplay.[h,cpp]

## Animation.[h,cpp]

## Particle.[h,cpp]

## EffectParticle.[h,cpp]

## ParticlesManager.[h,cpp]

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

Bibliothèque permettant le chargement et l'utilisation de **sons** dans le jeu. Nous l'avons choisie car elle est beaucoup utilisée dans le domaine du jeu vidéo et parce qu'elle est fiable et simple à utiliser.

## Fichiers Sources

### SoundUtils (.h, .cpp)

Classe permettant de traiter des fichiers wav, développée par **VU Alex**.

## Audio

### Celeste

**apple_get.wav** : Strawberry 1000  
**death_sfx.wav** : Death Goldenberry

### Undertale

**death_jingle.wav** : Determination

