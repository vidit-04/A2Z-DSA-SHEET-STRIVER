#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &a, int i){
    for(int j=0;j<a[0].size();j++){
        if(a[i][j]!=0){
            a[i][j]=-1;
        }
    }
}
void markCol(vector<vector<int>> &a, int j){
    for(int i=0;i<a[0].size();i++){
        if(a[i][j]!=0){
            a[i][j]=-1;
        }
    }
}

void SetMatrixZeroes(vector<vector<int>> &a){
    //YOU WILL BE GIVEN A 2D ARRAY WHERE ELEMENTS WOULD BE 0 AND 1. SO WHEREVER YOU FIND 0, MARK ROW AND COLUMN ELEMENTS AS 0.
    //BRUTE FORCE
    int m=a.size();
    int n=a[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(a[i][j]==0){
                markRow(a,i);
                markCol(a,j);
            }
        }   
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j]==-1){
                a[i][j]=0;
            }
        }
    }    
    //T.C. - (m*n)(m+n)+m*n ~ O(n^3)
    //S.C. - O(1)
}

void SetMatrixZeroes(vector<vector<int>> &a){
    //BETTER APPROACH
    //BY THIS METHOD WE AVOID TO MARK THE SAME ELEMENT AS 0 MORE THAN 1 TIME AS WE WERE DOING ABOVE. IN BRUTE FORCE, WE WERE AGAIN AND AGAIN MARKING THE SAME ELEMENT AS 0 EVEN IF IT WAS MARKED PREVIOUSLY. WHICH CREATED T.C. TO O(N^3).
    //STEP 1 :: MAKE 2 arrays of size no. of rows and cols. What we do here is we mark which row and column element it is to be marked zero.
    //STEP 2 :: THEN WHEN WE KNOW WHICH COL AND ROW ELEMENT IS TO BE MARKED ZERO THEN WE RE ITERATE AND MARK THEM 0. 
    
    int m=a.size();
    int n=a[0].size();
    vector<int>row(m,0);
    vector<int>col(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==1 || col[j]==1){
                a[i][j]=0;
            }
        }
    }
    //T.C. - O(2*m*n)
    //S.C. - O(m+n)
}

void SetMatrixZeroes(vector<vector<int>> &matrix){
    //OPTIMAL APPROACH
    //SAME APPROACH AS ABOVE BUT HERE WE ARE CONIDERING FLAG ROW AND COL AS NOT SEPERATED BUT AS FIRST ROW AND COLUMN AS A FLAG ROW & COLUMN
    int m=matrix.size();
    int n=matrix[0].size();
    // int col[m]={0}   matrix [0][...]
    // int row[n]={0}   matrix [...][0]
    int col0=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if (j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    //FIRST ITERATE OVER REST ELEMENTS EXCEPT 0TH COL AND ROW BCS IF YOU CHANGE THEM THEN IT WILL CREATE PROBLEM
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            if(matrix[i][0]==0 || matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }        
    }
    //NOW WHILE DOING OPERATION FOR 0TH COL AND ROW. FIRSTLY DO ON 0TH COL BCS ITS VALUE DEPENDS ON MATRIX[0][0]
    if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    //THIS IS DONE AFTERWARDS BCS ITS VALUE DEPENDS ON VARIABLE COL0 WHICH IS NOT THE PART OF ARRAY AND WHICH MAKES THIS EXECUTION RUN PROPERLY
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
    //T.C. - O(2*m*n)
    //S.C. - O(1)
}


int main(){
    
    return 0;
}   