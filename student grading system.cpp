#include <iostream>
using namespace std;

int main()
{

    float x, y, z;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << "Enter third number: ";
    cin >> z;

    int total = x + y + z;
    float average = total / 3;

    cout << "Average Score: " << average << endl;

    if (average >= 70)
    {
        cout << "Result: Passed" << endl;
    }
    else
    {
        cout << "Result: Failed" << endl;
    }

    return 0;
}