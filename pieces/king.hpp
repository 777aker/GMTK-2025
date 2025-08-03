#ifndef KING_HPP
#define KING_HPP

#include "../main/board.hpp"
#include "../window/window.hpp"
#include "piece.hpp"

class King : public Piece
{
public:
    King(int xpos, int ypos, color my_color, Board *board);
    ~King();

protected:
    bool move_math(int xpos, int ypos);
};

#endif