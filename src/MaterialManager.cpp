//------------------------------------------------------------------------------
//
// File Name:	MaterialManager.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include <iterator>
#include "MaterialManager.h"
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


Material* MaterialManager::CreateMaterial(const std::string& MaterialName, Texture* texture, Shader* shader)
{
	auto iter = MaterialList.find(MaterialName);
	if ( (iter == MaterialList.end()) || 
		(iter != MaterialList.end() && iter->second == nullptr))
	{
		Material* newMaterial = new Material(texture, shader);

		if (newMaterial)
		{
			MaterialList[MaterialName] = newMaterial;
			return newMaterial;
		}
		
	}

	if (iter != MaterialList.end() && iter->second)
	{
		std::cout << "MATERIAL: " << MaterialName << "already exists." << "\n"
			<< "PLEASE RELEASE IT FIRST" << std::endl;
	}
	return nullptr;
}

Material* MaterialManager::CreateMaterial(const std::string& MaterialName)
{
	return CreateMaterial(MaterialName, nullptr, nullptr);
}
Material* MaterialManager::GetMaterial(const std::string& MaterialName)
{
	auto iter = MaterialList.find(MaterialName);
	if (iter == MaterialList.end()) 
	{
		//error handling
		std::cout << "Material: " << MaterialName << " does not exist." << std::endl;
		return nullptr;
	}

	return iter->second;	
}
void MaterialManager::ReleaseMaterial(const std::string& MaterialName)
{
	auto iter = MaterialList.find(MaterialName);
	if (iter == MaterialList.end())
	{
		//error handling
		std::cout << "Material: " << MaterialName << " does not exist." << std::endl;
		return;
	}

	delete iter->second;
	iter->second = nullptr;
	MaterialList.erase(MaterialName);
}

int MaterialManager::Init()
{
	Material* DefaultMat = CreateMaterial("SmoothPlastic");
	DefaultMat->SetMaterialTint(glm::vec4(1.f, 0.7f, 0.7f, 1.f));
	return 0;
}

void MaterialManager::ReleaseAll()
{
	for (auto& Material : MaterialList)
	{
		delete Material.second;
		Material.second = nullptr;
	}
	MaterialList.clear();
}



