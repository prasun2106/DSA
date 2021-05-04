# include <iostream>
using namespace std;

void swap(int*a, int* b){
    temp = *a;
    *a = *b;
    *b = temp;
}

// mergesort

void mergeSort(int arr[], int lb, int ub){
    if (lb<ub){
        // if lower bound is less than upper bound it means that there are more than 2 elements
        // so divide the array in two parts
        int mid = (lb+ub)/2;

        //recursive call
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        
        // we have divided the array into smaller parts. Now merge the divided array
        merge(arr, lb,mid, ub);
    }
}

void merge(int arr[], int lb,int mid, int ub){
    //merging elements from arr[lb to mid] and arr[mid+1 to ub] in a sorted way

    k++;


}