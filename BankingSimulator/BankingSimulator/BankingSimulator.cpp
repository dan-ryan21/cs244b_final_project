// BankingSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankingSimulatorTests.h"
#include "PreProcessor.h"
#include "TransactionGenerator.h"

int main()
{
	BankingSimulatorTests::TestAccount();
	BankingSimulatorTests::TestTransactions();
	BankingSimulatorTests::TestGenerator();
	BankingSimulatorTests::TestPreProcessor();
	
}


