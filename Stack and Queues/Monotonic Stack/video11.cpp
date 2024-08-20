#include<bits/stdc++.h>
using namespace std;

vector<int> AsteroidCollision(vector<int>a){
    //BRUTE FORCE
    list<int>s;
    for(int i=0;i<a.size();i++){
        if(a[i]>0){
            s.push_back(a[i]);
        }
        else{
            while(!s.empty() && s.back()>0 && abs(a[i])>s.back()){
                s.pop_back();
            }
            if(!s.empty() && abs(a[i])==s.back()){
                s.pop_back();
            }
            else if(s.empty() || s.back()<0){
                s.push_back(a[i]);
            }
        }
    }
    vector<int>ans(s.begin(),s.end());
    return ans;
    //T.C.-O(2N)
    //S.C.-O(N)
}

int main(){
    //ASTEROID COLLISION
    vector<int>a={4,7,1,1,2,-3,-7,17,15,-16};
    vector<int>ans=AsteroidCollision(a);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}