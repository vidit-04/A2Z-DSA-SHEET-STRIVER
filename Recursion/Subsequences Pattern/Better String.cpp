#include<bits/stdc++.h>
using namespace std;

void subs(string a, int n, int index, set<string> &subsequences, string curr = "") {
    if (index == n) {
        if (!curr.empty()) {
            subsequences.insert(curr);
        }
        return;
    }
    // Include the current character
    subs(a, n, index + 1, subsequences, curr + a[index]);
    // Exclude the current character
    subs(a, n, index + 1, subsequences, curr);
}

int countDistinctSubsequences(string a) {
    set<string> subsequences;
    subs(a, a.length(), 0, subsequences);
    return subsequences.size();
}

string betterString(string str1, string str2) {
    int cnt1 = countDistinctSubsequences(str1);
    int cnt2 = countDistinctSubsequences(str2);

    if (cnt1 == cnt2) return str1;
    return cnt1 > cnt2 ? str1 : str2;
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    cout << betterString(str1, str2);
    return 0;
}