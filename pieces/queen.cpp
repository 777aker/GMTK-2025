#include "queen.hpp"

Queen::Queen(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'Q';
    }
    else
    {
        name = 'q';
    }
    get_textures();
}

Queen::~Queen()
{
}

bool Queen::move_math(int xpos, int ypos)
{
    // Queens can move any number of squares along a row, column, or diagonal
    return (this->xpos == xpos || this->ypos == ypos ||
            abs(this->xpos - xpos) == abs(this->ypos - ypos));
}