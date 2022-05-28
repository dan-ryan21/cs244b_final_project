#include "TransactionGenerator.h"
#include <iostream>
#include <stdlib.h>

TransactionGenerator::TransactionGenerator(int accounts, int transactions, double balance)
{
	m_number_of_accounts = accounts;
	m_number_of_transactions = transactions;
	m_balance = balance;
}

void TransactionGenerator::Generate()
{
	CreateAccounts();
	CreateTransactions();	
}

std::vector<Account*> TransactionGenerator::GetAccounts()
{
	return m_accounts;
}

std::vector<Transaction*> TransactionGenerator::GetTransactions()
{
	return m_transactions;
}

void TransactionGenerator::CreateAccounts()
{
	for (int i = 0; i < m_number_of_accounts; i++)
	{
		Account* a = new Account(i + 1, m_balance);
		m_accounts.push_back(a);
	}
}

void TransactionGenerator::CreateTransactions()
{
	while (m_transactions.size() < m_number_of_transactions)
	{
		// Select 2 distinct accounts (even though we only need 1 for deposit/withdrawal TXNs)
		int idx1 = rand() % m_number_of_accounts;
		int idx2 = rand() % m_number_of_accounts;
		while (idx1 == idx2)
		{
			idx2 = rand() % m_number_of_accounts;
		}

		Account* a = m_accounts.at(idx1);
		Account* b = m_accounts.at(idx2);

		// Select a TXN type
		int txn_type = rand() % 3;

		// Select a TXN amount
		double txn_amount = (rand() % 50000) / 25.00;

		// Create the TXN.  If its valid, add it to the list of TXNs
		if (txn_type == 0)
		{
			Withdrawal* w = new Withdrawal(a, txn_amount);
			if (w->IsValid())
			{
				m_transactions.push_back(w);
				w->Execute();
			}
		}
		else if (txn_type == 1)
		{
			Deposit* d = new Deposit(a, txn_amount);
			if (d->IsValid())
			{
				m_transactions.push_back(d);
				d->Execute();
			}
		}
		else
		{
			Transfer* t = new Transfer(a, b, txn_amount);
			if (t->IsValid())
			{
				m_transactions.push_back(t);
				t->Execute();
			}
		}
	}

	// Rollback all of the transactions
	std::vector<Transaction*>::iterator i = m_transactions.end();
	while (i != m_transactions.begin())
	{
		--i;
		(*i)->Rollback();
	}
}