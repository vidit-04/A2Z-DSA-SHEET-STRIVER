#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &a,int i,int j){
    if(i>=j) return;
    swap(a[i],a[j]);
    reverseArray(a,i+1,j-1);
}

void reverseArrayPart2(vector<int> &a,int i){
    if(i>=a.size()/2) return;
    int j=a.size()-i-1;
    swap(a[i],a[j]);
    reverseArrayPart2(a,i+1);
}

bool checkpalindrome(string s,int i,int n){
    if(i>n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    return checkpalindrome(s,i+1,n);
}

int main(){
    // vector<int>a={1,2,3,4,5};
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }
    // // reverseArray(a,0,a.size()-1);
    // reverseArrayPart2(a,0);
    // cout<<endl;
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }

    string s="madam";
    cout<<checkpalindrome(s,0,s.length());
    return 0;
}