#include "board.hpp"

Board::Board()
{
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
                pieces[i][j]->draw();
            }
        }
    }
}

void Board::draw()
{
    draw_checkerboard();
    draw_pieces();
}

void Board::mouse_clicked(double xpos, double ypos)
{
    printf("Mouse clicked at: (%f, %f)\n", xpos, ypos);
    int x_tile = static_cast<int>((xpos - top_left_x) / tile_size);
    int y_tile = static_cast<int>((ypos - top_left_y) / tile_size) - 1;
    if (selected_piece != nullptr)
    {
        selected_piece->clicked();
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
            selected_piece->select();
        }
    }
}

Piece *Board::get_piece(int xpos, int ypos)
{
    printf("Piece (%d, %d)\n", xpos, ypos);
    return pieces[xpos][ypos];
}