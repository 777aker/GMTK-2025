#include "knight.hpp"

Knight::Knight(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    name = 'N';
}

Knight::~Knight()
{
}

void Knight::draw(double tile_pos_x, double tile_pos_y, double tile_size)
{
    if (!selected)
    {
        glColor3ub(my_color.r, my_color.g, my_color.b);
    }
    else
    {
        glColor3ub(highlight_color.r, highlight_color.g, highlight_color.b);
    }

    glBegin(GL_QUADS);
    glVertex2f(tile_pos_x + tile_size * 0.25, tile_pos_y + tile_size * 0.25); // Top right corner
    glVertex2f(tile_pos_x + tile_size * 0.25, tile_pos_y + tile_size * 0.75); // Top left corner
    glVertex2f(tile_pos_x + tile_size * 0.75, tile_pos_y + tile_size * 0.75); // Bottom left corner
    glVertex2f(tile_pos_x + tile_size * 0.75, tile_pos_y + tile_size * 0.25); // Bottom right corner
    glEnd();
}

bool Knight::move_math(int xpos, int ypos)
{
    // Knights move in an "L" shape: two squares in one direction and one square perpendicular
    return (abs(this->xpos - xpos) == 2 && abs(this->ypos - ypos) == 1) ||
           (abs(this->xpos - xpos) == 1 && abs(this->ypos - ypos) == 2);
}