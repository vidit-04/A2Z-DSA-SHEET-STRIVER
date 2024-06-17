    #include<bits/stdc++.h>
using namespace std;

int findMissingNumber(vector<int>arr,int n,int k){
    //FIND MISSING NUMBER - BRUTE FORCE
    //LINEAR SEARCH 
    //WE DON'T HAVE REPEATING  NUMBERS HERE
    for (int i = 1; i <= k; i++)
    {
        int flag=0;
        for (int j = 0; j < n; j++)
        {
            if(arr[j]==i) {
                flag=1;
                break;
            }
        }
        if(flag==0) return i;        
    }
    return 0;
    //T.C.= O(n*k)
    //S.C.= O(1)    
}

int findMissingNumberApproach2(vector<int>arr,int n,int k){
    //FIND MISSING NUMBER - Approach 2 - Better Approach
    //HASHING

    int arr1[k+1]={0};
    for(int i=0;i<n;i++){
        arr1[arr[i]]++;
    }
    for(int i=1;i<k+1;i++){
        if(arr1[i]==0) return i;
    }
    return 0;
    //T.C.= O(2n)
    //S.C.= O(k+1)
} 
int findMissingNumberApproach3(vector<int>arr,int n,int k){
    //FIND MISSING NUMBER - Approach 3 - Better Approach
    //SUM OF FIRST K NATURAL NUMBERS
    int sum=(k*(k+1))/2;
    int sum2=0;
    for(int i=0;i<n;i++){
        sum2+=arr[i];
    }
    return sum-sum2;
    //T.C.= O(n)
    //S.C.= O(1)
} 

int findMissingNumberApproach4(vector<int>arr,int n,int k){
    //FIND MISSING NUMBER - Approach 4 - Best Approach
    //XOR
    int xor1=0,xor2=0;
    for(int i=0;i<n;i++){
        xor2=xor2^arr[i];
        xor1=xor1^i+1;
    }
        xor1=xor1^k;
    return xor1^xor2;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                 cnt++;
                maxi=max(cnt,maxi);
            }
            else cnt=0;

        }
        return maxi;
}

int findNumberThatAppearsOnce(vector<int>arr){
    //FIND NUMBER THAT APPEARS ONCE - BRUTE FORCE
    for(int i=0;i<arr.size();i++){
        int cnt=0;
        for(int j=0;j<arr.size();j++){
            if(arr[i]==arr[j]) cnt++;
        }
        if(cnt==1) return arr[i];
    }
    return 0;
    //T.C.= O(n^2)
    //S.C.= O(1)
}

int findNumberThatAppearsOnceApproach2(vector<int>arr){
    //FIND NUMBER THAT APPEARS ONCE - Better FORCE
    //HASHING
    unordered_map<long long,int>mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it:mpp){
        if(it.second==1) return it.first;
    }
    return 0;
    //T.C.= O(n)
    //S.C.= O(n)
}

int findNumberThatAppearsOnceApproach3(vector<int>arr){
    //FIND NUMBER THAT APPEARS ONCE - Best Approach
    //XOR
    int xor1=0;
    for(int i=0;i<arr.size();i++){
        xor1=xor1^arr[i];
    }
    return xor1;
}


int main(){
    vector<int>arr1={1,2,4,5};
    cout<<findMissingNumber(arr1,arr1.size(),5);
    cout<<endl;

    vector<int>arr2={1,2,4,5};
    cout<<findMissingNumberApproach2(arr2,arr2.size(),5);
    cout<<endl;

    vector<int>arr3={1,2,4,5};
    cout<<findMissingNumberApproach3(arr3,arr3.size(),5);
    cout<<endl;

    vector<int>arr4={1,2,3,5};
    cout<<findMissingNumberApproach4(arr4,arr4.size(),5);
    cout<<endl;

    vector<int>arr5={1,1,0,1,1,1,1};
    cout<<findMaxConsecutiveOnes(arr5);
    cout<<endl;

    vector<int>arr6={1,1,2,2,3,3,4,5,5};
    cout<<findNumberThatAppearsOnce(arr6);
    cout<<endl;

    vector<int>arr7={1,1,2,2,3,3,4,5,5};
    cout<<findNumberThatAppearsOnceApproach2(arr7);
    cout<<endl;

    vector<int>arr8={1,1,2,2,3,3,4,5,5};
    cout<<findNumberThatAppearsOnceApproach3(arr8);
    cout<<endl;
    return 0;
}