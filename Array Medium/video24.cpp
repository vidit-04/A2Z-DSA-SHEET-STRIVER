#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int>a){
    //Maximum Subarray Sum- Brute Force
    int maxSum=0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum=0;
        for (int j = i; j < a.size(); j++)
        {
            for (int k = i; k < j; k++)
            {
                sum+=a[j];
            }
                        
        }
        maxSum=max(maxSum,sum);
    }
    return maxSum;    
    //T.C.- O(n3)
    //S.C.- O(1)
}

int maximumSubarraySumApproach2(vector<int>a){
    //Maximum Subarray Sum- Better Solution
    int maxSum=0;
    for (int i = 0; i < a.size(); i++)
    {
        int sum=0;
        for (int j = i; j < a.size(); j++)
        {
            sum+=a[j];                       
        }
        maxSum=max(maxSum,sum);
    }
    return maxSum;    
    //T.C.- O(n2)
    //S.C.- O(1)
}

int maximumSubarraySumApproach3(vector<int>a){
    //Maximum Subarray Sum- KADANE's ALGORITHM BEST SOLUTION  
    int maxi = INT_MIN; // maximum sum
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {

        sum += a[i];

        if (sum > maxi) {
            maxi = sum;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}


int main(){
    vector<int>a={-2,-3,4,-1,-2,1,5,-3};
    cout<<maximumSubarraySumApproach3(a);
    return 0;
}