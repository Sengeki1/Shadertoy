#version 400

uniform float deltaTime;

void main() {
	vec2 uv_ndc = (gl_FragCoord.xy / vec2(800.0, 600.0));

	// Use polar coordinates instead of cartesian
    vec2 toCenter = vec2(0.5)-uv_ndc;
    // angles
    float angle_x = atan(toCenter.x,toCenter.y); 
    float angle_y = atan(toCenter.x,-toCenter.y);
    float radius = length(toCenter)*2.0;

    // Map the angle (-PI to PI) to the Hue (from 0 to 1)
    // and the Saturation to the radius
    vec3 color = vec3(abs(sin((angle_y / radius) * deltaTime)), abs(sin((angle_y / radius) * deltaTime)), abs(cos(angle_x / radius * deltaTime)));

	gl_FragColor = vec4(color, 1.0);
}