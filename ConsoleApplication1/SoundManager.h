#pragma once
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <vector>
#include <map>
#include <string>
#include "GameConstants.h"
#define SOUND_SOURCES_COUNT 4
class idSoundManager
{
private:
	ALCdevice* device;
	ALCcontext* context;
	ALuint musicSource; // source = sound emitter
	ALuint soundSources[SOUND_SOURCES_COUNT];
	std::vector<int> busySoundSources;
	std::map<soundTrack_t, ALuint> soundBuffers;
	std::map<musicTrack_t, ALuint> musicBuffers;

	void RefreshBusySoundSources();
	ALuint GetNextSoundSource();
public:
	idSoundManager();
	~idSoundManager();
	void PlaySoundTrack(soundTrack_t);
	void PlaySoundTrack(soundTrack_t track, int canal);
	void PlayMusicTrack(musicTrack_t);
};

