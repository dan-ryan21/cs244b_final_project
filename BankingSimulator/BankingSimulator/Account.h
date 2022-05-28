#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:
	
	int m_id;
	double m_balance;

public:

	Account(int id, double opening_balance);

	double CreditAccount(double amount);

	double DebitAccount(double amount);

	double GetBalance();

	std::string ToString();

};

#endif // ACCOUNT_H