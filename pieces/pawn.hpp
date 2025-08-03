#ifndef PAWN_HPP
#define PAWN_HPP

#include "../main/board.hpp"
#include "../window/window.hpp"
#include "piece.hpp"

class Pawn : public Piece
{
public:
    Pawn(int xpos, int ypos, color my_color, Board *board);
    ~Pawn();
    bool move(int xpos, int ypos);

protected:
    bool move_math(int xpos, int ypos);
};

#endif