#include<bits/stdc++.h>
using namespace std;

int SumN(vector<int>a,int sum){
    if(sum==0) return 1;
    if(sum<0) return 0;

    int ans=0;
    for(int i=0;i<a.size();i++){
        ans+=SumN(a,sum-a[i]);
    }
    return ans;
}

int main(){
    vector<int>a={1,5,6};
    int sum=7;
    
    cout<<SumN(a,sum);
    return 0;
}