#include<bits/stdc++.h>
using namespace std;

void MergeSortedArraysWithExtraSpace(vector<int> &a,vector<int> &b){
    //BRUTE FORCE
    //Extra Space
    vector<int>c(a.size()+b.size());
    int n=a.size();
    int m=b.size();
    int i=0,j=0;
    while (i<n && j<m)
    {
        if(a[i]<=b[j]){
            c.push_back(a[i]);
            i++;
        }
        else{
            c.push_back(b[j]);
            j++;
        }
    }
    while(i<n){
        c.push_back(a[i]);
        i++;
    }
    while(j<m){
        c.push_back(b[j]);
        j++;
    }
    for (int i = 0; i < c.size(); i++){
        if(i<n){
            a[i]=c[i];
        }
        else{
            b[i-n]=c[i];
        }
    }
    //T.C. - O(n+m)+O(n+m)    
    //S.C. - O(n+m)
}

void MergeSortedArraysWithoutExtraSpace(vector<int> &a,vector<int> &b){
    //OPTIMAL SOLUTION -1
    int n=a.size();
    int m=b.size();
    int left=n-1;
    int right=0;

    while(a[left]>b[right] && left>=0 && right<m ){
        swap(a[left],b[right]);
        left--;
        right++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    //T.C. - O(nlogn)+O(mlogm)+O(min(n,m))
    //S.C. - O(1)
}

void swapIfGreater(vector<int> &a,vector<int> &b,int left,int right){
    if(a[left]>b[right]){
        swap(a[left],b[right]);
    }
}

void MergeSortedArraysWithoutExtraSpaceApproach2(vector<int> &a,vector<int> &b){
    //OPTIMAL SOLUTION -2
    // GAP METHOD TAKEN FROM  SHELL SORT
    //After gap is calculate just keep a pointer at first element and other at a gap + left.
    //Then keep on comparing and swapping the elements.
    //Then reduce the gap by half and repeat the process.
    int n=a.size();
    int m=b.size();
    int gap=(n+m)/2+(n+m)%2; // if gap=4.5 then it is converted to 5. for ex-n=4 m=5 then gap=9/2=4.5+9%2=1==>4+1=5.
    while (gap>0){
        int left=0;
        int right=left+gap;
        while(right<n+m){
            //arr1->left and arr2->right   ---Pointer Position---
            //Here what we did is that if the left pointer and right pointer are in array 1 or 2. To maintain that we are just creating when to send which array for swapping
            if(left<n && right>=n){
                swapIfGreater(a,b,left,right-n);
            }
            else if(left>=n){
                swapIfGreater(b,b,left-n,right-n);
            }
            else{
                swapIfGreater(a,a,left,right);
            }
            left++;
            right++;
        }
        if(gap==1) break;
        gap=(gap/2)+(gap%2);
    }
    //T.C. - O(nlogn)+O(mlogm)+O(n+m)
    //S.C. - O(1)
}

int main(){
    vector<int>a={1,3,5,7};
    vector<int>b={0,2,6,8,9};
    MergeSortedArraysWithoutExtraSpaceApproach2(a,b);
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:b){
        cout<<i<<" ";
    }
    return 0;
}