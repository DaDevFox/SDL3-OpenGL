#include "input_manager.h"
#include <cstring>

InputManager::InputManager()
{
	init();
}

void InputManager::init()
{
	// Keyboard

	// Assign current state pointer
	inputState.keyboardState.currentValue = SDL_GetKeyboardState(nullptr);
	// Clear previous state memory
	memset(inputState.keyboardState.previousValue, 0, SDL_SCANCODE_COUNT);
}


void InputManager::prepareForUpdate()
{
	// Keyboard: Copy current state to previous
	memcpy(inputState.keyboardState.previousValue, inputState.keyboardState.currentValue, SDL_SCANCODE_COUNT);
}

bool InputManager::pollInputs()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	bool isRunning = true;
	switch (event.type)
	{
	case SDL_EVENT_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
	return isRunning;
}

const InputState& InputManager::getState() const
{
	return inputState;
}