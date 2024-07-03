#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(vector<int>a){
    //Sum of three numbers should be zero
    //BRUTE FORCE
    int n=a.size();
    set<vector<int>>s;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(a[i]+a[j]+a[k]==0){
                    vector<int>temp={a[i],a[j],a[k]};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    vector<vector<int>>ans(s.begin(),s.end());
    return ans;
}

vector<vector<int>> tripletApproach2(vector<int>a){
    //Better Approach
    //HASHING
    int n=a.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashmap;
        for(int j=i+1;j<n;j++){
            int third=-(a[i]+a[j]);
            if(hashmap.find(third)!=hashmap.end()){
                vector<int>temp={a[i],a[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashmap.insert(a[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    //T.C.=O(n^2)
    //S.C.=O(n)
}

vector<vector<int>> tripletApproach3(vector<int>a){
    //Optimal Approach
    //Sorting
    sort(a.begin(),a.end());
    int n=a.size();
    vector<vector<int>>ans;
    //Here we fix the place of i 
    for(int i=0;i<n;i++){
        if(i>0 && a[i-1]==a[i]) continue;
        int j=i+1;
        int k=n-1;
        while(j<k){
            int sum=a[i]+a[j]+a[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                vector<int>temp={a[i],a[j],a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j-1]==a[j]) j++;
                while(j<k && a[k+1]==a[k]) k--;
            }
        }
    }
    return ans;
    //T.C.=O(n^2)
    //S.C.=O(1)
}

int main(){
    vector<int>a={-1,0,1,2-1,-4};
    vector<vector<int>>ans=tripletApproach3(a);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}