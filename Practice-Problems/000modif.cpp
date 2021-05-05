#include <iostream>
using namespace std;
#include <iomanip> 

void merge(int arr[], int lb, int mid, int ub) {
   int i = 0, j = mid+1, k = 0, nl, nr;
   //size of left and right sub-arrays
//    nl = m-l+1; nr = r-m;
//    int larr[nl], rarr[nr];
//    //fill left and right sub-arrays
//    for(i = 0; i<nl; i++)
//       larr[i] = array[l+i];
//    for(j = 0; j<nr; j++)
//       rarr[j] = array[m+1+j];
//    i = 0; j = 0; k = l;
   int b[ub];
   //marge temp arrays to real array
   while(i < mid && j< ub) {
      if(arr[i] <= arr[j]) {
         b[k] = arr[i];
         i++;
      }else{
         b[k] = arr[j];
         j++;
      }
      k++;
   }
   while(i<mid) {       //extra element in left array
      b[k] = arr[i];
      i++; k++;
   }
   while(j<ub) {     //extra element in right array
      b[k] = arr[j];
      j++; k++;
   }
   for (i = 0; i< ub; i++){
       arr[i] = b[i];
   }
}

void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

// We have 2 unsorted arrays whose median we have to find

int main() {

    
   int n, m;
   cout << "Enter the number of elements in first array: ";
   cin >> m;
   int sec1[m];     //create an array with given number of elements
   cout << "Enter elements of first array:" << endl;
   for(int i = 0; i<m; i++) {
      cin >> sec1[i];
   }

   cout << "Enter the number of elements in second array: ";
   cin >> n;
   int sec2[n];     //create an array with given number of elements
   cout << "Enter elements of second array:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> sec2[i];
   }

   mergeSort(sec1,0,m-1);
   mergeSort(sec2,0,n-1);

   // now we have 2 sorted arrays sec1 and sec2 
   // we will find median of these two sorted arrays
   // For doing so, we will merge these two arrays using 
   // the concept of merge function of merge sort





   int a= 0; //for  traversing sec1
   int b = 0; //for traversing sec2
   int num = 0; // for counting the number of swaps
   int k = 0;
   int newarray[m+n];
   while(a< m && b< n){
       if (sec1[a] < sec2[b]){
           newarray[k] = sec1[a];
           a = a+1;
           k++;
       }
       else{
           newarray[k] = sec2[b];
          b++;
          k++;
       }
   }
   // Checking the elements which are left
   while(a<m){
       newarray[k] = sec1[a];
       a++;
       k++;
   }
   while(b<n){
       newarray[k] = sec2[b];
       b++;
       k++;
   }

   // Now we have our final array called newarray in which all the elements of
   // sec1 and sec2 are stored in a sorted manner
   if ((m+n)%2 == 0){
       float median_value = (newarray[(m+n)/2] + newarray[((m+n)/2)- 1])/2;
       std::cout << std::setprecision (2) << median_value <<" L"<< std::endl;
    //    cout<< median_value << "L";
   }
   else{
       cout<<newarray[(m+n-1)/2] << "L";
   }

}