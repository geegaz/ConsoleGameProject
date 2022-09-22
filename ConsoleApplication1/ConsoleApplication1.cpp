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
    float delta_time = 0.0f; // elapsed time between a frame
    float previous = 0.0f;
    bool started = false;

    idDisplay display;
    NYTimer frame_timer;
    idInputManager input_manager;

    // add SPACE keyboard key for the title screen
    input_manager.AddKey(' ');

    // load sprites
    idSprite snakeBackground("SnakeBackground.txt");
    idSprite snakeSprite("SnakeSprite.txt"), appleSprite("AppleSprite.txt");
    idSprite titleScreen("title_screen.txt");

    // initialize snake game
    idSnake snake(snakeSprite, appleSprite);

    titleScreen.Draw(display, 0, 0);
    display.Refresh();
    //TODO make text flash
    while (!started) {
        input_manager.UpdateKeys();
        if (input_manager.lastKey == ' ') {
            started = true;
        }
    }

    while(true){
        // add ZQSD as possible keys for inputs
        input_manager.AddKey('Z');
        input_manager.AddKey('Q');
        input_manager.AddKey('S');
        input_manager.AddKey('D');
        // remove spacebar as input
        input_manager.RemoveKey(' ');

        frame_timer.start();
        display.Fill(BLACK);
        snakeBackground.Draw(display, 0, UI_HEIGHT); // draw background for game
        snake.Start(); // initialize snake game
        snake.DrawGame(display);
        while (!snake.IsGameOver()) {
            previous = delta_time;
            delta_time = frame_timer.getElapsedSeconds();
            snake.Forward(delta_time - previous);
            input_manager.UpdateKeys();
            if (delta_time >= frame_delay) {
                if (snake.CanMove()) {
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
                delta_time = previous = 0.0f;
                frame_timer.getElapsedSeconds(true);
            }
        }
        started = false;
        // add ZQSD as possible keys for inputs
        input_manager.RemoveKey('Z');
        input_manager.RemoveKey('Q');
        input_manager.RemoveKey('S');
        input_manager.RemoveKey('D');
        // remove spacebar as input
        input_manager.AddKey(' ');
        while (!started) {
            input_manager.UpdateKeys();
            if (input_manager.lastKey == ' ') {
                started = true;
            }
        }
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
