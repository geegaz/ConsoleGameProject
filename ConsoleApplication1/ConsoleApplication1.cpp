// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 40
#include <windows.h>
#include <iostream>
#include <string>
#include "Display.h"

using namespace std;

int main()
{
    HANDLE hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };

    CHAR_INFO* buffer;
    buffer = new CHAR_INFO [SCREEN_HEIGHT*SCREEN_WIDTH];

    SetConsoleScreenBufferSize(hOutput, dwBufferSize);

    SetConsoleWindowInfo(hOutput, true, &rcRegion);
    ReadConsoleOutput(hOutput,(CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
    
    for (int j = 1; j < SCREEN_HEIGHT; j++) {
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            buffer[j*SCREEN_WIDTH +i].Attributes = (( (j + i) + (j%2) )% 2) ? 0x00F0 : 0x000F;
            buffer[j*SCREEN_WIDTH +i].Char.UnicodeChar = 0x2580;
        }
    }

    Display display(buffer, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    /*
    draw(buffer, 3, 2);
    draw(buffer, 1, 3);
    draw(buffer, 0, 2);
    draw(buffer,2, 2);
    */
    WriteConsoleOutput(hOutput, (CHAR_INFO*)buffer, dwBufferSize,
        dwBufferCoord, &rcRegion);
    
    char character;
    cin >> character;

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
