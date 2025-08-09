#include "piece.hpp"

#include "../main/board.hpp"

#include <cstdlib>

Piece::Piece(int xpos, int ypos, color my_color, Board *board)
{
    this->xpos = xpos;
    this->ypos = ypos;
    this->my_color = my_color;
    this->board = board;
    this->selected = false;

    this->current_tex = std::rand() % 3;
    this->tex_time = 0.2 + double(std::rand() % 10) / 50.0;

    if (my_color == green_sea)
    {
        this->highlight_color = turquoise; // Example highlight color for green pieces
    }
    else if (my_color == pumpkin)
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
        there_piece->my_color == my_color)
    {
        return true; // Same team
    }
    return false; // Different team or no piece
}

bool Piece::valid_space(int xpos, int ypos)
{
    return move_math(xpos, ypos) && !same_team(xpos, ypos) && !piece_between(xpos, ypos);
}

bool Piece::move(int xpos, int ypos)
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
        return true;
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

void Piece::get_textures()
{
    std::string assets = "assets/";
    std::string ai = "";
    if (this->board->ai_color == my_color)
        ai = "_ai";
    std::string tex_loc = assets + name + "1" + ai + ".bmp";
    textures[0] = LoadTexBMP(tex_loc.c_str());
    tex_loc = assets + name + "2" + ai + ".bmp";
    textures[1] = LoadTexBMP(tex_loc.c_str());
    tex_loc = assets + name + "3" + ai + ".bmp";
    textures[2] = LoadTexBMP(tex_loc.c_str());
}

void Piece::draw(double tile_pos_x, double tile_pos_y, double tile_size, int filter_shader, double deltaTime)
{
    int id = -1;
    accumulated_time += deltaTime;

    if (accumulated_time > tex_time)
    {
        accumulated_time = 0;
        current_tex = (current_tex + 1) % 3;
    }
    if (invisible && !(my_color == board->player_color))
    {
        return;
    }

    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, textures[current_tex]);
    id = glGetAttribLocation(filter_shader, "aTexCoord");

    glBegin(GL_QUADS);
    glVertexAttrib2f(id, 1.0, 0.0);
    glVertex2f(tile_pos_x, tile_pos_y); // Top right corner
    glVertexAttrib2f(id, 1.0, 1.0);
    glVertex2f(tile_pos_x, tile_pos_y + tile_size); // Top left corner
    glVertexAttrib2f(id, 0.0, 1.0);
    glVertex2f(tile_pos_x + tile_size, tile_pos_y + tile_size); // Bottom left corner
    glVertexAttrib2f(id, 0.0, 0.0);
    glVertex2f(tile_pos_x + tile_size, tile_pos_y); // Bottom right corner
    glEnd();
    glDisable(GL_TEXTURE_2D);
}