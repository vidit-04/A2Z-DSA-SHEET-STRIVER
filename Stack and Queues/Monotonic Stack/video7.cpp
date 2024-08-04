#include<bits/stdc++.h>
using namespace std;

vector<int> PreviousSmallerElement(vector<int>a,int n){
    //BRUTE FORCE
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){
                ans[i]=a[j];
                break;
            }
        }
    }
    return ans;
    //T.C.- O(N^2)
    //S.C.- O(N)
}

vector<int> PreviousSmallerElementApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while
    }
}
    
int main(){
    vector<int>a={4,5,2,10,8};
    int n=a.size();
    vector<int>ans=PreviousSmallerElement(a,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}