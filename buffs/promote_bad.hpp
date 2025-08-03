#ifndef PROMOTE_BAD_HPP
#define PROMOTE_BAD_HPP

#include "buff.hpp"

class PromoteBad : public Buff
{

public:
    PromoteBad()
    {
        this->buff_name = "promote_bad";
        this->modifier = 20;
        update_texture();
    };
    ~PromoteBad() = default;
    double loop()
    {
        promoteq += 1;
        return modifier;
    }
};

#endif