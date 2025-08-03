#include "pawn.hpp"
#include "queen.hpp"

Pawn::Pawn(int xpos, int ypos, color my_color, Board *board)
    : Piece(xpos, ypos, my_color, board)
{
    if (my_color == board->player_color)
    {
        name = 'P';
    }
    else
    {
        name = 'p';
    }
    get_textures();
}

Pawn::~Pawn()
{
}

bool Pawn::move_math(int xpos, int ypos)
{
    // Pawns move forward one square, or two squares from their starting position
    if (my_color == board->player_color)
    {
        if (xpos == this->xpos && ypos == this->ypos + 1)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward one square
        }
        if (abs(this->xpos - xpos) == 1 && ypos == this->ypos + 1)
        {
            if (board->get_piece(xpos, ypos) != nullptr && !same_team(xpos, ypos))
            {
                return true; // Capture diagonally
            }
        }
        if (this->ypos == 1 && xpos == this->xpos && ypos == this->ypos + 2)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward two squares from starting position
        }
    }
    else // Assuming white pawns move down
    {
        if (xpos == this->xpos && ypos == this->ypos - 1)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward one square
        }
        if (abs(this->xpos - xpos) == 1 && ypos == this->ypos - 1)
        {
            if (board->get_piece(xpos, ypos) != nullptr && !same_team(xpos, ypos))
            {
                return true; // Capture diagonally
            }
        }
        if (this->ypos == 6 && xpos == this->xpos && ypos == this->ypos - 2)
        {
            return board->get_piece(xpos, ypos) == nullptr; // Move forward two squares from starting position
        }
    }

    return false;
}

bool Pawn::move(int xpos, int ypos)
{
    if (valid_space(xpos, ypos))
    {
        printf("%c moved to: (%d, %d)\n", name, xpos, ypos);
        // Move the knight to the new position
        board->remove_piece(xpos, ypos);                 // Remove any piece at the target position
        board->pieces[xpos][ypos] = this;                // Place knight at new position on the board
        board->pieces[this->xpos][this->ypos] = nullptr; // Clear old position
        this->xpos = xpos;                               // Update knight's position
        this->ypos = ypos;
        deselect();

        if (my_color == board->player_color)
        {
            if (ypos == 7)
            {
                Queen *que = new Queen(xpos, ypos, my_color, board);
                board->pieces[xpos][ypos] = que;
                delete this;
            }
        }
        else
        {
            if (ypos == 0)
            {
                Queen *que = new Queen(xpos, ypos, my_color, board);
                board->pieces[xpos][ypos] = que;
                delete this;
            }
        }

        return true;
    }
    deselect();
    return false;
}