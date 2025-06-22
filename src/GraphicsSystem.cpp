//------------------------------------------------------------------------------
//
// File Name:	GraphicsSystem.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "GraphicsSystem.h"
#include "glfwInterface.h"
// Using glad to help with loading OpenGL
#include "glad/glad.h"
// Using glfw for window handling
#include <glfw/glfw3.h>
// Using glm for math
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Mesh.h"
#include <string>
#include "Camera.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------
GraphicsSystem* gGraphics = nullptr;
//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------




GraphicsSystem::GraphicsSystem(glfwInterface& glfw) :mglfw(glfw)
{
	gGraphics = this;
}
int GraphicsSystem::Init()
{
	if (!mglfw.Initalize("Tangerine"))
	{
		//error thing
		return -1;
	}
	
	Camera.Init(mglfw);
	glfwSetFramebufferSizeCallback(mglfw.GetWindowHandle(), ResizeViewport);
	ResizeViewport(mglfw.GetWindowHandle(), 1080, 720);
	glm::mat4 transform = glm::scale(glm::vec3(50.f, 50.f, 1.f));
	mTransformMatrix = transform;
	mMeshManager.Init();
	mTextureManager.Init();
	mShaderManager.Init();
	return 0;
}

void GraphicsSystem::Update()
{
	
}

int GraphicsSystem::Exit()
{
	mMeshManager.ReleaseAll();
	mTextureManager.ReleaseAll();
	mShaderManager.ReleaseAll();
	return 0;
}

void GraphicsSystem::SetBGColor(const glm::vec4& color)
{
	glClearColor(color.x, color.y, color.z, color.w);
}

void GraphicsSystem::SetTransformMatrix(const glm::mat4& transform)
{
	mTransformMatrix = transform;
}

void GraphicsSystem::SetTransformMatrix(const glm::vec2& pos, const glm::vec2& scale, float rotation)
{
	
	glm::mat4 scaleMatrix = glm::scale(glm::vec3(scale, 1.0));
	glm::mat4 rotationMatrix = glm::rotate(glm::radians(rotation), glm::vec3(0.0, 0.0, 1.0));
	glm::mat4 translationMatrix = glm::translate(glm::vec3(pos, 0.0));

	glm::mat4 transformationMatrix = translationMatrix * rotationMatrix * scaleMatrix;

	mTransformMatrix = transformationMatrix;
}

glm::vec2 GraphicsSystem::ScreentoWorld(const glm::vec2& pos)
{
	glm::vec2 worldpos = glm::vec2(pos.x - (Camera.GetWindowSize().x / 2), (Camera.GetWindowSize().y / 2) - pos.y);
	return worldpos;
}

void GraphicsSystem::InScreenSpace(bool inScreen)
{
	isInScreenSpace = inScreen;
}

void GraphicsSystem::SetTintColor(const glm::vec4& color)
{
	mTintColor = color;
}

void GraphicsSystem::SetTextureOffset(const glm::vec2& offset)
{
	mTextureOffset = offset;
}

void GraphicsSystem::SetWindowSize(int width, int height)
{
	mglfw.SetWindowSize(width, height);
	ResizeViewport(mglfw.GetWindowHandle(), width, height);
}

glm::vec2 GraphicsSystem::GetWindowSize() const
{
	return mglfw.GetWindowSize();
}

void GraphicsSystem::StartDraw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	isDrawingEnabled = true;
}

void GraphicsSystem::EndDraw()
{
	isDrawingEnabled = false;
}

void GraphicsSystem::Draw(const Mesh* mesh)
{
	if (!isDrawingEnabled) return;

	if (mcurrShader) 
	{
		mcurrShader->Use();
		glm::mat4 identity = glm::mat4(1.0f);
		glm::mat4 viewproj;
		if (isInScreenSpace) viewproj = Camera.GetScreenViewProjMatrix();
		else viewproj = Camera.GetWorldViewProjMatrix();
		mcurrShader->SetMat4("viewprojection", viewproj);
		mcurrShader->SetMat4("transform", mTransformMatrix);
		mcurrShader->SetVec4("tintColor", mTintColor); //@@TODO; move to the material class in future
		mcurrShader->SetVec2("textOffset", mTextureOffset); //@@TODO: move to the material class in future
	}
	else {}; //error stuff



	if (mcurrTexture)mcurrTexture->Use();
	mesh->Draw();
}

void GraphicsSystem::SetCurrShader(Shader* shader)
{
	mcurrShader = shader;
}

void GraphicsSystem::SetCurrTexture(Texture* texture)
{
	mcurrTexture = texture;
}

Shader* GraphicsSystem::GetCurrShader()
{
	return mcurrShader;
}

void GraphicsSystem::ResizeViewport(WindowHNDL window, int width, int height)
{
	UNREFERENCED_PARAMETER(window);

	glViewport(0, 0, width, height);
	gGraphics->Camera.SetWindowSize(width, height);
}


//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

