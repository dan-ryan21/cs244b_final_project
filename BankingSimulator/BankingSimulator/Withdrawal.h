#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h"

// Concrete Transaction class to withdrawal money from an account
class Withdrawal : public Transaction
{

public:

	Withdrawal(Account a, double amount);

	virtual void Execute();

	virtual void Log();
};

#endif // WITHDRAWAL_H

