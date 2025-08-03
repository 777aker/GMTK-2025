#include "number_field.hpp"

#include <iostream>

NumberField::NumberField(int *update_num, int min, int max, double xpos, double ypos, int def, std::string words)
{
    this->update_num = update_num;
    this->min = min;
    this->max = max;
    this->xpos = xpos;
    this->ypos = ypos;
    this->def = def;
    this->words = words;
    this->width = dim * 0.8 * 2;
    this->height = dim * 0.04;
    this->field_str = std::to_string(*update_num);
}

NumberField::~NumberField()
{
}

bool NumberField::clicked(double xpos, double ypos)
{
    if (xpos > this->xpos - this->width && xpos < this->xpos + this->width && ypos > this->ypos - this->height && ypos < this->ypos + this->height)
    {
        selected = true;
        return true;
    }
    selected = false;
    return false;
}

void NumberField::draw_field()
{
    if (selected)
    {
        glColor3ub(nephritis.r, nephritis.g, nephritis.b);
    }
    else
    {
        glColor3ub(turquoise.r, turquoise.g, turquoise.b);
    }
    glBegin(GL_QUADS);
    glVertex2f(xpos + width, -(ypos + height));
    glVertex2f(xpos - width, -(ypos + height));
    glVertex2f(xpos - width, -(ypos - height));
    glVertex2f(xpos + width, -(ypos - height));
    glEnd();

    glColor3ub(black.r, black.g, black.b);
    glRasterPos2f(-(xpos + width - width * 0.1), -(ypos + height));
    Print("%s='%s' (default=%d, min=%d, max=%d)", words.c_str(), field_str.c_str(), def, min, max);
}

void NumberField::key_pressed(int key)
{
    printf("key=%d\n", key);
    if (key == GLFW_KEY_BACKSPACE || key == GLFW_KEY_DELETE)
    {
        if (field_str.length() > 0)
        {
            field_str = field_str.substr(0, field_str.length() - 1);
        }
    }
    else if (key >= GLFW_KEY_0 && key <= GLFW_KEY_9)
    {
        field_str += std::to_string(key - GLFW_KEY_0);
        printf("Added to field_str %d?\n", key - GLFW_KEY_0);
    }
    std::cout << "Field_str: " << field_str << std::endl;
    try
    {
        int f_num = std::stoi(field_str);
        if (f_num < min || f_num > max)
            return;
        *update_num = f_num;
    }
    catch (const std::invalid_argument &e)
    {
        return;
    }
}