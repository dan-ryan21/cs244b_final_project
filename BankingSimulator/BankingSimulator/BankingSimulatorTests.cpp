#include <iostream>
#include "BankingSimulatorTests.h"
#include "Account.h"
#include "Deposit.h"
#include "Withdrawal.h"
#include "Transfer.h"

void BankingSimulatorTests::TestAccount()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START Account Tests\n";
    std::cout << "---------------------------------------------------\n";

    Account a(1, 1000);

    std::cout << a.ToString();

    a.CreditAccount(500);

    std::cout << a.ToString();

    a.DebitAccount(25.50);

    std::cout << a.ToString();

    std::cout << "---------------------------------------------------\n";
    std::cout << "END Account Tests\n";
    std::cout << "---------------------------------------------------\n";
}

void BankingSimulatorTests::TestTransactions()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "START Transaction Tests\n";
    std::cout << "---------------------------------------------------\n";

    Account a(1, 1000);
    Account b(2, 1000);

    std::cout << a.ToString();
    std::cout << b.ToString();

    Deposit d(&a, 150.25);
    d.Execute();

    std::cout << a.ToString();
    std::cout << b.ToString();

    Withdrawal w(&b, 75);
    w.Execute();

    std::cout << a.ToString();
    std::cout << b.ToString();

    Transfer t(&a, &b, 500);
    t.Execute();

    std::cout << a.ToString();
    std::cout << b.ToString();

    std::cout << "---------------------------------------------------\n";
    std::cout << "END Transaction Tests\n";
    std::cout << "---------------------------------------------------\n";
}

