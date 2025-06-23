//------------------------------------------------------------------------------
//
// File Name:	Material.h
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
//------------------------------------------------------------------------------




//------------------------------------------------------------------------------
// Forward References:
//------------------------------------------------------------------------------
class Texture;
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
// Class:
//------------------------------------------------------------------------------

class Material
{
public:
	//Public Functions:
	Material();
	Material(Texture* texture,Shader* shader = nullptr);
	void SetMaterialShader(Shader* shader);
	void SetMaterialTexture(Texture* texture);
	void SetMaterialTint(const glm::vec4& tintColor);
	void SetMaterialTextureOffset(const glm::vec2& textureOffset);
	void SetMaterialTransparency(float transparency);
	Shader* GetShader() const;
	Texture* GetTexture() const;
	const glm::vec4& GetTintColor();
	const glm::vec2& GetTextureOffset();
	float GetTransparency();
	//Public Variables:
private:
	//Private Functions:
	//Private Variables:
	Shader* mShader{ nullptr };
	Texture* mTexture{ nullptr };
	glm::vec4 mTintColor{ 0.0f };
	glm::vec2 mTextureOffset{ 0.0f };
	float mTransparency{ 1.f };
};




