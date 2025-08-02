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
    void draw(double tile_pos_x, double tile_pos_y, double tile_size);
    void die();
    void clicked(int xpos, int ypos);
};

#endif