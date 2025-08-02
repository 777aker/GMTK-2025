#ifndef PIECE_HPP
#define PIECE_HPP

class Piece
{
public:
    Piece() = default;
    virtual ~Piece() = default;
    virtual void select() = 0;
    virtual void deselect() = 0;
    virtual void draw() = 0;
    virtual void die() = 0;
    virtual void clicked() = 0;

private:
    bool selected = false;
};

#endif