#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>a,int n, int target){
    //BRUTE FORCE
    set<vector<int>>s;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            for (int k = j+1; k < n; k++){
                for (int l = k+1; l < n; l++){
                    long long sum=a[i]+a[j];
                    sum+=a[k]; // See the sum of i,j,k,l may exceeed int and to avoid that we took long long. ALso it is difficult to manage 4 addition and conversion to long long that's why we split it up.
                    sum+=a[l];
                    if(sum==target){
                        vector<int>temp={a[i],a[j],a[k],a[l]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
    }
    
    vector<vector<int>>ans(s.begin(),s.end());
    return ans;
    //T.C.- O(N^4)
    //S.C.- O(N)
}

vector<vector<int>> fourSumApproach2(vector<int>a,int n, int target){
    //Better Approach
    //HASHING
    set<vector<int>>st;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            set<long long> hashmap;
            for (int k = j+1; k < n; k++){
                long long sum=a[i]+a[j];
                sum+=a[k];
                int fourth=target-sum; 
                if(hashmap.find(fourth)!=hashmap.end()){
                    vector<int>temp={a[i],a[j],a[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashmap.insert(a[k]);
            }
        }
    }
    
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    //T.C.- O(N^3*log m)
    //S.C.- O(N)+ O(quads)2

}
vector<vector<int>> fourSumApproach3(vector<int>a,int n, int target){
    //Optimal Approach
    //Sorting
    // HEre we fix the place of i and j 
    sort(a.begin(),a.end());
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        for (int j = i+1; j < n; j++){
            if (j>i+1 && a[j]==a[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=a[i]+a[j];
                sum+=a[k];
                sum+=a[l];
                if(sum>target) l--;
                else if(sum<target) k++;
                else{
                    vector<int>temp={a[i],a[j],a[k],a[l]};
                    ans.push_back(temp);
                    while(k<l && a[k]==a[k+1]) k++;
                    while(k<l && a[l]==a[l-1]) l--;
                    k++;
                    l--;
                }
            }
        }   
    }
    return ans;
    //T.C.- O(N^2)
    //S.C.- O(1)
}

int main(){
    vector<int>a={1,2,-1,-2,2,0,-1};
    int n=a.size();
    int target=0;
    vector<vector<int>>ans=fourSumApproach2(a,n,target);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}