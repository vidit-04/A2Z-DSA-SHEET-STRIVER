#include<bits/stdc++.h>
using namespace std;

int NumberofSubarrayswithxorK(vector<int>a,int n,int k){
    //BRUTE FORCE
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            //Calculate xor of subarray from i to j
            //If xor is equal to k then increment count
            int xor1=0;
            for (int k = i; k < j; k++){
                xor1=xor1^a[i];
            }
            if(xor1==k) count++;
        }
    }
    return count;
    //T.C. - O(N^3)
    //S.C. - O(1)
}

int NumberofSubarrayswithxorKApproach2(vector<int>a,int n,int k){
    //BETTER SOLUTION
    int count=0;
    for(int i=0;i<n;i++){
        int xor1=0;
        for(int j=i;j<n;j++){
            //Calculate xor of subarray from i to j
            //If xor is equal to k then increment count
            xor1=xor1^a[i];
            if(xor1==k) count++;
        }
    }
    return count;
    //T.C. - O(N^2)
    //S.C. - O(1)
}

int NumberofSubarrayswithxorKApproach3(vector<int>a,int n,int k){
    //OPTIMAL SOLUTION
    //HASHING
    int count=0;
    int xor1=0;
    map<int,int>mpp; // it takes the xor and then count of how many times we had the same xor
    mpp[xor1]++;
    for(int i=0;i<n;i++){
        xor1=xor1^a[i];
        int x=xor1^k;   // IT CONSIDERS THAT XOR1 it takes k from XOR1 and FINDS THE FIRST(remaining) ELEMENT
        count+=mpp[x];
        mpp[xor1]++;
    }
    return count;
    //T.C. - O(N)*(O(logn )(for map)*O(1)-O(n)  for unordered map)
    //S.C. - O(N)
}

int main(){
    
    return 0;
}