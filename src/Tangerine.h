//------------------------------------------------------------------------------
//
// File Name:	stub.h
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
//------------------------------------------------------------------------------
// Public Functions
//------------------------------------------------------------------------------



namespace Tangerine
{
	void Engine_Init();
	void Engine_Update();
	void Engine_Exit();
	void Start_Draw();

	void End_Draw();
	void Set_TransformMatrix(glm::mat4& transformMatrix);
	void Set_CameraPos(glm::vec2& pos);
	void Set_CameraZoom(float zoom);
	void Rotate_Camera(float angle);
	Shader* Create_Shader(const char* vertPath, const char* fragPath);
	void Release_Shader(Shader** shader);
	void Draw(const Mesh* mesh);
	Mesh* Create_Mesh(Vertex vertices[], size_t arraySize);
	void Release_Mesh(Mesh** mesh);
	void Set_CurrShader(Shader* shader);
	bool ShouldClose();
}




