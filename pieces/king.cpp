#include "king.hpp"

King::King(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'K';
    }
    else
    {
        name = 'k';
    }
    get_textures();
}

King::~King()
{
    if (board->run_game)
        board->game_over(my_color);
}

bool King::move_math(int xpos, int ypos)
{
    // Kings can move one square in any direction
    return (abs(this->xpos - xpos) <= 1 && abs(this->ypos - ypos) <= 1);
}