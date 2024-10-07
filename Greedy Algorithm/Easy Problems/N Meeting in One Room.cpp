#include<bits/stdc++.h>
using namespace std;

struct Data{
    int start;
    int end;
    int pos;    
};

bool cmp(Data a,Data b){
    return a.end<b.end;
}

vector<int> NMeetinginOneRoom(vector<int>start,vector<int>end){
    vector<Data> a(start.size());
    for(int i=0;i<start.size();i++){
        a[i].start=start[i];
        a[i].end=end[i];
        a[i].pos=i+1;
    }
    sort(a.begin(),a.end(),cmp);
    int count=1;
    int freeTime=a[0].end;
    vector<int>ans;
    ans.push_back(a[0].pos);
    for(int i=1;i<a.size();i++){
        if(a[i].start>freeTime){
            count++;
            freeTime=a[i].end;
            ans.push_back(a[i].pos);
        }
    }
    return ans;
    //T.C.-O(nlogn+2n)
    //S.C.-O(3*n+n)
}

int main(){
    vector<int>start={0,3,1,5,5,8};
    vector<int>end={5,4,2,9,7,9};

    vector<int>ans=NMeetinginOneRoom(start,end);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}