#ifndef INVISIBLE_ENEMIES_HPP
#define INVISIBLE_ENEMIES_HPP

#include "buff.hpp"

class InvisibleEnemies : public Buff
{

public:
    InvisibleEnemies()
    {
        this->buff_name = "invisible_enemies";
        this->modifier = 50;
        update_texture();
    };
    ~InvisibleEnemies() = default;
    double loop()
    {
        if (invisible)
            return 0;
        invisible = true;
        return modifier;
    }
};

#endif