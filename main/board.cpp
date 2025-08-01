#include "board.hpp"

Board::Board()
{
}

Board::~Board()
{
}

void Board::draw_checkerboard(Window *windowobj)
{
    float tile_width = windowobj->dim * windowobj->asp * 0.2;                                      // Width of each tile
    float tile_height = windowobj->dim * 0.2;                                                      // Height of each tile
    float top_left_x = -windowobj->dim * windowobj->asp + (windowobj->dim * windowobj->asp * 0.1); // Top left corner x-coordinate
    float top_left_y = -windowobj->dim + windowobj->dim * 0.1;                                     // Top left corner y-coordinate
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
            glVertex2f(top_left_x + (i + 1) * tile_width, top_left_y + (j + 1) * tile_height); // Top right corner
            glVertex2f(top_left_x + i * tile_width, top_left_y + (j + 1) * tile_height);       // Top left corner
            glVertex2f(top_left_x + i * tile_width, top_left_y + j * tile_height);             // Bottom left corner
            glVertex2f(top_left_x + (i + 1) * tile_width, top_left_y + j * tile_height);       // Bottom right corner
            glEnd();
        }
    }
}

void Board::draw(Window *windowobj)
{
    this->draw_checkerboard(windowobj);
}