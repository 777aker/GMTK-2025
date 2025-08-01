#ifndef BOARD_HPP
#define BOARD_HPP

#include "../window/window.hpp"

class Board
{
public:
    Board();
    ~Board();
    void draw(Window *windowobj);
    void draw_checkerboard(Window *windowobj);
};

#endif