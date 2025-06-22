#version 330 core

in vec2 TexCoord;
in vec4 Color;

out vec4 pixelColor;

//CUSTOM UNIFORMS

void main(void) 
{
    pixelColor = Color;
}
