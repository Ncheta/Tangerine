//------------------------------------------------------------------------------
//
// File Name:	Tangerine.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include "Tangerine.h"
#include "GraphicsSystem.h"
#include "glfwInterface.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------
glfwInterface glfw;
GraphicsSystem Graphics(glfw);

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
namespace Tangerine
{
	void Engine_Init()
	{
		Graphics.Init();
		glm::vec3 startColor = glm::vec3(0.68f, 0.85f, 0.9f);
		Graphics.SetBGColor(startColor);
	}

	void Engine_Update()
	{
		glfw.Update();
		Graphics.Update();
	}

	void Engine_Exit()
	{
		Graphics.Exit();
		glfw.Exit();
	}

	void Start_Draw()
	{
		Graphics.StartDraw();
	}

	void End_Draw()
	{
		Graphics.EndDraw();
	}

	void Set_TransformMatrix(glm::mat4& transformMatrix)
	{
		Graphics.SetTransformMatrix(transformMatrix);
	}

	void Draw(const Mesh* mesh)
	{
		if (!mesh)
		{
			//@@TODO: error checking
			std::cout << "Attempted to draw NULL mesh" << std::endl;
			return;
		}

		Graphics.Draw(mesh);
	}

	void Rotate_Camera(float angle)
	{
		Graphics.Camera.Rotate(angle);
	}

	Shader Create_Shader(const char* vertPath, const char* fragPath)
	{
		return Shader(vertPath, fragPath);
	}

	Mesh* Create_Mesh(Vertex vertices[], size_t arraySize)
	{
		return Graphics.mMeshManager.CreateMesh(vertices, arraySize);
	}

	void Release_Mesh(Mesh** mesh)
	{
		Graphics.mMeshManager.ReleaseMesh(mesh);
	}

	void Set_CurrShader(Shader& shader)
	{
		Graphics.SetCurrShader(shader);
	}

	bool ShouldClose()
	{
		return Graphics.mglfw.ShouldClose();
	}
}
//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





