#include "bishop.hpp"

Bishop::Bishop(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    name = 'B';
}

Bishop::~Bishop()
{
}

void Bishop::draw(double tile_pos_x, double tile_pos_y, double tile_size)
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

bool Bishop::move_math(int xpos, int ypos)
{
    // Bishops move diagonally any number of squares
    return abs(this->xpos - xpos) == abs(this->ypos - ypos);
}