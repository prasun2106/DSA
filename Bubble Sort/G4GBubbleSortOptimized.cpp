#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n){

    for (int i= 0; i<n-1; i ++){
        for (int j=0; j<n-i-1; j++){
            int flag = 0;
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            if (flag == 0){
                break;
            }

        }
    }
}
void printArray(int arr[], int n){
    for (int i = 0; i = n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {2,1,3,5,2,9,34,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    printArray(arr, n);

}