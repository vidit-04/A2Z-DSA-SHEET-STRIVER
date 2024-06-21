#include<bits/stdc++.h>
using namespace std;

vector<int> MajorityElement(vector<int>a){
    //Element that occurs more than n/3 times
    //Brute Force
    //The ans will always be of size 2 bcs if any array of size ex-17 is there then 17/3=5. then every number must occur more than 5 times i.e. 6. So,6+6+6=18 while we have 17 elements. That's why we always have only 2 elements as answer.
    int count=0;
    vector<int>ans;
    for (int i = 0; i < a.size(); i++)
    {
        if(ans.size()==0 || ans[0]!=a[i]){
            for (int j = 0; j < a.size(); j++)
            {
                if (a[i]==a[j])  
                {
                    count++;
                }
            }
            if(count>a.size()/3){
                ans.push_back(a[i]);
            }
        }
        count=0;
        if (ans.size()==2)
        {
            break;
        }
        
    }
    return ans;
    //T.C.=O(n^2)
    //S.C.=O(1)
}

vector<int> MajorityElementApproach2(vector<int>a){
    //Better Approach
    //Hashing
    //We will take 2 variables and 2 counters
    //We will iterate through the array and check if the element is equal to the first element then we will increase the counter1 and if it is equal to the second element then we will increase the counter2
    //If the element is not equal to any of the elements then we will decrease the counter1 and counter2
    unordered_map<int,int>mpp;
    vector<int>ans;
    int n=(a.size()/3)+1;
    for(auto it:a){
        mpp[it]++;
        //By doing this we avoided the following for loop
        if(mpp[it]==n){  
            ans.push_back(it);
        }
    }
    //
    // for(auto it:mpp){
    //     if(it.second>a.size()/3){
    //         ans.push_back(it.first);
    //     }
    // }
    return ans;
    //T.C.=O(n)
    //S.C.=O(n)
}

vector<int> MajorityElementApproach3(vector<int>a){
    //Optimal Solution
    //MOORE VOTING ALGORITHM
    int count1=0;
    int count2=0;
    int ele1=INT_MIN;
    int ele2=INT_MIN;

    for(int i=0;i<a.size();i++){
        if(count1==0 && a[i]!=ele2){
            ele1=a[i];
        }
        else if(count2==0 && a[i]!=ele1){
            ele2=a[i];
        }
        else if(a[i]==ele1) count1++;
        else if(a[i]==ele2) count2++;
        else{
            count1--;
            count2--;
        }
    }  
    vector<int>ans;
    count1=0;
    count2=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==ele1) count1++;
        else if(a[i]==ele2) count2++;
    }
    if(count1>a.size()/3) ans.push_back(ele1); //manually checking needed when it is not  sure that whether majority element exist or not.
    if(count2>a.size()/3) ans.push_back(ele2);
    return ans;
}

int main(){
    vector<int>a={1,1,1,1,3,2,2,2};   
    vector<int>ans=MajorityElementApproach2(a);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}