//------------------------------------------------------------------------------
//
// File Name:	ShaderManager.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include <iterator>
#include "ShaderManager.h"
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

Shader* ShaderManager::CreateShader(const std::string& ShaderName, const char* vertPath, const char* fragPath)
{
	auto iter = ShaderList.find(ShaderName);
	if ((iter == ShaderList.end()) ||
		(iter != ShaderList.end() && iter->second == nullptr))
	{
		Shader* newShader = new Shader(vertPath, fragPath);

		if (newShader)
		{
			ShaderList[ShaderName] = newShader;
			return newShader;
		}

	}
	return nullptr;
}
Shader* ShaderManager::GetShader(const std::string& ShaderName)
{
	auto iter = ShaderList.find(ShaderName);
	if (iter == ShaderList.end())
	{
		//error handling
		std::cout << "Shader: " << ShaderName << " does not exist." << std::endl;
		return nullptr;
	}

	return iter->second;
}
void ShaderManager::ReleaseShader(const std::string& ShaderName)
{
	auto iter = ShaderList.find(ShaderName);
	if (iter == ShaderList.end())
	{
		//error handling
		std::cout << "Shader: " << ShaderName << " does not exist." << std::endl;
		return;
	}

	delete iter->second;
	iter->second = nullptr;
	ShaderList.erase(ShaderName);
}

void ShaderManager::ReleaseAll()
{
	for (auto& Shader : ShaderList)
	{
		delete Shader.second;
		Shader.second = nullptr;
	}
	ShaderList.clear();
}



