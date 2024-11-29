#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0));

    float left = smoothstep(0.1, 0.2, uv_ndc.x);
	float bottom = smoothstep(0.1, 0.2, uv_ndc.y);

	float right = smoothstep(0.1, 0.2, 1 - uv_ndc.x); // invert
	float top = smoothstep(0.1, 0.2, 1 - uv_ndc.y);

	vec3 color = vec3(cos(left * deltaTime) * sin(bottom * deltaTime) + cos(right * deltaTime) * sin(top * deltaTime));

	gl_FragColor = vec4(color, 1.0);
}