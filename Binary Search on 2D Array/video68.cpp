#include<bits/stdc++.h>
using namespace std;


int RowWithMaximumOnes(vector<vector<int>>a){
    //Return index of row with maximum ones's
    //BRUTE FORCE
    int maxcnt=-1,index=-1;
    for(int i=0;i<a.size();i++){
        int cntrow=0; //Counts no. of 1's in row
        for(int j=0;j<a[i].size();j++){
            cntrow+=a[i][j];
        }
        if(cntrow>maxcnt){
            maxcnt=cntrow;
            index=i;
        }
    }
    return index;
    //T.C.-O(n*m)
    //S.C.-O(1)
}

int lowerBound(vector<int>a){
    //OR u can count upper bound of zero
    //First Occurence of 1
    int low=0;
    int high=a.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==1){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;  // Number of 1's
}

int RowWithMaximumOnesApproach2(vector<vector<int>>a){
    //Return index of row with maximum ones's
    //Binary Search
    int maxcnt=0; //KEEP COUNT AS 0 bcs if consider there is no 1 in row then it would be like lowerbound is hypothetical index- a[i].size() that's why
    int index=-1;
    for(int i=0;i<a.size();i++){
        int cntrow=0; //Counts no. of 1's in row
        cntrow=a[i].size()-lowerBound(a[i]);
        if(cntrow>maxcnt){
            maxcnt=cntrow;
            index=i;
        }
    }
    return index;
    //T.C.-O(nlogm)
    //S.C.-O(1)
}

int main(){
    // Row With Maximum 1's 
    vector<vector<int>>a={{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
    cout<<RowWithMaximumOnesApproach2(a)<<endl;
    return 0;
}