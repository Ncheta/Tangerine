//------------------------------------------------------------------------------
//
// File Name:	MeshManager.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include <iterator>
#include "MeshManager.h"
#include <iostream>

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
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

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

Mesh* MeshManager::CreateMesh(const std::string& MeshName, Vertex vertices[], size_t arraySize)
{
	auto iter = MeshList.find(MeshName);
	if ((iter == MeshList.end()) ||
		(iter != MeshList.end() && iter->second == nullptr))
	{
		Mesh* newMesh = new Mesh(vertices, arraySize);

		if (newMesh)
		{
			MeshList[MeshName] = newMesh;
			return newMesh;
		}

	}

	if (iter != MeshList.end() && iter->second)
	{
		std::cout << "MESH: " << MeshName << "already exists." << "\n"
			<< "PLEASE RELEASE IT FIRST" << std::endl;
	}
	return nullptr;
}

int MeshManager::Init()
{
	Vertex trianglevertices[3] = { Vertex(glm::vec2(0.0f,0.5f), glm::vec2(0.5f,1.0f), glm::vec4(1.0,0.0,0.0,1.0f)),
					   Vertex(glm::vec2(-0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0,0.0,0.0,1.0f)),
					   Vertex(glm::vec2(0.5f,-0.5f), glm::vec2(1.0f,0.0f), glm::vec4(1.0,0.0,0.0,1.0f)) };

	Vertex rectanglevertices[6] = { Vertex(glm::vec2(0.5f,0.5f), glm::vec2(1.0f,1.0f), glm::vec4(0.0f,1.0f,0.0f,1.0f)),
								   Vertex(glm::vec2(0.5f,-0.5f), glm::vec2(1.0f,0.0f), glm::vec4(0.0f,0.0f,1.0f,1.0f)),
									Vertex(glm::vec2(-0.5f,0.5f), glm::vec2(0.0f,1.0f), glm::vec4(1.0f,0.0f,0.0f,1.0f)),

									Vertex(glm::vec2(0.5f,-0.5f), glm::vec2(1.0f,0.0f), glm::vec4(0.0f,0.0f,1.0f,1.0f)),
									Vertex(glm::vec2(-0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0f,0.0f,1.0f,1.0f)),
									 Vertex(glm::vec2(-0.5f,0.5f), glm::vec2(0.0f,1.0f), glm::vec4(1.0f,0.0f,0.0f,1.0f)) };

	Mesh* triangleMesh = CreateMesh("TriangleMesh", trianglevertices, sizeof(trianglevertices));
	Mesh* rectangleMesh = CreateMesh("RectMesh", rectanglevertices, sizeof(rectanglevertices));

	return 0;
}

Mesh* MeshManager::GetMesh(const std::string& MeshName)
{
	auto iter = MeshList.find(MeshName);
	if (iter == MeshList.end())
	{
		//error handling
		std::cout << "Mesh: " << MeshName << " does not exist." << std::endl;
		return nullptr;
	}

	return iter->second;
}
void MeshManager::ReleaseMesh(const std::string& MeshName)
{
	auto iter = MeshList.find(MeshName);
	if (iter == MeshList.end())
	{
		//error handling
		std::cout << "Mesh: " << MeshName << " does not exist." << std::endl;
		return;
	}

	delete iter->second;
	iter->second = nullptr;
	MeshList.erase(MeshName);
}

void MeshManager::ReleaseAll()
{
	for (auto& Mesh : MeshList)
	{
		delete Mesh.second;
		Mesh.second = nullptr;
	}
	MeshList.clear();
}



