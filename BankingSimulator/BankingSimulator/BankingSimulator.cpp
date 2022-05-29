// BankingSimulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankingSimulatorTests.h"
#include "PreProcessor.h"
#include "TransactionGenerator.h"

int main()
{
	//BankingSimulatorTests::TestAccount();
	//BankingSimulatorTests::TestTransactions();
	//BankingSimulatorTests::TestGenerator();

	TransactionGenerator tg(5, 100000, 5000);
	tg.Generate();

	PreProcessor pp(tg.GetTransactions());
	std::vector<std::vector<Transaction*>> batches = pp.CreateBatches();

	int count = 0;
	int total = 0;

	for (std::vector<Transaction*> b : batches)
	{
		count++;
		total += b.size();
		std::cout << "Batch Size = " << b.size() << "\n";
	}

	std::cout << "\n" << count << " Batches with average size = " << total/count << "\n";
}


