#include<bits/stdc++.h>
using namespace std;

int MinimumNumberOfFlipsToGetGoal(int start,int goal){
    int ans=start^goal;  //It is Up for those bits which are to be changed
    //We now just need to count 1s im ans
    int count=0;
    for(int i=0;i<31;i++){
        if(ans&(1<<i)){
            count++;
        }
    }
    return count;
}

int main(){
    int start;
    cin>>start;
    int goal;
    cin>>goal;
    cout<<MinimumNumberOfFlipsToGetGoal(start,goal);
    return 0;
}
