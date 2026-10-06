#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


int main() {
	// Initialize GLFW
	if (!glfwInit()) return -1;

	// Create a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Project", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	// Initialize GLAD function pointers after making the context current
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}


	// Main loop
	while (!glfwWindowShouldClose(window)) {
		// Render step
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap front and back buffers & poll events
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// End application
	glfwTerminate();
	return 0;
}
