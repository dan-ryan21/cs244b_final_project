#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include "Transaction.h"

// Takes a serial array of transactions and applies commutativity rules to generate batches
// of transactions that can be processed parallel
class PreProcessor
{

private:
	
	std::vector<Transaction*> m_transactions;

	Transaction* PopFrontTransaction();
	Transaction* ViewFrontTransaction();

public:

	PreProcessor(std::vector<Transaction*> transactions);
	std::vector<std::vector<Transaction*>> CreateBatches();

};

#endif // PRE_PROCESSOR_H
