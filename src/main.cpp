#include <iostream>
#include "task_1.h"
#include "task_3.h"
#include "task_4.h"

int main() {

    cout << "Problem 1:" << endl;
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();

    stack.display();

    cout << "Problem 3: " << endl;
    problem3();

    cout << "Problem 4: " << endl;
    problem4();

    return 0;
}

