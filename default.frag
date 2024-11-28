#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0));

	vec3 color = vec3(1., 0.633, 0.024);

	float a = smoothstep(1.0, 0.0, uv_ndc.x);
	float b = smoothstep(0.0, 1.0, uv_ndc.y);
	vec3 colorA = color * a;
	vec3 colorB = color * b;

	gl_FragColor = vec4(mix(colorB, (colorB + color), abs(sin(deltaTime))), 1.0);
}