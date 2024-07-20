#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7;
int subsequence(vector<int>arr,int n,int index,int sum){
	if(sum==0 && index==n){
        return 1;
    }
    if(index==n || sum<0){
        return 0;
    }
	return subsequence(arr,n,index+1,sum)+ subsequence(arr,n,index+1,sum-arr[index]);	    
}

int main(){
    vector<int>a={2,5,6,1,0};
    int target=8;
    int n=a.size();
    long ans=subsequence(a,n,0,target);
    cout<<ans;
    return 0;
}