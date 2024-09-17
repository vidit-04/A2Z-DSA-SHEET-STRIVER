#include<bits/stdc++.h>
using namespace std;

class Card{
    public:
    int card;
    int count;
    Card(int card,int count){
        this->card=card;
        this->count=count;
    }
};
class compare{
    public:
    bool operator()(Card* a,Card*b){
        return a->card > b->card;
    }
};

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()%groupSize!=0) return false;
    if(groupSize==1) return true;
    priority_queue<Card*,vector<Card*>,compare> p;
    map<int,int> mpp;
    for(int i=0;i<hand.size();i++){
        mpp[hand[i]]++;
    }
    for(auto it: mpp){
        Card* c=new Card(it.first,it.second);
        p.push(c);
    }
    while(!p.empty()){
        Card* c=p.top();
        p.pop();
        queue<Card*> q;
        c->count--;
        for(int i=1;i<groupSize;i++){
            if(!p.empty() && p.top()->card == c->card+i){
                Card* curr=p.top(); p.pop();
                curr->count--;
                if(curr->count>0) q.push(curr);
            }
            else return false;
        }
        while(!q.empty()){
            p.push(q.front());
            q.pop();
        }
        if(c->count>=1) p.push(c);
    }
    return true;
}


int main(){
    
    return 0;
}