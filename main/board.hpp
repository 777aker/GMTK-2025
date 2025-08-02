#ifndef BOARD_HPP
#define BOARD_HPP

#include "../window/window.hpp"
#include "../pieces/piece.hpp"

class Board
{
public:
    Board();
    ~Board();
    void draw();
    void mouse_clicked(double xpos, double ypos);
    Piece *get_piece(int xpos, int ypos);

private:
    void draw_checkerboard();
    void draw_pieces();
    float tile_size;                 // Width of each tile
    float top_left_x;                // Top left corner x-coordinate
    float top_left_y;                // Top left corner y-coordinate
    Piece *pieces[8][8] = {};        // 2D array of pointers to pieces
    Piece *selected_piece = nullptr; // Pointer to the currently selected piece
};

#endif