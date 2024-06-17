#include<bits/stdc++.h>
using namespace std;
int addDigits(int num) {
    //LEETCODE 
        if(num<10) return num;
        int sum=0;
        while(num>0){
            int digit=num%10;
            sum+=digit;
            num/=10;
        }
        // cout<<sum<<endl
        return addDigits(sum);
}

void leftRotateByOne(int arr[],int n){
    //Left Rotate by One -BRUTE FORCE 1
    for(int i=0;i<n-1;i++){
        swap(arr[i],arr[i+1]);
    }
}

void leftRotateByOneApproach2(int arr[],int n){
    //Left Rotate by One - Approach 2 
    int temp=arr[0];
    for(int i=0;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}

void leftRotateByDsteps(int arr[],int n,int d){
    //Left Rotate by D steps - BRUTE FORCE
    d=d%n;
    vector<int>temp;

    //Creating a copy of those elements which are to be shifted
    for(int i=0;i<d;i++){
        temp.push_back(arr[i]);
    }

    //Shifting those elements towards left
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }

    //Placing elements back to last positions
    for(int i=n-d;i<n;i++){
        arr[i]=temp[i-(n-d)];
    }

    //T.C. - d+n-d+d = O(n+d)
    //S.C. - O(d)
}

void leftRotateByDstepsApproach2(int arr[],int n,int d){
    //Left Rotate by D steps - Approach 2 - OPTIMAL APPROACH

    d=d%n;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverse(arr,arr+d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    
    reverse(arr+d,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverse(arr,arr+n);    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //T.C. - O(n)
    //S.C. - O(1)
}
void rightRotateByDsteps(vector<int> nums,int n,int d){
    //Left Rotate by D steps - OPTIMAL APPROACH
        d=d%nums.size();
        reverse(nums.begin(),nums.end()-d);
        reverse(nums.end()-d,nums.end());
        reverse(nums.begin(),nums.end());
    //T.C. - O(n)
    //S.C. - O(1)
}



void moveZeroesApproach2(vector<int>& nums) {
    //MOVE ZEROES TO END - BRUTE FORCE
    vector<int>temp;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=0){
            temp.push_back(nums[i]);
        }
    }

    for(int i=0;i<temp.size();i++){
        nums[i]=temp[i];
    }

    for(int i=temp.size();i<nums.size();i++){
        nums[i]=0;
    }
}

void moveZeroes(vector<int>& nums) {
    int j=-1;
    //MOVE ZEROES TO END - BEST APPROACH
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<nums.size();i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
}

void unionOfArrays(vector<int>arr1,vector<int>arr2){
    //UNION OF TWO ARRAYS - BRUTE FORCE
    set<int>s;
    for(int i=0;i<arr1.size();i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<arr2.size();i++){
        s.insert(arr2[i]);
    }

    vector<int>unionArr;
    for (auto it: s){
        unionArr.push_back(it);
    }
    for(auto it: unionArr){
        cout<<it<<" ";
    }
    
}

void unionOfArraysApproach2(vector<int>arr1,vector<int>arr2){
    //UNION OF TWO ARRAYS - Best Approach
    int i=0,j=0;
    vector<int>unionArr;
    while(i<arr1.size() && j<arr2.size()){
        if (arr1[i]<=arr2[j]){
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
                unionArr.push_back(arr1[i]);
            }
                i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
                unionArr.push_back(arr2[j]);
            }
                j++;
        }
    }
    while(i<arr1.size()){
        if(unionArr.size()==0 || unionArr.back()!=arr1[i]){
            unionArr.push_back(arr1[i]);
        }
            i++;
    }
    while(j<arr2.size()){
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]){
            unionArr.push_back(arr2[j]);
        }
            j++;
    }

    for(int i=0;i<unionArr.size();i++){
        cout<<unionArr[i]<<" ";
    }
}

void intersectionOfArrays(vector<int>arr1,vector<int>arr2){
    //INTERSECTION OF TWO ARRAYS - BRUTE FORCE
    vector<int>visit(arr2.size(),0);
    vector<int>intersectionArr;

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if(arr1[i]==arr2[j] && visit[j]==0){
                intersectionArr.push_back(arr2[j]);
                visit[j]=1;
                break;
            }
            else if (arr2[j]>arr1[i])
            {
                break;
            }
            
        }
        
    }
    for (int i = 0; i < intersectionArr.size(); i++)
    {
        cout<<intersectionArr[i]<<" ";
    }
    // T.C. - O(n1*n2)
    // S.C. - O(n2)
    
}

void intersectionOfArraysApproach2(vector<int>a,vector<int>b){
    //INTERSECTION OF TWO ARRAYS - BEST APPROACH
    int i=0,j=0;
    vector<int>ans;
    while(i<a.size() && j<b.size()){
        if(a[i]==b[j]){
            ans.push_back(b[j]);
            i++;
            j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else{
            j++;
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    // T.C. - O(n1+n2)
    // S.C. - O(1)
}

int main(){
    // cout<<addDigits(761)<<endl;

    // int arr[]={1,2,3,4,5};
    // leftRotateByOne(arr,5);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // int arr2[]={1,2,3,4,5,6,7};
    // int d;
    // cin>>d;
    // leftRotateByDsteps(arr2,7,d);
    // for(int i=0;i<7;i++){
    //     cout<<arr2[i]<<" ";
    // }
    // cout<<endl;

    // leftRotateByDstepsApproach2(arr2,7,d);

    // vector<int>arr3={1,0,2,3,2,0,0,4,5,1};
    // moveZeroesApproach2(arr3);
    // for(int i=0;i<arr3.size();i++){
    //     cout<<arr3[i]<<" ";
    // }
    // cout<<endl;

    // int arr[]={1,2,3,4,5};
    // leftRotateByOne(arr,5);
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // int arr2[]={1,2,3,4,5,6,7};
    // int d;
    // cin>>d;
    // leftRotateByDsteps(arr2,7,d);
    // for(int i=0;i<7;i++){
    //     cout<<arr2[i]<<" ";
    // }
    // cout<<endl;

    // leftRotateByDstepsApproach2(arr2,7,d);

    // vector<int>arr3={1,0,2,3,2,0,0,4,5,1};
    // moveZeroesApproach2(arr3);
    // for(int i=0;i<arr3.size();i++){
    //     cout<<arr3[i]<<" ";
    // }
    // cout<<endl;

    // vector<int>arr4={1,1,2,3,4,5,9};
    // vector<int>arr5={2,3,4,4,5,6,7};
    // unionOfArraysApproach2(arr4,arr5);

    vector<int>arr6={1,2,2,3,3,4,5,6,9};
    vector<int>arr7={2,3,3,5,6,6,7,9    };
    intersectionOfArraysApproach2(arr6,arr7);
    return 0;
}