#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0)) * 2. - 1;

    float distance = length(abs(uv_ndc) - vec2(0.5));

	gl_FragColor = vec4(vec3(
	(tan(-distance * deltaTime)),
	(tan(-distance * deltaTime)),
	(tan(-distance * deltaTime))
	), 1.0);
}