#pragma once
#include "AssetManager.h"





class AudioManager {
private:
	static AudioManager* sInstance;
	AssetManager* mAssetManager;

public:
	static AudioManager* GetInstance();
	static void Release();

	void PlayMusic(std::string filename, int loops = -1);
	void PlayMusic(Mix_Music* music, int loops = -1);
	void PauseMusic();
	void ResumeMusic();

	void PlaySFX(std::string filename, int loops = 0, int channel = -1);
	void PlaySFX(Mix_Chunk* sfx, int loops = 0, int channel = -1);

private:
	AudioManager();
	~AudioManager();
};