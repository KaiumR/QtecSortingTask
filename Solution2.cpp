/***
 * 
 * Autor: Rume
 * CodeChef: @kaium75
 * Date: March 21, 2024
 *
 ***/
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int left, int midIndx, int right) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = midIndx-left+1;
    int n2 = right- midIndx;

    int leftPart[n1], rightPart[n2];

    for(int i=0; i<n1; i++)
        leftPart[i] = arr[left+i];
    for(int j=0; j<n2; j++)
        rightPart[j] = arr[midIndx+1+j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;


    while (i<n1 && j<n2) {
        if (leftPart[i] <= rightPart[j]) {
          arr[k] = leftPart[i];
          i++;
        } else {
          arr[k] = rightPart[j];
          j++;
        }
        k++;
    }

    while(i<n1) {
        arr[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightPart[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int left, int right) {
  if (left<right) {
    int midIndx = left+(right-left)/2;

    mergeSort(arr, left, midIndx);
    mergeSort(arr, midIndx + 1, right);

    // Merge the sorted subarrays
    merge(arr, left, midIndx, right);
  }
}
int binarySearch(int arr[], int left, int right, int value){
    while(left<=right){
        int midIndx = left+(right-left)/2;
 
        if (arr[midIndx] == value)
            return midIndx;
 
        if (arr[midIndx]<value)
            left = midIndx+1;
        else
            right = midIndx-1;
    }
 
    return -1;
}
int32_t main(){

    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    //test case
    int t;
    cin>>t;

    while(t--){
    	//length of array and value to find
    	int n, value;
    	cin>>n>>value;

    	int arr[n];

    	//taking array input from user
    	for(int i=0; i<n; i++){
    		cin>>arr[i];
    	}

    	//margesort the array
    	mergeSort(arr,0,n-1);

    	//find the element using binary search
    	int temp=binarySearch(arr,0,n-1,value);

    	if(temp!=-1)
    		cout<<temp;
    	else
    		cout<<"Value not found"<<endl;

    }
   
    return 0;
}