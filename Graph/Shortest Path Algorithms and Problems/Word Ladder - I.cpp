#include<bits/stdc++.h>
using namespace std;

int WordLadder1(vector<string> wordlist,string beginWord,string endWord){
    unordered_set<string> s(wordlist.begin(),wordlist.end());
    s.erase(beginWord);
    queue<pair<string,int>> q; //word,level level-the number of conversion to that word
    q.push({beginWord,1});
    while(!q.empty()){
        string word=q.front().first;
        int level=q.front().second;
        q.pop();
        // everytime we find our target that is the shortest path beecause we are doing BFS
        if(word==endWord) return level;
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(s.find(word)!=s.end()){
                    //Every time we find a word in the set, we erase it from the set because there is no point to visit the same word again because it will not lead to the shortest path.
                    q.push({word,level+1});
                    s.erase(word);
                }
            }
            word[i]=original;
        }
    }
    return 0;
    //T.C. - O(N*word.lenth*26)*O(log n)
}

int main(){
    vector<string> wordlist={"hot","dot","dog","lot","log","cog"};
    string beginWord="hit";
    string endWord="cog";
    cout<<WordLadder1(wordlist,beginWord,endWord);
    return 0;
}