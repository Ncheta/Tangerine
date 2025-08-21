//------------------------------------------------------------------------------
//
// File Name:	InputSystem.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

// Using glfw for window handling
#include <glfw/glfw3.h>
#include "glfwInterface.h"
#include "InputSystem.h"


//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------
static InputSystem* gInput = nullptr;
//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

InputSystem::InputSystem()
{
	gInput = this;
	prevkeys.fill(false);
	currkeys.fill(false);
}

int InputSystem::Init()
{
	return 0;
}

void InputSystem::Update()
{
	prevkeys = currkeys;

	lastkeytriggered = 0;
}

void InputSystem::Exit()
{
	gInput = nullptr;
}

bool InputSystem::KeyDown(unsigned char key)
{
	if (key > 256 || key < 0)
	{
		//@@TODO: ERROR CHECKING
		return false;
	}

	if (currkeys[key] && prevkeys[key]) return true;
	else return false;
}

bool InputSystem::KeyTriggered(unsigned char key)
{
	if (key > 256 || key < 0)
	{
		//@@TODO: ERROR CHECKING
		return false;
	}

	if (currkeys[key] && !prevkeys[key]) return true;
	else return false;
}

bool InputSystem::KeyReleased(unsigned char key)
{
	if (key > 256 || key < 0)
	{
		//@@TODO: ERROR CHECKING
		return false;
	}

	if (!currkeys[key] && prevkeys[key]) return true;
	else return false;
}

void InputSystem::SetKeyState(unsigned char key, bool state)
{
	if (key > 256 || key < 0)
	{
		//@@TODO: ERROR CHECKING
		return;
	}

	currkeys[key] = state;
	if (state && !prevkeys[key]) lastkeytriggered = key;
}

void InputSystem::HandleInputs(WindowHNDL window, int key, int scancode, int action, int mods)
{
	if (key < 256 && key > 0)
	{
		if (action == GLFW_PRESS) 	gInput->SetKeyState(key, true);
		else if (action == GLFW_RELEASE) gInput->SetKeyState(key, false);
	}

	
}
//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

