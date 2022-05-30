#include "Logger.h"
#include <fstream>
#include <chrono>

Logger::Logger() {}

void Logger::LogBatches(std::vector<std::vector<Transaction*>>)
{

}

long long Logger::LogSerialTransactions(std::vector<Transaction*> transactions)
{
    auto t1 = std::chrono::high_resolution_clock::now();

    std::ofstream output_file;
    output_file.open("output/serial_processing.txt");

    for (Transaction* t : transactions)
    {
        output_file << t->ToString() << "\n";
    }

    output_file.close();

    auto t2 = std::chrono::high_resolution_clock::now();

    auto elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    return elapsed_time_ms;
}