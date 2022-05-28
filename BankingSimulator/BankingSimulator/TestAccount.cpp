#include <iostream>
#include "Account.h"
#include "TestAccount.h"

void TestAccount::Execute()
{
    Account DansAccount(1, 1000);

    std::cout << DansAccount.ToString();

    DansAccount.CreditAccount(500);

    std::cout << DansAccount.ToString();

    DansAccount.DebitAccount(25.50);

    std::cout << DansAccount.ToString();
}

