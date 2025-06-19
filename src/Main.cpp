#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

//// Using glad to help with loading OpenGL
//#include "glad/glad.h" //remove after adding camera and stuff just here for testing rn


// Using glm for math
#include "glm/glm.hpp"
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//// Using glfw for window handling
//#include <glfw/glfw3.h>
// Using stb image for image file loading
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include "Tangerine.h"



int main(void)
{

	Tangerine::Engine_Init();
	Vertex vertices[3] = { Vertex(glm::vec2(0.0f,0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0,0.0,0.0,1.0f)),
		                   Vertex(glm::vec2(-0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0,0.0,0.0,1.0f)),
						   Vertex(glm::vec2(0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0,0.0,0.0,1.0f))};

	Vertex rectanglevertices[6] = { Vertex(glm::vec2(0.5f,0.5f), glm::vec2(0.0f,0.0f), glm::vec4(0.0f,1.0f,0.0f,1.0f)),
								   Vertex(glm::vec2(0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(0.0f,0.0f,1.0f,1.0f)),
									Vertex(glm::vec2(-0.5f,0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0f,0.0f,0.0f,1.0f)),

									Vertex(glm::vec2(0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(0.0f,0.0f,1.0f,1.0f)),
									Vertex(glm::vec2(-0.5f,-0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0f,0.0f,1.0f,1.0f)),
									 Vertex(glm::vec2(-0.5f,0.5f), glm::vec2(0.0f,0.0f), glm::vec4(1.0f,0.0f,0.0f,1.0f)) };

	Shader* testshader = Tangerine::Create_Shader("shaders/DefaultShader.vert", "shaders/DefaultShader.frag");
	Mesh* testmesh = Tangerine::Create_Mesh(vertices, sizeof(vertices));
	Mesh* testmesh2 = Tangerine::Create_Mesh(rectanglevertices, sizeof(rectanglevertices));
	Tangerine::Set_CurrShader(testshader);
	
	float pos = 0.f;
	float rotation = 0.f;
	while (!Tangerine::ShouldClose())
	{
		
		Tangerine::Engine_Update();
		Tangerine::Start_Draw();

		//Tangerine::Rotate_Camera(rotation);
		glm::mat4 testmatrix = glm::mat4(1.f);
		testmatrix = glm::scale(testmatrix,glm::vec3(100.f, 100.0f, 1.0f));
		testmatrix = glm::translate(testmatrix,glm::vec3(pos, 0.0f, 0.0f));
		Tangerine::Set_TransformMatrix(testmatrix);
		Tangerine::Draw(testmesh);
		pos += 0.02f;

		glm::mat4 testmatrix2 = glm::mat4(1.f);
		testmatrix2 = glm::scale(testmatrix2, glm::vec3(100.f, 100.0f, 1.0f));
		//testmatrix2 = glm::rotate(testmatrix2, glm::radians(rotation), glm::vec3(0.0, 0.0, 1.0f));
		testmatrix2 = glm::translate(testmatrix2, glm::vec3(0.f, 0.0f, 0.0f));
		Tangerine::Set_TransformMatrix(testmatrix2);
		Tangerine::Draw(testmesh2);
		++rotation;


		Tangerine::End_Draw();
	}
	
	Tangerine::Engine_Exit();


	return 0;
}