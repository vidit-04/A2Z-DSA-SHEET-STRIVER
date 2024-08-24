#include<bits/stdc++.h>
using namespace std;

 class StockSpanner{
    vector<int>arr;
    StockSpanner(){
        vector<int>arr;
    }
    int next(int price){
        arr.push_back(price);
        int ans=1;
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i]<=price){
                ans++;
            }
            else break;
        }
        return ans;
    }
 };

class StockSpanner {
public:
    int index;
    stack<pair<int,int>> st;
    StockSpanner() {
        index =-1; 
        // st.clear();
    }
    
    int next(int price) {
        index+=1;
        int ans;
        while(!st.empty() && st.top().first<= price ){
            st.pop();
        }
        ans = index - (st.empty()? -1: st.top().second);
        st.push({price,index});
        return ans;
    }
};



int main(){
    
    return 0;
}