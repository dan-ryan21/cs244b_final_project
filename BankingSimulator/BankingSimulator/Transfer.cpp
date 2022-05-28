#include "Transfer.h"

Transfer::Transfer(Account *a, Account *b, double amount)
	: m_account_A(a), m_account_B(b)
{
	m_amount = amount;
}

void Transfer::Execute()
{
	m_account_A->CreditAccount(m_amount);
	m_account_B->DebitAccount(m_amount);
}

void Transfer::Log()
{

}