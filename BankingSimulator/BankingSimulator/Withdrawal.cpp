#include "Withdrawal.h"
#include <sstream>
#include <chrono>
#include <thread>

Withdrawal::Withdrawal(Account *a, double amount)
	: m_account_A(a)
{
	m_amount = amount;
}

void Withdrawal::Execute()
{
	m_account_A->CreditAccount(m_amount);
}

void Withdrawal::Rollback()
{
	m_account_A->DebitAccount(m_amount);
}

void Withdrawal::Log()
{
	std::this_thread::sleep_for(std::chrono::microseconds(LOGGING_DELAY_NS));
}

// Can't withrawal more money than is in your account
bool Withdrawal::IsValid()
{
	return m_amount <= m_account_A->GetBalance();
}

bool Withdrawal::FromAccount(Account* a)
{
	return m_account_A == a;
}

bool Withdrawal::ToAccount(Account* a)
{
	return false;
}

Account* Withdrawal::GetFromAccount()
{
	return m_account_A;
}

Account* Withdrawal::GetToAccount()
{
	return NULL;
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

	return str;
}

std::string Withdrawal::TransactionType()
{
	return WITHDRAWAL_TYPE;
}