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



#include "Tangerine.h"



int main(void)
{

	Tangerine::Engine_Init();


	Shader* testshader = Tangerine::Create_Shader("DefaultShader","shaders/DefaultShader.vert", "shaders/DefaultShader.frag");
	Shader* testTexshader = Tangerine::Create_Shader("DefaultTexShader", "shaders/DefaultShader.vert", "shaders/DefaultShaderAltTex.frag");
	Texture* testTexture = Tangerine::Create_Texture("ManTexture","assets/man.png");



	Tangerine::Set_CurrShader(testshader);
	
	float pos = 1.f;
	float zoom = 0.f;
	float rotation = 0.f;
	while (!Tangerine::ShouldClose())
	{
		
		Tangerine::Engine_Update();
		Tangerine::Start_Draw();


		Tangerine::Set_TransformData(glm::vec2(-100.f, 0.f), glm::vec2(100.f, 100.f), rotation);
		Tangerine::Set_CurrShader(Tangerine::Get_Shader("DefaultShader"));
		Tangerine::Draw(Tangerine::Get_Mesh("TriangleMesh"));
		//pos += 0.02f;

		Tangerine::Set_TransformData(glm::vec2(100.0f,0.0f), glm::vec2(200.f,200.f), rotation);
		Tangerine::Set_CurrShader(Tangerine::Get_Shader("DefaultTexShader"));
		Tangerine::Set_CurrTexture(Tangerine::Get_Texture("ManTexture"));
		Tangerine::Draw(Tangerine::Get_Mesh("RectMesh"));
		++rotation;

		glm::vec2 vec = glm::vec2(pos, 0.f);
		//Tangerine::Set_CameraZoom(fabs(sinf(zoom)) + 0.1f);
		zoom += 0.01f;
		//Tangerine::Set_CameraPos(vec);

		Tangerine::End_Draw();
	}
	
	Tangerine::Engine_Exit();


	return 0;
}