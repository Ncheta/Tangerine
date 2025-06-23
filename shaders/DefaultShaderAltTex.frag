#version 330 core

in vec2 TexCoord;
in vec4 Color;

out vec4 pixelColor;

uniform sampler2D inTexture;
uniform float alpha;

//CUSTOM UNIFORMS

void main(void) 
{
    vec4 texColor = texture(inTexture, TexCoord);
    if (texColor.a < 0.1)
        discard;
    pixelColor.rgb = texColor.rgb + Color.rgb;
    pixelColor.a = alpha;

}
