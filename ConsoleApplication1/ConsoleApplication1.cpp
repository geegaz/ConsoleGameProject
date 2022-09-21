// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <windows.h>
#include <iostream>
#include <string>
#include "Display.h"
#include "Sprite.h"
#include "Snake.h"
#include "NYTimer.h"

using namespace std;

int main()
{
    const float frame_delay = 1.0f / 15.0f;
    Display display;
    NYTimer timer;
    timer.start();
    ifstream background_file;
    background_file.open("SnakeBackground.txt");

    Sprite snakeBackground("SnakeBackground.txt");

    Sprite snakeSprite("SnakeSprite.txt"), appleSprite("AppleSprite.txt");
    Snake snake(snakeSprite, appleSprite);
    snake.Start();
    snakeBackground.Draw(display, 0, UI_HEIGHT);
    // TODO Title screen with flashing text
    while (true) {
        if (timer.getElapsedSeconds() >= frame_delay) {
            // TODO Add score/UI manager
            // TODO Add sound manager
            snakeBackground.Draw(display, 0, UI_HEIGHT);
            snake.DrawGame(display);
            display.Refresh();
            snake.Update();
            timer.getElapsedSeconds(true);
        }
        // TODO Add input manager
    }
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
