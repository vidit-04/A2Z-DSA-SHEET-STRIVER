#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    a=a+b;
    b=a-b;
    a=a-b;
}

void swapApproach2(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}



bool checkIfIthBitIsSet(int n,int i){
    //BRute force: Convert to binary then check if ith bit is set from right
}
bool checkIfIthBitIsSetApproach2(int n,int i){
    //OPTIMAL SOLUTION: Convert to binary then check if ith bit is set from right
    //USING LEFT SHIFT OPERATOR
    // return (n & (1<<i))!=0;

    //USING RIGHT SHIFT OPERATOR
    return ((n>>i)&1)==1;
}

int setIthBit(int n,int i){
    //USING LEFT SHIFT OPERATOR

    return (n | 1<<i);

}

int clearIthBit(int n,int i){
    //USING LEFT SHIFT OPERATOR
    return (n & ~(1<<i));
}

int ToggleIthBit(int n,int i){
    //USING LEFT SHIFT OPERATOR
    return (n ^ 1<<i);
}

int RemoveFirstSetBitFromRight(int n){
    //in power of two we have only 1 up bit.
    //if we subtract 1 from no. then resultant number will have that bit as 0 and rest bits as 1.
    //if we do and operation of n and n-1 then it will be 0.
    //FOR ex- 16- 1000 and 15-0111 then after & it is equal to 0 thus ans.
    return (n & (n-1));
}

int checkIfNisPowerOf2(int n){
    //in power of two we have only 1 up bit.
    //if we subtract 1 from no. then resultant number will have that bit as 0 and rest bits as 1.
    //if we do and operation of n and n-1 then it will be 0.
    //FOR ex- 16- 1000 and 15-0111 then after & it is equal to 0 thus ans.
    return (n & (n-1))==0;
}

int CountNumberOfSetBits(int n){
    //BRUTE FORCE: Convert to binary then count no. of 1's
    int cnt=0;
    while(n>1){
        cnt+=n&1; // if number is odd then remainder is 1 so cnt++;
        n=n>>1;
    }
    if(n==1) cnt+=1;
    return cnt;
}

int CountNumberOfSetBitsApproach2(int n){
    //OPTIMAL SOLUTION: Convert to binary then count no. of 1's
    int cnt=0;
    while(n!=0){
        n=n&(n-1); //remove the first set bit from right and if you convert all bits to 0 then it shows the base condition
        cnt++;
    }
    return cnt;
    //T.C.- O(no. of set bits)
    //S.C.- O(1)
}

int main(){
    int a=3;
    int b=2;
    swapApproach2(a,b);
    cout<<a<<" "<<b<<endl;

    int n;
    cin>>n;
    int i;
    cin>>i;
    cout<<checkIfIthBitIsSetApproach2(n,i)<<endl;
    cout<<setIthBit(n,i)<<endl;
    cout<<clearIthBit(n,i)<<endl;
    cout<<ToggleIthBit(n,i)<<endl;
    cout<<RemoveFirstSetBitFromRight(n)<<endl;
    cout<<checkIfNisPowerOf2(n)<<endl;
    cout<<CountNumberOfSetBitsApproach2(n)<<endl;

    return 0;
}