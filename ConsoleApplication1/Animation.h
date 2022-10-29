#pragma once
#include <map>
#include <string>
#include "GameConstants.h"

struct frameAnimation_t {
    int* frames;
	int length;
	bool loop;
};

struct positionAnimation_t {
    int* yPositions;
    int length;
    bool flipY;
};

class idAnimationState {
public:
    positionAnimation_t* positionAnimation;
    frameAnimation_t* frameAnimation;
	int frameStep;
    int yPositionStep;
    int defaultFrame;
    idAnimationState();
    bool NextFrame();
    bool NextPosition();
    void SetPositionAnimation(positionAnimation_t* _positionAnimation);
    void SetFrameAnimation(frameAnimation_t* _frameAnimation);
};

class idAnimationRegister {
private:
    static std::map<std::string, positionAnimation_t> POSITION_ANIMATIONS;
    static std::map<std::string, frameAnimation_t> FRAME_ANIMATIONS;
    static void LoadAllPositionAnimations(std::string filename);
    static void  LoadAllFrameAnimations(std::string filename);
    idAnimationRegister();
public:
    static void LoadAllAnimations(std::string positionFilename, std::string frameFilename);
    static void UnloadAllAnimations();
    static positionAnimation_t* getPositionAnimation(const std::string);
    static frameAnimation_t* getFrameAnimation(const std::string);
};