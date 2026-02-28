#include <iostream>
using namespace std;

int main() {
 int i = 0;
 int flag = 0;
    int input[10] ={77,78,88,82,85,84,96,98,99,45};
    int tosearch;
    cout<<"enter a number: ";
    cin>> tosearch;
    for(; i<10 ; i++){
        if(tosearch == input[i]){
            cout<<"Value found at index: "<<i;
            flag = 1;
            break;
        }
    }
    if(flag == 0){
    cout<<"Value not found"<<endl;
        }
}
