#ifndef STICKY_HAND_HPP
#define STICKY_HAND_HPP

#include "buff.hpp"

class StickyHand : public Buff
{

public:
    StickyHand()
    {
        this->buff_name = "sticky_hand";
        this->modifier = -5;
        update_texture();
    };
    ~StickyHand() = default;
    double loop()
    {
        stickies += 1;
        return modifier;
    }
};

#endif