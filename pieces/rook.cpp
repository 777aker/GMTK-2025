#include "rook.hpp"

Rook::Rook(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'R';
    }
    else
    {
        name = 'r';
    }
    get_textures();
}

Rook::~Rook()
{
}

bool Rook::move_math(int xpos, int ypos)
{
    // Rooks move in straight lines: horizontally or vertically
    return (this->xpos == xpos || this->ypos == ypos);
}