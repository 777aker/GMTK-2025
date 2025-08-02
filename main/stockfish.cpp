#include "stockfish.hpp"

Stockfish::Stockfish(int elo, int depth)
{
    printf("Initing stockfish");
}

Stockfish::~Stockfish()
{
}

void Stockfish::blast_cache()
{
}

std::string Stockfish::get_best_move(std::string fen_str)
{
    std::cout << fen_str << std::endl;
    return "hey";
}