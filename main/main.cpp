#include "../window/window.hpp"
#include "../main/board.hpp"
#include "../ui/button.hpp"
#include "../ui/number_field.hpp"

#include <iostream>
#include <fstream>

bool main_menu = true;
Board *gameboard = nullptr; // Global game board object
#define MAIN_BUTTONS 2
Button *main_menu_buttons[MAIN_BUTTONS];
#define BUFFS 0
Button *main_menu_buffs[BUFFS];
#define MAIN_FIELDS 2
NumberField *main_menu_fields[MAIN_FIELDS];

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
		if (main_menu)
		{
			glfwSetWindowShouldClose(windowobj, 1);
		}
		else
		{
			if (gameboard != nullptr && gameboard->run_game)
			{
				gameboard->game_over(green_sea);
			}
			main_menu = true;
		}
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

		if (gameboard != nullptr)
			gameboard->mouse_left_clicked(xpos, ypos);
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		if (gameboard != nullptr)
			gameboard->mouse_right_clicked();
	}
}

void draw_main_menu(double high_score)
{
}

/**
 * @brief main display loop
 *
 * @param windowobj
 */
void display_loop(Window *windowobj)
{
	// double last_time = glfwGetTime();

	std::ifstream scores("scores.txt");
	std::string line;
	double high_score = -100000000;
	while (std::getline(scores, line))
	{
		double rscore = std::stod(line);
		if (rscore > high_score)
			high_score = rscore;
	}
	scores.close();

	while (!glfwWindowShouldClose(windowobj->glwindow))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// double now = glfwGetTime();
		// double deltaTime = now - last_time;

		if (main_menu)
		{
			draw_main_menu(high_score);
		}

		if (!main_menu && gameboard != nullptr)
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