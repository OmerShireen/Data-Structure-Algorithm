#include <iostream>
using namespace std;

int main() {
    int input[10] = {24, 36, 44, 52, 63, 71, 85, 89, 93, 94};
    int tosearch;
    
    int l = 0;
    int r = 9;
    int mid;
    
    cout << "Enter a number: ";
    cin >> tosearch;
    
    while (l <= r) {
        mid = (l+r) / 2;
        
        if(tosearch == input[mid]) {
            cout << "Value found at index: " << mid;
            return 0;
        }
        else if (tosearch < input[mid]){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    
    cout << "Value not found";
    return 0;
}    
  
