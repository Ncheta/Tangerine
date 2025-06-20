//------------------------------------------------------------------------------
//
// File Name:	GraphicsSystem.h
// Author(s):	Ncheta Mbaraonye (ncheta.mbaraonye)
// 
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
#include "glfwInterface.h"
// Using glm for math
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "MeshManager.h"
#include "ShaderManager.h"
#include "Camera.h"
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

class GraphicsSystem
{
public:
//Public Functions:
	GraphicsSystem( glfwInterface& glfw); //Initialize with WindowInterface rn it's glfw
	int Init();
	void Update();
	int Exit();
	void SetBGColor(glm::vec3& color);
	void SetWindowSize(int width, int height);
	void SetCurrShader(Shader* shader);
	void SetTransformMatrix(const glm::mat4& transform);
	void SetTransformMatrix(const glm::vec2& pos, const glm::vec2& scale, float rotation);
	Shader* CurrShader();
	glm::vec2 GetWindowSize() const;
	void StartDraw();
	void EndDraw();
	void Draw(const Mesh* mesh);

	
	

//Public Variables:
	glfwInterface& mglfw;
	CameraObj Camera;
	MeshManager mMeshManager;
	ShaderManager mShaderManager;
	 
private:
// Private Functions:
	static void ResizeViewport(WindowHNDL window, int width, int height);

// Private Variables:

	Shader* mcurrShader{nullptr};
	glm::mat4 mTransformMatrix{ 1 };
	bool isDrawingEnabled{ false };
	

};

extern GraphicsSystem* gGraphics;







