#include<bits/stdc++.h>
using namespace std;

int MaximumPointsFromKCards(vector<int>a,int k){
    //MAXIMUM POINTS FROM K CARDS
    //BRUTE FORCE
    int n=a.size();
    int lsum=0;
    int rsum=0;
    int maxSum=0;
    for(int i=0;i<k;i++){
        lsum+=a[i];
    }
    maxSum=lsum;
    int rindex=n-1;
    for(int i=k-1;i>=0;i--){
        lsum-=a[i];
        rsum+=a[rindex];
        rindex--;
        maxSum=max(maxSum,lsum+rsum);
    }
    return maxSum;
    //T.C.-O(2*K)
    //S.C.-O(1)
}

int main(){
    //MAXIMUM POINTS FROM K CARDS
    vector<int>a={6,2,3,4,7,2,1,7,1};
    int k=4;
    cout<<MaximumPointsFromKCards(a,k);
    return 0;
}