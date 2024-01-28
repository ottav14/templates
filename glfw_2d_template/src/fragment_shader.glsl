#version 330 core
out vec4 FragColor;

uniform vec2 resolution;

void main() {

	vec2 uv = vec2(gl_FragCoord.x / resolution.x, gl_FragCoord.y / resolution.y);
	vec3 col = vec3(uv, 0.0); 

	FragColor = vec4(col, 1.0);
}
