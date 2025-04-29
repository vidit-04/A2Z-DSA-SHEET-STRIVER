#include<bits/stdc++.h>
using namespace std;

int tabulation(vector<int>& nums, int total) {
    int n = nums.size();
    map<int, unordered_map<int, bool>> dp;
    // Base case: We can always form sum 0 with an empty subset
    dp[0][0] = true;
    if (nums[0] <= total) dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
        for (auto it = dp[i - 1].begin(); it != dp[i - 1].end(); ++it) {
            int sum = it->first;
            dp[i][sum] = true;  // Not taking nums[i]
            dp[i][sum + nums[i]] = true;  // Taking nums[i]
        }
    }
    int mini = 1e9;
    for (auto it = dp[n - 1].begin(); it != dp[n - 1].end(); ++it) {
        int sum = it->first;
        int diff = abs(sum - (total - sum));
        mini = min(mini, diff);
    }
    return mini;
}

int minimumDifference(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    return tabulation(nums, total);
}
    

int main(){
    
    return 0;
}