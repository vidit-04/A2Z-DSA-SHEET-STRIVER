#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int maxi=-1;
    int count=0;
    for(auto i:s){
        if(i=='(') count++;
        if(i==')') count--;
        maxi=max(maxi,count);
    }
    return maxi;
}

int main(){
    string s="(1+(2*3)+((8)/4))+1";
    cout<<maxDepth(s);    
    return 0;
}