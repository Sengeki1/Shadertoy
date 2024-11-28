#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0));
	
	// Step will return 0.0 unless the value is over 0.5,
    // in that case it will return 1.0
	float x = step(0.1, uv_ndc.x);

	// Smooth interpolation between 0.1 and 0.9
	float y = smoothstep(0.1, 0.9, uv_ndc.y);
	float y_vertical = smoothstep(0.2,0.5,uv_ndc.x) - smoothstep(0.5,0.8, uv_ndc.x); // 50% each side when subtracting we get the inner vertical pixels at the center as the effect
	
	float y_vertical_ = smoothstep(0.2, 0.5, 0.5) - smoothstep(0.5, 0.8, 0.7);
	vec3 color = mix(vec3(y_vertical_), vec3(y_vertical), 
	abs(cos(deltaTime)) * 2.0);

	gl_FragColor = vec4((vec3(color) * abs(cos(deltaTime)) * vec3(uv_ndc, 1.0)), 1.0);

	//gl_FragColor = vec4(vec3(step(uv_ndc.x, 0.5), step(uv_ndc.y, 0.5), step(uv_ndc.x, 0.5)), 1.0); // banderia colorida
}