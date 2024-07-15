#include<bits/stdc++.h>
using namespace std;

int SingleNumber2(vector<int>a){
    //BRUTE FORCE
    map<int,int>mpp;
    for(int i=0;i<a.size();i++){
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

int SingleNumber2Approach2(vector<int>a){
    //BRUTE SOLUTION
    int n=a.size();
    int ans=0;
    for (int bitIndex = 0; bitIndex < 31; bitIndex++){
        int count = 0;
        for(int i=0;i<n;i++){
            if(a[i]&(1<<bitIndex)){
                count++;
            }
        }
        if(count%3!=0){
            ans=ans|(1<<bitIndex);
        }
    }
    return ans;
    //T.C.-O(n*32)
    //S.C.-O(1)
}

int SingleNumber2Approach3(vector<int>a){
    //BETTER SOLUTION
    int n=a.size();
    for(int i=1;i<n;i+=3){
        if(a[i]!=a[i-1]) return a[i-1];
    }
    return a[n-1];
}

int SingleNumber2Approach4(vector<int>a){
    //OPTIMAL SOLUTION
    int n=a.size();
}

int main(){
    vector<int>a={5,5,5,8,4,4,4};
    cout<<SingleNumber2Approach3(a);
    return 0;
}