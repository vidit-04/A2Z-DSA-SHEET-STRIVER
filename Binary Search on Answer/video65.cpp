#include<bits/stdc++.h>
using namespace std;

int MedianOfTwoSortedArrays(vector<int>a1,vector<int>a2){
    int i=0;
    int j=0;
    vector<int>newArr;
    int n1=a1.size();
    int n2=a2.size();
    //MERGE BOTH ARRAYS
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            newArr.push_back(a1[i]);
            i++;
        }
        else{
            newArr.push_back(a2[j]);
            j++;
        }           
    }
    while(i<n1){
        newArr.push_back(a1[i]);
        i++;
    }
    while(j<n2){
        newArr.push_back(a2[j]);
        j++;
    }
    int n=n1+n2;
    //FIND MEDIAN
    if(n%2==1) return newArr[n/2];
    return ((newArr[n/2]+newArr[(n/2)-1])/2);
    //T.C.-O(n1+n2)
    //S.C.-O(n1+n2)
    //TLE
}

int MedianOfTwoSortedArraysApproach2(vector<int>a1,vector<int>a2){
    //We don't create new array here  instead we count the index
    int i=0;
    int j=0;

    int n1=a1.size();
    int n2=a2.size();
    int n=n1+n2;
    int ind2=n/2;
    int ind1=ind2-1;
    int ele1=-1;
    int ele2=-1;
    int count=0;

    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            if(count==ind1) ele1=a1[i];
            if(count==ind2) ele2=a1[i];
            count++;
            i++;
        }
        else{
            if(count==ind1) ele1=a2[j];
            if(count==ind2) ele2=a2[j];
            count++;
            j++;            
        }    
    }
    while(i<n1){
        if(count==ind1) ele1=a1[i];
        if(count==ind2) ele2=a1[i];
        count++;
        i++;
    }
    while(j<n2){
        if(count==ind1) ele1=a2[j];
        if(count==ind2) ele2=a2[j];
        count++;
        j++;            
    }
    if(n%2==1) return ele2;
    return ((ele1+ele2)/2);
    //T.C.-O(n1+n2)
    //S.C.-O(1)
}

int main(){
    vector<int>a1={1,3,4,7,10,12};
    vector<int>a2{2,3,6,15};
    cout<<MedianOfTwoSortedArrays(a1,a2);    
    return 0;
}