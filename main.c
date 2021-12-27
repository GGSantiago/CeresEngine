#define GLFW_INCLUDE_NONE
#include <stdio.h>
#include <unistd.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ceresMath.h"

int main () {
	GLenum err = glewInit();
	if (!glfwInit()) {
		printf("Little things are not comming :(");
		return -1;
	}
	GLFWwindow* m_window = glfwCreateWindow(640, 480, "Little things", NULL, NULL);
	GLFWwindow* s_window = glfwCreateWindow(200, 200, "Little things", NULL, NULL);
	sleep(20000);
	glfwTerminate();
	return 0;
}
