#version 400 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;

uniform double dim;
uniform double asp;

void main()
{
    gl_Position = vec4(aPos.x / (dim * asp), aPos.y / dim, aPos.z, 1.0);
    TexCoord = aTexCoord;
}