#include "pawn.hpp"

Pawn::Pawn(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'P';
    }
    else
    {
        name = 'p';
    }
}

Pawn::~Pawn()
{
}

void Pawn::draw(double tile_pos_x, double tile_pos_y, double tile_size)
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

bool Pawn::move_math(int xpos, int ypos)
{
    // Pawns move forward one square, or two squares from their starting position
    if (my_color == board->player_color)
    {
        if (xpos == this->xpos && ypos == this->ypos + 1)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward one square
        }
        if (abs(this->xpos - xpos) == 1 && ypos == this->ypos + 1)
        {
            if (board->get_piece(xpos, ypos) != nullptr && !same_team(xpos, ypos))
            {
                return true; // Capture diagonally
            }
        }
        if (this->ypos == 1 && xpos == this->xpos && ypos == this->ypos + 2)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward two squares from starting position
        }
    }
    else // Assuming white pawns move down
    {
        if (xpos == this->xpos && ypos == this->ypos - 1)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward one square
        }
        if (abs(this->xpos - xpos) == 1 && ypos == this->ypos - 1)
        {
            if (board->get_piece(xpos, ypos) != nullptr && !same_team(xpos, ypos))
            {
                return true; // Capture diagonally
            }
        }
        if (this->ypos == 6 && xpos == this->xpos && ypos == this->ypos - 2)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward two squares from starting position
        }
    }

    return false;
}