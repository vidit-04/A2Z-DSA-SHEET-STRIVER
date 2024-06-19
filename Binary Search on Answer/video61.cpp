#include<bits/stdc++.h>
using namespace std;

bool canweplace(vector<int>a,int cows,int dist){
    int cntCows=1;
    int last=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]-last>=dist){
            cntCows++;
            last=a[i];
        }
    }
    return cntCows>=cows;  //This is just checking if we can place cows. The cnt of cows will be more if there is more space available
}

int AggresiveCows(vector<int>a,int cows){
    //minimum distance between cows is max--means to arrange cows in different cofiguration and in each you will find a minimum distance. Out of all configuration find the max minimum distance
    //BRUTE FORCE
    sort(a.begin(),a.end());
    int n=a.size();
    
    for(int i=1;i<(a[n-1]-a[0]);i++){
        if(canweplace(a,cows,i)){
            continue;
        }
        else{
            return  i-1;
        }
    }
    //T.C.-O(max-min)*(n)
    //S.C.-O(1)
}

int AggresiveCowsApproach2(vector<int>a,int cows){
    sort(a.begin(),a.end());
    int n=a.size();

    int low=1;
    // int high=a[n-1]-a[0];
    int ans=0;
    int high = a.back() - a.front(); // More clear than a[n-1] - a[0]
    while(low<=high){
        int mid=(low+high)/2;
        if(canweplace(a,cows,mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;//ans
    //T.C.-O(log(max-min)*(n)
    //S.C.-O(1)
}

int main(){
    vector<int>a={0,3,4,7,10,9};
    int cows=4;
    cout<<AggresiveCowsApproach2(a,cows);
    return 0;
}