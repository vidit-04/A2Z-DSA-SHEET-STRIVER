#include<bits/stdc++.h>
using namespace std;

long long AvgWaitingTime(vector<int>bt){
    sort(bt.begin(),bt.end());
        long long t=0;
        long long wt=0;
        for(int i=0;i<bt.size();i++){
            wt+=t;
            t+=bt[i];
        }
        return wt/bt.size();
}

int main(){
    vector<int>a={4,3,7,1,2};
    cout<<AvgWaitingTime(a);
    return 0;
}