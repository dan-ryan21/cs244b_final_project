#include "Withdrawal.h"

Withdrawal::Withdrawal(Account a, double amount)
{
	m_account_A = a;
	m_amount = amount;
}

void Withdrawal::Execute()
{
	m_account_A.CreditAccount(m_amount);
}