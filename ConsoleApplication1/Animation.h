#pragma once
#include <map>
#include <string>

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
    std::map<std::string, positionAnimation_t*> positionAnimations;
    std::map<std::string, frameAnimation_t*> frameAnimations;
    static void LoadAllPositionAnimations(std::string filename);
    static void  LoadAllFrameAnimations(std::string filename);
public:
    static idAnimationRegister defaultRegister;
    static void LoadAllAnimations(std::string positionFilename, std::string frameFilename);
    static void UnloadAllAnimations();
    void LoadPositionAnimations(std::string filename);
    void LoadFrameAnimations(std::string filename);
    positionAnimation_t* getPositionAnimation(const std::string);
    frameAnimation_t* getFrameAnimation(const std::string);
};