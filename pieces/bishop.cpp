#include "bishop.hpp"

Bishop::Bishop(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
}

Bishop::~Bishop()
{
}

void Bishop::draw(double tile_pos_x, double tile_pos_y, double tile_size)
{
}

void Bishop::die()
{
}

void Bishop::clicked(int xpos, int ypos)
{
}
