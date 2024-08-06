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

int SumOfSubArrayMinimumsApproach2(vector<int>a,int n){
    //OPTIMAL APPROACH
    
}


int main(){
    vector<int>a={3,1,2,4};
    int n=a.size();
    cout<<SumOfSubArrayMinimums(a,n);
    return 0;
}