#ifndef PRE_PROCESSOR_H
#define PRE_PROCESSOR_H

#include <vector>
#include "Transaction.h"

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
