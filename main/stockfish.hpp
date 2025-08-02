#ifndef STOCKFISH_HPP
#define STOCKFISH_HPP

#include <boost/process.hpp>
#include <iostream>
#include <string>

class Stockfish
{
public:
    Stockfish::Stockfish(int elo, int depth);
    Stockfish::~Stockfish();
    void Stockfish::blast_cache();
    std::string Stockfish::get_best_move(std::string fen_str);
};

#endif