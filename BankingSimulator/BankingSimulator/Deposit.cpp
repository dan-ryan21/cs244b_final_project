#include "Deposit.h"

Deposit::Deposit(Account a, double amount)
{
	m_account_A = a;
	m_amount = amount;
}

void Deposit::Execute()
{
	m_account_A.DebitAccount(m_amount);
}