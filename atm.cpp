#include "atm.h"
#include <iostream>
#include <string>

using namespace std;

int string_reverse(const string &str)
{
    int result = 0;
    for (char c : str)
    {
        if (c >= '0' && c <= '9')
        {
            result = result * 10 + (c - '0');
        }
        else
        {
            return -1;
        }
    }
    return result;
}

ATM::ATM(const string &number, const string &balance_2, int min, int max)
    : atm_num(number), balance(balance_2), min(min), max(max),
      n1(100), n2(200), n3(500), n4(1000) {}

void ATM::load_money(int count_1, int count_2, int count_3, int count_4)
{
    int total = count_1 * n1 + count_2 * n2 + count_3 * n3 + count_4 * n4;
    balance = to_string(string_reverse(balance) + total);
}

bool ATM::cash_out(int amount)
{
    int balance = string_reverse(this->balance);

    if (amount < min || amount > max || amount > balance)
    {
        return false;
    }

    int remain_amount = amount;
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;

    while (remain_amount > 0)
    {
        if (remain_amount >= n4)
        {
            count_4++;
            remain_amount -= n4;
        }
        else if (remain_amount >= n3)
        {
            count_3++;
            remain_amount -= n3;
        }
        else if (remain_amount >= n2)
        {
            count_2++;
            remain_amount -= n2;
        }
        else if (remain_amount >= n1)
        {
            count_1++;
            remain_amount -= n1;
        }
    }

    balance -= (count_1 * n1 + count_2 * n2 + count_3 * n3 + count_4 * n4);
    this->balance = to_string(balance);

    return true;
}

string ATM::to_string() const
{
    string result = "ATM Number: " + atm_num + "\n";
    result += "Current Balance: " + balance + " USD\n";
    result += "Min Withdrawal: " + to_string(min) + " USD\n";
    result += "Max Withdrawal: " + to_string(max) + " USD\n";

    return result;
}
