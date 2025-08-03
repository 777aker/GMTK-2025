#ifndef NOTHIN_HPP
#define NOTHIN_HPP

#include "buff.hpp"

class Nothin : public Buff
{

public:
    Nothin()
    {
        this->buff_name = "nothin";
        this->modifier = 0;
        update_texture();
    };
    ~Nothin() = default;
    double loop()
    {
        return modifier;
    }
};

#endif