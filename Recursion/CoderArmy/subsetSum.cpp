#include<bits/stdc++.h>
using namespace std;

// int subsetSum(vector<int>temp, int index){
//     if(index<0) return 0;
//     return temp[index]+subsetSum(temp,index-1);
// }

// void subsequence(vector<int>a,int n,vector<int> &ans,vector<int> &temp,int index){
//     BRUTE FORCE
//     if(index==n){
//         ans.push_back(subsetSum(temp,temp.size()-1));
//         // ans.push_back(temp);
//         return;
//     }
//     //Not Included
//     subsequence(a,n,ans,temp,index+1);
//     //Included
//     temp.push_back(a[index]);
//     subsequence(a,n,ans,temp,index+1);
//     temp.pop_back();
//     //TIME AND SPACE COMPLEXTY
//     //TIME: O(2^n)
//     //SPACE: O(2^n)

// }


void subsequence(vector<int>a,int n,vector<int> &ans,int index,int sum){
    // BRUTE FORCE
    if(index==n){
        ans.push_back(sum);  
        return;
    }
    //Not Included
    subsequence(a,n,ans,index+1,sum);
    //Included
    sum+=a[index];
    subsequence(a,n,ans,index+1,sum);
    sum-=a[index];
    //TIME AND SPACE COMPLEXTY
    //TIME: O(2^n)
    //SPACE: O(2^n)

}

int main(){
    vector<int>a={3,4,5};    
    vector<int>ans;
    vector<int>temp;
    int n=a.size();
    int sum=0;
    subsequence(a,n,ans,0,sum);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}