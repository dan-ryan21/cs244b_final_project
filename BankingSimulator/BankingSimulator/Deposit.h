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
	virtual void Rollback();
	virtual void Log();
	virtual bool IsValid();
	virtual bool FromAccount(Account* a);
	virtual Account* GetFromAccount();
	virtual std::string ToString();
	virtual std::string TransactionType();

};

#endif // DEPOSIT_H

