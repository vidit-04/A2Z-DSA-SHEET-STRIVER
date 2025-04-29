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
        while(!s.empty() && s.top()>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        s.push(a[i]);
    }
    return ans;
    //T.C.- O(2N)
    //S.C.- O(N)
}
    
vector<int> PreviousGreaterElementApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()<=a[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        s.push(a[i]);
    }
    return ans;
    //T.C.- O(2N)
    //S.C.- O(N)
}

int main(){
    vector<int>a={4,5,2,10,8};
    int n=a.size();
    vector<int>ans=PreviousSmallerElementApproach2(a,n);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}