#include<bits/stdc++.h>
using namespace std;

void rearrangeElementsWithSign(vector<int>a){
    //Rearrange Elements with Sign - BRUTE FORCE
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<a.size();i++){
        if(a[i]>=0){
            pos.push_back(a[i]);
        }else{
            neg.push_back(a[i]);
        }
    }
    for(int i=0;i<a.size()/2;i++){
        a[2*i]=pos[i];
        a[2*i+1]=neg[i];
    }
    //T.C. - O(n)+O(n/2)
    // S.C. - O(n/2)+O(n/2)=O(n)
}

void rearrangeElementsWithSignApproach2(vector<int>A){
    //Rearrange Elements with Sign - BEST SOLUTION IF BOTH NEGATIVE AND POSITIVE ARE EQUAL IN COUNT.
    int n = A.size();
  
    // Define array for storing the ans separately.
    vector<int> ans(n,0);
  
    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;
    for(int i = 0;i<n;i++){
      
      // Fill negative elements in odd indices and inc by 2.
        if(A[i]<0){
            ans[negIndex] = A[i];
            negIndex+=2;
        }
      
        // Fill positive elements in even indices and inc by 2.
        else{
            ans[posIndex] = A[i];
            posIndex+=2;
        }
    }
    //return ans;    
    //T.C. - O(n)
    // S.C. - O(n)
}
void rearrangeElementsWithSignApproach3(vector<int> &a){
    //Rearrange Elements with Sign - BEST SOLUTION IF BOTH NEGATIVE AND POSITIVE UNEQUAL IN COUNT.
    vector<int>pos,neg;
    int n=a.size();
    //Make seprate arrays for +ve and -ve elements of array
    for(int i=0;i<n;i++){
        if(a[i]>=0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }

    //Insert those elements which are less bcs if you do with larger one then it may create problem as the index of large array would not be existing in another array and making pointing to null
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=2*neg.size();
        for (int i = neg.size(); i < pos.size(); i++){
            a[index]=pos[i];
            index++;
        }        
    }
    else{
        for(int i=0;i<pos.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=2*pos.size();
        for (int i = pos.size(); i < neg.size(); i++){
            a[index]=neg[i];
            index++;
        }
    }
}
int main(){
    vector<int>a={3,1,-2,-5,2,-4};
    rearrangeElementsWithSignApproach2(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}