#ifndef BOARD_HPP
#define BOARD_HPP

#include "../window/window.hpp"
#include "stockfish.hpp"
#include <fstream>
#include <iostream>

extern int stickies;
extern bool invisible;
extern bool pexp;
extern bool Pexp;
extern int spawn_b;
extern int spawn_B;
extern int hammer;
extern int promoteq;
extern int promoteQ;
extern int stones;

class Buff;

class Piece;

class Board
{
public:
    Board(color player_color, int stockfish_elo, int stockfish_depth, int loop_amount, int filter_shader, std::vector<Buff *> buffs);
    ~Board();
    void draw(double deltaTime);
    void mouse_left_clicked(double xpos, double ypos);
    void mouse_right_clicked();
    Piece *get_piece(int xpos, int ypos);
    void remove_piece(int xpos, int ypos);
    Piece *pieces[8][8] = {}; // 2D array of pointers to pieces
    color player_color;
    color ai_color;
    std::string enpassant = "-";
    std::string can_castle = "-"; // "KQkq";
    void game_over(color loser);
    bool run_game = true;
    double score = 500;
    double modifier = 0;
    int loop_num;
    bool ready_for_delete = false;
    int filter_shader;
    float tile_size;  // Width of each tile
    float top_left_x; // Top left corner x-coordinate
    float top_left_y; // Top left corner y-coordinate
    int loop_pos = 0;
    std::vector<Buff *> buffs;

private:
    bool get_stockfish = false;
    bool player_turn = true;
    void draw_checkerboard();
    std::string get_best_move();
    void draw_pieces(double deltaTime);
    Piece *player_king;
    bool take_king();
    void move_stockfish();
    Piece *selected_piece = nullptr; // Pointer to the currently selected piece
    Stockfish *stockfish = nullptr;
    void apply_loop();
};

#endif