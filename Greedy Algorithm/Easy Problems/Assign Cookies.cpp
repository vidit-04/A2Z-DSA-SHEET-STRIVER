#include<bits/stdc++.h>
using namespace std;

int AssignCookies(vector<int>children,vector<int>cookies){
    //GREEDY
    sort(children.begin(),children.end());
    sort(cookies.begin(),cookies.end());
    int i=0,j=0;
    while((i<children.size()) && (j<cookies.size())){
        if(children[i]<=cookies[j]){
            i++;
        }
        j++;
    }
    return i;
}

int main(){
    vector<int>children={1,5,3,3,4};
    vector<int>cookies={4,2,1,2,1,3};

    cout<<AssignCookies(children,cookies);
    return 0;
}