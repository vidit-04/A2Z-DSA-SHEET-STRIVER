#include<bits/stdc++.h>
using namespace std;

int countVowels(string s, int index){
    if(index==-1) return 0;

    if(s[index]=='a' || s[index]=='e' || s[index]=='i' || s[index]=='o' || s[index]=='u'){
        return 1+countVowels(s,index-1);        
    }
    else return countVowels(s,index-1);
}

int main(){
    string s="vidit";
    cout<<countVowels(s,5);
    return 0;
}