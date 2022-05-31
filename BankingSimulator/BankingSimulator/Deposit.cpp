#include "Deposit.h"
#include <sstream>
#include <chrono>
#include <thread>

Deposit::Deposit(Account *a, double amount)
	: m_account_A(a)
{
	m_amount = amount;
}

void Deposit::Execute()
{
	m_account_A->DebitAccount(m_amount);
}

void Deposit::Rollback()
{
	m_account_A->CreditAccount(m_amount);
}

void Deposit::Log()
{
	std::this_thread::sleep_for(std::chrono::microseconds(LOGGING_DELAY_NS));
}

// We can always deposit money
bool Deposit::IsValid()
{
	return true;
}

bool Deposit::FromAccount(Account* a)
{
	return false;
}

Account* Deposit::GetFromAccount()
{
	return m_account_A;
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

	return str;
}

std::string Deposit::TransactionType()
{
	return DEPOSIT_TYPE;
}