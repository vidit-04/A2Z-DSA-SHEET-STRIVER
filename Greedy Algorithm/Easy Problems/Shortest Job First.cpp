#include<bits/stdc++.h>
using namespace std;

int WaitingTImeInSJF(vector<int>a){
    int ans=0;
    sort(a.begin(),a.end());
    int time=0;
    for(int i=0;i<a.size();i++){
        ans+=time;
        time+=a[i];
    }
    return ans;
}

int main(){
    vector<int>a={4,3,7,1,2};
    cout<<WaitingTImeInSJF(a);
    return 0;
}