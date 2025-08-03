#ifndef NOTHIN_HPP
#define NOTHIN_HPP

#include "buff.hpp"
#include "../main/board.hpp"

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
        stickies = 0;
        invisible = false;
        pexp = false;
        Pexp = false;
        spawn_b = 0;
        spawn_B = 0;
        hammer = 0;
        promoteq = 0;
        promoteQ = 0;
        stones = 0;
        return modifier;
    }
};

#endif