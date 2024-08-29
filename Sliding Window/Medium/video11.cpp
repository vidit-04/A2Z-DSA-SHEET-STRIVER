#include<bits/stdc++.h>
using namespace std;

int SubarrayWithKDifferentIntegers(vector<int>a,int k){
    //BRUTE FORCE
    int n=a.size();
    int count=0;
    for(int i=0;i<n;i++){
        map<int,int>mpp;
        for(int j=i;j<n;j++){
            mpp[a[j]]++;
            if(mpp.size()==k){
                count+=1;
            }
            else if(mpp.size()>k) break;
        }
    }
    return count;
    //T.C.-O(N^2)
    //S.C.-O(N)
}

int SubarrayWithKDifferentIntegersApproach2(vector<int>a,int k){
    //BRUTE FORCE
    int n=a.size();
    int count=0;
    map<int,int>mpp;
    int l=0,r=0;
    while(r<n){
        mpp[a[r]]++;
        while(mpp.size()>k){
            mpp[a[l]]--;
            if(mpp[a[l]]==0){
                mpp.erase(a[l]);
            }
            l++;
        }
        count+=r-l+1;
        r++;
    }
    return count;
    //T.C.-O(2N)
    //S.C.-O(N)
}

int main(){
    //Subarray with k different integers
    vector<int>a={1,2,1,3,4};    
    int k=3;
    cout<<SubarrayWithKDifferentIntegersApproach2(a,k)-SubarrayWithKDifferentIntegersApproach2(a,k-1);
    return 0;
}