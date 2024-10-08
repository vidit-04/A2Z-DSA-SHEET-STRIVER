#include<bits/stdc++.h>
using namespace std;

int MinimumNumberOfPlatforms(vector<int>arr,vector<int>dep){
    //BRUTE FORCE
    //IF just find the number of intersection then we can also find number of minimum numer of platform required
    int maxCount=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[j]<=arr[i] && arr[i]<=dep[j]){
                count++;
            }
        }
        maxCount=max(maxCount,count);
    }
    return maxCount;
    //T.C.-O(n^2)
    //S.C.-O(1)
}

int MinimumNumberOfPlatformsApproach2(vector<int>arr,vector<int>dep){
    //OPTIMAL APPROACH
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int n=arr.size();
    int i=0,j=0;
    int count=0;
    int maxCount=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            count++;
            i++;
        }
        else{
            count--;
            j++;
        }
        maxCount=max(maxCount,count);
    }
    return maxCount;
    //T.C.-O(2n+2nlogn)
    //S.C.-O(1)
}

int main(){
    vector<int>arr={900,945,955,1100,1500,1800};
    vector<int>dep={920,1200,1130,1150,1900,2000};
    cout<<MinimumNumberOfPlatforms(arr,dep);
    return 0;
}