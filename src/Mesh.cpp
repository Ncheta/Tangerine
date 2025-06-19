//------------------------------------------------------------------------------
//
// File Name:	Mesh.cpp
// Author(s):	Ncheta Mbaraonye 
//
//------------------------------------------------------------------------------

#include "Mesh.h"

#include "glad/glad.h"
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cstdlib>
#include "GraphicsSystem.h"

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
Mesh::Mesh(Vertex vertices[], size_t arraySize) //@@TODO: add indexed meshes
{
	unsigned int VAOID = 0;
	glGenVertexArrays(1, &VAOID);
	glBindVertexArray(VAOID);

	mVAOID = VAOID;

	unsigned int VBOID = 0;
	glGenBuffers(1, &VBOID);
	glBindBuffer(GL_ARRAY_BUFFER, VBOID);
	glBufferData(GL_ARRAY_BUFFER, arraySize, vertices, GL_STATIC_DRAW);

	mVBOID = VBOID;

	GLuint position = 0;
	GLuint texture = 1;
	GLuint color = 2;

	glVertexAttribPointer(position, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(position);

	glVertexAttribPointer(texture, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(glm::vec2));
	glEnableVertexAttribArray(texture);

	glVertexAttribPointer(color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec2) * 2));
	glEnableVertexAttribArray(color);

	glBindVertexArray(0);

	mVertexCount = (unsigned int)arraySize/sizeof(Vertex);
}

void Mesh::Draw() const
{				
	glBindVertexArray(mVAOID);
	glDrawArrays(GL_TRIANGLES,0, mVertexCount);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &mVBOID);
	glDeleteVertexArrays(1, &mVAOID);
}
//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------





