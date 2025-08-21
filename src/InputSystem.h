//------------------------------------------------------------------------------
//
// File Name:	InputSystem.h
// Author(s):	Ncheta Mbaraonye 
// 
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
#include <array>
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------
class glfwInterface;
typedef WindowHNDL;
//------------------------------------------------------------------------------
// Public Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Typedefs:
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Class:
//------------------------------------------------------------------------------

class InputSystem
{
public:

	//Public Functions:
	InputSystem();
	int Init();
	void Update();
	void Exit();

	bool KeyDown(unsigned char key);
	bool KeyTriggered(unsigned char key);
	bool KeyReleased(unsigned char key);

	void SetKeyState(unsigned char key, bool state);
	static void HandleInputs(WindowHNDL window, int key, int scancode, int action, int mods);
	//Public Variables:
private:
	//Private Functions:
	
	//Private Variables:
	std::array<bool, 256> prevkeys;
	std::array<bool, 256> currkeys;

	unsigned char lastkeytriggered{ 0 };
};




