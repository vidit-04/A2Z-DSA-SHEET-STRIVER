#include<bits/stdc++.h>
using namespace std;



int main(){
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // int hash[13]={0};
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]+=1;
    // }

    // int q;
    // cin>>q;
    // while (q--)
    // {   
    //     int x;
    //     cin>>x;
    //     cout<<hash[x]<<endl;
    // }
    //Input:5
    // 1 3 2 1 3
    // 5
    // 1
    // 4
    // 3
    // 2
    // 12

    // CHARACTER HASHING
    // string s;
    // cin>>s;
    // int hash1[26]={0};
    // for(int i=0;i<s.size();i++){
    //     hash1[s[i]-'a']++;
    // }
    // int q;
    // cin>>q;
    // while (q--)
    // {
    //     char x;
    //     cin>>x;

    //     cout<<hash1[x-'a']<<endl;
    // }
    //INPUT:
    // abcdabehf
    // 5
    // a
    // g
    // h
    // b
    // c


    //Mapping for Hashing
    //Mapping stores in sorted manner   
    // int n;
    // cin>>n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }

    // map<int,int>mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     mpp[arr[i]]++; //T.C. -o(log n)
    // }
    
    // int q;
    // cin>>q;
    // while (q--)
    // {
    //     int x;
    //     cin>>x;
    //     cout<<mpp[x]<<endl;
    // }
    // for(auto it:mpp){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    // INPUT:
    // 7
    // 1 2 3 1 3 2 12
    // 5
    // 1
    // 2
    // 3
    // 4
    // 12

    // for character hashing
    // map<char,int>mpp1;


    //UNORDERED_MAP FOR HASHING

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    unordered_map<int,int>mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++; //T.C. -o(1) avg and best case. It may take O(n) time in worst case which we rarely face.
    }
    
    int q;
    cin>>q;
    while (q--)
    {
        int x;
        cin>>x;
        cout<<mpp[x]<<endl;
    }
    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    // INPUT:
    // 7
    // 1 2 3 1 3 2 12
    // 5
    // 1
    // 2
    // 3
    // 4
    // 12


    // UNORDERED MAP CAN TAKE ONLY SOME DATATYPES SUCH AS INT, DOUBLE, FLOAT, STRING, CHARACTER,ETC. AS KEYS . WHILE MAP ALLOWS YOU TO USE ANY DATA STRUCUTURE YOU WISH.
    return 0;
}