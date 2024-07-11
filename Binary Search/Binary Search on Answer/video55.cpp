#include<bits/stdc++.h>
using namespace std;

int findNthRoot(int x){
    //BRUTE FORCE
    if(x==0 || x==1) return x;
    for(int i=1;i<=x/2;i++){
        if(i*i==x) return i;
        if(i*i>x) return i-1;
    }
    // T.C.-O(n)
    // S.C.-O(1)
}

//return 1, if == m:
//return 0, if < m:
//return 2, if > m:
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * mid;
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int n, int m) {
    //Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1) {
            return high;
        }
        else if (midN == 0) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(){
    cout<<NthRoot(3,27);
    return 0;
}