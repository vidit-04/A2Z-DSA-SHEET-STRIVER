#include<bits/stdc++.h>
using namespace std;

int SumOfSubarrayRanges(vector<int>a){
    //BRUTE FORCE
    int n=a.size();
    int sum=0;
    int mod=(int)(1e9+7);
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int j=i;j<n;j++){
            mini=min(mini,a[j]);
            maxi=max(maxi,a[j]);
            sum=(sum+(maxi-mini));
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
        while(!s.empty() && arr[s.top()]>=arr[i]){
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
        while(!s.empty() && a[s.top()]>a[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        else{
            ans[i]=-1;
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

vector<int> NextGreaterElementApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    stack<int>s;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]<=a[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=n;
        }
        else ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> PreviousGreaterElementApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    vector<int>ans(n,-1);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]<=a[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        else{
            ans[i]=-1;
        }
        s.push(i);
    }
    return ans;
}

int SumOfSubArrayMaximumsApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    vector<int>nse=NextGreaterElementApproach2(a,n);
    vector<int>pse=PreviousGreaterElementApproach2(a,n);
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

int SumOfSubarrayRangesApproach2(vector<int>a){
    //OPTIMAL APPROACH
    int n=a.size();
    int sum=0;
    int mod=(int)(1e9+7);
    int sum1=SumOfSubArrayMaximumsApproach2(a,n);
    int sum2=SumOfSubArrayMinimumsApproach2(a,n);
    sum=(sum1-sum2)%mod;
    return sum;
    //T.C.-O(5N)+O(5N)+O(1)=O(10N)
    //S.C.-O(5N)
}

int main(){
    //Sum of subarray ranges
    vector<int>a={1,4,3,2};
    cout<<SumOfSubarrayRangesApproach2  (a)<<endl;
    return 0;
}