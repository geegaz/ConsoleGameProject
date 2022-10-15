#include "LevelLoader.h"
#include <fstream>

using namespace std;
void idLevelLoader::LoadLevel(string levelname, int xSize, int ySize) {
	int** level_entities = LoadCsv("levelname", xSize, ySize);
	int** level_background = LoadCsv("levelname", xSize, ySize);
	int** level_structure = LoadCsv("levelname", xSize, ySize);

	LoadBackground(level_background, xSize, ySize);
	LoadStructure(level_structure, xSize, ySize);
	LoadEntities(level_entities, xSize, ySize);

	for (int i = 0; i < xSize; i++) {
		delete[] level_entities[i];
		delete[] level_background[i];
		delete[] level_structure[i];
	}

	delete[] level_entities;
	delete[] level_background;
	delete[] level_structure;
}

void idLevelLoader::LoadEntities(int** level, int xSize, int ySize) {
	int element;
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			element = level[j][i];
			if (element != -1) {
				// TODO Place element
			}
		}
	}
}

void idLevelLoader::LoadBackground(int** level, int xSize, int ySize) {
	int element;
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			element = level[j][i];
			if (element != -1) {
				// TODO Place element
			}
		}
	}
}
void idLevelLoader::LoadStructure(int** level, int xSize, int ySize) {
	int element;
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			element = level[j][i];
			if (element != -1) {
				// TODO Place element
			}
		}
	}
}

int** idLevelLoader::LoadCsv(string filename, int xSize, int ySize) {
	int** xArray = new int*[xSize];
	ifstream file(filename);

	for (int i = 0; i < xSize; i++) {
		xArray[i] = new int[ySize];
	}

	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j < xSize; j++) {
			
			file >> xArray[j][i];
			file.get(); // removes '\n' and ','
		}
	}
	return xArray;
}