#ifndef PIECE_HPP
#define PIECE_HPP

#include "../window/window.hpp"

class Board;

class Piece
{
public:
    Piece(int xpos, int ypos, color my_color, Board *board);
    virtual ~Piece() = 0;
    void select(color player_color);
    void deselect();
    virtual void draw(double tile_pos_x, double tile_pos_y, double tile_size) = 0;
    virtual void die() = 0;
    virtual void clicked(int xpos, int ypos) = 0;

protected:
    bool selected = false;
    int xpos = 0;
    int ypos = 0;
    color my_color;
    Board *board = nullptr;
};

#endif