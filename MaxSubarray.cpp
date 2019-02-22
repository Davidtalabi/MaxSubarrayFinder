//Created by David Talabi 2-19-2019

#include <iostream>
using namespace std;

// A function to find the maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b;
    } 
  
// A function to find the maximum of three integers
int max(int a, int b, int c) 
{ 
    return max(max(a, b), c);
    } 
  
// Find the maximum possible sum in arr[] auch that arr[m] is part of it 
int FindMaxCrossingSubarray(int A[], int low, int mid, int high) //Function to find the maximum of a subarray that crosses the midpoint
{ 
//FINDING THE TOTAL OF THE SUBARRAY FROM LOW TO MID
    int sum = 0; //Initializing sum of subarray as 0
    int leftsum = -2147483647; //Initializing sum of left side of array to negative infinity
    for (int i = mid; i >= low; i--) //Moving backwards in the array starting from mid and going down to low
    { 
        sum = sum + A[i]; //adding the value stored at A[i] to the total su
        if (sum > leftsum) //Basically when sum is a valid number
          leftsum = sum; 
		  int maxleft = i;
    } 
  
    //REPEATING THE SAME THING FOR THE RIGHT SUBARRAY WHICH IS FROM MID+1 TO HIGH 
    sum = 0; 
    int rightsum = -2147483647; 
    for (int i = mid+1; i <= high; i++) 
    { 
        sum = sum + A[i]; 
        if (sum > rightsum) 
          rightsum = sum; 
	  int maxright = i;
    } 
  
    
    return leftsum + rightsum; //Returning the sum of the elements to the left of mid and to the right of mid
    //Now we know the total of the subarray that crosses the midpoint
} 
  
 
int FindMaxSubarray(int A[], int low, int high) 
{ 

   if (low == high) //Array size is 1 so the maximum subarray is literally equal to the only array element
     return A[low]; 
  
   
   int mid = (low + high)/2; // Find middle point 
  
  return max(FindMaxSubarray(A, low, mid), //max subarray sum in left half
              FindMaxSubarray(A, mid+1, high), //max subarray sum in right half
              FindMaxCrossingSubarray(A, low, mid, high)); //max subarray sum where subarray crosses midpoint 
} 
  

int main() //Main function where user inputs array size and array elements
{ 
   int n;
   
   cout << "Enter Array Size!" << endl;
   cin >> n;
   int A[n];
   cout << "Enter Array Elements!" << endl;
   for(int i=0; i<n; i++)
   cin >> A[i];
   
   int maxsum;
   maxsum = FindMaxSubarray(A, 0, n-1);
   cout << "Max subbarray is: " << maxsum;
} 
