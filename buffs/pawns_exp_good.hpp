#ifndef PAWNS_EXPLODE_GOOD_HPP
#define PAWNS_EXPLODE_GOOD_HPP

#include "buff.hpp"

class PawnsExplodeGood : public Buff
{

public:
    PawnsExplodeGood()
    {
        this->buff_name = "pawns_exp_good";
        this->modifier = 5;
        update_texture();
    };
    ~PawnsExplodeGood() = default;
    double loop()
    {
        if (Pexp)
            return 0;
        Pexp = true;
        return modifier;
    }
};

#endif