#version 330 core
layout (location = 0) in vec2 inPos;
layout (location = 1) in vec2 inTexCoord;
layout (location = 2) in vec4 inColor;

out vec4 Color;
out vec2 TexCoord; 


uniform mat4 viewprojection;
uniform mat4 transform;
uniform mat4 projection;
uniform mat4 view;
uniform vec4 tintColor;
uniform vec2 textOffset;
uniform float alpha;

//CUSTOM UNIFORMS

void main()
{
     gl_Position =  viewprojection * transform * vec4(inPos,0.0, 1.0);
     Color.rgb = inColor.rgb + (tintColor.rgb * tintColor.w);
     Color.a = alpha;
     TexCoord = inTexCoord + textOffset;
}