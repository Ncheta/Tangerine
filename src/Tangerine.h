//------------------------------------------------------------------------------
//
// File Name:	Tangerine.h
// Author(s):	Ncheta Mbaraonye 
// 
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------
// Using glm for math
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------
class Mesh;
class Shader;
class Texture;
class CustomShader;
class Material;
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
// Public Structures:
//------------------------------------------------------------------------------

typedef struct Vertex
{
	glm::vec2 pos{ 0 };
	glm::vec2 textureCoord{ 0 };
	glm::vec4 color{ 0 };

	Vertex(glm::vec2 _pos, glm::vec2 _textCoord, glm::vec4 _color) :
		pos(_pos)
		, textureCoord(_textCoord)
		, color(_color)
	{
	}


}Vertex;

enum class GlobalShaderMode
{
	DEFAULT,
	CUSTOM
};
//------------------------------------------------------------------------------
// Public Functions
//------------------------------------------------------------------------------



namespace Tangerine //@@TODO: add some kind of pixel to position thing for all position setters.
{
	void Engine_Init();
	void Engine_Update();
	void Engine_Exit();
	void Start_Draw();
	void End_Draw();
	void Set_BGColor(const glm::vec4& color);
	void Set_CurrMatTextureOffset(const glm::vec2& offset);
	
	void Set_CurrMatShader(Shader* shader);

	void Set_CurrMatTintColor(const glm::vec4& color);

	void Set_CurrMatTransparency(float value);
	
	void Set_MaterialTransparency(Material* material, float value);

	void Set_TransformMatrix(const glm::mat4& transformMatrix);

	void Set_MaterialTextureOffset(Material* material, const glm::vec2& offset);
	void Set_MaterialTintColor(Material& material, const glm::vec4& color);
	void Set_MaterialTexture(Material& material, Texture* texture);
	void Set_TransformData(const glm::vec2& pos, const glm::vec2& scale, float angle);
	void Set_CameraPos(const glm::vec2& pos);
	void Set_CameraZoom(float zoom);
	void Set_WindowSize(const glm::vec2& windowSize);
	void Set_WindowSize(int width, int height);
	void Set_ScreenSpaceDraw(bool draw);
	void Set_GlobalShaderMode(GlobalShaderMode mode);
	void Rotate_Camera(float angle);
	Mesh* Create_Mesh(const std::string& name, Vertex vertices[], size_t arraySize);
	Texture* Create_Texture(const std::string& name,const char* filePath);
	Shader* Create_Shader(const std::string& name,const char* vertPath, const char* fragPath);
	Material* Create_Material(const std::string& name, Texture* texture);
	Material* Create_Material(const std::string& name, Texture* texture, Shader* shader);
	void Draw(const Mesh* mesh);
	void Release_Mesh(const std::string& name);


	void Release_Material(const std::string& name);
	void Release_Texture(const std::string& name);
	void Release_Shader(const std::string& name);

	Mesh* Get_Mesh(const std::string& name);
	Texture* Get_Texture(const std::string& name);
	Shader* Get_Shader(const std::string& name);
	Material* Get_Material(const std::string& name);

	glm::vec2 Get_WindowSize();
	glm::vec2 ScreenToWorld(const glm::vec2& pos);

	void Set_CustomShader(Shader* shader);
	void Set_CurrMaterial(Material* material);
	bool ShouldClose();
	float GetTime();
}




