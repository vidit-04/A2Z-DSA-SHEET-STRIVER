#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s,string goal){
    for(int i=1;i<=s.size();i++){
        string str=s;
        reverse(str.begin(),str.begin()+i);
        reverse(str.begin()+i,str.end());
        reverse(str.begin(),str.end());
        cout<<str<<endl;
        if(str==goal) return 1;
    }
    return 0;
}

int main(){
    string s="abcde";
    string goal="cdeab";
    
    cout<<rotateString(s,goal);
    return 0;
}