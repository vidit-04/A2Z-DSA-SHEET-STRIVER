#include<bits/stdc++.h>
using namespace std;

int CelebrityProblem(vector<vector<int>>a){
    int n = a.size();
    vector<int> knowMe(n);
    vector<int> Iknow(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1){
                knowMe[i]++;
                Iknow[j]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(knowMe[i]==0 && Iknow[i]==n-1){
            return i;
        }
    }
    return -1;
    // T.C.-O(N^2)+O(N)
    // S.C.-O(2N)
}
int CelebrityProblemApproach2(vector<vector<int>>a){
    int n = a.size();
    int top=0;
    int down=n-1;
    while(top<down){
        if(a[top][down]==1){
            top++;
        }
        else if(a[down][top]==1){
            down--;
        }
        else{
            top++;
            down--;
        }
    }
    if(top>down) return -1;  // So now top==down
    for(int i=0;i<n;i++){
        if(a[top][i]==0 && a[i][top]==1){
            continue;
        }
        else if(i==top) continue;
        else{
            return -1;
        }
    }
    return top;
    // T.C.-O(2N)
    // S.C.-O(1)
}

int main(){
    //CELEBRITY PROBLEM
    vector<vector<int>> a={{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
    cout<<CelebrityProblemApproach2(a);
    return 0;
}