#include <iostream>
using namespace std;

void atmWithdraw()
{
    int balance, withdraw;

    cout << "Enter your current account balance: ";
    cin >> balance;

    while (true)
    {
        cout << "Enter the amount you wish to withdraw: ";
        cin >> withdraw;

        if (withdraw > balance)
        {
            cout << "Insufficient Funds. Re-enter an amount: " << endl;
        }
        else if (withdraw % 100 != 0)
        {
            cout << "Invalid amount. Enter an amount that is only a multiple of 100" << endl;
        }
        else
        {
            balance -= withdraw;
            cout << "Succesful. Remaining Balance: " << balance << endl;
            break;
        }
    }
    cout << "Final Balance:" << balance << endl;
}

int main()
{
    atmWithdraw();
    return 0;
}