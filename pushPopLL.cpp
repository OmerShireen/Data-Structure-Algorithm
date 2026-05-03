#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void push(int value)
{
    Node *temp = new Node;
    temp->data = value;
    temp->next = top;
    top = temp;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    Node *temp = top;
    cout << "Popped: " << temp->data << endl;
    top = temp->next;
    delete temp;
}

void display()
{
    Node *cur = top;
    while (cur != NULL)
    {
        cout << cur->data << " -> ";
        cur = cur->next;
    }
    cout << "Stack is Empty\n";
}


void peek()
{
    if (top == NULL)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << top->data << endl;
}

int main()
{
    int ch;
    int value;

    cout << "Press 1 Push Value" << endl
         << "Press 2 to Pop value" << endl
         << "Press 3 to display" << endl
         << "Press 4 to peek" << endl
         << "Press 5 to exit" << endl;

    while (true)
    {
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter a value you wanna push: ";
            cin >> value;
            push(value);
        }
        else if (ch == 2)
        {
            pop();
        }
        else if (ch == 3)
        {
            display();
        }
        else if (ch == 4)
        {
            peek();
        }
        else if (ch == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice!" << endl;
        }

        cout << "Press number to execute function" << endl;
    }

    return 0;
}
