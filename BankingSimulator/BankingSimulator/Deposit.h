#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h"

// Concrete Transaction class to deposit money to an account
class Deposit : public Transaction
{

private:

	Account *m_account_A;
	double m_amount;

public:

	Deposit(Account *a, double amount);

	virtual void Execute();

	virtual void Log();
};

#endif // DEPOSIT_H

