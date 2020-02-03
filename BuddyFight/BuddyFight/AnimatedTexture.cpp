#include "AnimatedTexture.h"




void AnimatedTexture::RunAnimation() {
	if (!mAnimationDone) {
		mAnimationTimer += mTimer->GetDeltaTime();

		if (mAnimationTimer >= mAnimationSpeed) {
			if (mWrapMode == LOOP) {
				// reset timer, accounting for extra time
				mAnimationTimer -= mAnimationSpeed;
			}
			else {
				mAnimationDone = true;
				// back up the timer to the last frame
				mAnimationTimer = mAnimationSpeed - mTimePerFrame;
			}
		}

		if (mAnimationDirection == HORIZONTAL) {
			sourceRect.x = mStartX + (int)(mAnimationTimer / mTimePerFrame) * width;
		}
		else {
			sourceRect.y = mStartY + (int)(mAnimationTimer / mTimePerFrame) * height;
		}
	}
}

AnimatedTexture::AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, AnimDir animationDir, bool managed)
	: Texture(filename, x, y, w, h, managed) {
	mTimer = Timer::GetInstance();

	mStartX = x;
	mStartY = y;

	mFrameCount = frameCount;
	mAnimationSpeed = animationSpeed;
	mTimePerFrame = mAnimationSpeed / mFrameCount;
	mAnimationTimer = 0.0f;

	mWrapMode = LOOP;
	mAnimationDirection = animationDir;

	mAnimationDone = false;
}

AnimatedTexture::~AnimatedTexture() { }

void AnimatedTexture::SetWrapMode(WrapMode wrapMode) {
	mWrapMode = wrapMode;
}

void AnimatedTexture::ResetAnimation() {
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
}

bool AnimatedTexture::IsAnimating() {
	return !mAnimationDone;
}

void AnimatedTexture::Update() {
	RunAnimation();
}