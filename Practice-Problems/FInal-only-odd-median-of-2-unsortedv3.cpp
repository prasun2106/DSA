#include<iostream>
using namespace std;

// Code for Merge Sort

void swapping(int &a, int &b) {     //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
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

// void printMedian(int num,int  m,int n, int arr[] ){
//     if ((m+n)%2 == 0){


//     }
    
//     if (num == (m+n)/2){
//                 cout << sec1[a] <<"L";
//             }
// }

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

   int a= 0; //for  traversing sec1
   int b = 0; //for traversing sec2
   int num = 0; // for counting the number of swaps

   while(a< m && b< n){
       if (sec1[a] < sec2[b]){
           //newarray[k] = sec1[a]
           
           if (num == (m+n)/2){
               cout << sec1[a] <<"L";
           }
           num = num+1;
           a = a+1;
       }
       else{
           //newarray[k] = sec2[b]
           if(num == (m+n)/2){
               cout<<sec2[b] << "L";
           }
            b++;
            num++;
       }
   }
   // Checking the elements which are left
   while(a<m){
       //newarray[k] = sec1[a]
       if (num == (m+n)/2){
           cout<<sec1[a] << "L";
       }
       a++;
       num++;
   }
   while(b<n){
       //newarray[k] = sec2[b]
       if(num == (m+n)/2){
           cout<<sec2[b] <<"L";
       }
       b++;
       num++;
   }

}