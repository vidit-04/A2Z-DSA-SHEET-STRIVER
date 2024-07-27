#include<bits/stdc++.h>
using namespace std;

void push(queue<int>q1,queue<int>q2,int x){
    q2.push(x);
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1,q2);
}
void push2(queue<int> &q1,int x){
    q1.push(x);
    for(int i=0;i<q1.size()-1;i++){
        q1.push(q1.front());
        q1.pop();
    }
}

void pop(queue<int> &q1){
    if(q1.empty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    q1.pop();
}

int top(queue<int>q1){
    if(q1.empty()){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return q1.front();
}

int main(){
    //Implement Stack using Queue
    //USING 2 Queues
    
    // queue<int>q1; //MAIN STACK
    // queue<int>q2;

    // push(q1,q2,9);

    //USING 1 Queue
    queue<int>q1;
    push2(q1,6);
    push2(q1,7);
    push2(q1,8);
    push2(q1,9);
    pop(q1);
    cout<<top(q1)<<endl;
    return 0;
}