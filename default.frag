#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0));

    float distance = length(uv_ndc - vec2(0.5));

	float angle = atan(uv_ndc.x - 0.5, uv_ndc.y - 0.5);

	vec3 color = vec3(distance);
	color *= vec3(abs(sin(angle * clamp(0.2, 10, deltaTime))), abs(sin(angle * clamp(0.2, 10, deltaTime))), 0.);

	gl_FragColor = vec4(color, 1.0);
}