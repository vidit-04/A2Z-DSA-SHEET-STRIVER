#include<bits/stdc++.h>
using namespace std;

int print2largest(int arr[], int n) {
    //Second Largest - Best Approach
	    if(n==0 || n==1) return -1;
	    int largest=INT_MIN;
	    int sec_largest=INT_MIN;
	    for(int i=0;i<n;i++){
	        if(arr[i]>largest) {
	            sec_largest=largest;
	            largest=arr[i];
	        }
	        else if(arr[i]>sec_largest && arr[i]!=largest){
	            sec_largest=arr[i];
	        }
	        
	    }
	    if(sec_largest==INT_MIN) return -1;
	    return sec_largest;
	}
int print2largestapproach2(int arr[],int n){
    //Second Largest - Approach 2 Better Approach
    int largest=arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    int sec_largest=arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>sec_largest && arr[i]!=largest){
            sec_largest=arr[i];
        }
    }
    return sec_largest;    
}
int print2largestapproach3(int arr[],int n){
    //Second Largest - Approach 3 Brute Force Approach
    sort(arr,arr+n);
    int largest=arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        if(arr[i]<largest){
            return arr[i];
        }
    }
    return -1;
}
int removeDuplicates(vector<int>& nums) {
    //Remove Duplicates from Sorted Array
        int n=nums.size();
        vector<int>a;
        int temp=nums[0];
        a.push_back(temp);
        for(int i=1;i<n;i++){
            if(temp!=nums[i]){
                temp=nums[i];
                a.push_back(temp);
            }
        }
        nums=a;
        return a.size();
}

int main(){
    
    return 0;
}