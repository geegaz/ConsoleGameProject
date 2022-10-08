#include "SoundManager.h"
#include "SoundUtils.h"
#include <cstdint>
#include <stdexcept>

static void initializeSource(ALuint source) {
    alSourcef(source, AL_PITCH, 1); // default pitch
    alSourcef(source, AL_GAIN, 1.0f); // default gain
    alSource3f(source, AL_POSITION, 0, 0, 0); // default position
    alSource3f(source, AL_VELOCITY, 0, 0, 0); // default velocity
}

static void LoadAudio(std::string path, ALuint buffer) {
    //------------------ Sound loading
    int32_t numChannels, sampleRate, bitsPerSample, dataSize;
    char* raw_sound_data = LoadWavFile(path, numChannels, sampleRate, bitsPerSample, dataSize);  // SoundUtils
    if (raw_sound_data != nullptr) {
        ALenum format;
        if (numChannels == 1 && bitsPerSample == 8)
            format = AL_FORMAT_MONO8;
        else if (numChannels == 1 && bitsPerSample == 16)
            format = AL_FORMAT_MONO16;
        else if (numChannels == 2 && bitsPerSample == 8)
            format = AL_FORMAT_STEREO8;
        else
            format = AL_FORMAT_STEREO16; // (numChannels == 1 && bitsPerSample == 8)

        alBufferData(buffer, format, raw_sound_data, dataSize, sampleRate); // put sound data in buffer

        delete[] raw_sound_data; // free buffer because sound data is stored by OpenAL
    }
    else {
        throw std::invalid_argument("LoadAudio: failed to load '" + path +"'");
    }
}


idSoundManager::idSoundManager() {
    device = alcOpenDevice(NULL); // retrieve default output device (speakers/headphones/...)
    context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context); // use current context

    // ------------- initializing audio sources (sound emitters) --------------
    alGenSources(SOUND_SOURCES_COUNT, soundSources);
    alGenSources(1, &musicSource);
    alSourcei(musicSource, AL_LOOPING, AL_TRUE); // Music will loop


    for (int i = 0; i < SOUND_SOURCES_COUNT; i++) {
        initializeSource(soundSources[i]);
    }
    initializeSource(musicSource);

    // ------------- generating buffers (audio tracks) --------------
    auto sf_i = SOUND_FILES.begin();
    auto sf_end = SOUND_FILES.end();
    ALuint* buffer;
    while (sf_i != sf_end) {
        buffer = &soundBuffers[(*sf_i).first];
        alGenBuffers(1, buffer);
        LoadAudio((*sf_i).second, *buffer);
        sf_i++;
    }
    auto mf_i = MUSIC_FILES.begin();
    auto mf_end = MUSIC_FILES.end();
    while (mf_i != mf_end) {
        buffer = &musicBuffers[(*mf_i).first];
        alGenBuffers(1, buffer);
        LoadAudio((*mf_i).second, *buffer);
        mf_i++;
    }
}


idSoundManager::~idSoundManager() {
    ALuint* buffer;
    alDeleteSources(SOUND_SOURCES_COUNT, soundSources);
    alDeleteSources(1, &musicSource);

    // buffers should be deleted after sources
    auto sb_i = soundBuffers.begin();
    auto sb_end = soundBuffers.end();

    while (sb_i != sb_end) {
        alDeleteBuffers(1, &((sb_i)->second));
        sb_i++;
    }

    auto mb_i = musicBuffers.begin();
    auto mb_end = musicBuffers.end();

    while (mb_i != mb_end) {
        alDeleteBuffers(1, &((mb_i)->second));
        mb_i++;
    }

    alcDestroyContext(context);
    alcCloseDevice(device);
}

void idSoundManager::PlaySoundTrack(soundTrack_t track) {
    ALuint source = GetNextSoundSource();
    alSourcei(source, AL_BUFFER, soundBuffers[track]);
    alSourcePlay(source);
}

void idSoundManager::PlayMusicTrack(musicTrack_t track) {
    alSourceStop(musicSource);
    alSourcei(musicSource, AL_BUFFER, musicBuffers[track]);
    alSourcePlay(musicSource);

}
void idSoundManager::RefreshBusySoundSources() {
    ALint state;
    for (int i = 0; i < SOUND_SOURCES_COUNT; i++) { 
        alGetSourcei(soundSources[i], AL_SOURCE_STATE, &state);

        if (state == AL_PLAYING) { // add if source is busy
            if (std::find(busySoundSources.begin(), busySoundSources.end(), i) == busySoundSources.end())
                busySoundSources.push_back(i);
        }

        else { // erase if source is not busy
            auto position = std::find(busySoundSources.begin(), busySoundSources.end(), i);
            if (position != busySoundSources.end())
                busySoundSources.erase(position);
        }
    }
}

ALuint idSoundManager::GetNextSoundSource() {
    RefreshBusySoundSources();
    for (int i = 0; i < SOUND_SOURCES_COUNT; i++) {
        if (std::find(busySoundSources.begin(), busySoundSources.end(), i) == busySoundSources.end())
            return soundSources[i];
    }
    ALuint source_id = busySoundSources[0];
    busySoundSources.erase(busySoundSources.begin());
    alSourceStop(source_id);
    return source_id;
}
