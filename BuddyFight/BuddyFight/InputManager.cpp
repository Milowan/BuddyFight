#include "InputManager.h"





InputManager* InputManager::instance = NULL;

InputManager* InputManager::GetInstance()
{
	if (instance == NULL)
		instance = new InputManager();

	return instance;
}

void InputManager::Release()
{
	delete instance;
	instance = NULL;
}

InputManager::InputManager()
{
	keyboardState = SDL_GetKeyboardState(&keylength);
	prevKeyboardState = new Uint8[keylength];
	SDL_memcpy(prevKeyboardState, keyboardState, keylength);
}

InputManager::~InputManager()
{
	delete[] prevKeyboardState;
	prevKeyboardState = NULL;
}

bool InputManager::KeyDown(SDL_Scancode scancode)
{
	return keyboardState[scancode];
}

bool InputManager::KeyPressed(SDL_Scancode scancode)
{
	return !prevKeyboardState[scancode] && keyboardState[scancode];
}

bool InputManager::KeyReleased(SDL_Scancode scancode)
{
	return prevKeyboardState[scancode] && !keyboardState[scancode];
}

bool InputManager::MouseButtonDown(MouseButton button)
{
	Uint32 mask = 0;

	switch (button)
	{
	case LEFT:
		mask = SDL_BUTTON_LMASK;
		break;
	case RIGHT:
		mask = SDL_BUTTON_RMASK;
		break;
	case MIDDLE:
		mask = SDL_BUTTON_MMASK;
		break;
	case BACK:
		mask = SDL_BUTTON_X1MASK;
		break;
	case FORWARD:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return (mouseState & mask) != 0;
}

bool InputManager::MouseButtonPressed(MouseButton button)
{
	Uint32 mask = 0;

	switch (button)
	{
	case LEFT:
		mask = SDL_BUTTON_LMASK;
		break;
	case RIGHT:
		mask = SDL_BUTTON_RMASK;
		break;
	case MIDDLE:
		mask = SDL_BUTTON_MMASK;
		break;
	case BACK:
		mask = SDL_BUTTON_X1MASK;
		break;
	case FORWARD:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return !(prevMouseState & mask) && (mouseState & mask);
}

bool InputManager::MouseButtonReleased(MouseButton button)
{
	Uint32 mask = 0;

	switch (button)
	{
	case LEFT:
		mask = SDL_BUTTON_LMASK;
		break;
	case RIGHT:
		mask = SDL_BUTTON_RMASK;
		break;
	case MIDDLE:
		mask = SDL_BUTTON_MMASK;
		break;
	case BACK:
		mask = SDL_BUTTON_X1MASK;
		break;
	case FORWARD:
		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return (prevMouseState & mask) && !(mouseState & mask);
}

Vector2 InputManager::GetMousePosition()
{
	return Vector2((float)mouseXPos, (float)mouseYPos);
}

void InputManager::Update()
{
	mouseState = SDL_GetMouseState(&mouseXPos, &mouseYPos);
}

void InputManager::UpdatePrevInput()
{
	SDL_memcpy(prevKeyboardState, keyboardState, keylength);
	prevMouseState = mouseState;
}