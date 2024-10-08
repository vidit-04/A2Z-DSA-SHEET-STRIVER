#include<bits/stdc++.h>
using namespace std;

int Candy(vector<int>a){
    //BRUTE FORCE
    //First take left side in consideration and get the answer
    //Then take right side in consideration and get the answer
    //Then take maximum of both and add them
    int n=a.size();
    vector<int>left(n);
    vector<int>right(n);
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            left[i]=left[i-1]+1;
        }
        else{
            left[i]=1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1]){
            right[i]=right[i+1]+1;
        }
        else{
            right[i]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(left[i],right[i]);
    }
    return ans;
    //T.C.-O(3N)
    //S.C.-O(2N)
}

int CandyApproach2(vector<int>a){
    //BETTER SOLUTION
    //First take left side in consideration and get the answer
    //Then take right side in consideration and get the answer
    //Then take maximum of both and add them
    int n=a.size();
    vector<int>left(n);
    left[0]=1;
    for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            left[i]=left[i-1]+1;
        }
        else{
            left[i]=1;
        }
    }

    int ans=max(1,left[n-1]);
    int right=1;
    int curr=1;
    for(int i=n-2;i>=0;i--){
        if(a[i]>a[i+1]){
            curr=right+1;
            right=curr;
        }
        else{
            curr=1;
            right=1;
        }
        ans+=max(left[i],curr);
    }
    return ans;
    //T.C.-O(3N)
    //S.C.-O(2N)
}

int CandyApproach3(vector<int>a){
    //SLOPE APPROACH 
    //OPTIMAL APPROACH
    int sum=1;
    int i=1;
    int n=a.size();
    while(i<n){
        if(a[i]==a[i-1]){
            sum+=1;
            i++;
            continue;
        }
        int peak=1;
        while(i<n && a[i]>a[i-1]){
            peak++;
            sum+=peak;
            i++;
        }
        int down=1;
        while(i<n && a[i]<a[i-1]){
            sum+=down;
            down++;
            i++;
        }
        if(down>peak){
            sum+=down-peak;
        }
    }
    return sum;
    //T.C.-O(N)
    //S.C.-O(1)
}

int main(){
    vector<int>ratings={0,2,4,3,2,1,1,3,5,6,4,0,0};
    cout<<CandyApproach3(ratings);
    return 0;
}