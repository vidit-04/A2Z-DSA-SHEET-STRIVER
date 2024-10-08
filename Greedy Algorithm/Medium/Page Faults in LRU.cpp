#include<bits/stdc++.h>
using namespace std;

int pageFaults(int N, int C, int pages[]){
        // code here
    deque<int>q;
    int pf=0;
    for(int i=0;i<N;i++){
        auto it=find(q.begin(),q.end(),pages[i]);
        if(it==q.end()){
            if(q.size()<C){
                q.push_back(pages[i]);
            }
            else{
                q.pop_front();
                q.push_back(pages[i]);
            }
            pf++;
        }
        else {
        // If the page is already in the cache, move it to the back (most recently used)
            q.erase(it);
            q.push_back(pages[i]);
        }
    }
    return pf;
}

int main(){
    int N = 9, C = 4;
    int pages[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};
    cout<<pageFaults(N,C,pages);
    return 0;
}