#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "../window/window.hpp"
#include "string"

class Button
{
public:
    Button(void (*call)(), double xpos, double ypos, std::string words);
    ~Button();
    bool clicked(double xpos, double ypos);
    void draw_button();

private:
    void (*call)();
    double xpos;
    double ypos;
    double width;
    double height;
    std::string words;
};

#endif