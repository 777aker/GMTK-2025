#include "../window/window.hpp"
#include "../main/board.hpp"

Board *gameboard; // Global game board object

/**
 * @brief respond to key pressed
 *
 * @param windowobj
 * @param key
 * @param scancode
 * @param action
 * @param mods
 */
void key(GLFWwindow *windowobj, int key, int scancode, int action, int mods)
{
	if (action == GLFW_RELEASE)
		return;

	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		glfwSetWindowShouldClose(windowobj, 1);
		break;
	}
}

/**
 * @brief respond to mouse button pressed
 *
 * @param windowobj
 * @param button
 * @param action
 * @param mods
 */
void mouse(GLFWwindow *window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		int xpix, ypix;
		glfwGetWindowSize(window, &xpix, &ypix);
		xpos = xpos / xpix * 2 * dim * asp - dim * asp; // Convert to world coordinates
		ypos = ypos / ypix * 2 * dim - dim;				// Convert to world coordinates
		gameboard->mouse_left_clicked(xpos, ypos);
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		gameboard->mouse_right_clicked();
	}
}

/**
 * @brief main display loop
 *
 * @param windowobj
 */
void display_loop(Window *windowobj)
{
	// double last_time = glfwGetTime();
	gameboard = new Board(green_sea);

	while (!glfwWindowShouldClose(windowobj->glwindow))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// double now = glfwGetTime();
		// double deltaTime = now - last_time;

		gameboard->draw();

		// want to see fps
		glColor3ub(nephritis.r, nephritis.g, nephritis.b);
		glRasterPos2i(-dim * asp + 5, dim - 5);
		Print("FPS=%d", windowobj->FramesPerSecond());

		// check for display errors
		int err = glGetError();
		if (err)
		{
			fprintf(stderr, "ERROR: %s [%s]\n", gluErrorString(err), "display");
		}
		// swap buffers
		glFlush();
		glfwSwapBuffers(windowobj->glwindow);
		// get key board events
		glfwPollEvents();
	}
}

/**
 * @brief program entry point
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char *argv[])
{
	Window mainwindow("Collisions", 0, 800, 800, key, mouse);
	glDisable(GL_DEPTH_TEST);
	glClearColor((float)midnight_blue.r / 255.0, (float)midnight_blue.g / 255.0, (float)midnight_blue.b / 255.0, 1.0);

	display_loop(&mainwindow);
}