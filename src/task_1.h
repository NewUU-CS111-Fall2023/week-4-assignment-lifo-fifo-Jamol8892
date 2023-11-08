#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() { top = NULL; }

    void push(int item) {
        Node* newNode = new Node;
        newNode->data = item;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int item = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        cout << "Stack: ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
