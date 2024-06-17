#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>a){
    // STEP 1 :: LONGER PREFIX -  a[i]<a[i+1]
    // STEP 2 :: FIND SOMEONE GREATER THAN I BUT SMALLER THEN REST NUMBERS. SO THAT YOU STAY CLOSE TO NEXT PERMUTATION.
    // STEP 3 :: SWAP A[I] AND A[J]
    // STEP 4 :: SORT THE REST NUMBERS

    int n=a.size();
    int index=-1;
    for(int i=n-2;i>0;i--){
        if(a[i]<a[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(a.begin(),a.end());
        return;
    }

    for(int i=n-1;i>index;i--){
        if(a[i]>a[index]){
            swap(a[i],a[index]);
            break;
        }
    }
    reverse(a.begin()+index+1,a.end());

    //T.C. - O(3n)
    // S.C. - O(1)
}

int main(){
    vector<int>a={3,2,1};
    next_permutation(a.begin(),a.end());  //METHOD 1
    nextPermutation(a);  // BEST METHOD
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }

    return 0;
}