#include "board.hpp"
#include "../pieces/piece.hpp"
#include "../pieces/bishop.hpp"
#include "../pieces/rook.hpp"
#include "../pieces/knight.hpp"
#include "../pieces/queen.hpp"
#include "../pieces/king.hpp"
#include "../pieces/pawn.hpp"

Board::Board(color player_color)
{
    this->player_color = player_color;
    if (player_color.r == green_sea.r &&
        player_color.g == green_sea.g &&
        player_color.b == green_sea.b)
    {
        this->ai_color = pumpkin; // Example AI color for green pieces
    }
    else
    {
        this->ai_color = green_sea; // Example AI color for red pieces
    }

    // Player pieces
    pieces[1][0] = new Knight(1, 0, player_color, this);
    pieces[2][0] = new Bishop(2, 0, player_color, this);

    pieces[5][0] = new Bishop(5, 0, player_color, this);
    pieces[6][0] = new Knight(6, 0, player_color, this);

    // AI pieces
    pieces[1][7] = new Knight(1, 7, ai_color, this);
    pieces[2][7] = new Bishop(2, 7, ai_color, this);

    pieces[5][7] = new Bishop(5, 7, ai_color, this);
    pieces[6][7] = new Knight(6, 7, ai_color, this);
}

Board::~Board()
{
}

void Board::draw_checkerboard()
{
    tile_size = asp < 1 ? dim * asp * 0.2 : dim * 0.2;
    top_left_x = -dim * asp + (dim * asp * 0.1);
    top_left_y = -dim + dim * 0.1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // Alternate colors for the checkerboard pattern
            if ((i + j) % 2 == 0)
            {
                glColor3ub(asbestos.r, asbestos.g, asbestos.b); // Dark color
            }
            else
            {
                glColor3ub(clouds.r, clouds.g, clouds.b); // Light color
            }

            glBegin(GL_QUADS);
            glVertex2f(top_left_x + (i + 1) * tile_size, top_left_y + (j + 1) * tile_size); // Top right corner
            glVertex2f(top_left_x + i * tile_size, top_left_y + (j + 1) * tile_size);       // Top left corner
            glVertex2f(top_left_x + i * tile_size, top_left_y + j * tile_size);             // Bottom left corner
            glVertex2f(top_left_x + (i + 1) * tile_size, top_left_y + j * tile_size);       // Bottom right corner
            glEnd();
        }
    }
}

void Board::draw_pieces()
{
    // Placeholder for drawing pieces
    // This function should iterate through the pieces array and call their draw methods
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (pieces[i][j] != nullptr)
            {
                pieces[i][j]->draw(top_left_x + i * tile_size, top_left_y + j * tile_size, tile_size);
            }
        }
    }
}

void Board::draw()
{
    draw_checkerboard();
    draw_pieces();
}

void Board::mouse_left_clicked(double xpos, double ypos)
{
    printf("Mouse clicked at: (%f, %f)\n", xpos, ypos);
    int x_tile = static_cast<int>((xpos - top_left_x) / tile_size);
    double bottom_left_y = top_left_y + 9 * tile_size;
    int y_tile = static_cast<int>((-ypos + bottom_left_y) / tile_size);
    if (x_tile < 0 || x_tile >= 8 || y_tile < 0 || y_tile >= 8)
    {
        if (selected_piece != nullptr)
        {
            selected_piece->deselect();
            selected_piece = nullptr;
        }
        printf("Click out of bounds: (%d, %d)\n", x_tile, y_tile);
        return;
    }
    if (selected_piece != nullptr)
    {
        selected_piece->clicked(x_tile, y_tile);
        selected_piece = nullptr;
    }
    else
    {
        selected_piece = get_piece(x_tile, y_tile);
        if (selected_piece == nullptr)
        {
            printf("No piece at (%d, %d)\n", x_tile, y_tile);
            return;
        }
        else
        {
            selected_piece->select(this->player_color);
        }
    }
}

void Board::mouse_right_clicked()
{
    if (selected_piece != nullptr)
    {
        selected_piece->deselect();
        selected_piece = nullptr;
    }
    printf("Right click detected, deselecting piece.\n");
}

Piece *Board::get_piece(int xpos, int ypos)
{
    printf("Piece (%d, %d)\n", xpos, ypos);
    return pieces[xpos][ypos];
}

void Board::remove_piece(int xpos, int ypos)
{
    if (pieces[xpos][ypos] != nullptr)
    {
        pieces[xpos][ypos]->die();    // Call the die method of the piece
        delete pieces[xpos][ypos];    // Free the memory of the piece
        pieces[xpos][ypos] = nullptr; // Set the pointer to nullptr
    }
}