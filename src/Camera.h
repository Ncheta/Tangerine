//------------------------------------------------------------------------------
//
// File Name:	Camera.h
// Author(s):	Ncheta Mbaraonye 
// 
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
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



//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Class:
//------------------------------------------------------------------------------

class CameraObj
{
public:
	//Public Functions:
	void Init(glfwInterface& glfw);
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	glm::mat4 GetWorldViewProjMatrix();
	glm::mat4 GetScreenViewProjMatrix();
	glm::vec2 GetWindowSize();
	void Rotate(float angle);
	
	void SetWindowSize(int width, int height);
	void SetCameraPos(const glm::vec2& pos);
	void SetZoom(float zoomval);
	
	//Public Variables:
private:
	//Private Functions:

	//Private Variables:
	glm::vec2 mWindowSize{ 0.f };
	float mRotation{0.f};
	glm::vec3 mCameraPosition{ 0.0f,0.0f,1.0f };
	float mzoom{ 1.f };

	bool isWorldMatrixDirty{ true };
	bool isScreenMatrixDirty{ true };
	glm::mat4 mworldViewProjMatrix{1.0f};
	glm::mat4 mscreenViewProjMatrix{ 1.0f };

};




