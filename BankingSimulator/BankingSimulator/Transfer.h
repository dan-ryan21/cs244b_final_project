#ifndef TRANSFER_H
#define TRANSFER_H

#include "Transaction.h"

// Concrete Transaction class to transfer money from one account to another
class Transfer : public Transaction
{

public:

	Transfer(Account a, Account b, double amount);

	virtual void Execute();

	virtual void Log();
};

#endif // TRANSFER_H

