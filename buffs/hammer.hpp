#ifndef HAMMER_HPP
#define HAMMER_HPP

#include "buff.hpp"

class Hammer : public Buff
{

public:
    Hammer()
    {
        this->buff_name = "hammer";
        this->modifier = -10;
        update_texture();
    };
    ~Hammer() = default;
    double loop()
    {
        hammer += 1;
        return modifier;
    }
};

#endif