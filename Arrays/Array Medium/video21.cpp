#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>a,int k){
    //TWO SUM - BRUTE FORCE
    for (int i = 0; i < a.size(); i++)
    {
        for(int j=i+1;j<a.size();j++){
            if(a[i]+a[j]==k){
                cout<<i<<" "<<j<<endl;
                return {i,j};
            }
        }
    }
    //T.C. = O(N2);
    //S.C. = O(1)

}

vector<int> twoSumApproach2(vector<int>a,int k){
    //TWO SUM - Approach 2 - Better Approach
    //HASHING
    //This approach is good when we need to throw indexes of those elements. Because this is easy and best way.
    map<int,int>mpp;
    for(int i=0;i<a.size();i++){
        int rem=k-a[i];
        if(mpp.find(rem)!=mpp.end()){
            cout<<mpp[rem]<<" "<<i<<endl;
            return {mpp[rem],i};
        }
        mpp[a[i]]=i;    
    }
    return {};
    //T.C. = O(Nlog n)  FOr unordered map O(n) or in worst case O(n2)
    //S.C. = O(N)
}

vector<int> twoSumApproach3(vector<int>a,int k){
    //TWO SUM - Approach 3 - Best Approach
    //TWO POINTER APPROACH
    sort(a.begin(),a.end());
    int i=0,j=a.size()-1;
    while(i<j){
        if(a[i]+a[j]==k){
            cout<<i<<" "<<j<<endl;
            return {i,j};
        }
        else if(a[i]+a[j]<k){
            i++;
        }
        else{
            j--;
        }
    }
    return {};
    //T.C. = O(Nlog n)  FOr unordered map O(n) or in worst case O(n2)
    //S.C. = O(1)
}
int main(){
    vector<int>v1={2,6,5,8,14};
    vector<int>ans=twoSumApproach2(v1,14);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}