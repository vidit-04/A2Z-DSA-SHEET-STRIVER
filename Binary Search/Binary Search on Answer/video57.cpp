#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int>a,int day,int m,int k){
    // m=no.of bouquet required
    // k=flowers in a bouquet
    int n=a.size();
    int count=0;
    int possible_boquets=0;
    for(int i=0;i<n;i++){
        if(a[i]<=day) count++;
        else{
            possible_boquets+=count/k;
            count=0;
        }
    }
    possible_boquets+=count/k;
    return possible_boquets>=m;
}

int MinimumDaysToMakeMBouquets(vector<int>a,int no_of_boq, int flower_count){
    //BRUTE FORCE
    int n=a.size();
    if (no_of_boq*flower_count>n) return -1;
    int maxi=*max_element(a.begin(),a.end());
    int mini=*min_element(a.begin(),a.end());
    for(int i=mini;i<=maxi;i++){
        if(possible(a,i,no_of_boq,flower_count)){
            return i;
        }
    }
    return -1;
    //T.C.-O(maxi-mini+1)*O(n)
    //S.C.-O(1)
}
int MinimumDaysToMakeMBouquetsApproach2(vector<int>a,int no_of_boq, int flower_count){
    //Optimised
    //BINARY SEARCH
    int n=a.size();
    int val=no_of_boq*1LL*flower_count*1LL;
    if (val>n) return -1;
    int maxi=*max_element(a.begin(),a.end());
    int mini=*min_element(a.begin(),a.end());

    int low=mini;
    int high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        if(possible(a,mid,no_of_boq,flower_count)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int main(){
    // vector<int>a={7,7,7,7,13,11,12,7};
    vector<int>b={1,10,3,10,2};
    int no_of_boq=3;
    int flower_count=1;
    cout<<MinimumDaysToMakeMBouquetsApproach2(b,no_of_boq,flower_count);
    return 0;
}