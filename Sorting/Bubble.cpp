#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){

        for(int j= 0; j<n - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printarray(int arr[],int n){
    for(int i =0; i<n; i++){
        cout << arr[i] <<" ";
    }
}
int main(){
    int arr[] = {19, 5, 3, 8, 5, 4, 2, 11, 9};
    int n = 9;

    BubbleSort(arr,n);
    printarray(arr,n);
    return 0;
}
