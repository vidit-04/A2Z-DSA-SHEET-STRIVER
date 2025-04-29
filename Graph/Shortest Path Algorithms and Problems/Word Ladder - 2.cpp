#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> WordLadder2(vector<string>& wordList,string beginWord,string endWord){
    unordered_set<string> st(wordList.begin(),wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<vector<string>> ans;
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level=0;

    while(!q.empty()){
        vector<string> vec=q.front();
        q.pop();
        //erase all words that are used in the previous level to transform
        if(vec.size()>level){
            level++;
            for(auto it : usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }
        string word=vec.back();
        //store the answers
        if(word==endWord){
            //the first answer that we reached
            if(ans.size()==0) ans.push_back(vec);
            //store other answers that are of the same length as there is no point in storing the longer answers
            else if(ans[0].size()==vec.size()) ans.push_back(vec);
        }

        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.count(word)>0){
                    vec.push_back(word);
                    q.push(vec);
                    //mark visit on this level
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
}

int main(){
    vector<string> wordList={"pat","bot","pot","poz","coz"};
    string beginWord="bat";
    string endWord="coz";
    vector<vector<string>> ans=WordLadder2(wordList,beginWord,endWord);
    for(auto it : ans){
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}