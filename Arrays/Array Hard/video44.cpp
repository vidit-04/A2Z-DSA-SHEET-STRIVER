#include<bits/stdc++.h>
using namespace std;

int maxiumProductSubarray(vector<int>a){
    int n=a.size();
    int maxProduct=1;
    for (int i = 0; i < n; i++){
        int product=1;
        for (int j = i; j < n; j++){
            product*=a[j];
            maxProduct=max(maxProduct,product);
        }
    }
    return maxProduct;
    //T.C. - O(n^2)
    //S.C. - O(1)    
}

int maxiumProductSubarray(vector<int>a){
    int n=a.size();
    int pre=1,suf=1;
    int maxProduct=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suf==0) suf=1;
        pre*=a[i];
        suf*=a[n-i-1];
        maxProduct=max(maxProduct,max(pre,suf));
    }
    return maxProduct;
}

int main(){
    vector<int>a={2,3,-2,4};
    cout<<maxiumProductSubarray(a)<<endl;
    return 0;
}