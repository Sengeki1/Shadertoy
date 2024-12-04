#version 400

in vec2 texCoords;
uniform sampler2D tex0;
uniform float deltaTime;

void main() {
	vec2 uv = (gl_FragCoord.xy / vec2(800.0, 600.0)) * 2. - 1;

	gl_FragColor = vec4(uv.xy, 0.0, 1.0);
}
