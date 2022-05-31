#include "Logger.h"
#include <fstream>
#include <chrono>
#include <thread>

Logger::Logger() {}

long long Logger::LogBatches(std::vector<std::vector<Transaction*>> batches, int num_of_cores)
{
    auto t1 = std::chrono::high_resolution_clock::now();

    for (std::vector<Transaction*> batch : batches)
    {
        LogBatchTransactions(batch, num_of_cores);
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    auto elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    return elapsed_time_ms;
}

long long Logger::LogSerialTransactions(std::vector<Transaction*> transactions)
{
    auto t1 = std::chrono::high_resolution_clock::now();

    for (Transaction* t : transactions)
    {
        t->Log();
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    auto elapsed_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    return elapsed_time_ms;
}

void Logger::LogBatchTransactions(std::vector<Transaction*> batch_transactions, int num_of_cores)
{
    std::vector<std::unique_ptr<std::thread>> threads(num_of_cores);

    for (int i = 0; i < num_of_cores; i++)
    {
        threads.at(i).reset(new std::thread(&Logger::LogTransactionsInParallelThread, this, batch_transactions, i, num_of_cores));
    }

    for (std::unique_ptr<std::thread> &th : threads)
    {
        th->join();
    }
}

void Logger::LogTransactionsInParallelThread(std::vector<Transaction*> batch_transactions, int idx, int num_of_cores)
{   
    for (int i = idx; i < batch_transactions.size(); i += num_of_cores)
    {
        batch_transactions.at(i)->Log();
    }
}