//------------------------------------------------------------------------------
//
// File Name:	glfwInterface.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include "glfwInterface.h"
// Using glad to help with loading OpenGL
#include "glad/glad.h"
// Using glfw for window handling
#include <glfw/glfw3.h>
// Using glm for math
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------






int glfwInterface::Initalize(std::string windowName, int width, int height)
{
	if (!glfwInit()) return -1;
	if (width < 0 || height < 0) return -1;


	//Set OpenGL version to Core profile 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mwindow = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);

	if (!mwindow)
		return -1;

	glfwMakeContextCurrent(mwindow);
	glfwSwapInterval(1);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		glfwDestroyWindow(mwindow);
		mwindow = nullptr;
		glfwTerminate();
		return -1;
	}

	return 1;
}

int glfwInterface::ShouldClose()
{
	if (!mwindow)
	{
		//error thing
		return 0;
	}
	return glfwWindowShouldClose(mwindow);
}

void glfwInterface::Update()
{
	if (!mwindow)
	{
		//error thing
		return;
	}

	glfwPollEvents();
	glfwSwapBuffers(mwindow);
}


void glfwInterface::Exit()
{
	if (!mwindow)
	{
		//error thing
		return;
	}

	glfwDestroyWindow(mwindow);
	mwindow = nullptr;
	glfwTerminate();
}

void glfwInterface::SetWindowSize(int width, int height)
{
	if (width < 0 || height < 0)
	{
		//error thing
		return;
	}

	glfwSetWindowSize(mwindow, width, height);
}

glm::vec2 glfwInterface::GetWindowSize()
{
	int width = 0;
	int height = 0;
	glfwGetWindowSize(mwindow, &width, &height);

	return glm::vec2(width, height);
}

WindowHNDL glfwInterface::GetWindowHandle()
{
	return mwindow;
}

glfwInterface::~glfwInterface()
{
	Exit();
}

void glfwInterface::SetCallBacks()
{
	
}









//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





