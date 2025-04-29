#include<bits/stdc++.h>
using namespace std;

class st{
    stack<pair<int,int>> s;
    public:

    void push(int x){
        if(s.empty()){
            s.push({x,x});
            return;
        }
        else{
            int sec=s.top().second;
            s.push({x,min(x,sec)});
        }
    }
    void pop(){
        s.pop();
    }
    int top(){
        return s.top().first;
    }
    int getMin(){
        return s.top().second;
    }
};

class MinStack{
    stack<int>s;
    int mini;
    public:
    void push(int x){
        if(s.empty()){
            s.push(x);
            mini=x;
        }
        else if(x>=s.top()) s.push(x);
        else{
            //2*val-prev-mini=newVal
            s.push(2*x-mini);
            mini=x;
        }
    }
    void pop(){
        if(s.empty()) return;
        // else if(s.top()>mini) s.pop();
        else{
            int x=s.top();
            s.pop();
            if(x<mini) mini=2*mini-x;
        }
    }
    int top(){
        if(s.empty()) return -1;
        // else if(s.top()>mini) return s.top();
        else if(mini<s.top()) return s.top();
        else return mini  ;
    }
    int getMin(){
        return mini;
    }
    //T.C.-O(1)
    // S.C.-O(N)
};

int main(){
    //MIN STACK    
    st s;
    s.push(10);
    s.push(20);
    s.push(5);
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;
    s.pop();
    return 0;
    // ex- 12 15 10
    // 10<12
    //val<prev-min
    //val-prev-min<0
    //2val-prev-min<val
    //8<10 always   
}