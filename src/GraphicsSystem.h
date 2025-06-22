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
#include "MaterialManager.h"
#include "Camera.h"
#include "Tangerine.h"

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

class GraphicsSystem //@@TODO: error handling for all pointer usages
{
public:


//Public Functions:
	GraphicsSystem( glfwInterface& glfw); //Initialize with WindowInterface rn it's glfw
	int Init();
	void Update();
	int Exit();
	void SetBGColor(const glm::vec4& color);
	void SetWindowSize(int width, int height);
	void SetCustomShader(Shader* shader);
	void SetCurrMaterial(Material* material);
	void SetTransformMatrix(const glm::mat4& transform);
	void SetTransformMatrix(const glm::vec2& pos, const glm::vec2& scale, float rotation);
	void SetGlobalShaderMode(GlobalShaderMode mode);
	glm::vec2 ScreentoWorld(const glm::vec2& pos);
	void InScreenSpace(bool InScreen);
	void SetCurrMatTintColor(const glm::vec4& color);
	void SetCurrMatTextureOffset(const glm::vec2& offset);
	void SetCurrMatShader(Shader* shader);
	Shader* GetCurrShader();
	Material* GetCurrMaterial();
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
	MaterialManager mMaterialManager;
	 
private:
// Private Functions:
	static void ResizeViewport(WindowHNDL window, int width, int height);
	void SetCommonUniforms();
	Shader* GetAppropriateShader();
// Private Variables:

	Shader* mcurrShader{nullptr};
	Shader* mcustomShader{ nullptr };
	Material* mcurrMaterial{ nullptr };
	glm::mat4 mTransformMatrix{ 1 };
	bool isDrawingEnabled{ false };
	bool isInScreenSpace{ false };
	GlobalShaderMode mGlobalShadermode{ GlobalShaderMode::DEFAULT };
	

};

extern GraphicsSystem* gGraphics;







