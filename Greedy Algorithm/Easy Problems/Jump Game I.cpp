#include<bits/stdc++.h>
using namespace std;

bool JumpingGame1(vector<int>a){
    int MaxIndex=0;
    int i=0;
    do{
        MaxIndex+=a[i];
        if(MaxIndex>=a.size()){
            return true;
        }   
        i++;
    }while (i<=MaxIndex);
    return false;
    //TIME COMPLEXITY
    //O(N)
    //SPACE COMPLEXITY
    //O(1)
}

int main(){
    // vector<int>a={1,2,3,1,1,0,2,5};
    vector<int>a={1,2,4,1,1,0,2,5};
    cout<<JumpingGame1(a);
    return 0;
}