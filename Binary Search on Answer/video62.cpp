#include<bits/stdc++.h>
using namespace std;

int func(vector<int>a,int no_of_pages){
    int cntStudent=1;
    int pages=0;
    for(int i=0;i<a.size();i++){
        if(pages+a[i]<=no_of_pages){
            pages+=a[i];
        }
        else{
            cntStudent++;
            pages=a[i];
        }
    }
    return cntStudent;
}

int bookAlloaction(vector<int>a,int students){
    int n=a.size();  // No. of books
    if(students>n) return -1;

    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);
    
    for(int i=low;i<=high;i++){
        int cntStudent=func(a,i);
        if(cntStudent==students){
            return i;
        }
    }

    //T.C.-O(sum-max)*O(n)
    //S.C.-O(1)
}

int bookAlloactionApproach2(vector<int>a,int students){
    int n=a.size();  // No. of books
    if(students<n) return -1;

    int low=*max_element(a.begin(),a.end());
    int high=accumulate(a.begin(),a.end(),0);

    while(low<=high){
        int mid=(low+high)/2;
        int cntStudent=func(a,mid);
        if(cntStudent<=students){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
    //T.C.-O(nlog(sum-max))
    //S.C.-O(1)
}
int main(){
    vector<int>a={25,46,28,49,24};
    int students=4;
    cout<<bookAlloaction(a,students)<<endl;
    return 0;
}