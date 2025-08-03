#ifndef PAWNS_EXPLODE_BAD_HPP
#define PAWNS_EXPLODE_BAD_HPP

#include "buff.hpp"

class PawnsExplodeBad : public Buff
{

public:
    PawnsExplodeBad()
    {
        this->buff_name = "pawns_exp_bad";
        this->modifier = -200;
        update_texture();
    };
    ~PawnsExplodeBad() = default;
    double loop()
    {
        if (pexp)
            return 0;
        pexp = true;
        return modifier;
    }
};

#endif