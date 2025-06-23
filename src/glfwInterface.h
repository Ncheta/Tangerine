//------------------------------------------------------------------------------
//
// File Name:	glfwInterface.h
// Author(s):	Ncheta Mbaraonye (ncheta.mbaraonye)
// 
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
#include <string>
// Using glm for math
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Typedefs:
//------------------------------------------------------------------------------
typedef struct GLFWwindow GLFWwindow;
typedef GLFWwindow* WindowHNDL;


//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Class:
//------------------------------------------------------------------------------
class glfwInterface
{
public:
// Public Functions:
	int Initalize(std::string windowName, int width = 1080, int height = 720);
	int ShouldClose();
	void Update();
	void Exit();
	void SetWindowSize(int width, int height);
	float GetTime();
	glm::vec2 GetWindowSize();
	WindowHNDL GetWindowHandle();
	~glfwInterface();
// Public Variables

private:
// Private Functions:


// Private Variables:
	WindowHNDL mwindow{nullptr};


};





