#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// Represents an individual bank account with a current balance.  Balance can be increased (debited)
// or decreased (credited), and we can report the current balance or return a string description of
// the account including its id and balance.
class Account
{

private:
	
	int m_id;
	double m_balance;

public:

	// Account constructor
	Account(int id, double opening_balance);

	// Subtract money from the account
	double CreditAccount(double amount);

	// Add money to the account
	double DebitAccount(double amount);

	double GetBalance();

	int GetId();

	std::string ToString();

};

#endif // ACCOUNT_H