#include<bits/stdc++.h>
using namespace std;

void FindMissingAndRepeatingNumber(vector<int>a, int n){
    //BRUTE FORCE
    //n= 6 means the array should have numbers 1 to 6
    int repeating=-1;
    int missing=-1;
    for(int i=1;i<=n;i++){
        int count=0;
        for(int j=0;j<a.size();j++){
            if(a[j]==i){
                count++;
            }
        }
        if(count==0){
            missing=i;
        }
        if(count==2){
            repeating=i;
        }
    }
    cout<<repeating<<" "<<missing<<endl;
    //T.C. - O(n^2)
    //S.C. - O(1)
}

void FindMissingAndRepeatingNumberApproach2(vector<int>a, int n){
    //Better SOlution
    //HASHING
    int repeating=-1;
    int missing=-1;
    vector<int>hasharr(n+1); //it stores element and number of times it comes into array
    for(int i=0;i<a.size();i++){
        hasharr[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(hasharr[i]==0){
            missing=i;
        }
        else if(hasharr[i]==2){
            repeating=i;
        }
    }
    cout<<repeating<<" "<<missing<<endl;
    //T.C. - O(2n)
    //S.C. - O(n)
}
vector<int> FindMissingAndRepeatingNumberApproach3(vector<int>a, int n){
    //Optimal SOlution
    //MAthematical way-- Refer to Notes
    long long n=a.size();
    //S- Sn = x-y
    //S2-S2n
    long long Sn=(n*(n+1))/2;
    long long S2n=(n*(n+1)*(2*n+1))/6;
    long long S=0,S2=0;
    for(int i=0;i<n;i++){
        S+=a[i];
        S2+=(long long)a[i]*(long long)a[i];
    }
    long long val1=S-Sn; //(x-y)
    long long val2=(S2-S2n);  //x^2-y^2=(x-y)(x+y)
    val2=val2/val1;  //(x+y)
    long long x=(val1+val2)/2;
    long long y=val2-x;
    cout<<x<<" "<<y<<endl;
    return {(int)x,(int)y};
    //T.C. - O(n)
    //S.C. - O(1)
}

vector<int> FindMissingAndRepeatingNumberApproach4(vector<int>a, int n){
    //Optimal Solution
    //XOR
    //REPEATING NUMBERS MAKE IT DIFFICULT AS COMPARED TO LAST SOLUTION HAD PREVIOUSLY
    long long n=a.size();
    int xr=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];
        xr=xr^(i+1);
    }
    //Refer to Notes
    int bitNo=0;
    while (1){
        if(xr & (1<<bitNo)) break;
        bitNo++;
    }
    int zero=0;
    int one=0;
    for (int i = 0; i < n; i++){
        //part of 1 club
        if(a[i] & (1<<bitNo)!=0){
            one=one^a[i];
        }
        //part of 0 club
        else{
            zero=zero^a[i];
        }
    }

    for (int i = 0; i < n; i++){
        //part of 1 club
        if(i & (1<<bitNo)!=0){
            one=one^a[i];
        }
        //part of 0 club
        else{
            zero=zero^a[i];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]==zero) cnt++;
    }
    if(cnt==2) return {zero,one};
    return {one,zero};
    //T.C. - O(n)
    //S.C. - O(1)    
}
int main(){
    vector<int>a={};
    return 0;
}