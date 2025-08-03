#ifndef BUFF_HPP
#define BUFF_HPP

#include <string>
#include <stdlib.h>
#include "../window/window.hpp"

class Buff
{
public:
    Buff() = default;
    ~Buff() = default;
    void update_texture()
    {
        std::string assets = "assets/" + buff_name + ".bmp";
        texture = LoadTexBMP(assets.c_str());
    };
    void draw(double xpos, double ypos)
    {
        glEnable(GL_TEXTURE_2D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glBindTexture(GL_TEXTURE_2D, texture);

        glBegin(GL_QUADS);
        glTexCoord2f(1.0, 1.0);
        glVertex2f(xpos, -ypos); // Top right corner
        glTexCoord2f(1.0, 0.0);
        glVertex2f(xpos, -(ypos + dim * buf_size)); // Top left corner
        glTexCoord2f(0.0, 0.0);
        glVertex2f(xpos + dim * buf_size, -(ypos + dim * buf_size)); // Bottom left corner
        glTexCoord2f(0.0, 1.0);
        glVertex2f(xpos + dim * buf_size, -ypos); // Bottom right corner
        glEnd();
        glDisable(GL_TEXTURE_2D);
    };
    bool clicked(double xpos, double ypos, double mx, double my)
    {
        if (mx > xpos && mx < xpos + dim * buf_size && my > ypos && my < ypos + dim * buf_size)
        {
            printf("clicked buff %s\n", buff_name.c_str());
            return true;
        }
        return false;
    };
    virtual double loop() = 0;

protected:
    double buf_size = 0.2;
    std::string buff_name;
    unsigned int texture;
    double modifier;
    double xpos, ypos;
};

#endif