//------------------------------------------------------------------------------
//
// File Name:	Camera.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Camera.h"
#include "GraphicsSystem.h"

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
void CameraObj::Init(glfwInterface& glfw)
{
	mWindowSize = glfw.GetWindowSize();
}

glm::mat4 CameraObj::GetViewMatrix()
{
	glm::mat4 view = glm::lookAt(mCameraPosition, glm::vec3(mCameraPosition.x, mCameraPosition.y, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	return view;
}

glm::mat4 CameraObj::GetProjectionMatrix() //@@TODO: increase near and far z's to add z layers (?)
{

	glm::mat4 projection = glm::ortho(
		mCameraPosition.x - (mWindowSize.x / 2.0f), mCameraPosition.x + (mWindowSize.x / 2.0f),
		mCameraPosition.y - (mWindowSize.y / 2.0f), mCameraPosition.y + (mWindowSize.y / 2.0f),-1.f, 1.f
	);

	return projection;
}

glm::mat4 CameraObj::GetViewProjMatrix()
{
	if (isMatrixDirty)
	{
		glm::mat4 viewprojMatrix(1.0f);
		glm::mat4 rotationMatrix = glm::rotate(glm::radians(mRotation), glm::vec3(0.0, 0.0, 1.0));
		glm::mat4 scaleMatrix = glm::scale(glm::vec3(mzoom, mzoom, 1.0f));

		viewprojMatrix = GetProjectionMatrix() * rotationMatrix * scaleMatrix * GetViewMatrix();
		mviewProjMatrix = viewprojMatrix;
		isMatrixDirty = false;
	}



	return mviewProjMatrix;
}

void CameraObj::Rotate(float angle)
{
	mRotation = angle;
	isMatrixDirty = true;
}


void CameraObj::SetWindowSize(int width, int height)
{
	mWindowSize = glm::vec2(width, height);
	isMatrixDirty = true;
}

void CameraObj::SetCameraPos(const glm::vec2& pos)
{
	mCameraPosition.x = pos.x;
	mCameraPosition.y = pos.y;
	isMatrixDirty = true;
}

void CameraObj::SetZoom(float zoom)
{
	mzoom = zoom;
	isMatrixDirty = true;
}






//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





