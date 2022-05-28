#include "Withdrawal.h"
#include <sstream>

Withdrawal::Withdrawal(Account *a, double amount)
	: m_account_A(a)
{
	m_amount = amount;
}

void Withdrawal::Execute()
{
	m_account_A->CreditAccount(m_amount);
}

void Withdrawal::Log()
{

}

// Can't withrawal more money than is in your account
bool Withdrawal::IsValid()
{
	return m_amount <= m_account_A->GetBalance();
}

std::string Withdrawal::ToString()
{
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << m_amount;

	std::string witdrawal_string = out.str();

	std::string str = "Withdrawal $";
	str += witdrawal_string;
	str += " from Account ";
	str += std::to_string(m_account_A->GetId());
	str += "\n";

	return str;
}