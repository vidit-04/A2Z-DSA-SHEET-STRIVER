#include<bits/stdc++.h>
using namespace std;

stack<int>s1;
stack<int>s2;
void push1(int x){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    //T.C.-O(N)
    //S.C.-O(2N)
}
void pop1(){
    s1.pop();
}
int top1(){
    return s1.top();
}

stack<int>input;
stack<int>output;

void push2(int x){
    input.push(x);
    //T.C.-O(1)
    //S.C.-O(N)
}
void pop2(){
    if(output.empty()){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
    output.pop();
}
int top2(){
    if(output.empty()){
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
    }
    return output.top();
}

int main(){
    //IMPLEMENTING QUEUE USING STACKS
    push1(7);
    push1(8);
    push1(9);
    pop1();
    cout<<top1()<<endl;

    push2(1);
    push2(2);
    push2(3);
    pop2();
    cout<<top2()<<endl;
    
    return 0;
}