#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"

// Abstract class that will define the interface for all Transactions that our banking
// application will simulate (Deposit, Withdrawal, Transfer Money)
class Transaction
{

public:

	Transaction() {};
	virtual void Execute() = 0;
	virtual void Log() = 0;

};

#endif // TRANSACTION_H
