# cs244b_final_project
This project simulates a scalable banking application by providing the capability to process transactions in batches while maintaining transaction consistency.  The application runs 5 separate tests, either unit testing some of the internal components or performance testing the Banking Simulator.  All 5 are enabled by default, but can be easily disabled by commenting out one of the lines in the main() method.

* TestAccount() - Tests the basic functionality of the Account class (creating an account and debiting/crediting that account)
* TestTransactions() - Tests the functionality of our 3 Transaction types (Deposit, Withdrawal, and Transfer), including executing each transaction, rolling back each transaction, and demonstrating that we catch invalid transactions.
* TestGenerator() - Tests that our TransactionGenerator class can generate an arbitrary number of Transactions for an arbitrary number of Accounts with an arbitrary starting balance.
* TestPreProcessor() - Tests that our PreProcessor class can properly apply our commutativity rules and split a list of Transactions into batches that can be processed in parallel.  Reports the total number of batches and average batch size.  Verifies that after executing the Transactions serially or in batches, we achieve the same results.
* TestLogger() - Performance tests the application by simulating database replication.  Compares the performance of serial replication and batch processing with a varying number of cores.

It is intended to run on an Ubuntu Linux platform (developed and tested on Ubuntu 22.04 LTS)

To install, compile, and run the application, issue the following commands:

* sudo apt install g++
* sudo apt install make
* git clone https://github.com/dan-ryan21/cs244b_final_project.git
* cd cs244b_final_project/BankingSimulator/BankingSimulator
* make
* ./BankingSimulator
