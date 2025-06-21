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
	return nullptr;
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



