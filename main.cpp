#include "atm.h"
#include <iostream>
using namespace std;

int main()
{
    ATM atm("24456", "20000", 100, 2000);

    atm.load_money(100, 200, 500, 1000);

    cout << atm.to_string() << endl;

    int amount = 1500;
    if (atm.cash_out(amount))
    {
        cout << "Withdrawal of " << amount << " USD successful." << endl;
    }
    else
    {
        cout << "Withdrawal of " << amount << " USD failed." << endl;
    }

    cout << atm.to_string() << endl;

    return 0;
}
