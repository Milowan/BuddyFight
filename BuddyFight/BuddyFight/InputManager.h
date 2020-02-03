#pragma once
#include <SDL.h>
#include "MathHelper.h"
#include "Types.h"





class InputManager
{
private:

	static InputManager* instance;

	const Uint8* keyboardState;
	Uint8* prevKeyboardState;
	int keylength;

	Uint32 prevMouseState;
	Uint32 mouseState;

	int mouseXPos;
	int mouseYPos;

public:

	static InputManager* GetInstance();
	static void Release();

	bool KeyDown(SDL_Scancode scancode);
	bool KeyPressed(SDL_Scancode scancode);
	bool KeyReleased(SDL_Scancode scancode);

	bool MouseButtonDown(MouseButton button);
	bool MouseButtonPressed(MouseButton button);
	bool MouseButtonReleased(MouseButton button);

	Vector2 GetMousePosition();

	void Update();
	void UpdatePrevInput();

private:

	InputManager();
	~InputManager();
};

