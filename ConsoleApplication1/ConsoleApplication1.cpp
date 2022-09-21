// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <windows.h>
#include <iostream>
#include <string>
#include "idDisplay.h"
#include "idSprite.h"
#include "idSnake.h"
#include "NYTimer.h"
#include <WinUser.h>
#include "idInputManager.h"

using namespace std;

int main()
{
    const float frame_delay = 1.0f / 30.0f; // delay between frames
    const float logic_delay = 1.0f / 10.0f; // delay between snake moves
    float logic_timer = 0.0f; // elapsed time between a snake's move
    float delta_time; // elapsed time between a frame

    idDisplay display;
    NYTimer frame_timer;
    idInputManager input_manager;

    frame_timer.start();

    // add ZQSD as possible keys for inputs
    input_manager.AddKey('Z');
    input_manager.AddKey('Q');
    input_manager.AddKey('S');
    input_manager.AddKey('D');

    // load sprites
    idSprite snakeBackground("SnakeBackground.txt");
    idSprite snakeSprite("SnakeSprite.txt"), appleSprite("AppleSprite.txt");

    // initialize snake game
    idSnake snake(snakeSprite, appleSprite);
    snake.Start();

    snakeBackground.Draw(display, 0, UI_HEIGHT); // draw background for game
    // TODO Title screen with flashing text
    
    while (true) {
        delta_time = frame_timer.getElapsedSeconds();
        input_manager.UpdateKeys();
        if (delta_time >= frame_delay) {
            logic_timer += delta_time;
            if (logic_timer >= logic_delay) {
                logic_timer -= logic_delay;
                switch (input_manager.lastKey) {
                case 'Z':
                    snake.ChangeDirection(UP);
                    break;
                case 'Q':
                    snake.ChangeDirection(LEFT);
                    break;
                case 'S':
                    snake.ChangeDirection(DOWN);
                    break;
                case 'D':
                    snake.ChangeDirection(RIGHT);
                    break;
                }
                snake.Update();
            }
            // TODO Add score/UI manager
            // TODO Add sound manager
            snakeBackground.Draw(display, 0, UI_HEIGHT);
            snake.DrawGame(display);
            display.Refresh();
            frame_timer.getElapsedSeconds(true);
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
