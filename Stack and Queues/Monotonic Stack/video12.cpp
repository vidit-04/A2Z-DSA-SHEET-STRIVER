#include<bits/stdc++.h>
using namespace std;

vector<int> findPSE(vector<int>a){
    int n=a.size();
    vector<int>ans(n);
    stack<int>s;
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(!s.empty()){
            ans[i]=s.top();
        }
        else{
            ans[i]=-1;
        }
        s.push(i);
    }
    return ans;
}

vector<int> findNSE(vector<int>a){
    int n=a.size();
    stack<int>s;
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && a[s.top()]>=a[i]){
            s.pop();
        }
        if(s.empty()) ans[i]=n;
        else ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int LargestRectangleInHistogram(vector<int> a){
    //BRUTE FORCE
    vector<int> pse=findPSE(a);
    vector<int> nse=findNSE(a);
    int maxArea=0;
    for(int i=0;i<a.size();i++){
        maxArea=max(maxArea,a[i]*(nse[i]-pse[i]-1));
    }
    return maxArea;
    // T.C.-O(5N)
    // S.C.-O(4N)
}

int main(){
    // Largest Rectangle In Histogram
    vector<int>a={2,1,5,6,2,3};
    cout<<LargestRectangleInHistogram(a);
    return 0;
}