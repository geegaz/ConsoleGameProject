#pragma once
#include <string>
#include <map>
#include <windows.h>
#include <Xinput.h>
#define PLAYER_MASK 1
#define BLOCK_MASK 2
#define WALL_MASK 4
#define FIRE_MASK 8
#define ENEMY_MASK 16
#define POWERUP 32

const std::string RESOURCES_PATH = ".\\resources\\";
enum class gameState_t { MENU, IN_GAME };
enum class control_t {UP, RIGHT, DOWN, LEFT, START};
const std::map<int, control_t> KEYBOARD_MAPPING = { {'Z', control_t::UP}, {'Q',control_t::LEFT}, {'S',control_t::DOWN}, {'D',control_t::RIGHT},
												{VK_UP, control_t::UP}, {VK_LEFT,control_t::LEFT}, { VK_DOWN ,control_t::DOWN}, {VK_RIGHT,control_t::RIGHT},
												{' ', control_t::START}};

const std::map<int, control_t> XINPUT_MAPPING = { {XINPUT_GAMEPAD_DPAD_UP, control_t::UP}, {XINPUT_GAMEPAD_DPAD_LEFT,control_t::LEFT}, {XINPUT_GAMEPAD_DPAD_DOWN ,control_t::DOWN}, {XINPUT_GAMEPAD_DPAD_RIGHT,control_t::RIGHT},
												{XINPUT_GAMEPAD_START, control_t::START} };

const std::string SOUNDS_PATH = RESOURCES_PATH + "sounds\\";
enum class musicTrack_t { OVERWORLD_1, DEATH };
enum class soundTrack_t { JUMP, COIN };
const std::map<musicTrack_t, std::string> MUSIC_FILES = { {musicTrack_t::DEATH, SOUNDS_PATH+"death_jingle.wav"} };
const std::map<soundTrack_t, std::string> SOUND_FILES = { {soundTrack_t::COIN, SOUNDS_PATH+"sfx8.wav"}, {soundTrack_t::JUMP, SOUNDS_PATH+"death_goldenberry.wav"} };

const std::string ANIMATIONS_PATH = RESOURCES_PATH + "animations\\";
const std::string POSITION_ANIMATIONS_FILE = ANIMATIONS_PATH +"position_animations.txt";
const std::string FRAME_ANIMATIONS_FILE = ANIMATIONS_PATH +"frame_animations.txt";
