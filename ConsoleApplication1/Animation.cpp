#include "Animation.h"
#include <fstream>
#include <iostream>

// idAnimationState --------------------------------------------------------
idAnimationState::idAnimationState() {
	frameStep = 0;
	yPositionStep = 0;
	positionAnimation = nullptr;
	frameAnimation = nullptr;
}

bool idAnimationState::NextFrame() {
	if (frameAnimation != nullptr) {
		if (frameAnimation->loop) {
			frameStep = (frameStep+1)%frameAnimation->length;
			return true;
		}
		else {
			if (frameStep < frameAnimation->length - 1) {
				frameStep++;
				return true;
			}
		}
	}
	return false;
}

bool idAnimationState::NextPosition() {
	if (positionAnimation != nullptr && yPositionStep < positionAnimation->length - 1) {
		yPositionStep++;
		return true;
	}
	return false;
}

void idAnimationState::SetPositionAnimation(positionAnimation_t* _positionAnimation) {
	 positionAnimation = _positionAnimation;
	 yPositionStep = 0;
}

void idAnimationState::SetFrameAnimation(frameAnimation_t* _frameAnimation) {
	frameAnimation = _frameAnimation;
	frameStep = 0;
}

// idAnimationRegister --------------------------------------------------------
std::map<std::string, positionAnimation_t> idAnimationRegister::POSITION_ANIMATIONS;
std::map<std::string, frameAnimation_t> idAnimationRegister::FRAME_ANIMATIONS;

void idAnimationRegister::LoadAllPositionAnimations(std::string filename) {
	int* y_positions;
	std::ifstream file(filename);
	std::string title;
	int length, line = 1;
	bool flip_y;
	do {
		file >> title;
		file >> flip_y;
		file >> length;
		if (file.fail())
		{
			std::cerr << "LoadAllPositionAnimations: failed to read line " << line << " of " << filename << std::endl;
			break;
		}
		y_positions = new int[length];
		POSITION_ANIMATIONS[title].yPositions = y_positions;
		POSITION_ANIMATIONS[title].length = length;
		POSITION_ANIMATIONS[title].flipY = flip_y;
		for (int i = 0; i < length; i++) {
			file.get();
			file >> y_positions[i];
			if (file.fail())
			{
				std::cerr << "LoadAllPositionAnimations: failed to read line " << line << " of " << filename << std::endl;
				i = length-1;
			}
		}
		line++;
	} while (!file.fail() && file.get() == '\n');
}

void idAnimationRegister::LoadAllFrameAnimations(std::string filename) {
	int* frames;
	std::ifstream file(filename);
	std::string title;
	int length, line = 1;
	bool loop;
	do {
		file >> title;
		file >> loop;
		file >> length;
		if (file.fail())
		{
			std::cerr << "LoadAllFrameAnimations: failed to read line " << line << " of " << filename << std::endl;
			break;
		}
		frames = new int[length];
		POSITION_ANIMATIONS[title].yPositions = frames;
		POSITION_ANIMATIONS[title].length = length;
		POSITION_ANIMATIONS[title].flipY = loop;
		for (int i = 0; i < length; i++) {
			file.get();
			file >> frames[i];
			if (file.fail())
			{
				std::cerr << "LoadAllFrameAnimations: failed to read line " << line << " of " << filename << std::endl;
				i = length - 1;
			}
		}
		line++;
	} while (!file.fail() && file.get() == '\n');
}

void idAnimationRegister::LoadAllAnimations(std::string positionFilename, std::string frameFilename) {
	LoadAllPositionAnimations(positionFilename);
	LoadAllFrameAnimations(frameFilename);
}

void idAnimationRegister::UnloadAllAnimations() {
	auto p_i = POSITION_ANIMATIONS.begin();
	auto p_end = POSITION_ANIMATIONS.end();
	while (p_i != p_end) {
		delete[] p_i->second.yPositions;
		p_i++;
	}
	auto f_i = FRAME_ANIMATIONS.begin();
	auto f_end = FRAME_ANIMATIONS.end();
	while (f_i != f_end) {
		delete[] f_i->second.frames;
		f_i++;
	}
}

void idAnimationRegister::LoadPositionAnimations(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		positionAnimations[line] = & (POSITION_ANIMATIONS.at(line));
	}
}

void idAnimationRegister::LoadFrameAnimations(std::string filename) {
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		frameAnimations[line] = &(FRAME_ANIMATIONS.at(line));
	}
}

positionAnimation_t* idAnimationRegister::getPositionAnimation(std::string key) {
	auto value = positionAnimations.find(key);
	auto end = positionAnimations.end();
	return (value != end) ? value->second : nullptr;
}

frameAnimation_t* idAnimationRegister::getFrameAnimation(std::string key) {
	auto value = frameAnimations.find(key);
	auto end = frameAnimations.end();
	return (value != end) ? value->second : nullptr;
}

idAnimationRegister idAnimationRegister::defaultRegister;