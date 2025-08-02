#ifndef BOARD_HPP
#define BOARD_HPP

#include "../window/window.hpp"
class Piece;

class Board
{
public:
    Board(color player_color);
    ~Board();
    void draw();
    void mouse_left_clicked(double xpos, double ypos);
    void mouse_right_clicked();
    Piece *get_piece(int xpos, int ypos);
    void remove_piece(int xpos, int ypos);
    Piece *pieces[8][8] = {}; // 2D array of pointers to pieces
    color player_color;
    color ai_color;

private:
    void draw_checkerboard();
    void draw_pieces();
    float tile_size;                 // Width of each tile
    float top_left_x;                // Top left corner x-coordinate
    float top_left_y;                // Top left corner y-coordinate
    Piece *selected_piece = nullptr; // Pointer to the currently selected piece
};

#endif