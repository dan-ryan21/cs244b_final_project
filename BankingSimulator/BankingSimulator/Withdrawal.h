#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h"

// Concrete Transaction class to withdrawal money from an account
class Withdrawal : public Transaction
{

private:

	Account *m_account_A;
	double m_amount;

public:

	Withdrawal(Account *a, double amount);

	virtual void Execute();
	virtual void Rollback();
	virtual void Log();
	virtual bool IsValid();
	virtual bool FromAccount(Account* a);
	virtual Account* GetFromAccount();
	virtual std::string ToString();
	virtual std::string TransactionType();

};

#endif // WITHDRAWAL_H

