#ifndef ROOK_HPP
#define ROOK_HPP

#include "../main/board.hpp"
#include "../window/window.hpp"
#include "piece.hpp"

class Rook : public Piece
{
public:
    Rook(int xpos, int ypos, color my_color, Board *board);
    ~Rook();

protected:
    bool move_math(int xpos, int ypos);
};

#endif