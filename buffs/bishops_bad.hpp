#ifndef BISHOPS_BAD_HPP
#define BISHOPS_BAD_HPP

#include "buff.hpp"
#include <stdlib.h>

class BishopsBad : public Buff
{
public:
    BishopsBad()
    {
        this->buff_name = "bishops_bad";
        this->modifier = 0;
        update_texture();
    }
    ~BishopsBad() = default;
    double loop()
    {
        int adding = std::rand() % 10;
        spawn_b += adding;
        modifier = (adding) * 2;
        return modifier;
    }
};

#endif