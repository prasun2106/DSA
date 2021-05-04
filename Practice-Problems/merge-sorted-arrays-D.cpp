#include <iostream>
using namespace std;

void mergeTwoArray(int arr1[], int arr2[], int arr3[], int n1, int n2){
    // traverse both array and store in arr3
    int i = 0, j = 0, k= 0;
    while (i<n1 && j<n2){
        if (arr1[i]<arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    // storing extra elements from both the array
    while(i<n1){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}


void printArray(int arr[], int n){
    for (int i=0; i<n ; i++){
        cout << arr[i] << " ";
    }
}
// DRIVER CODE
int main(){
    int arr1[] ={1,3,5,7};
    int arr2[] = {2,4,6,8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int arr3[n1+n2];

    mergeTwoArray(arr1, arr2, arr3, n1, n2);
    printArray(arr3, n1+n2);


}