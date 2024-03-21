/***
 * 
 * Autor: Rume
 * CodeChef: @kaium75
 * Date: March 21, 2024
 *
 ***/
#include<bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int length){
    int i, j, lowest;
    for(i=0; i<length-1; i++){
        lowest=i;
        for(j=i; j<length; j++){
            if(arr[lowest]>arr[j]){
                lowest=j;
            }
        }
        if(lowest!=i){
            int temp = arr[lowest];
            arr[lowest]=arr[i];
            arr[i]=temp;
        }
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

    	//sorting the array
    	insertionSort(arr,n);

    	//find the element using binary search
    	int temp=binarySearch(arr,0,n-1,value);

    	if(temp!=-1)
    		cout<<temp;
    	else
    		cout<<"Value not found"<<endl;

    }
   
    return 0;
}