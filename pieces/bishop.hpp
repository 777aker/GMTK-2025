#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "../main/board.hpp"
#include "../window/window.hpp"
#include "piece.hpp"

class Bishop : public Piece
{
public:
    Bishop(int xpos, int ypos, color my_color, Board *board);
    ~Bishop();

protected:
    bool move_math(int xpos, int ypos);
};

#endif