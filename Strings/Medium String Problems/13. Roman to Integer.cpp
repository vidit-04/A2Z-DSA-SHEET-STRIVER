#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    int x = 0;
    for (int i = 0; i < s.length(); i++) {
        bool done = true;
        string r = s.substr(i, 2);
        if (r == "CM") {
            x += 900;
            done = false;
            i++;
        }
        if (r == "CD") {
            x += 400;
            done = false;
            i++;
        }
        if (r == "XC") {
            x += 90;
            done = false;
            i++;
        }
        if (r == "XL") {
            x += 40;
            done = false;
            i++;
        }
        if (r == "IX") {
            x += 9;
            done = false;
            i++;
        }
        if (r == "IV") {
            x += 4;
            done = false;
            i++;
        }
        if (done) {
            if (s[i] == 'M') {
                x += 1000;
            } else if (s[i] == 'D') {
                x += 500;
            } else if (s[i] == 'C') {
                x += 100;
            } else if (s[i] == 'L') {
                x += 50;
            } else if (s[i] == 'X') {
                x += 10;
            } else if (s[i] == 'V') {
                x += 5;
            } else if (s[i] == 'I') {
                x += 1;
            }
        }
    }
    return x;
}
int main(){
    string s = "MCMXCIV";
    cout << romanToInt(s);
    return 0;
}