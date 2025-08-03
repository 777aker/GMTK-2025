#ifndef PROMOTE_GOOD_HPP
#define PROMOTE_GOOD_HPP

#include "buff.hpp"

class PromoteGood : public Buff
{

public:
    PromoteGood()
    {
        this->buff_name = "promote_good";
        this->modifier = 20;
        update_texture();
    };
    ~PromoteGood() = default;
    double loop()
    {
        promoteQ += 1;
        return modifier;
    }
};

#endif