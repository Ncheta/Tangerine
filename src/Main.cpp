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
//// Using glfw for window handling
//#include <glfw/glfw3.h>



#include "Tangerine.h"
#include "CustomShaderTest.h"




int main(void)
{

	Tangerine::Engine_Init();
	Texture* testTexture = Tangerine::Create_Texture("ManTexture","assets/man.png");
	Shader* testShader = Tangerine::Create_Shader("test", "shaders/DefaultShader.vert", "shaders/DefaultShader.frag");
	Material* man = Tangerine::Create_Material("man", Tangerine::Get_Texture("ManTexture"));
	Shader* LineGradientBaseShader = Tangerine::Create_Shader("LineGrad", "shaders/DefaultShader.vert", "shaders/LinePractice.frag");
	Shader* ColorGradientBaseShader = Tangerine::Create_Shader("ColorGrad", "shaders/DefaultShader.vert", "shaders/ColorGradients.frag");
	CustomShaderTest LineGradient(LineGradientBaseShader);
	CustomShaderTest ColorGradient(ColorGradientBaseShader);
	Material* testingMat = Tangerine::Create_Material("TestingMat", nullptr, ColorGradientBaseShader);
	//Tangerine::Set_MaterialTextureOffset(man, glm::vec2(1.0, 0.5));
	
	float pos = 1.f;
	float zoom = 0.f;
	float rotation = 0.f;
	float tint = 0.3f;
	float offset = 0.0f;
	while (!Tangerine::ShouldClose())
	{
		//Tangerine::Set_BGColor(glm::vec4(1.0, 0.0, 0.0, 0.0));
		Tangerine::Engine_Update();
		Tangerine::Start_Draw();
		//Tangerine::Set_CurrMatTintColor(glm::vec4(0.0, 1.0, 0.0, 0.5));

		Tangerine::Set_TransformData(Tangerine::Get_WindowSize()/4.f, glm::vec2(100.f, 100.f), rotation);
		Tangerine::Set_CurrMaterial(Tangerine::Get_Material("SmoothPlastic"));
		//Tangerine::Set_MaterialTransparency(Tangerine::Get_Material("SmoothPlastic"), 0.1f);
		Tangerine::Set_MaterialTransparency(Tangerine::Get_Material("man"), fabs(sinf(Tangerine::Get_Time())));
		Tangerine::Set_CurrMatTextureOffset(glm::vec2(0.0f, 0.0f));
		Tangerine::Set_ScreenSpaceDraw(true);
		Tangerine::Draw(Tangerine::Get_Mesh("TriangleMesh"));
		Tangerine::Set_ScreenSpaceDraw(false);
		pos -= 100.f * Tangerine::Get_DeltaTime();

		Tangerine::Set_TransformData(glm::vec2(pos,0.0f), glm::vec2(200.f, 200.f), 0.f);
		Tangerine::Set_CurrMaterial(Tangerine::Get_Material("man"));
		Tangerine::Set_GlobalShaderMode(GlobalShaderMode::DEFAULT);
		Tangerine::Set_CustomShader(Tangerine::Get_Shader("test"));
		//Tangerine::Set_CurrMatTintColor(glm::vec4(0.0, 0.0, 0.0, 0.0));
		//Tangerine::Set_CurrMatTextureOffset(glm::vec2(offset, 0.0f));
		Tangerine::Draw(Tangerine::Get_Mesh("RectMesh"));

		//SHADER PRACTICE MESH
		Tangerine::Set_TransformData(glm::vec2(0.0f, 0.0f), glm::vec2(200.f, 200.f), 0.f);
		Tangerine::Set_CurrMaterial(Tangerine::Get_Material("TestingMat"));
		Tangerine::Draw(Tangerine::Get_Mesh("RectMesh"));
		ColorGradient.SetCustomUniforms();
		


		++rotation;
		offset += 0.01f;
		glm::vec2 vec = glm::vec2(pos, 0.f);
		//Tangerine::Set_CameraZoom(fabs(sinf(zoom)) + 0.1f);
		//zoom += 0.01f;
		//Tangerine::Set_CameraPos(vec);
		Tangerine::End_Draw();
	}
	
	Tangerine::Engine_Exit();


	return 0;
}