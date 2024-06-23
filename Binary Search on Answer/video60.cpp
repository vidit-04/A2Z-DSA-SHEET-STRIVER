#include<bits/stdc++.h>
using namespace std;

int KthMissingNumber(vector<int>a,int k){
    //BRUTE FORCE THIS IS JUST A WAY TO DO THERE MAY BE MANY WAYS
    //SO for ex- a={5,7,9,11} here 4 is the 4th missing element. and if we want 5th missing element then it is 6
    //See if you want to have 5th missing number then in normal count it is 1,2,3,4,5. 5 is the answer. But since you found 5 in array so 5 not the answer so 6 is the answer.
    //We just add a number to k when we find a number that is present in the array.
    for(int i=0;i<a.size();i++){
        if(a[i]<=k) k++;
        else break;
    }
    return k;
    //T.C.-O(n)
    //S.C.-O(1)
}

int KthMissingNumberApproach2(vector<int>a,int k){
    int low=0;
    int high=a.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=a[mid]-(mid+1);
        if(missing<k){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return k+high+1; // low+1 as low=high+1
    //T.C.-O(n)
    //S.C.-O(1)
}

int main(){
    //Here missing number is 1,5,6,8,9,10, we can see 9 is the 5th misssing element
    vector<int>a={2,3,4,7,11};
    int k=5;
    cout<<KthMissingNumber(a,k);
    return 0;
}