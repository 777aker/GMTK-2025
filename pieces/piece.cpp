#include "piece.hpp"

#include "../main/board.hpp"

Piece::Piece(int xpos, int ypos, color my_color, Board *board)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->my_color = my_color;
    this->board = board;
    this->selected = false;

    if (my_color.r == green_sea.r &&
        my_color.g == green_sea.g &&
        my_color.b == green_sea.b)
    {
        this->highlight_color = turquoise; // Example highlight color for green pieces
    }
    else if (my_color.r == pumpkin.r &&
             my_color.g == pumpkin.g &&
             my_color.b == pumpkin.b)
    {
        this->highlight_color = carrot; // Example highlight color for red pieces
    }
    else
    {
        this->highlight_color = clouds; // Default highlight color
    }
};

Piece::~Piece() = default; // Pure virtual destructor must be defined

void Piece::select(color player_color)
{
    this->selected = true;
}

void Piece::deselect()
{
    this->selected = false;
}

bool Piece::same_team(int xpos, int ypos)
{
    Piece *there_piece = board->get_piece(xpos, ypos);
    if (there_piece != nullptr &&
        there_piece->my_color.r == my_color.r &&
        there_piece->my_color.g == my_color.g &&
        there_piece->my_color.b == my_color.b)
    {
        return true; // Same team
    }
    return false; // Different team or no piece
}

bool Piece::valid_space(int xpos, int ypos)
{
    return move_math(xpos, ypos) && !same_team(xpos, ypos) && !piece_between(xpos, ypos);
}

bool Piece::clicked(int xpos, int ypos)
{
    if (my_color.r == board->player_color.r && my_color.g == board->player_color.g && my_color.b == board->player_color.b)
    {
        if (valid_space(xpos, ypos))
        {
            printf("%c clicked at: (%d, %d)\n", name, xpos, ypos);
            // Move the knight to the new position
            board->remove_piece(xpos, ypos);                 // Remove any piece at the target position
            board->pieces[xpos][ypos] = this;                // Place knight at new position on the board
            board->pieces[this->xpos][this->ypos] = nullptr; // Clear old position
            this->xpos = xpos;                               // Update knight's position
            this->ypos = ypos;
            deselect();
            return true;
        }
    }
    deselect();
    return false;
}

void Piece::die()
{
    printf("%c at (%d, %d) has died.\n", name, xpos, ypos);
}

bool Piece::piece_between(int xpos, int ypos)
{
    int x_dir = this->xpos > xpos ? -1 : 1;
    if (this->xpos - xpos == 0)
        x_dir = 0;
    int y_dir = this->ypos > ypos ? -1 : 1;
    if (this->ypos - ypos == 0)
        y_dir = 0;
    int i = this->xpos + x_dir, j = this->ypos + y_dir;
    while ((i != xpos || x_dir == 0) && (j != ypos || y_dir == 0))
    {
        if (board->get_piece(i, j) != nullptr)
            return true;
        i += x_dir;
        j += y_dir;
    }

    return false;
}