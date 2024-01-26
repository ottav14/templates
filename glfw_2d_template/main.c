#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

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
