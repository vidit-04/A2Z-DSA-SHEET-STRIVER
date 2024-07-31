#include<bits/stdc++.h>
using namespace std;

void push(int arr[],int &top,int x){
    if(top==4){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    arr[top]=x;
}

void pop(int &top){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    top--;
}

int topPrint(int arr[], int top){
    if(top==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}

int size(int top){
    return top+1;
}

bool isEmpty(int top){
    return top==-1;
}

int main(){
    //IMPLEMENTATION OF STACK USING ARRAYS
    int arr[5];
    int top=-1;
    //PUSH OPERATION
    push(arr,top,7);
    push(arr,top,8);
    //POP OPERATION
    pop(top);
    //TOP OPERATION
    cout<<topPrint(arr,top)<<endl;
    //SIZE OPERATION
    cout<<size(top)<<endl;
    //ISEMPTY OPERATION
    cout<<isEmpty(top)<<endl;

    return 0;
}