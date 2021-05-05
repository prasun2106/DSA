#include <iostream>
using namespace std;
#include <iomanip> 

void merge(int array[], int lb, int mid, int ub) {
   int i,j, k, left_arr, right_arr;
    //length of left and right array
   left_arr = mid-lb+1; right_arr = ub-mid;
   
   int arr1[left_arr], arr2[right_arr];

   // create two sub arrays for left and right
   for(i = 0; i<left_arr ; i++)
      arr1[i] = array[lb+i];
   for(j = 0; j<right_arr; j++)
      arr2[j] = array[mid+1+j];
   
   i = 0; j = 0; k = lb;

   while(i < left_arr && j<right_arr) { 
       // while i and j stays within the array lenth, compare the current element
       // of both left and right array
       // so that we can insert the smaller one into array
      if(arr1[i] <= arr2[j]) { 
         array[k] = arr1[i];
         i++;
      }else{
         array[k] = arr2[j];
         j++;
      }
      k++;
   }
   // putting extra element from any of the two arrays into our main array
   while(i<left_arr) { 
       // if after the previous while loop, i is lesser than left_arr, then 
       // it means that there are some elements left in the 
       // left array arr1. So we will put all those elements in
       // our main array as it is
      array[k] = arr1[i];
      i++; k++;
   }
   while(j<right_arr) {    
       // extra elements left in array 2 is put into the main array as it is.
       // please note that only one of these two while loop will run
      array[k] = arr2[j];
      j++; k++;
   }
}

void mergeSort(int array[], int lb, int ub) {
   int mid;
   if(lb < ub) {
      int mid = lb+(ub-lb)/2;
      // Sort first and second arrays
      mergeSort(array, lb, mid);
      mergeSort(array, mid+1, ub);
      merge(array, lb, mid, ub);
   }
}

// We have 2 unsorted arrays whose median we have to find

int main() {

   int n, m;
   // get the size of first array as input
   cout << "Enter the number of houses in sec1: ";
   cin >> m;
   int sec1[m];
   
   // get the elements of sec1
   cout << "Enter elements of first array:" << endl;
   for(int i = 0; i<m; i++) {
      cin >> sec1[i];
   }

   // get the size of second array as input

   cout << "Enter the number of houses in sec2: ";
   cin >> n;
   int sec2[n];     
   //get the elements of sec2
   cout << "Enter elements of second array:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> sec2[i];
   }

    //use mergeSort function defined by me to sort the numbers
   mergeSort(sec1,0,m-1);
   mergeSort(sec2,0,n-1);

   // now we have 2 sorted arrays sec1 and sec2 
   // we will find median of these two sorted arrays
   // For doing so, we will merge these two arrays using 
   // the concept of merge function of merge sort



   int a= 0; //for  traversing sec1
   int b = 0; //for traversing sec2
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
   //printing the array - testing purpose
   // for (int q = 0; q < m+n ; q++){
   //      cout<< newarray[q] << " ";       
   // }

   // Now we have our final array called newarray in which all the elements of
   // sec1 and sec2 are stored in a sorted manner
   if ((m+n)%2 == 0){
       float median_value = (newarray[(m+n)/2] + newarray[((m+n)/2)- 1])/2.0;
    //    std::cout << std::setprecision (2) << median_value <<" L"<< std::endl;
       cout<< median_value << " L";
   }
   else{
       cout<<newarray[(m+n-1)/2] << "L";
   }

}

// PSEUDO CODE AND TIME COMPLEXITY OF THE ALGORITHM
// Time Complexity
/*
To solve this problem, I have at first sorted both the array sec1 and sec2
using merge sort and then merged both the sorted array in such a way that 
after merging, the new array remains sorted.

1. For sorting array sec1 of length m, time complexity = O(mlogm) [because we are using
merge sort]
2. For sorting array sec2 of length n, time complexity = O(nlogn) [because we are using
merge sort]
3. For merging both array, we will have to compare elements of array sec1 with corresponding 
elements of sec2, and since these two are sorted, it will require linear time.
Time complexity of this part = O(m+n)
4. After that we are calculating median. The calculation of median does not depend on the
length of arrays, because it is the middle term (in case of odd length) or average of the
two middle terms (in case of even length). Thus time complexit = O(1)
5. So total time complexity = O(m+ n + n(log(n)) + m(log(m) + 1)

PSEUDO CODE: 
//merge sort
MergeSort(arr, left, right):
    if left > right 
        return
    mid = (left+right)/2
    mergeSort(arr, left, mid)
    mergeSort(arr, mid+1, right)
    merge(arr, left, mid, right)
end
// merge function is same as the merge part of merge sort

//sort both array
MergeSort(sec1)
MergeSort(sec2)

//merge both array in sorted order
merge(sec1, sec2)

if length(new_array) is even:
   median = average of two middle term
if length(new array) is odd:
   median= middle term







*/

