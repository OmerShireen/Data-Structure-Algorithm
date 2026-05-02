#include <iostream>
using namespace std;

int arr[5];
int top = -1;

void push(int value){
    if(top == 4){
        cout << "Stack overflow" <<endl;
        return;
    }
    top++;
    arr[top] = value;
}

void pop(int value){
    if(top == -1){
         cout<< "Stack underflow"<< endl;
         return;
    }
    cout<< "Popped:" << arr[top]<<endl;
    top--;
}

void display(){
    if(top == -1){
        cout<< "Stack is empty"<< endl;
    }
    for(int i = top; i>=0; i--){
        cout<< arr[i]<< endl;
    }
}

int main(){
    int ch;
    int value;

    cout << "Press 1 Push Value" << endl <<"Press 2 to Pop value " << endl << "Press 3 to display"<< endl << "Press 4 to exit"<< endl;

    while (true)
    {
        cin >> ch;
        if(ch == 1)
      {
            cout << "Enter a value you wanna push" << endl;
            cin >> value;
            push(value);
        }
        if (ch == 2)
        {
            cout << "" << endl;
            pop(value);
        }
        else if(ch == 3 ){
            display();
        }
        if (ch == 4)
        {
            break;
        }
        cout << "Press number to execute function" << endl;
    };
}