#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include "Transaction.h"

// Simulates database replication for Batch and Serial Processing of transactions
class Logger
{

public:

	Logger() {};
	void LogBatches(std::vector<std::vector<Transaction*>>);
	void LogSerialTransactions(std::vector<Transaction*>);

};

#endif // LOGGER_H
