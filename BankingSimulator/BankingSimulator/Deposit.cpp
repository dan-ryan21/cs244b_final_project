#include "Deposit.h"
#include <sstream>

Deposit::Deposit(Account *a, double amount)
	: m_account_A(a)
{
	m_amount = amount;
}

void Deposit::Execute()
{
	m_account_A->DebitAccount(m_amount);
}

void Deposit::Log()
{

}

// We can always deposit money
bool Deposit::IsValid()
{
	return true;
}

std::string Deposit::ToString()
{
	std::ostringstream out;
	out.precision(2);
	out << std::fixed << m_amount;

	std::string deposit_string = out.str();

	std::string str = "Deposit $";
	str += deposit_string;
	str += " to Account ";
	str += std::to_string(m_account_A->GetId());
	str += "\n";

	return str;
}