#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }   
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int *min=min_element(arr+i,arr+n);
        swap(arr[i],*min);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int j=i+1;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int  n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // INPUT
    // 7
    // 45 73 24 9 1 95 7

    bubbleSort(arr,n);
    // cout<<endl;
    selectionSort(arr,n);
    // cout<<endl;
    insertionSort(arr,n);
    
    return 0;
}