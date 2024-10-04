#include<bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

bool cmp(job a, job b){
    return a.profit>b.profit;
}

pair<int,int> JobSequencingProblem(vector<job>a){
    sort(a.begin(),a.end(),cmp);
    int maxDeadline=-1,cnt=0,profit=0;
    for(int i=0;i<a.size();i++){
        maxDeadline=max(maxDeadline,a[i].deadline);
    }
    vector<int>slot(maxDeadline+1,-1);
    for(int i=0;i<a.size();i++){
        for(int j=a[i].deadline;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=a[i].id;
                cnt++;
                profit+=a[i].profit;
                break;
            }
        }
    }
    return {cnt,profit};
    //T.C.-O(n^2+n+nlogn)
    //S.C.-O(2*n)
}

int main(){
    vector<job>a={{
        {1,4,20},
        {2,5,60},
        {3,6,70},
        {4,6,65},
        {5,4,25},
        {6,2,80},
        {7,2,10},
        {8,2,22},
    }};
    pair<int,int> ans=JobSequencingProblem(a);
    cout<<ans.first<<" "<<ans.second;
    return 0;
}