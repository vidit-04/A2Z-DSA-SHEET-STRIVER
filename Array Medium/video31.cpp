  #include<bits/stdc++.h>
using namespace std;

void RotatematrixBy90Degree(vector<vector<int>> &a){
    //BRUTE FORCE
    //Directly placing them at position in new arr
    int m=a.size();
    int n=a[0].size();
    vector<vector<int>>ans;
    for(int i=0;i<m;i++){
        for (int j = 0; j < n; j++){
            ans[j][m-i-1]=a[i][j];
        }        
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    //T.C. - O(n^2)
    //S.C. - O(n^2)
}

void reverseRow(vector<vector<int>> &a, int i){
    int low=0;
    int high=a.size()-1;
    while(low<high){
        swap(a[i][low],a[i][high]);
        low++;
        high--;
    }
}

void RotatematrixBy90DegreeApproach2(vector<vector<int>> &a){
    //STEP 1: Transpose of matrix 
    //STEP 2: Reverse each row
    //Optimal Code
    int n=a.size();

    //STEP 1
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(a[i][j],a[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverseRow(a,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    //T.C. - O(n^2)
    //S.C. - O(1)
}

int main(){
    vector<vector<int>>a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    RotatematrixBy90DegreeApproach2(a);
    return 0;
}