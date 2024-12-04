#include <iostream>

#include <stack>

#include <cctype>

using namespace std;



int applyOp(int a, int b, char op) {

    if (op == '+') return a + b;

    if (op == '-') return a - b;

    if (op == '*') return a * b;

    if (op == '/') return a / b;

    return 0;

}



int precedence(char op) {

    if (op == '+' || op == '-') return 1;

    if (op == '*' || op == '/') return 2;

    return 0;

}



int evaluateInfix(string exp) {

    stack<int> values;

    stack<char> ops;



    for (int i = 0; i < exp.length(); i++) {

        if (isdigit(exp[i])) {

            int val = 0;

            while (i < exp.length() && isdigit(exp[i])) {

                val = val * 10 + (exp[i] - '0');

                i++;

            }

            values.push(val);

            i--;

        } else if (exp[i] == '(') {

            ops.push(exp[i]);

        } else if (exp[i] == ')') {

            while (!ops.empty() && ops.top() != '(') {

                int val2 = values.top(); values.pop();

                int val1 = values.top(); values.pop();

                char op = ops.top(); ops.pop();

                values.push(applyOp(val1, val2, op));

            }

            ops.pop();

        } else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {

            while (!ops.empty() && precedence(ops.top()) >= precedence(exp[i])) {

                int val2 = values.top(); values.pop();

                int val1 = values.top(); values.pop();

                char op = ops.top(); ops.pop();

                values.push(applyOp(val1, val2, op));

            }

            ops.push(exp[i]);

        }

    }



    while (!ops.empty()) {

        int val2 = values.top(); values.pop();

        int val1 = values.top(); values.pop();

        char op = ops.top(); ops.pop();

        values.push(applyOp(val1, val2, op));

    }



    return values.top();

}



int main() {

    string exp;

    cout << "Enter an infix expression: ";

    getline(cin, exp);



    cout << "Result: " << evaluateInfix(exp) << endl;

    return 0;

}