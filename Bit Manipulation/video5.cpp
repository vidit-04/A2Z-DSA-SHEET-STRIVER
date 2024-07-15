#include<bits/stdc++.h>
using namespace std;

int SingleNumber(vector<int>a){
    //BRUTE FORCE
    int n=a.size();
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }
    for(auto i:mpp){
        if(i.second==1){
            return i.first;
        }
    }
    return -1;
    //T.C.-O(nlogm)+O(m)
    //S.C.-O(m)
}

int SingleNumberApproach2(vector<int>a){
    //OPTIMAL SOLUTION
    int n=a.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=a[i];
    }
    return ans;
    //T.C.-O(n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={4,1,2,1,2};
    cout<<SingleNumberApproach2(a);
    return 0;
}