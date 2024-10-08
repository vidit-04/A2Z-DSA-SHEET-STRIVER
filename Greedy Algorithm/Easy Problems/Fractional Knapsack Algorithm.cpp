#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>a,vector<int>b){
    double r1=(double)a[0]/a[1];
    double r2=(double)b[0]/b[1];
    return r1>r2;
}

int FractionalKnapsack(vector<vector<int>>a,int w){
    int n=a.size();
    sort(a.begin(),a.end(),cmp);
    int ans=0;
    for(int i=0;i<n;i++){
        if(w-a[i][1]>=0){
            ans+=a[i][0];
            w-=a[i][1];
        }
        else{
            ans+=w*((double)a[i][0]/a[i][1]);
            break;
        }
    }
    return ans;
    //T.C.-O(NlogN)
    //S.C.-O(1)
}

int main(){
    vector<vector<int>>a={{100,20},{60,10},{100,50},{200,50}};
    int w=90;
    cout<<FractionalKnapsack(a,w);
    return 0;
}