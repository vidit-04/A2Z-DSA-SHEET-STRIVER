#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber3(vector<int>a){
    //BRUTE FORCE: Here there will be two single numbers
    map<int,int>mpp;
    for(int i=0;i<a.size();i++){
        mpp[a[i]]++;
    }
    vector<int>ans;
    for(auto i:mpp){
        if(i.second==1){
            ans.push_back(i.first);
        }
    }
    return ans;
    //T.C.-O(nlogm)+O(m)
    //S.C.-O((n/2)+1)
}

vector<int> singleNumber3Approach2(vector<int>a){
    //OPTIMAL SOLUTION
    //CONCEPTS OF BUCKETS
    int n=a.size();
    long xorr=0;

    for(int i=0;i<n;i++){
        xorr^=a[i];
    }
    //Now we have the xor of two numbers
    //Now we have to find the rightmost set bit
    int rightmostsetbit=(xorr&(xorr-1))^xorr;
    //Now we have the rightmost set bit
    int b1=0;
    int b2=0;
    for(int i=0;i<n;i++){
        if(a[i]&rightmostsetbit){
            b1=b1^a[i];
        }
        else{
            b2=b2^a[i];
        }
    }
    return {b1,b2};
    //T.C.-O(2n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={2,4,2,14,8,7,7,8};
    vector<int>ans=singleNumber3Approach2(a);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}