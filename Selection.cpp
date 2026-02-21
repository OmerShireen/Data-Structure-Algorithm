#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n){
    for(int i =0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]< arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}
void printarray(int arr[],int n){
    for(int i =0; i<n; i++){
        cout<< arr[i] <<" ";
    }
}

int main(){
    int arr[] = {19, 5, 3, 8, 5, 4, 2, 11, 9};
    int n = sizeof(arr)/ sizeof(arr[0]);

    SelectionSort(arr,n);
    printarray(arr,n);
}