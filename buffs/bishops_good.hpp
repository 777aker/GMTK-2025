#ifndef BISHOPS_GOOD_HPP
#define BISHOPS_GOOD_HPP

#include "buff.hpp"

class BishopsGood : public Buff
{

public:
    BishopsGood()
    {
        this->buff_name = "bishops_good";
        this->modifier = 0;
        update_texture();
    };
    ~BishopsGood() = default;
    double loop()
    {
        int adding = std::rand() % 10;
        spawn_B += adding;
        modifier = -(adding) * 2;
        return modifier;
    }
};

#endif