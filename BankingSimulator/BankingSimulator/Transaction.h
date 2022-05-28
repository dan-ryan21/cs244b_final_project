#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"

// Abstract class that will define the interface for all Transactions that our banking
// application will simulate (Open Account, Deposit, Withdrawal, Transfer Money)
class Transaction
{

private:

	Account m_account_A;
	Account m_account_B;
	double m_amount;

public:

	virtual void Execute();

	virtual void Log();

};

#endif // TRANSACTION_H
