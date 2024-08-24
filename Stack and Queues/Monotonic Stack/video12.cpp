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

int main(){
    // Largest Rectangle In Histogram
    vector<int>a={3,2,10,11,5,10,6,3};
    cout<<LargestRectangleInHistogramApproach2(a);
    return 0;
}