#include<bits/stdc++.h>
using namespace std;

bool valid(string s, int index,int counter){
    if(counter < 0) return 0;
    if(index == s.size()){
        return counter == 0;
    }
    if(s[index]=='('){
        return valid(s,index+1,counter+1);
    }
    if(s[index]==')'){
        return valid(s,index+1,counter-1);
    }
    return valid(s,index+1,counter+1) || valid(s,index+1,counter-1) || valid(s,index+1,counter);
    //either at star we can have '(',i.e.,counter+1, ')',i.e.counter-1,*,i.e.nothing just star 
    //T.C.-O(3^n)
    //S.C.-O(N) 
}

int main(){
    string s="(*()";
    int n=s.size();
    cout<<valid(s,0,0);   //string,index,counter
    return 0;
}