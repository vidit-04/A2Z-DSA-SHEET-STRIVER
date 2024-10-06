#include<bits/stdc++.h>
using namespace std;

int JumpGame2(vector<int>a,int ind,int jumps){
    if(ind>=a.size()-1) return jumps; 
    int mini=INT_MAX;
    for(int i=1;i<=a[ind];i++){
        mini=min(mini,JumpGame2(a,ind+i,jumps+1));
    }
    return mini;
    //T.C.-O(n*n)
}

int main(){
    vector<int>a={2,3,1,1,4};
    int ind=0;
    int jumps=0;
    cout<<JumpGame2(a,ind,jumps);
    return 0;
}