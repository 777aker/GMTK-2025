#include "bishop.hpp"

Bishop::Bishop(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'B';
    }
    else
    {
        name = 'b';
    }
    get_textures();
}

Bishop::~Bishop()
{
}

bool Bishop::move_math(int xpos, int ypos)
{
    // Bishops move diagonally any number of squares
    return abs(this->xpos - xpos) == abs(this->ypos - ypos);
}