#include<bits/stdc++.h>
using namespace std;

vector<int> LeadersInArray(vector<int>a){
    //Every Number at right is smaller than leader-- BRUTE FORCE
    int ele=0;
    vector<int>ans;
    for (int i = 0; i < a.size()-1; i++)
    {
        int ele=a[i];
        int flag=0;
        for(int j=i+1;j<a.size();j++){
            if (a[j]>ele)
            {
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans.push_back(ele);
        }
    }
    ans.push_back(a[a.size()-1]);
    return ans;
    //T.C. - O(n^2)
    // S.C. - O(n)
}

vector<int> LeadersInArrayApproach2(vector<int>a){
    //Every Number at right is smaller than leader-- BEST APPROACH
    //ITERATE IN REVERSE ORDER AND MAINTAIN THE MAXIMUM IN RIGHT
    vector<int>ans;
    int maxi=INT_MIN;
    for (int i = a.size()-1; i > 0 ; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
            maxi=a[i];
        }
    }
    //IF THEY ASK TO RETURN LEADERS IN SORTED MANNER THAN SORT THE ANS ARRAY  ---> O(N LOG N)

    //T.C. - O(N)
    // S.C. - O(N)
    return ans;    
}

int main(){
    vector<int>a={10,22,12,3,0,6};
    vector<int>ans=LeadersInArrayApproach2(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}