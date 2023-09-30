#pragma once
#include <iostream>
#include <string>

using namespace std;

class ATM
{
private:
    string atm_num;
    string balance;
    int min;
    int max;
    int n1; // 100
    int n2; // 200
    int n3; // 500
    int n4; // 1000

public:
    ATM(const string &number, const string &balance, int min, int max);
    void load_money(int count_1, int count_2, int count_3, int count_4);
    bool cash_out(int amount);
    string to_string() const;
};
