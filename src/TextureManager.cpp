//------------------------------------------------------------------------------
//
// File Name:	TextureManager.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include <iterator>
#include "TextureManager.h"
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

Texture* TextureManager::CreateTexture(const std::string& textureName,const char* path)
{
	auto iter = TextureList.find(textureName);
	if ( (iter == TextureList.end()) || 
		(iter != TextureList.end() && iter->second == nullptr))
	{
		Texture* newTexture = new Texture(path);

		if (newTexture)
		{
			TextureList[textureName] = newTexture;
			return newTexture;
		}
		
	}
	return nullptr;
}
Texture* TextureManager::GetTexture(const std::string& textureName)
{
	auto iter = TextureList.find(textureName);
	if (iter == TextureList.end()) 
	{
		//error handling
		std::cout << "TEXTURE: " << textureName << " does not exist." << std::endl;
		return nullptr;
	}

	return iter->second;	
}
void TextureManager::ReleaseTexture(const std::string& textureName)
{
	auto iter = TextureList.find(textureName);
	if (iter == TextureList.end())
	{
		//error handling
		std::cout << "TEXTURE: " << textureName << " does not exist." << std::endl;
		return;
	}

	delete iter->second;
	TextureList.erase(textureName);
}

void TextureManager::ReleaseAll()
{
	for (auto Texture : TextureList)
	{
		ReleaseTexture(Texture.first);
	}
}



