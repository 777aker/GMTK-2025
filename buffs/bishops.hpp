#ifndef BISHOPS_HPP
#define BISHOPS_HPP

#include "buff.hpp"

class Bishops : public Buff
{

public:
    Bishops()
    {
        this->buff_name = "bishops";
        this->modifier = 10;
        update_texture();
    };
    ~Bishops() = default;
    double loop()
    {
        int badding = std::rand() % 10;
        int Badding = std::rand() % 10;
        spawn_b += badding;
        spawn_B += Badding;
        return badding * 2 - Badding * 2;
    }
};

#endif