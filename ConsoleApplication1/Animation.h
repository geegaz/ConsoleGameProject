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
    void NextFrame();
    void NextPosition();
    void SetPositionAnimation(positionAnimation_t* positionAnimation);
    void SetFrameAnimation(frameAnimation_t* frameAnimation);
};

class idAnimationRegister {
private:
    static std::map<std::string, positionAnimation_t> POSITION_ANIMATIONS;
    static std::map<std::string, positionAnimation_t> FRAME_ANIMATIONS;
    std::map<std::string, positionAnimation_t*> positionAnimations;
    std::map<std::string, frameAnimation_t*> frameAnimations;
public:
    static void LoadAllAnimations(std::string filename);
    static void UnloadAllAnimations();
    void LoadPositionAnimations(std::string filename);
    void LoadFrameAnimations(std::string filename);
    positionAnimation_t* getPositionAnimation(std::string);
    frameAnimation_t* getFrameAnimation(std::string);
};