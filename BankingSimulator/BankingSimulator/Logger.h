#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include "Transaction.h"

// Simulates database replication for Batch and Serial Processing of transactions
class Logger
{

public:

	Logger();
	long long LogBatches(std::vector<std::vector<Transaction*>> batches, int num_of_cores);
	long long LogSerialTransactions(std::vector<Transaction*> serial_transactions);

private:

	void LogBatchTransactions(std::vector<Transaction*> batch_transactions, int num_of_cores);
	void LogTransactionsInParallelThread(std::vector<Transaction*> batch_transactions, int idx, int num_of_cores);

};

#endif // LOGGER_H
