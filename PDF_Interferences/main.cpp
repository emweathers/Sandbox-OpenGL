#define GLFW_STATIC
#define GLAD_STATIC
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>


#define WIDTH 800
#define HEIGHT 600


float P(float Pmax, float X, float Y, float X_0, float Y_0, float s_x, float s_y);



void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
}


void drawPixelLegacy(int x, int y, float r, float g, float b) {
	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2f(x + 0.5f, y + 0.5f);
	glEnd();
}


int main() {
	// Initialize GLFW
	glfwInit();
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	// Initialize Window
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Project", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
		glfwTerminate();
		return -1;
	}

	glViewport(0,0,WIDTH,HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);


	int M = 1;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	float l1 = 1;
	float l2 = 1;
	float l3 = 1;
	// Main Loop
	while (!glfwWindowShouldClose(window)) {
		processInput(window);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) a += 10;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) a -= 10;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) b += 10;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) b -= 10;
		if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) c += 10;
		if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) c -= 10;
		if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) d += 10;
		if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) d -= 10;
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) e += 10;
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) e -= 10;
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) f += 10;
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) f -= 10;
		if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) != GLFW_PRESS) l1 += 0.05;
		if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) != GLFW_PRESS) l1 -= 0.05;
		if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) != GLFW_PRESS) l2 += 0.05;
		if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) != GLFW_PRESS) l2 -= 0.05;
		if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) l3 += 0.05;
		if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) != GLFW_PRESS
			&& glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) l3 -= 0.05;

		for (int i = -1*WIDTH/2; i < WIDTH/2; i++) for (int j = -1*HEIGHT/2; j < HEIGHT/2; j++) {
			float x = i/M;
			float y = j/M;
			int random = std::rand();
			float p1 = P(1, x+50, y-50, a, b, 10000, 10000);
			float p2 = P(1, x, y+50, c, d, 10000, 10000);
			float p3 = P(1, x-50, y-50, e, f, 10000, 10000);
			if (random < (pow((l1 * p1 - l2 * p2 - l3 * p3), 2) * pow((l2 * p2 - l1 * p1 - l3 * p3), 2) * pow((l3 * p3 - l1 * p1 - l2 * p2), 2)) * (RAND_MAX + 1.0)) {
				drawPixelLegacy(x + WIDTH / 2, y + HEIGHT / 2, pow((p3 - p1 - p2), 2), pow((p2 - p1 - p3), 2), pow((p1 - p2 - p3), 2));
			}
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}

float P(float Pmax, float X, float Y, float X_0, float Y_0, float s_X, float s_Y) {
	float e = 2.718281828;
	float temp = -1 * (((X - X_0) * (X - X_0) / (2 * s_X)) + ((Y - Y_0) * (Y - Y_0) / (2 * s_Y)));
	return Pmax*pow(e,temp);
}