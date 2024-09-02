#include<bits/stdc++.h>
using namespace std;

int FruitIntoBasket(vector<int>a,int k){
    //BRUTE FORCE
    int n=a.size();
    int maxLength=0;
    set<int>s;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            s.insert(a[j]);
            if(s.size()<=k){
                maxLength=max(maxLength,j-i+1);
            }
            else{
                break;
            }
        }
        s.clear();
    }
    return maxLength;
    //T.C.-O(N^2)
    //S.C.-O(3)
}

int FruitIntoBasketApproach2(vector<int>a, int k){
    //BETTER SOLUTION
    int n=a.size();
    int maxLength=0;
    map<int,int>mpp;   //mapping-> value,frequency and remove that number while sliding whose frequency turns zero

    int l=0,r=0;
    while(r<n){
        mpp[a[r]]++;
        if(mpp.size()>k){
            while(mpp.size()>k){
                mpp[a[l]]--;
                if(mpp[a[l]]==0){
                    mpp.erase(a[l]);
                }
                l++;
            }
        }
        if(mpp.size()<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;
    }
    return maxLength;
    //T.C.-O(2N)
    //S.C.-O(3)
}

int FruitIntoBasketApproach3(vector<int>a, int k){
    //OPTIMAL SOLUTION
    int n=a.size();
    int maxLength=0;
    map<int,int>mpp;   //mapping-> value,frequency and remove that number while sliding whose frequency turns zero

    int l=0,r=0;
    while(r<n){
        mpp[a[r]]++;
        if(mpp.size()>k){
            mpp[a[l]]--;
            if(mpp[a[l]]==0){
                mpp.erase(a[l]);
            }
            l++;
        }
        if(mpp.size()<=k){
            maxLength=max(maxLength,r-l+1);
        }
        r++;
    }
    return maxLength;
    //T.C.-O(N)
    //S.C.-O(1)
}

int main(){
    //FRUIT INTO BASKET
    vector<int>a={3,3,3,1,2,1,1,2,3,3,4};
    int k=2;
    cout<<FruitIntoBasketApproach2(a,k);
    return 0;
}