#ifndef TRANSACTION_GENERATOR_H
#define TRANSACTION_GENERATOR_H

#include <vector>
#include "Account.h"
#include "Transaction.h"
#include "Withdrawal.h"
#include "Deposit.h"
#include "Transfer.h"

// Generates a sequence of transaction for a specified number of accounts and transactions
class TransactionGenerator
{

private:
	
	int m_number_of_accounts;
	int m_number_of_transactions;
	double m_balance;
	std::vector<Account*> m_accounts;
	std::vector<Transaction*> m_transactions;

	void CreateAccounts();
	void CreateTransactions();

public:

	TransactionGenerator(int accounts, int transactions, double balance);
	void Generate();
	std::vector<Account*> GetAccounts();
	std::vector<Transaction*> GetTransactions();

};

#endif // TRANSACTION_GENERATOR_H