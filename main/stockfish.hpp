#ifndef STOCKFISH_HPP
#define STOCKFISH_HPP

#include <boost/process.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <atomic>

using namespace boost::process;

class Stockfish
{
public:
    Stockfish(int elo, int depth);
    ~Stockfish();
    void blast_cache();
    std::string get_best_move(std::string fen_str);

private:
    int stock_depth;
    child *stockproc = nullptr;
    bool stockfish_ready = false;
    opstream input;
    ipstream output;
    std::mutex stream_mtx;
    std::thread reader_thread;
    std::atomic_bool found_move = false;
    std::string last_best_move;
    void stock_loop();
};

#endif