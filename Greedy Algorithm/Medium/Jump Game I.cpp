#include<bits/stdc++.h>
using namespace std;

bool JumpingGame1(vector<int>a){
    int MaxIndex=0;
    int maxIndex=0;
        for(int i=0;i<a.size();i++){
            if(i>maxIndex) return 0;
            maxIndex=max(maxIndex,i+a[i]);
        }
        return 1;
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
