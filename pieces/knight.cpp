#include "knight.hpp"

Knight::Knight(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'N';
    }
    else
    {
        name = 'n';
    }
    get_textures();
}

Knight::~Knight()
{
}

bool Knight::move_math(int xpos, int ypos)
{
    // Knights move in an "L" shape: two squares in one direction and one square perpendicular
    return (abs(this->xpos - xpos) == 2 && abs(this->ypos - ypos) == 1) ||
           (abs(this->xpos - xpos) == 1 && abs(this->ypos - ypos) == 2);
}

bool Knight::piece_between(int xpos, int ypos)
{
    // Knights can jump over pieces, so this always returns false
    return false;
}