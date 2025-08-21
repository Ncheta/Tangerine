#version 330 core

in vec2 TexCoord;
in vec4 Color;

out vec4 pixelColor;

#define PI 3.14159265359

float plot(vec2 st, float pct)
{
    return smoothstep(pct - 0.02, pct, st.y) - smoothstep(pct, pct + 0.02, st.y);
}

float quadraticBezier (float x, float a, float b){
  // adapted from BEZMATH.PS (1993)
  // by Don Lancaster, SYNERGETICS Inc. 
  // http://www.tinaja.com/text/bezmath.html

  float epsilon = 0.00001;
  a = max(0, min(1, a)); 
  b = max(0, min(1, b)); 
  if (a == 0.5){
    a += epsilon;
  }
  
  // solve t from x (an inverse operation)
  float om2a = 1 - 2*a;
  float t = (sqrt(a*a + om2a*x) - a)/om2a;
  float y = (1-2*b)*(t*t) + (2*b)*t;
  return y;
}

//CUSTOM UNIFORMS
uniform float u_time;
void main(void) 
{
  
    vec2 st = TexCoord;
   // float y =  ceil(sin(st.x)) + floor(sin(st.x));//abs(sin(st.x + (u_time/2.f)));//smoothstep(0.2,0.5,st.x) - smoothstep(0.5,0.8,st.x);
   // float y = quadraticBezier(st.x, 0.940, 0.780);
   //float y = 1.0 - pow(abs(st.x), 1.0);
   float y = sin(st.x);
    vec3 color = vec3(y);

    float pct = plot(st, y);
    color = (1.0 - pct) * color + pct * vec3(0.0,1.0,0.0);
    //color = vec3(pct); //black and white curve
    pixelColor = vec4(color,1.0);
   // pixelColor = vec4(color, pct);
}
