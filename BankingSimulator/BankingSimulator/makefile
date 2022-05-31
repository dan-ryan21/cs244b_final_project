# Makefile for BankingSimulator

# *****************************************************
# Variables to control Makefile operation
 
CC = g++
CFLAGS = -Wall -g
 
# ****************************************************
# Targets needed to bring the executable up to date
BankingSimulator: BankingSimulator.o Account.o BankingSimulatorTests.o Deposit.o Logger.o PreProcessor.o TransactionGenerator.o Transfer.o Withdrawal.o
	$(CC) $(CFLAGS) -o BankingSimulator BankingSimulator.o Account.o BankingSimulatorTests.o Deposit.o Logger.o PreProcessor.o TransactionGenerator.o Transfer.o Withdrawal.o
	
BankingSimulator.o: BankingSimulator.cpp BankingSimulatorTests.h
	$(CC) $(CFLAGS) -c BankingSimulator.cpp
	
Account.o: Account.h

BankingSimulatorTests.o: BankingSimulatorTests.h Account.h Deposit.h Withdrawal.h Transfer.h TransactionGenerator.h PreProcessor.h Logger.h

Deposit.o: Deposit.h

Logger.o:  Logger.h

PreProcessor.o: PreProcessor.h

TransactionGenerator.o: TransactionGenerator.h

Transfer.o: Transfer.h

Withdrawal.o: Withdrawal.h