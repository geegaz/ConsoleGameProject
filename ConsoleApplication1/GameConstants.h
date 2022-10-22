#pragma once
#include <string>
#include <map>
#include <windows.h>
#include <Xinput.h>
#include <vector>
#define PLAYER_MASK 1
#define BLOCK_MASK 2
#define WALL_MASK 4
#define FIRE_MASK 8
#define ENEMY_MASK 16
#define POWERUP_MASK 32
#define NONE_MASK 0

const std::string RESOURCES_PATH = ".\\resources\\";
enum class gameState_t { MENU, IN_GAME };
enum class control_t {UP, RIGHT, DOWN, LEFT, START};

const std::vector<int> KEYBOARD_KEYS = {'Z','Q','S','D',' ', VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT};
const std::map<int, control_t> KEYBOARD_MAPPING = { {'Z', control_t::UP}, {'Q',control_t::LEFT}, {'S',control_t::DOWN}, {'D',control_t::RIGHT},
												{VK_UP, control_t::UP}, {VK_LEFT,control_t::LEFT}, { VK_DOWN ,control_t::DOWN}, {VK_RIGHT,control_t::RIGHT}};
const std::map<int, control_t> KEYBOARD_MENU_MAPPING = { {' ', control_t::START} };

const std::vector<int> XINPUT_KEYS = { XINPUT_GAMEPAD_DPAD_UP, XINPUT_GAMEPAD_DPAD_LEFT, XINPUT_GAMEPAD_DPAD_RIGHT, XINPUT_GAMEPAD_DPAD_DOWN, XINPUT_GAMEPAD_START };
const std::map<int, control_t> XINPUT_MAPPING = { {XINPUT_GAMEPAD_DPAD_UP, control_t::UP}, {XINPUT_GAMEPAD_DPAD_LEFT,control_t::LEFT}, {XINPUT_GAMEPAD_DPAD_DOWN ,control_t::DOWN}, {XINPUT_GAMEPAD_DPAD_RIGHT,control_t::RIGHT},
												{XINPUT_GAMEPAD_START, control_t::START} };

const std::map<int, control_t> XINPUT_MENU_MAPPING = { {XINPUT_GAMEPAD_START, control_t::START} };

const std::string SOUNDS_PATH = RESOURCES_PATH + "sounds\\";

const std::string SPRITES_PATH = RESOURCES_PATH + "sprites\\";

enum class musicTrack_t { NONE, DEATH };
enum class soundTrack_t { DEATH, COLLECT };
const std::map<musicTrack_t, std::string> MUSIC_FILES = { {musicTrack_t::DEATH, SOUNDS_PATH + "death_jingle.wav"}, {musicTrack_t::NONE, SOUNDS_PATH+"music_none.wav"}};
const std::map<soundTrack_t, std::string> SOUND_FILES = { {soundTrack_t::COLLECT, SOUNDS_PATH+"sfx8.wav"}, {soundTrack_t::DEATH, SOUNDS_PATH+"death_goldenberry.wav"} };

const std::string ANIMATIONS_PATH = RESOURCES_PATH + "animations\\";
const std::string POSITION_ANIMATIONS_FILE = ANIMATIONS_PATH +"position_animations.txt";
const std::string FRAME_ANIMATIONS_FILE = ANIMATIONS_PATH +"frame_animations.txt";
