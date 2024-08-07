#include<bits/stdc++.h>
using namespace std;

int SumOfSubArrayMinimums(vector<int>a,int n){
    //BRUTE FORCE
    int sum=0;
    int mini=INT_MAX;
    int mod=(int)(1e9+7);
    for(int i=0;i<n;i++){
        mini=a[i];
        for(int j=i;j<n;j++){
            mini=min(mini,a[j]);
            sum=(sum+mini)%mod; 
        }
    }
    return sum;
    //T.C.-O(N^2)
    //S.C.-O(1)
}

vector<int> NextSmallerElementApproach2(vector<int>arr,int n){
    //OPTIMAL APPROACH
    stack<int>s;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=n;
        }
        else ans[i]=s.top();
        s.push(i);
    }
    return ans;
    //T.C.- O(N)+O(N)
    //S.C.- O(N)+O(N)
}

vector<int> PreviousSmallerElementApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>a[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
    //T.C.- O(2N)
    //S.C.- O(N)
}

int SumOfSubArrayMinimumsApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    vector<int>nse=NextSmallerElementApproach2(a,n);
    vector<int>pse=PreviousSmallerElementApproach2(a,n);
    int sum=0;
    int mod=(int)(1e9+7);
    for(int i=0;i<n;i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        sum=(sum+(a[i]*left*right*1LL)%mod)%mod;
    }
    return sum;
    //T.C.-O(N)+O(2N)+O(2N)=O(5N)
    //S.C.-O(5N)
}


int main(){
    vector<int>a={3,1,2,4};
    int n=a.size();
    cout<<SumOfSubArrayMinimumsApproach2(a,n);
    return 0;
}