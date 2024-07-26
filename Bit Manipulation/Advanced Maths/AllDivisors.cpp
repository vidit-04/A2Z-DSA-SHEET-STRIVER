#include<bits/stdc++.h>
using namespace std;
vector<int> AllDivisors(int n){
    vector<int> ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i!=i) ans.push_back(n/i);
        }
    }

    return ans;
    //T.C.-O(n**1/2)
    //S.C.-O(1)
}

int main(){
    int n=36;
    vector<int> ans=AllDivisors(n);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}