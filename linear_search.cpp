 #include <iostream>

 using namespace std;
 // Linearly search x in arr[]. If x is present then return index,
 // else return -1

 int search(int arr[], int n, int x){
     int i; 
     for (int i = 0; i < n; i++)
     {
         if (x == arr[i])
             return i;
     }
     return -1;
 }

 int main(){
     int arr[] = {1,10, 30,15};
     int x = 30;
     int n = sizeof(arr)/ sizeof(arr[0]);

     cout<< x<<" is present at "<<search(arr, n, x);
     return 0;

 }