#include <iostream>
#include <stack>

using namespace std;

int problem3() {
    string expression;
    cin >> expression;

    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            int operand = c - '0';
            operands.push(operand);
        } else {
            int operand1 = operands.top();
            operands.pop();

            int operand2 = operands.top();
            operands.pop();

            int result;
            switch (c) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
            }

            operands.push(result);
        }
    }

    cout << operands.top() << endl;

    return 0;
}
