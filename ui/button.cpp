#include "button.hpp"

Button::Button(void (*call)(), double xpos, double ypos, std::string words)
{
    this->call = call;
    this->xpos = xpos;
    this->ypos = ypos;
    this->words = words;
    this->width = dim * 0.8 * 2;
    this->height = dim * 0.04;
}

Button::~Button()
{
}

bool Button::clicked(double xpos, double ypos)
{
    if (xpos > this->xpos - this->width && xpos < this->xpos + this->width && ypos > this->ypos - this->height && ypos < this->ypos + this->height)
    {
        call();
        return true;
    }
    return false;
}

void Button::draw_button()
{
    glColor3ub(turquoise.r, turquoise.g, turquoise.b);
    glBegin(GL_QUADS);
    glVertex2f(xpos + width, -(ypos + height));
    glVertex2f(xpos - width, -(ypos + height));
    glVertex2f(xpos - width, -(ypos - height));
    glVertex2f(xpos + width, -(ypos - height));
    glEnd();

    glColor3ub(black.r, black.g, black.b);
    glRasterPos2f(-(xpos + width - width * 0.1), -(ypos + height));
    Print(words.c_str());
}