#pragma once
#include "Texture.h"
#include "Timer.h"
#include "Types.h"





class AnimatedTexture :
	public Texture
{

protected:
	Timer* mTimer;
	int mStartX;
	int mStartY;

	int mFrameCount; // total frames

	float mAnimationSpeed; // in seconds
	float mTimePerFrame; // time to display
	float mAnimationTimer; // time displayed

	WrapMode mWrapMode;
	AnimDir mAnimationDirection;

	bool mAnimationDone;

	virtual void RunAnimation();

public:
	AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed = false);
	~AnimatedTexture();

	void SetWrapMode(WrapMode mode);

	virtual void ResetAnimation();
	bool IsAnimating();

	void Update();
};

