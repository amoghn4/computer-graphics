#include <GLFW/glfw3.h>
#include "math.h"

static void drawCircle() {
	const float x = 0, y = 0;
	const float radius = 0.5f;
	const int nTriangles = 100;
	const float twoPi = 2 * 3.14159265f;

	/*First quadrant*/
	for (int i = 0; i < (nTriangles / 4); i++) {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(x + radius * sin(i * twoPi / nTriangles), y + radius * cos(i * twoPi / nTriangles));
		glVertex2f(x + radius * sin((i + 1) * twoPi / nTriangles), y + radius * cos((i + 1) * twoPi / nTriangles));
		glEnd();
	}

	/*Second quadrant*/
	for (int i = (nTriangles / 4 * 3); i < nTriangles; i++) {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(x + radius * sin(i * twoPi / nTriangles), y + radius * cos(i * twoPi / nTriangles));
		glVertex2f(x + radius * sin((i + 1) * twoPi / nTriangles), y + radius * cos((i + 1) * twoPi / nTriangles));
		glEnd();
	}

	/*Third quadrant*/
	for (int i = (nTriangles / 4 * 2); i < (nTriangles / 4 * 3); i++) {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(x + radius * sin(i * twoPi / nTriangles), y + radius * cos(i * twoPi / nTriangles));
		glVertex2f(x + radius * sin((i + 1) * twoPi / nTriangles), y + radius * cos((i + 1) * twoPi / nTriangles));
		glEnd();
	}

	/*Fourth quadrant*/
	for (int i = (nTriangles / 4); i < (nTriangles / 4 * 2); i++) {
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0, 0);
		glVertex2f(x + radius * sin(i * twoPi / nTriangles), y + radius * cos(i * twoPi / nTriangles));
		glVertex2f(x + radius * sin((i + 1) * twoPi / nTriangles), y + radius * cos((i + 1) * twoPi / nTriangles));
		glEnd();
	}
}


int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 640, "Lukas Gacek", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		drawCircle();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
