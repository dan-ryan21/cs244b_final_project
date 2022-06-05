#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"
#include <string>

static std::string WITHDRAWAL_TYPE = "Withdrawal";
static std::string DEPOSIT_TYPE = "Deposit";
static std::string TRANSFER_TYPE = "Transfer";
static int LOGGING_DELAY_NS = 100;

// Abstract class that will define the interface for all Transactions that our banking
// application will simulate (Deposit, Withdrawal, Transfer Money)
class Transaction
{

public:

	Transaction() {};
	virtual void Execute() = 0;
	virtual void Rollback() = 0;
	virtual void Log() = 0;
	virtual bool IsValid() = 0;
	virtual bool FromAccount(Account* a) = 0;
	virtual bool ToAccount(Account* a) = 0;
	virtual Account* GetFromAccount() = 0;
	virtual Account* GetToAccount() = 0;
	virtual std::string ToString() = 0;
	virtual std::string TransactionType() = 0;

};

#endif // TRANSACTION_H
