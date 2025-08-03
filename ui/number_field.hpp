#ifndef NUMBER_FIELD_HPP
#define NUMBER_FIELD_HPP

#include "../window/window.hpp"
#include <string>

class NumberField
{
public:
    NumberField(int *update_num, int min, int max, double xpos, double ypos, int def, std::string words);
    ~NumberField();
    bool clicked(double xpos, double ypos);
    void draw_field();
    void key_pressed(int key);

private:
    int *update_num;
    std::string field_str;
    int min;
    int max;
    double xpos;
    double ypos;
    double width;
    double height;
    int def;
    bool selected = false;
    std::string words;
};

#endif