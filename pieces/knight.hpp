#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "../main/board.hpp"
#include "../window/window.hpp"
#include "piece.hpp"

class Knight : public Piece
{
public:
    Knight(int xpos, int ypos, color my_color, Board *board);
    ~Knight();
    void draw(double tile_pos_x, double tile_pos_y, double tile_size);

protected:
    bool move_math(int xpos, int ypos);
    bool piece_between(int xpos, int ypos);
};

#endif