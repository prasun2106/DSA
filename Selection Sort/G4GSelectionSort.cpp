# include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for (int i = 0; i<n-1; i++){
        for(int j=i; j< ; j++){
            if(arr[j]<arr[i]){
                int temp = arr[i];
                arr[j] = arr[i];
                arr[j] = temp;
            }
        }
    }
}