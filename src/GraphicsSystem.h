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
#include "TextureManager.h"
#include "Texture.h"
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
	void SetBGColor(const glm::vec4& color);
	void SetWindowSize(int width, int height);
	void SetCurrShader(Shader* shader);
	void SetCurrTexture(Texture* texture);
	void SetTransformMatrix(const glm::mat4& transform);
	void SetTransformMatrix(const glm::vec2& pos, const glm::vec2& scale, float rotation);
	glm::vec2 ScreentoWorld(const glm::vec2& pos);
	void InScreenSpace(bool InScreen);
	void SetTintColor(const glm::vec4& color);
	void SetTextureOffset(const glm::vec2& offset);
	Shader* GetCurrShader();
	glm::vec2 GetWindowSize() const;
	void StartDraw();
	void EndDraw();
	void Draw(const Mesh* mesh);

	
	

//Public Variables:
	glfwInterface& mglfw;
	CameraObj Camera;
	MeshManager mMeshManager;
	ShaderManager mShaderManager;
	TextureManager mTextureManager;
	 
private:
// Private Functions:
	static void ResizeViewport(WindowHNDL window, int width, int height);

// Private Variables:

	Shader* mcurrShader{nullptr};
	Texture* mcurrTexture{ nullptr };
	glm::mat4 mTransformMatrix{ 1 };
	glm::vec4 mTintColor{ 0.0f };
	glm::vec2 mTextureOffset{ 0.0f };
	bool isDrawingEnabled{ false };
	bool isInScreenSpace{ false };
	

};

extern GraphicsSystem* gGraphics;







