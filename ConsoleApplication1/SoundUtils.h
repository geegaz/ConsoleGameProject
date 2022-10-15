#ifndef __SOUND_UTILS__
#define __SOUND_UTILS__
/*
Code provided by Alex VU
*/

char* LoadWavFile(
	const std::string& fileName,
	int32_t& numChannels,
	int32_t& sampleRate,
	int32_t& bitsPerSample,
	int32_t& dataSize);

#endif
