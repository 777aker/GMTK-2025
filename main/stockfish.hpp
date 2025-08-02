#ifndef STOCKFISH_HPP
#define STOCKFISH_HPP

#include <boost/process.hpp>
#include <iostream>
#include <string>

class Stockfish
{
public:
    Stockfish(int elo, int depth);
    ~Stockfish();
    void blast_cache();
    std::string get_best_move(std::string fen_str);
};

#endif