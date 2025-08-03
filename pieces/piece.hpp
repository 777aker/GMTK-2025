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
    void draw(double tile_pos_x, double tile_pos_y, double tile_size, int filter_shader, double deltaTime);
    void die();
    bool move(int xpos, int ypos);
    color my_color;
    char name;
    int xpos = 0;
    int ypos = 0;

protected:
    bool selected = false;
    color highlight_color;
    Board *board = nullptr;
    bool valid_space(int xpos, int ypos);
    bool same_team(int xpos, int ypos);
    virtual bool move_math(int xpos, int ypos) = 0;
    bool piece_between(int xpos, int ypos);
    unsigned int textures[3] = {};
    unsigned int current_tex;
    double tex_time;
    double accumulated_time = 0;
    void get_textures();
};

#endif