#include "Transfer.h"
#include <sstream>

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

void Transfer::Rollback()
{
	m_account_A->DebitAccount(m_amount);
	m_account_B->CreditAccount(m_amount);
}

void Transfer::Log()
{

}

// Can't transfer money from A -> B if A doesn't have enough money
bool Transfer::IsValid()
{
	return m_amount <= m_account_A->GetBalance();
}

std::string Transfer::ToString()
{
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << m_amount;

	std::string transfer_string = out.str();

	std::string str = "Transfer $";
	str += transfer_string;
	str += " from Account ";
	str += std::to_string(m_account_A->GetId());
	str += " to Account ";
	str += std::to_string(m_account_B->GetId());

	return str;
}