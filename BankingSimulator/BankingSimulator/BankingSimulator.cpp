// BankingSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BankingSimulatorTests.h"

int main(int argc, char* argv[])
{
	if (argc == 0) // Run all tests if no arguments given
	{
		BankingSimulatorTests::TestAccount();
		BankingSimulatorTests::TestTransactions();
		BankingSimulatorTests::TestGenerator();
		BankingSimulatorTests::TestPreProcessor();
		BankingSimulatorTests::TestLogger();
	}
	else if (argc == 1)
	{
		int select = std::stoi(argv[1]);

		switch (select)
		{
		case 1:
			BankingSimulatorTests::TestAccount();
			break;
		case 2:
			BankingSimulatorTests::TestTransactions();
			break;
		case 3:
			BankingSimulatorTests::TestGenerator();
			break;
		case 4:
			BankingSimulatorTests::TestPreProcessor();
			break;
		case 5:
			BankingSimulatorTests::TestLogger();
			break;
		}
	}
	else
	{
		std::cout << "Invalid arguments passed.  Enter no arguments to run all tests, or 1-5 to run an individual test";
	}
}


