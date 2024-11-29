#version 400 

layout (location = 0) in vec2 inPos;
layout (location = 1) in vec2 aTex;

out vec2 texCoords;

void main() {
	gl_Position = vec4(inPos.xy, 0.0, 1.0);
	texCoords = aTex;
}