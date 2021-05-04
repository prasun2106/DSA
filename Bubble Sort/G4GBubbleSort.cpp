#include <iostream>
using namespace std;

// 1. Bubble sort 2. Swap 3. Print array 4. Driver code


void bubbleSort(int arr[], int n){
    for(int i =0; i<n-1; i++ ){
        for (int j = 0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//print array
void printArray(int arr[], int n){
    for(int i = 0; i<n; i++){

        cout << arr[i]<<" ";
    }
}

// driver code

int main(){
    int arr[] = {10,2,3,4,2,1,6,4,7,9,34,2,5,3,7,3,2,1,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);
}