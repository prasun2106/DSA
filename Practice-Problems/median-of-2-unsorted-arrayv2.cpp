#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub){
    
    // 3 indicators for traversing left array, right array and the actual array
    int i = 0, j = mid, k = 0;
    //size of left array
    int n_left =  mid - lb + 1;
    //size of right array
    int n_right  = ub - mid;
    int b[ub+1];
    while (i<= mid && j<= ub){
        // when i stays inside the left array and j stays inside the right array
        // we will compare the current elements and put it in a third array 
        // whichever is smaller.
        
        if (arr[i]< arr[j]){
            b[k] = arr[i];
            k++;
            i++;
        }
        else{
            b[k] = arr[j];
            k++;
            j++;
        }
    }
    // there might be some of the elements left in any of the left or right array
    // lets put them in sorted order in the new array
    if (i > mid){
        while (j<=ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<= mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    // replace elements of actual array with that of the newly created array

    for (i=0; i<ub; i++){
        arr[i] = b[i];
    }
    }
void printArray(int arr[],int  n){
    for (int i =0; i<n; i++){
        cout << arr[i]<< " ";
    }
}


void mergeSort(int arr[], int lb, int ub){
    if (lb<ub){ 
    //if lower bound is less than upper bound, then it means that there are more than 
    // one elenent in the array
        int mid = lb + (ub - lb)/2; // getting index of middle element

        mergeSort(arr, lb, mid); // recursively call mergeSort on the left half of original array
        mergeSort(arr, mid+1, ub); // recursively call mergeSort on the right half of original array 
        merge(arr, lb, mid, ub); // function to merge two array so that the final array is sorted
    }
}


int main(){
    int arr[9] = {10,3,7,2,5,6,34,3,2};
    mergeSort(arr, 0, 8);
    printArray(arr,9);

}
    
    