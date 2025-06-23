//------------------------------------------------------------------------------
//
// File Name:	Material.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------


#include "Material.h"
#include "Texture.h"
#include "shader.h"
#include <algorithm>

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

Material::Material()
{
}

Material::Material(Texture* texture,Shader* shader) :mShader(shader), mTexture(texture)
{

}

void Material::SetMaterialShader(Shader* shader)
{
	mShader = shader;
}

void Material::SetMaterialTexture(Texture* texture)
{
	mTexture = texture;
}

void Material::SetMaterialTint(const glm::vec4& tintColor)
{
	mTintColor = tintColor;
}

void Material::SetMaterialTextureOffset(const glm::vec2& textureOffset)
{
	mTextureOffset = textureOffset;
}

void Material::SetMaterialTransparency(float transparency)
{
	mTransparency = std::min(1.f,std::max(0.0f, transparency));
}

Shader* Material::GetShader() const 
{
	return mShader;
}

Texture* Material::GetTexture() const
{
	return mTexture;
}

const glm::vec4& Material::GetTintColor()
{
	return mTintColor;
}

const glm::vec2& Material::GetTextureOffset()
{
	return mTextureOffset;
}

float Material::GetTransparency()
{
	return mTransparency;
}
