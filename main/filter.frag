#version 400 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vec4 texColor = texture(ourTexture, TexCoord);
    if(texColor.r > 0.9 && texColor.g > 0.9 && texColor.b > 0.9) {
        FragColor = vec4(0.0, 0.0, 0.0, 0.0);
    } else {
        FragColor = texture(ourTexture, TexCoord);
    }
}