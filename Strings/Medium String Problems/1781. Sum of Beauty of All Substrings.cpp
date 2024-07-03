#include<bits/stdc++.h>
using namespace std;

int beautySum(string s) {
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        std::vector<int> freq(26, 0);
        for (int j = i; j < n; ++j) {
            int ch = s[j] - 'a';
            freq[ch]++;
            int maxi = INT_MIN;
            int mini = INT_MAX;
            // Find max and min non-zero frequencies
            for (int k = 0; k < 26; ++k) {
                if (freq[k] > 0) {
                    maxi = std::max(maxi, freq[k]);
                    mini = std::min(mini, freq[k]);
                }
            }
            res += (maxi - mini);
        }
    }
    return res;
}


int main(){
    string s = "aabcb";
    cout << beautySum(s);    
    return 0;
}