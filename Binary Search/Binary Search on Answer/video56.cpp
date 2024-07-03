#include<bits/stdc++.h>
using namespace std;

int maxOfArray(vector<int>a){
    int max=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]>max) max=a[i];
    }
    return max;
}
long long int time(vector<int>a,int i){
    long long int totalHours=0;
    for(int j=0;j<a.size();j++){
        totalHours+=ceil((double)a[j]/(double)i);
    }
    return totalHours;
}

int kokoEatingBanana(vector<int>a, int h){
    //BRUTE FORCE
    int reqTime=0;
    for(int i=1;i<=maxOfArray(a);i++){
        reqTime+=time(a,i);
        if(reqTime<=h) return i;
    }
    
}

int kokoEatingBananaApproach2(vector<int>a, int h){
    //Optimal using binary search
    int low=1;
    int high=maxOfArray(a);
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;
        long long int totalHrs=time(a,mid);
        if(totalHrs<=h){
            high=mid-1;
            ans=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low; //low also always points to answer
    // return ans;
    //T.C. - O(n)*O(logn) , n=size of a
    //S.C.-O(z1)
}

int main(){
    vector<int>a={3,6,7,11};
    int h=8;
    cout<<kokoEatingBananaApproach2(a,h);
    return 0;
}