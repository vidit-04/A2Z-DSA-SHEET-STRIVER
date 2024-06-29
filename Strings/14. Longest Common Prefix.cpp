#include<bits/stdc++.h>
using namespace std;

string LongestCommonPrefix(vector<string>a){
    //BRUTE FORCE
    string ans="";
    for(int i=0;i<a[0].size();i++){
        char c=a[0][i];
        for(int j=1;j<a.size();j++){
            if(a[j].size()< i || a[j][i]!=c){
                return ans;
            }
        }
        ans+=c;
    }
    return ans; 
    //T.C.- O(n*m)
    //S.C.- O(1)
}
string LongestCommonPrefixApproach2(vector<string>strs){
    string ans="";
    for(int j=1,i=0;j<strs.size();j++,i++){
        char ch=strs[0][i];
        if(ch!=strs[j][i] || strs[j].size()<i) return ans;
        ans+=ch;
    }
    return ans;
}

int main(){
    vector<string>a={"flower","flower","flower","flower"};
    cout<<LongestCommonPrefix(a);
    return 0;
}