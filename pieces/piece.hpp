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
    void die();
    void clicked(int xpos, int ypos);
    color my_color;

protected:
    char name;
    bool selected = false;
    int xpos = 0;
    int ypos = 0;
    color highlight_color;
    Board *board = nullptr;
    bool valid_space(int xpos, int ypos);
    bool same_team(int xpos, int ypos);
    virtual bool move_math(int xpos, int ypos) = 0;
    bool piece_between(int xpos, int ypos);
};

#endif