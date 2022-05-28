#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"

// Abstract class that will define the interface for all Transactions that our banking
// application will simulate (Deposit, Withdrawal, Transfer Money)
class Transaction
{

protected:

	Account m_account_A;
	Account m_account_B;
	double m_amount;

public:

	Transaction();

	virtual void Execute();

	virtual void Log();

};

#endif // TRANSACTION_H
