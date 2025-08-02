#include "board.hpp"

Board::Board()
{
}

Board::~Board()
{
}

void Board::draw_checkerboard(Window *windowobj)
{
    tile_size = asp < 1 ? dim * asp * 0.2 : dim * 0.2;
    top_left_x = -dim * asp + (dim * asp * 0.1);
    top_left_y = -dim + dim * 0.1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Alternate colors for the checkerboard pattern
            if ((i + j) % 2 == 0)
            {
                glColor3ub(asbestos.r, asbestos.g, asbestos.b); // Dark color
            }
            else
            {
                glColor3ub(clouds.r, clouds.g, clouds.b); // Light color
            }

            glBegin(GL_QUADS);
            glVertex2f(top_left_x + (i + 1) * tile_size, top_left_y + (j + 1) * tile_size); // Top right corner
            glVertex2f(top_left_x + i * tile_size, top_left_y + (j + 1) * tile_size);       // Top left corner
            glVertex2f(top_left_x + i * tile_size, top_left_y + j * tile_size);             // Bottom left corner
            glVertex2f(top_left_x + (i + 1) * tile_size, top_left_y + j * tile_size);       // Bottom right corner
            glEnd();
        }
    }
}

void Board::draw(Window *windowobj)
{
    draw_checkerboard(windowobj);
}

void Board::mouse_clicked(double xpos, double ypos)
{
    printf("Mouse clicked at: (%f, %f)\n", xpos, ypos);
}

void Board::get_piece(double xpos, double ypos)
{
}