#ifndef STONE_HPP
#define STONE_HPP

#include "buff.hpp"

class Stone : public Buff
{

public:
    Stone()
    {
        this->buff_name = "stone";
        this->modifier = -5;
        update_texture();
    };
    ~Stone() = default;
    double loop()
    {
        stones += 1;
        return modifier;
    }
};

#endif