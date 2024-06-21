#include<bits/stdc++.h>
using namespace std;

int pascalTriangleQ1(int row,int col){
    //Question 1 : Get the value at ith row and jth col from the pattern
    //Brute Force
    // We can directly calculate value using n-1Cr-1 as n=no.of rows r= no. of column
    row=row-1;
    col=col-1;
    int r=1;  //For col
    int n=1;   //For row
    int x=1;    //FOR ROW-COl
    for (int i =1; i <= row; i++){
        n*=i;
    }
    for (int i =1; i <= col; i++){
        r*=i;
    }
    for (int i =1; i <= row-col; i++){
        x*=i;
    }
    return (n/(r*x));
}


long long pascalTriangleQ1Approach2(int row,int col){
    //Just a better way to find nCr
    // ex-10-1 C 3-1= 9 C 2 = 9*8/1*2
    int n=row-1;
    int r=col-1;
    long long result=1;
    for(int i=0;i<r;i++){
        result=result*(n-i);
        result=result/(i+1);
    }
    return result;
    //T.C.=O(r)
    //S.C.=O(1)
}

void pascalTriangleQ2(int row){
    // Q2 : Print the nth row of pasca, triangle
    //Brute Force
    //IN every nth row of pascal triangle we have n values so we take for loop till n
    for(int i=1;i<=row;i++){
        cout<<pascalTriangleQ1(row,i)<<" ";
    }
    //T.C.=O(n*r)
    //S.C.=O(1)
}

list<int> pascalTriangleQ2Approach2(int row){
    int ans=1;
    list<int>temp;
    temp.push_back(ans);
    cout<<ans<<" ";
    for(int i=1;i<row;i++){
        ans=ans*(row-i);
        ans=ans/(i);
        temp.push_back(ans);
        cout<<ans<<" ";
    }
    cout<<endl;
    return temp;
    //T.c.- O(N)
    //S.C.=O(1)
}

void pascalTriangleQ3(int n){
    // Q3 : Print the first n rows of pascal triangle
    //Brute Force
    //We can use the above function to print the first n rows
    list<list<int>>ans;
    for(int i=1;i<=n;i++){
        list<int>temp;
        for (int j = 1; j < i; j++)
        {
            temp.push_back(pascalTriangleQ1Approach2(i,j));
        }
        ans.emplace_back(temp);
        // cout<<endl;
    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    //T.C.=O(n*n*r)
    //S.C.=O(1)

}
void pascalTriangleQ3Approach2(int n){
    list<list<int>>ans;
    
    for(int i=1;i<n;i++){
        ans.push_back(pascalTriangleQ2Approach2(n));
    }
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    //T.C.=O(n*r)
    //S.C.=O(1)
}


int main(){  
    // pascalTriangleQ2Approach2(6);
    cout<<pascalTriangleQ1Approach2(5,2);
    return 0;
}