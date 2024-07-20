#include<bits/stdc++.h>
using namespace std;

void permutations(vector<int>a,vector<vector<int>> &ans,vector<int> &temp,vector<int> &visited){
    if(temp.size()==a.size()){
        ans.push_back(temp);
        return;
    }
    
    for(int i=0;i<a.size();i++){
        if(visited[i]==0){
            visited[i]=1;
            temp.push_back(a[i]);
            permutations(a,ans,temp,visited);
            temp.pop_back();
            visited[i]=0;
        }
    }
}

int main(){
    vector<int>a={1,2,3};
    vector<vector<int>>ans;
    vector<int>temp;
    vector<int>visited(a.size(),0);

    permutations(a,ans,temp,visited);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}