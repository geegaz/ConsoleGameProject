#pragma once
#include <string>
#include "GameConstants.h"
class idLevelLoader
{
public:
	static void LoadLevel(std::string levelname, int xSize, int ySize);
	static int** LoadCsv(std::string filename, int xSize, int ySize);
private:
	static void LoadEntities(int** level, int xSize, int ySize);
	static void LoadBackground(int** level, int xSize, int ySize);
	static void LoadStructure(int** level, int xSize, int ySize);
};