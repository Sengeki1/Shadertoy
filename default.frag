#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0));

	// some orange gradient
	vec3 color = vec3(1.0, 0.633, 0.024);

	// determine circumference
	vec2 center = vec2(0.5, 0.5);
	float radius = 0.2;
	float distance_ = length(uv_ndc - center);

	// smooth transitions
	float a = smoothstep(1.0, 0.0, uv_ndc.x);
	float b = smoothstep(0.0, 1.0, uv_ndc.y);
	vec3 colorA = color * a;
	vec3 colorB = color * b;

	// add the gradient with the transition
	vec3 gradient = mix(colorB, (colorB + color), abs(sin(0.5)));
	
	// check if pixel is in circumference
	if (distance_ < radius) gradient += vec3(1., 0.633, 0.024) * abs(sin(1.2));

	// some math to have a have a smoother sunset transition
	gradient *= (b * 15.) + vec3(.6, 0.0, 0.0);

	gl_FragColor = vec4(gradient, 1.0);
}