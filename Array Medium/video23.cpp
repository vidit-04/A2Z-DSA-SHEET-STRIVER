#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>a){
    //Majority Element- the element who appears more than n/2 times. Brute Force
    int n=a.size();
    for (int i = 0; i < n; i++)
    {
        int ele=a[i];
        int count=0;
        for (int j = 0; j < n; j++)
        {
            if(a[j]==ele) count++;
        }
        if(count>n/2) return ele;        
    }    
}

int majorityElementApproach2(vector<int>a){
    //Majority Element- the element who appears more than n/2 times. Approach 2
    //HASHING- Better Solution
    unordered_map<int,int>mpp;
    int n=a.size();
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }
    for(auto it: mpp){
        if(it.second>n/2) return it.first;
    }
    return -1;
    //T.C. - O(n)+ O(nlog n)
    //S.C. - O(n)
    //Can we optimise s.c. to O(1)
}

int majorityElementApproach3(vector<int>a){
    //Majority Element- the element who appears more than n/2 times. Approach 3
    //Boyer-Moore Voting Algorithm
    //Step 1: Boye Moore Algo.
    //Step 2: Check whether the element is majority element or not.
    int n=a.size();
    int ele=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(count==0){
            ele=a[i];
            count=1;
        }
        else if(ele==a[i])count++;
        else count--;
    }
    //IF ALWAYS A MAJORITY ELEMENT EXIST THEN DON'T DO BELOW CODE.
    int cnt2=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]==ele) cnt2++;
    }
    if(cnt2>n/2) return ele;
    return -1;   
    
    //T.C. - O(n)+O(n)-> this one is only when there is no surity whether there is majority element or not
    //S.C. - O(1)
}

int main(){
    vector<int>a={2,2,3,3,1,2,2};
    cout<<majorityElementApproach3(a);
    // cout<<"hello";
    return 0;
}