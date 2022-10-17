#pragma once
#include <map>
#include <string>

struct frameAnimation_t {
    int* frames;
	int length;
	bool loop;
};

struct positionAnimation_t {
    int* positions;
    int length;
    bool flipVertically;
};

struct animationState_t {
    positionAnimation_t* positionAnimation;
    frameAnimation_t* frameAnimation;
	int frameStep;
    int positionStep;
};

struct animationRegister {
    std::map<std::string, positionAnimation_t> positionAnimations;
    std::map<std::string, frameAnimation_t> frameAnimations;
};