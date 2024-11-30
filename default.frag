#version 400

in vec2 texCoords;

uniform sampler2D tex0;

uniform float deltaTime;

void main() {
	vec2 uv = (gl_FragCoord.xy / vec2(800.0, 600.0)) * 5.;

    vec2 blackHolePosition = vec2(0.5, 0.5) * 5.;
	float blackHoleRadius = 0.3;
	float effectRadius = 2.9;
	float transitionIntensity;

	float distanceToBlackHole = length(abs(uv) - blackHolePosition); // distance of each pixel to the center

	if (distanceToBlackHole < blackHoleRadius) {
		discard;
	}

	vec4 t0, t1 = texture(tex0, texCoords);
	if (distanceToBlackHole < blackHoleRadius + 0.8) {
		transitionIntensity = 1.0 - smoothstep(blackHoleRadius, blackHoleRadius + 0.8, distanceToBlackHole);
		t1 = texture(tex0, sin(distanceToBlackHole * effectRadius) * texCoords);
	} else {
		t0 = texture(tex0, texCoords);
	}

	gl_FragColor = mix(texture(tex0, texCoords), t1, transitionIntensity);

}