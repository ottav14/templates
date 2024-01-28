#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

char* read_shader(FILE *shader) {

	fseek(shader, 0, SEEK_END);
	long file_size = ftell(shader);
	fseek(shader, 0, SEEK_SET);

	char *buffer = (char*)malloc(file_size);

	fread(buffer, file_size, 1, shader);

	return buffer;
}

void draw_quad(GLFWwindow *window) {

	const float size = 0.5f;

	glBegin(GL_QUADS);

	glColor3f(1.0, 0.0, 1.0);
	glVertex2f(-1.0, -1.0);

	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-1.0,  1.0);
	
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f( 1.0,  1.0);
	
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f( 1.0, -1.0);
	
	glEnd();

}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods) {

	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

}

void init(GLFWwindow *window) {

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	glfwSwapInterval(1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	FILE *fragment_shader = fopen("../shaders/fragment_shader.glsl", "r");
	FILE *vertex_shader = fopen("../shaders/vertex_shader.glsl", "r");


	char *vertex_shader_content = read_shader(vertex_shader);
	char *fragment_shader_content = read_shader(fragment_shader);

	fclose(fragment_shader);
	fclose(vertex_shader);
}

int main(int argc, char **argv) {

	if(!glfwInit()) {
		return -1;
	}

	GLFWmonitor *monitor = glfwGetPrimaryMonitor();
	GLFWwindow *window = glfwCreateWindow(1920, 1080, "OpenGL Window", monitor, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}


	init(window);
	int width, height;
	glfwGetWindowSize(window, &width, &height);

		while (!glfwWindowShouldClose(window)) {
		
		glClear(GL_COLOR_BUFFER_BIT);

		draw_quad(window);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}
