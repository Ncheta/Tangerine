//------------------------------------------------------------------------------
//
// File Name:	Texture.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include "Texture.h"
// Using stb image for image file loading
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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

Texture::Texture(const char* path)
{
	unsigned int TextureID = 0;
	glGenTextures(1, &TextureID); //generate the object
	glBindTexture(GL_TEXTURE_2D, TextureID); //bind it to be the active one
	// set the default texture wrapping/filtering options @@TODO: functions for changing current texture wrapping stuff
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrCHannels = 0;
	unsigned char* data = stbi_load(path, &width, &height, &nrCHannels, 0);

	if (data)
	{
		switch (nrCHannels)
		{
		case 3:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			break;
		case 4:
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
			break;
		default:
			break;
		}
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}

	stbi_image_free(data);
	mTextureID = TextureID;
	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture()
{
	glDeleteTextures(1, &mTextureID);
}

void Texture::Use() //@@TODO: this and probably all use functions should have some kind of error checking
{
	glBindTexture(GL_TEXTURE_2D, mTextureID);
}

void Texture::stbiInit()
{
	stbi_set_flip_vertically_on_load(true);
}






