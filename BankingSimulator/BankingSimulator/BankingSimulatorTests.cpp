#include <iostream>
#include "BankingSimulatorTests.h"
#include "Account.h"
#include "Deposit.h"
#include "Withdrawal.h"
#include "Transfer.h"
#include "TransactionGenerator.h"
#include "PreProcessor.h"
#include "Logger.h"

void BankingSimulatorTests::TestAccount()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START Account Tests\n";
    std::cout << "---------------------------------------------------\n\n";

    Account a(1, 1000);

    std::cout << a.ToString() << "\n";

    a.CreditAccount(500);

    std::cout << a.ToString() << "\n";

    a.DebitAccount(25.50);

    std::cout << a.ToString() << "\n";

    std::cout << "\n---------------------------------------------------\n";
    std::cout << "END Account Tests\n";
    std::cout << "---------------------------------------------------\n\n";
}

void BankingSimulatorTests::TestTransactions()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START Transaction Tests\n";
    std::cout << "---------------------------------------------------\n\n";

    std::cout << "Create 2 accounts\n\n";

    Account a(1, 1000);
    Account b(2, 1000);
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nDeposit $150.25 to Account 1\n\n";

    Deposit d(&a, 150.25);
    d.Execute();
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nRollback\n\n";

    d.Rollback();
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nWithdrawal $75.00 from Account 2\n\n";

    Withdrawal w(&b, 75);
    w.Execute();
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nRollback\n\n";

    w.Rollback();
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nTransfer $500.00 from Account 1 to Account 2\n\n";

    Transfer t(&a, &b, 500);
    t.Execute();
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nRollback\n\n";

    t.Rollback();
    std::cout << a.ToString() << "\n";
    std::cout << b.ToString() << "\n";

    std::cout << "\nAll Deposits are Valid\n\n";

    Deposit d2(&a, 1000);
    std::string valid = d2.IsValid() ? " Is Valid" : " Is Not Valid";
    std::cout << d2.ToString() << valid;

    std::cout << "\n\nA Valid Withdrawal\n\n";

    Withdrawal w2(&b, 1000);
    valid = w2.IsValid() ? " Is Valid" : " Is Not Valid";
    std::cout << w2.ToString() << valid;

    std::cout << "\n\nAn Invalid Withdrawal\n\n";

    Withdrawal w3(&b, 1000.01);
    valid = w3.IsValid() ? " Is Valid" : " Is Not Valid";
    std::cout << w3.ToString() << valid;

    std::cout << "\n\nA Valid Transfer\n\n";

    Transfer t2(&a, &b, 1000);
    valid = t2.IsValid() ? " Is Valid" : " Is Not Valid";
    std::cout << t2.ToString() << valid;

    std::cout << "\n\nAn Invalid Transfer\n\n";

    Transfer t3(&a, &b, 1000.01);
    valid = t3.IsValid() ? " Is Valid" : " Is Not Valid";
    std::cout << t3.ToString() << valid;

    std::cout << "\n\n---------------------------------------------------\n";
    std::cout << "END Transaction Tests\n";
    std::cout << "---------------------------------------------------\n\n";
}

void BankingSimulatorTests::TestGenerator()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START Generator Tests\n";
    std::cout << "---------------------------------------------------\n\n";

    std::cout << "Generate 5 accounts\n\n";

    TransactionGenerator tg(5, 100, 5000);
    tg.Generate();
    std::vector<Account*> accounts = tg.GetAccounts();
    for (Account *a : accounts)
    {
        std::cout << a->ToString() << "\n";
    }

    std::cout << "\nGenerate 100 transactions\n\n";

    std::vector<Transaction*> transactions = tg.GetTransactions();
    for (Transaction* t : transactions)
    {
        std::cout << t->ToString() << "\n";
    }

    std::cout << "\nExecute transactions and display results\n\n";

    for (Transaction* t : transactions)
    {
        t->Execute();
    }
    for (Account* a : accounts)
    {
        std::cout << a->ToString() << "\n";
    }

    std::cout << "\n---------------------------------------------------\n";
    std::cout << "END Generator Tests\n";
    std::cout << "---------------------------------------------------\n\n";
}

void BankingSimulatorTests::TestPreProcessor()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START PreProcessor Tests\n";
    std::cout << "---------------------------------------------------\n\n";

    TransactionGenerator tg(10, 100000, 5000);
    tg.Generate();

    std::vector<Transaction*> serial_transactions = tg.GetTransactions();

    PreProcessor pp(serial_transactions);

    std::vector<std::vector<Transaction*>> batches = pp.CreateBatches();

    int count = 0;
    int total = 0;

    for (std::vector<Transaction*> b : batches)
    {
        count++;
        total += b.size();
    }

    std::cout << count << " Batches with average size = " << total / count << " Transactions\n\n";

    std::cout << "Inital Account States\n\n";

    std::vector<Account*> accounts = tg.GetAccounts();
    for (Account* a : accounts)
    {
        std::cout << a->ToString() << "\n";
    }

    std::cout << "\nAccount States after Serial Processing\n\n";

    for (Transaction* t : serial_transactions)
    {
        t->Execute();
    }

    for (Account* a : accounts)
    {
        std::cout << a->ToString() << "\n";
    }

    // Rollback all of the transactions
    std::vector<Transaction*>::iterator i = serial_transactions.end();
    while (i != serial_transactions.begin())
    {
        --i;
        (*i)->Rollback();
    }

    std::cout << "\nAccount States after Batch Processing\n\n";

    for (std::vector<Transaction*> b : batches)
    {
        while (!b.empty())
        {
            // Get a random TXN from the batch
            int i = rand() % b.size();
            std::vector<Transaction*>::iterator it = b.begin() + i;

            Transaction* t = b.at(i);
            b.erase(it);

            t->Execute();

            for (Account* a : accounts)
            {
                if (a->GetBalance() < 0)
                    throw std::runtime_error("Negative Account Balance.  Something went wrong.");
            }
        }
    }

    for (Account* a : accounts)
    {
        std::cout << a->ToString() << "\n";
    }

    std::cout << "\n---------------------------------------------------\n";
    std::cout << "END PreProcessor Tests\n";
    std::cout << "---------------------------------------------------\n\n";
}

void BankingSimulatorTests::TestLogger()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START Performance Tests\n";
    std::cout << "---------------------------------------------------\n\n";

    TransactionGenerator tg(10, 100000, 5000);
    tg.Generate();

    std::vector<Transaction*> serial_transactions = tg.GetTransactions();

    PreProcessor pp(serial_transactions);

    std::vector<std::vector<Transaction*>> batches = pp.CreateBatches();

    Logger logger;
    long long elapsed_time_ms = logger.LogSerialTransactions(serial_transactions);

    std::cout << "Serial Processing took " << elapsed_time_ms << "ms\n";

    int num_of_cores[6] = { 1, 2, 4, 8, 16, 32 };

    for (int n : num_of_cores)
    {
        elapsed_time_ms = logger.LogBatches(batches, n);

        std::string thread_text = (n == 1) ? " thread" : " threads";

        std::cout << "Batch Processing with " << n << thread_text << " took " << elapsed_time_ms << "ms\n";
    }
   
    std::cout << "\n---------------------------------------------------\n";
    std::cout << "END Performance Tests\n";
    std::cout << "---------------------------------------------------\n\n";
}