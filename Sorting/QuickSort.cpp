#include <iostream>
using namespace std;
 
int arr[] = {22,92,18,17,11,52,78,66,51,85};
int arrsize = 10;

int SetPivot(int L, int R){
    int P_index = (L+R)/2;
    int pivot = arr[P_index];

    swap(arr[P_index], arr[R]);
    P_index = L;

    int current = L;
    while(current < R){
        if(arr[current] < pivot){
            swap(arr[current], arr[P_index]);
            P_index++;
        }
        current++;
    }


    swap(arr[P_index], arr[R]);
    return P_index;
}

void QuickSort(int L,int R){
    if (L < R){
        int P_index = SetPivot(L,R);

        QuickSort(L, P_index - 1);
        QuickSort(P_index + 1, R);
    }
}
            
int main(){
    QuickSort(0, arrsize - 1);

    cout << "Sorted Array:\n";
    int k = 0;
    while(k < arrsize){
        cout << arr[k] << " ";
        k++;
    }

    return 0;
}
