#ifndef TRANSFER_H
#define TRANSFER_H

#include "Transaction.h"

// Concrete Transaction class to transfer money from one account (A) to another (B)
class Transfer : public Transaction
{

private:

	Account *m_account_A;
	Account *m_account_B;
	double m_amount;

public:

	Transfer(Account *a, Account *b, double amount);

	virtual void Execute();
	virtual void Rollback();
	virtual void Log();
	virtual bool IsValid();
	virtual bool FromAccount(Account* a);
	virtual bool ToAccount(Account* a);
	virtual Account* GetFromAccount();
	virtual Account* GetToAccount();
	virtual std::string ToString();
	virtual std::string TransactionType();

};

#endif // TRANSFER_H

