#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>> matrix(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]) matrix[i][j]=1+matrix[i-1][j-1];
            else matrix[i][j]=max(matrix[i-1][j],matrix[i][j-1]);
        }
    }
    int i=n,j=m;
    string ans="";
    while(i>0 && j>0){
        if(str1[i-1]!=str2[j-1]){
            if(matrix[i-1][j] > matrix[i][j-1]){
                ans=str1[i-1]+ans;
                i--;
            } 
            else{
                ans=str2[j-1]+ans;
                j--;
            }
        }
        else{
            ans=str1[i-1]+ans;
            i--;
            j--;
        }
    }
    while(i>0){
        ans=str1[i-1]+ans;
        i--;
    }
    while(j>0){
        ans=str2[j-1]+ans;
        j--;
    }
    return ans;
}

int main(){
    string str1="abac",str2="cab";
    cout<<shortestCommonSupersequence(str1,str2)<<endl; //cabac   
    return 0;
}