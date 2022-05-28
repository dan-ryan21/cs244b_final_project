#include "Account.h"
#include <sstream>

Account::Account(int id, double opening_balance)
{
	m_id = id;
	m_balance = opening_balance;
}

double Account::CreditAccount(double amount)
{
	m_balance -= amount;

	return m_balance;
}

double Account::DebitAccount(double amount)
{
	m_balance += amount;

	return m_balance;
}

double Account::GetBalance()
{
	return m_balance;
}

int Account::GetId()
{
	return m_id;
}

std::string Account::ToString()
{
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << m_balance;

	std::string balance_string = out.str();

	std::string str = "Account Id ";
	str += std::to_string(m_id);
	str += " has a balance of $";
	str += balance_string;
	str += "\n";

	return str;
}