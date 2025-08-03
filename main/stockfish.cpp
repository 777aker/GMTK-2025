#include "stockfish.hpp"

#include <chrono>
#include <filesystem>

Stockfish::Stockfish(int elo, int depth)
{
    printf("Initing stockfish\n");
    this->elo = elo;
#ifdef _WIN32
    std::filesystem::path stockfish_relative = "stockfish/stockfish-windows-x86-64-avx2.exe";
#elif defined(__linux__)
    std::filesystem::path stockfish_relative = "stockfish/stockfish-ubuntu-x86-64-avx2";
#else
    printf("ERROR DETECTING SYSTEM: TRYING WINDOWS STOCKFISH\n");
    std::filesystem::path stockfish_relative = "stockfish/stockfish-windows-x86-64-avx2.exe";
#endif

    std::filesystem::path stockfish_abs = std::filesystem::absolute(stockfish_relative);
    if (!std::filesystem::exists(stockfish_abs))
    {
        std::filesystem::path me = std::filesystem::current_path();
        stockfish_abs = me.parent_path() / stockfish_relative;
    }

    std::string stockfish_bin = stockfish_abs.string();
    std::cout << "Where I think stockfish is: '" << stockfish_bin << "'" << std::endl;

    stock_depth = depth;

    stockfish_ready = false;
    stockproc = new child(stockfish_bin, std_in<input, std_out> output);
    reader_thread = std::thread(&Stockfish::stock_loop, this);
    input << "uci" << std::endl;
    while (true)
    {
        stream_mtx.lock();
        if (stockfish_ready)
        {
            stream_mtx.unlock();
            break;
        }
        stream_mtx.unlock();
    }
    stockfish_ready = false;
    input << "setoption name UCI_LimitStrength value true" << std::endl;
    input << "setoption name UCI_Elo value " << std::to_string(elo) << std::endl;
    input << "setoption name Threads value 6" << std::endl;
    input << "ucinewgame" << std::endl;
    input << "isready" << std::endl;
    while (true)
    {
        stream_mtx.lock();
        if (stockfish_ready)
        {
            stream_mtx.unlock();
            break;
        }
        stream_mtx.unlock();
    }
}

void Stockfish::stock_loop()
{
    std::string line;
    while (std::getline(output, line))
    {
        if (!stockfish_ready && (line.find("uciok", 0) == 0 || line.find("readyok", 0) == 0))
        {
            stream_mtx.lock();
            stockfish_ready = true;
            stream_mtx.unlock();
            continue;
        }
        stream_mtx.lock();
        std::cout << line << std::endl;
        if (line.find("bestmove", 0) == 0)
        {
            last_best_move = line.substr(9);
            found_move = true;
        }
        stream_mtx.unlock();
    }
}

Stockfish::~Stockfish()
{
    input << "quit" << std::endl;
    input.close();
    reader_thread.join();
    stockproc->wait();
}

void Stockfish::blast_cache()
{
}

std::string Stockfish::get_best_move(std::string fen_str)
{
    std::cout << fen_str << std::endl;
    found_move = false;
    input << "position fen " << fen_str << std::endl;
    input << "go depth " << stock_depth << std::endl;
    while (!found_move)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return last_best_move;
}