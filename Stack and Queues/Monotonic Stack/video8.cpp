#include<bits/stdc++.h>
using namespace std;

vector<int> PrefixMax(vector<int>a,int n){
    vector<int>prefix(n);
    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=max(prefix[i-1],a[i]);
    }
    return prefix;
}

vector<int> SuffixMax(vector<int>a,int n){
    vector<int>suffix(n);
    suffix[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=max(suffix[i+1],a[i]);
    }
    return suffix;
}

int TrappingRainwater(vector<int>a,int n){
    //BRUTE FORCE
    vector<int>prefix=PrefixMax(a,n);
    vector<int>suffix=SuffixMax(a,n);
    int ans=0;
    for(int i=1;i<n-1;i++){
        int leftMax=prefix[i];
        int rightMax=suffix[i];
        if(a[i]<leftMax && a[i]<rightMax){
            ans+=min(prefix[i],suffix[i])-a[i];
        }
    }
    return ans;
    //T.C.-O(2N)+O(N)=O(3N)
    //S.C.-O(2N)
}

int TrappingRainwaterApproach2(vector<int>a,int n){
    //OPTIMIZED
    int left=0,right=n-1;
    int leftMax=0,rightMax=0;
    int ans=0;
    while(left<right){
        if(a[left]<=a[right]){
            if(a[left]>=leftMax){
                leftMax=a[left];
            }
            else{
                ans+=leftMax-a[left];
            }
            left++;
        }
        else{
            if(a[right]>=rightMax){
                rightMax=a[right];
            }
            else{
                ans+=rightMax-a[right];
            }
            right--;
        }
    }
    return ans;
    //T.C.-O(N)
    //S.C.-O(1)
}

int main(){
    //TRAPPING RAINWATER 
    vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
    int n=arr.size();
    cout<<TrappingRainwater(arr,n)<<endl;
    return 0;
}