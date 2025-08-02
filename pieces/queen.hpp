#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../main/board.hpp"
#include "../window/window.hpp"
#include "piece.hpp"

class Queen : public Piece
{
public:
    Queen(int xpos, int ypos, color my_color, Board *board);
    ~Queen();
    void draw(double tile_pos_x, double tile_pos_y, double tile_size);

protected:
    bool move_math(int xpos, int ypos);
};

#endif