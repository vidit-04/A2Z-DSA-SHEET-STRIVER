#include<bits/stdc++.h>
using namespace std;

int NumberofSubarraysWithSumK(vector<int>a,int t){
    //BRUTE FORCE
    int count=0;
    int sum=0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = i; k < j; k++)
            {
                sum+=a[k];
                if(sum==t){
                count++;
            }
            }
            
        }
        
    }
    return count;    
    //T.C. - O(N^3)
    //S.C. - O(1)
}

int NumberofSubarraysWithSumKApproach2(vector<int>a,int t){
    //Better Solution
    int count=0;
    int sum=0;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            sum+=a[j];
            if(sum==t){
                count++;
            }
        }
    }
    return count;    
    //T.C. - O(N^2)
    //S.C. - O(1)
}

int NumberofSubarraysWithSumKApproach3(vector<int>a,int t){
    //OPTIMAL SOLUTION
    //Store the sum and no. of times that sum occurs in map.
    unordered_map<int,int>mpp;
    mpp[0]=1;
    int sum=0;
    int count=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        int rem=sum-t;
        count+=mpp[rem];
        mpp[sum]+=1;
    }
    return count;
}

int main(){
    vector<int>a={1,2,3,-3,1,1,1,4,2,-3};
    cout<<NumberofSubarraysWithSumKApproach3(a,3);
    return 0;
}