#include "../window/window.hpp"
#include "../main/board.hpp"
#include "../ui/button.hpp"
#include "../ui/number_field.hpp"

#include <iostream>
#include <fstream>

bool main_menu = true;
Board *gameboard = nullptr; // Global game board object
#define MAIN_BUTTONS 2
Button *main_menu_buttons[MAIN_BUTTONS] = {};
#define BUFFS 0
Button *main_menu_buffs[BUFFS] = {};
#define MAIN_FIELDS 3
NumberField *main_menu_fields[MAIN_FIELDS] = {};
NumberField *selected_field = nullptr;

int bot_elo = 1320;
int depth = 10;
int loop_amount = 1;
int filter_shader;

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
	default:
		if (selected_field != nullptr)
			selected_field->key_pressed(key);
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
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && action != GLFW_REPEAT)
	{
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		int xpix, ypix;
		glfwGetWindowSize(window, &xpix, &ypix);
		xpos = xpos / xpix * 2 * dim * asp - dim * asp; // Convert to world coordinates
		ypos = ypos / ypix * 2 * dim - dim;				// Convert to world coordinates

		if (main_menu)
		{
			for (int i = 0; i < MAIN_BUTTONS; i++)
			{
				main_menu_buttons[i]->clicked(xpos, ypos);
			}
			for (int i = 0; i < BUFFS; i++)
			{
				main_menu_buffs[i]->clicked(xpos, ypos);
			}
			bool was_selected = false;
			for (int i = 0; i < MAIN_FIELDS; i++)
			{
				if (main_menu_fields[i]->clicked(xpos, ypos))
				{
					selected_field = main_menu_fields[i];
					was_selected = true;
				}
			}
			if (!was_selected)
			{
				selected_field = nullptr;
			}
		}

		if (!main_menu && gameboard != nullptr)
			gameboard->mouse_left_clicked(xpos, ypos);
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		if (!main_menu && gameboard != nullptr)
			gameboard->mouse_right_clicked();
	}
}

void draw_main_menu(double high_score)
{
	for (int i = 0; i < MAIN_BUTTONS; i++)
	{
		main_menu_buttons[i]->draw_button();
	}
	for (int i = 0; i < BUFFS; i++)
	{
		main_menu_buffs[i]->draw_button();
	}
	for (int i = 0; i < MAIN_FIELDS; i++)
	{
		main_menu_fields[i]->draw_field();
	}
}

void start_game()
{
	printf("Starting game: elo %d, depth %d, loop %d\n", bot_elo, depth, loop_amount);
	gameboard = new Board(green_sea, bot_elo, depth, loop_amount, filter_shader);
	main_menu = false;
}

void remove_buffs()
{
	printf("Removing buffs\n");
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

	std::string start_str = "START GAME";
	Button *start = new Button(start_game, 0, -dim * 0.6, start_str);
	std::string rbuff_str = "Remove ALL Buffs";
	Button *rbuffs = new Button(remove_buffs, 0, dim * 0.6, rbuff_str);
	main_menu_buttons[0] = start;
	main_menu_buttons[1] = rbuffs;

	std::string elo_str = "Stockfish elo";
	NumberField *elo_f = new NumberField(&bot_elo, 1320, 3190, 0, -dim * 0.4, 1320, elo_str);
	main_menu_fields[0] = elo_f;
	std::string depth_str = "Stockfish depth";
	NumberField *depth_f = new NumberField(&depth, 5, 100, 0, -dim * 0.3, 10, depth_str);
	main_menu_fields[1] = depth_f;
	std::string loop_str = "Loop increment each turn";
	NumberField *loop_f = new NumberField(&loop_amount, 1, 50, 0, -dim * 0.2, 1, loop_str);
	main_menu_fields[2] = loop_f;

	while (!glfwWindowShouldClose(windowobj->glwindow))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// double now = glfwGetTime();
		// double deltaTime = now - last_time;
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBlendEquation(GL_FUNC_ADD);

		if (main_menu)
		{
			draw_main_menu(high_score);
		}

		if (!main_menu && gameboard != nullptr && !gameboard->ready_for_delete)
		{
			gameboard->draw();
			if (gameboard->score > high_score)
			{
				high_score = gameboard->score;
			}
		}

		if (gameboard != nullptr && gameboard->ready_for_delete)
		{
			if (gameboard->score > high_score)
			{
				high_score = gameboard->score;
			}
			delete gameboard;
			gameboard = nullptr;
		}

		// want to see fps
		glColor3ub(nephritis.r, nephritis.g, nephritis.b);
		glRasterPos2i(-dim * asp + 5, dim - 5);
		Print("FPS=%d, ELO=%d, DEPTH=%d, LOOP=%d", windowobj->FramesPerSecond(), bot_elo, depth, loop_amount);
		glRasterPos2i(-dim * asp + 5, dim - 10);
		Print("Your highest score = %lf", high_score);
		glRasterPos2i(-dim * asp + 5, dim - 15);
		Print("Press ESCAPE to quit or start a new game");

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
	Window mainwindow("CHOOP", 0, 800, 500, key, mouse);
	glDisable(GL_DEPTH_TEST);
	glClearColor((float)midnight_blue.r / 255.0, (float)midnight_blue.g / 255.0, (float)midnight_blue.b / 255.0, 1.0);

	filter_shader = CreateShaderProg("main/filter.vert", "main/filter.frag");

	display_loop(&mainwindow);
}