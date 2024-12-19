#include<bits/stdc++.h>
using namespace std;

int NumberOfSubstringOfAllThreeCharacters(string s){
        int n = s.length();

        int i=0,j=0,count=0;

        unordered_map<char, int> mp;

        while(j<n)
        {
            mp[s[j]]++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1)
            {
                count += (n - j);

                //shrinking the window
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return count;
}

int main(){
    //Number of Substrings Containing All Three Characters
    string s="bbacba";
    cout<<NumberOfSubstringOfAllThreeCharacters(s);
    return 0;
}