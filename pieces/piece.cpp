#include "piece.hpp"

#include "../main/board.hpp"

Piece::Piece(int xpos, int ypos, color my_color, Board *board)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->my_color = my_color;
    this->board = board;
    this->selected = false;
};

Piece::~Piece() = default; // Pure virtual destructor must be defined

void Piece::select(color player_color)
{
    if (this->my_color.r != player_color.r ||
        this->my_color.g != player_color.g ||
        this->my_color.b != player_color.b)
    {
        return;
    }
    this->selected = true;
}

void Piece::deselect()
{
    this->selected = false;
}