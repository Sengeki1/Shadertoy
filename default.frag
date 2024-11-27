#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0)) * 2.0 - 1.0;
	gl_FragColor = vec4(abs(sin(deltaTime)), abs(cos(deltaTime)), 0.0, 1.0);
}