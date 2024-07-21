#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n,int src, int help,int dest){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    TowerOfHanoi(n-1,src,dest,help);
    cout<<"Move "<<n<<" from "<<src<<" to "<<dest<<endl;
    TowerOfHanoi(n-1,help,src,dest);
}

int main(){ 
    TowerOfHanoi(3,1,2,3);
    return 0;
}