#include<bits/stdc++.h>
using namespace std;

int SumOfArr(vector<int>a,int n,int index){
    if(index==n) return 0;
    return a[index]+SumOfArr(a,n,index+1);

}

int main(){
    vector<int>a={1,2,3,4,5};
    cout<<SumOfArr(a,a.size(),0);
    return 0;
}