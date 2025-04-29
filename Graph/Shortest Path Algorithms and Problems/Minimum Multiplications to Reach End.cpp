#include<bits/stdc++.h>
using namespace std;

int MinSteps(vector<int> a,int start,int end){
    if(start==end) return 0;
    queue<pair<int,int>> q; //{node,steps}
    q.push({start,0});
    vector<int> dist(9999,1e9);
    dist[start]=0;
    int mod=1e5;
    while(!q.empty()){
        int node=q.front().first;
        int steps=q.front().second;
        q.pop();
        for(auto it: a){
            int num=(node*it)%mod;
            if(steps+1<dist[num]){
                dist[num]=steps+1;
                if(num==end) return steps+1;
                q.push({num,steps+1});
            }
        }
    }
    return -1;
    //T.C.- O(1e5)*O(n) where n is the size of the array
    //S.C.- O(1e5)
}

int main(){
    vector<int> a={2,5,7};
    int start=3;
    int end=60;
    cout<<MinSteps(a,start,end)<<endl;
    return 0;
}