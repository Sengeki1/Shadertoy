#version 400

uniform float deltaTime;

void main() {
	vec2 uv = (gl_FragCoord.xy / vec2(800.0, 600.0));

    vec2 blackHolePosition = vec2(0.5, 0.5);
	float blackHoleRadius = 0.1;              // Event horizon radius
    float gravitationalStrength = 2.0;        // Controls bending

	vec3 direction = vec3(normalize(uv - blackHolePosition).xy, 0.0);
	float distanceToBlackHole = length(uv - blackHolePosition);

	 vec2 backgroundTextureCoordinates;
	if (distanceToBlackHole < blackHoleRadius) {
		discard;
	} else {
		// Bend the ray based on gravity
        float bendingFactor = gravitationalStrength / distanceToBlackHole;
        vec2 bentRay = vec2(direction.yx + (bendingFactor * normalize(uv - blackHolePosition)));
        
        // Map bent ray to background
        backgroundTextureCoordinates = bentRay;
	}

	gl_FragColor = vec4(vec2(cos(backgroundTextureCoordinates.x * deltaTime)), sin(backgroundTextureCoordinates.y * deltaTime), 1.);
}