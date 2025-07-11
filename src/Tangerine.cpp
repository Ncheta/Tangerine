//------------------------------------------------------------------------------
//
// File Name:	Tangerine.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include "Tangerine.h"
#include "GraphicsSystem.h"
#include "glfwInterface.h"
#include "FrameControl.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------
glfwInterface glfw;
GraphicsSystem Graphics(glfw);
FrameControl FrameController;

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
		Graphics.SetBGColor(glm::vec4(0.68f,0.85f,0.9f,1.0f));
		FrameController.Init();
	}

	void Engine_Update()
	{
		glfw.Update();
		Graphics.Update();
		FrameController.Update();
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

	void Set_BGColor(const glm::vec4& color)
	{
		Graphics.SetBGColor(color);
	}

	void Set_CurrMatTextureOffset(const glm::vec2& offset)
	{
		Graphics.SetCurrMatTextureOffset(offset);
	}

	void Set_MaterialTextureOffset(Material* material, const glm::vec2& offset)
	{
		material->SetMaterialTextureOffset(offset);
	}

	void Set_MaterialShader(Material* material, Shader* shader)
	{
		material->SetMaterialShader(shader);
	}

	void Set_CurrMatShader(Shader* shader)
	{
		Graphics.SetCurrMatShader(shader);
	}

	void Set_CurrMatTintColor(const glm::vec4& color)
	{
		Graphics.SetCurrMatTintColor(color);
	}

	void Set_CurrMatTransparency(float value)
	{
		Graphics.SetCurrMatTransparency(value);
	}

	void Set_MaterialTintColor(Material* material, const glm::vec4& color)
	{
		material->SetMaterialTint(color);
	}

	void Set_MaterialTransparency(Material* material, float value)
	{
		material->SetMaterialTransparency(value);
	}

	void Set_TransformMatrix(const glm::mat4& transformMatrix)
	{
		Graphics.SetTransformMatrix(transformMatrix);
	}

	void Set_MaterialTexture(Material* material, Texture* texture)
	{
		material->SetMaterialTexture(texture);
	}

	void Set_TransformData(const glm::vec2& pos, const glm::vec2& scale, float angle)
	{
		Graphics.SetTransformMatrix(pos, scale, angle);
	}

	void Set_CameraPos(const glm::vec2& pos)
	{
		Graphics.Camera.SetCameraPos(pos);
	}

	void Set_CameraZoom(float zoom)
	{
		Graphics.Camera.SetZoom(zoom);
	}

	void Set_WindowSize(const glm::vec2& windowSize)
	{
		Graphics.Camera.SetWindowSize(windowSize.x, windowSize.y);
	}

	void Set_WindowSize(int width, int height)
	{
		Graphics.Camera.SetWindowSize(width, height);
	}

	void Set_ScreenSpaceDraw(bool draw)
	{
		Graphics.InScreenSpace(draw);
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

	Shader* Create_Shader(const std::string& name,const char* vertPath, const char* fragPath)
	{
		return Graphics.mShaderManager.CreateCustomShader(name, vertPath, fragPath);
	}

	void Release_Shader(const std::string& name)
	{
		Graphics.mShaderManager.ReleaseShader(name);
	}

	Mesh* Get_Mesh(const std::string& name)
	{
		return Graphics.mMeshManager.GetMesh(name);
	}

	Mesh* Create_Mesh(const std::string& name, Vertex vertices[], size_t arraySize)
	{
		return Graphics.mMeshManager.CreateMesh(name, vertices, arraySize);
	}

	void Release_Mesh(const std::string& name)
	{
		Graphics.mMeshManager.ReleaseMesh(name);
	}

	Material* Get_Material(const std::string& name)
	{
		return Graphics.mMaterialManager.GetMaterial(name);
	}

	Material* Create_Material(const std::string& name,Texture* texture)
	{
		return Graphics.mMaterialManager.CreateMaterial(name, texture);
	}

	Material* Create_Material(const std::string& name, Texture* texture, Shader* shader = nullptr)
	{
		return Graphics.mMaterialManager.CreateMaterial(name, texture, shader);
	}

	void Release_Material(const std::string& name)
	{
		Graphics.mMaterialManager.ReleaseMaterial(name);
	}

	void Release_Texture(const std::string& name)
	{
		Graphics.mTextureManager.ReleaseTexture(name);
	}

	Texture* Get_Texture(const std::string& name)
	{
		return Graphics.mTextureManager.GetTexture(name);
	}

	Shader* Get_Shader(const std::string& name)
	{
		return Graphics.mShaderManager.GetShader(name);
	}

	glm::vec2 Get_WindowSize()
	{
		return Graphics.Camera.GetWindowSize();
	}

	glm::vec2 ScreenToWorld(const glm::vec2& pos)
	{
		return Graphics.ScreentoWorld(pos);
	}

	Texture* Create_Texture(const std::string& name, const char* filePath)
	{
		return Graphics.mTextureManager.CreateTexture(name, filePath);
	}

	void Set_CustomShader(Shader* shader)
	{
		Graphics.SetCustomShader(shader);
	}

	void Set_GlobalShaderMode(GlobalShaderMode mode)
	{
		Graphics.SetGlobalShaderMode(mode);
	}

	void Set_CurrMaterial(Material* material)
	{
		Graphics.SetCurrMaterial(material);
	}

	bool ShouldClose()
	{
		return Graphics.mglfw.ShouldClose();
	}

	float Get_Time()
	{
		return Graphics.mglfw.GetTime();
	}

	float Get_DeltaTime()
	{
		return FrameController.GetDeltaTime();
	}
}
//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





