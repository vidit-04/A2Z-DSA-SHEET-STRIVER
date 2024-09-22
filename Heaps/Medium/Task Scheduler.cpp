#include<bits/stdc++.h>
using namespace std;

class Task{
    public:
    int time;
    int count;
    Task(int time,int count){
        this->time=time;
        this->count=count;
    }
};
class compare{
    public:
    bool operator()(Task* a,Task* b){
        return a->count < b->count;
    }
};

int leastInterval(vector<char>& tasks, int n) {
    vector<int>freq(26);
    int time=0;
    priority_queue<Task*,vector<Task*>,compare> p;
    for(auto i: tasks){
        freq[i-'A']++;
    }
    for(int i=0;i<26;i++){
        if(freq[i]>=1){
            Task* t1=new Task(0,freq[i]);
            p.push(t1);
        }
    }
    queue<Task*> q;
    while(!p.empty() || !q.empty()){
        if(!q.empty() && time-q.front()->time>n){
            p.push(q.front());
            q.pop();
        }
        if(!p.empty()){
            Task* t= p.top();p.pop();
            t->count--;
            t->time=time;
            if(t->count>0){
                q.push(t);
            }
        }
        time++;
    }
    return time;
}

int main(){
    
    return 0;
}