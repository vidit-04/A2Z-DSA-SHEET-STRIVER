#include<bits/stdc++.h>
using namespace std;

int LongestBitonicSequence(int n, vector<int> &nums) {
    // code here
    vector<int> lis(n,1);
    for(int i=1;i<n;i++){
        for(int back=0;back<i;back++){
            if(nums[back]<nums[i]){
                lis[i]=max(1+lis[back],lis[i]);
            }
        }
    }
    vector<int> lds(n,1);
    for(int i=n-1;i>=0;i--){
        for(int back=n-1;back>i;back--){
            if(nums[back]<nums[i]){
                lds[i]=max(1+lds[back],lds[i]);
            }
        }
    }
    int maxlen=0;
    for(int i=0;i<n;i++){
        if (lis[i] > 1 && lds[i] > 1) maxlen=max(lis[i]+lds[i]-1,maxlen);
    }
    return maxlen;
}

int main(){
    int n=8;
    vector<int> arr={1,11,2,10,4,5,2,1};
    cout<<LongestBitonicSequence(n,arr)<<endl; //6
    // 1 2 3 4 5 6 7
    return 0;
}