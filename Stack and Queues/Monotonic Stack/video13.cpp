#include<bits/stdc++.h>
using namespace std;

int LargestRectangleInHistogramApproach2(vector<int> a){
    //OPTIMAL APPROACH
    stack<int>s;
    int maxArea=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>a[i]){
            int ele=s.top();
            s.pop();
            int nse=i;
            int pse=s.empty()?-1:s.top();
            maxArea=max(a[ele]*(nse-pse-1),maxArea);
        }
        s.push(i);
    }
    while(!s.empty()){
        int ele=s.top();
        s.pop();
        int nse=n;
        int pse=s.empty()?-1:s.top();
        maxArea=max(a[ele]*(nse-pse-1),maxArea);
    } 
    return maxArea;
    // T.C.-O(2N)
    // S.C.-O(N)
}

int MaximalRectangle(vector<vector<int>>a,int n,int m){
    int maxArea=0;
    vector<vector<int>>pSum(n, vector<int>(m, 0));
    for(int j=0;j<m;j++){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i][j];
            if(a[i][j]==0){
                sum=0;
            }
            pSum[i][j]=sum;
        }
    }
    for(int i=0;i<n;i++){
        maxArea=max(maxArea,LargestRectangleInHistogramApproach2(pSum[i]));
    }
    return maxArea;
    // T.C.-O(N*M)+O(N*2M)
    // S.C.-O(N*M) +O(N)
}

int main(){
    //MAXIMAL RECTANGLE
    vector<vector<int>>a={{1,0,1,0,1},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    int n=a.size();
    int m=a[0].size();
    cout<<MaximalRectangle(a,n,m);
    return 0;
}