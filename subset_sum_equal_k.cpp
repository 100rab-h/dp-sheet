#include <bits/stdc++.h> 
bool f(int ind, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if (k == 0) return true;
    if (ind == 0) return arr[ind] == k;
    
    if (dp[ind][k] != -1) return dp[ind][k];
    
    bool notpick = f(ind - 1, k, arr, dp);
    bool pick = false; 
    if (arr[ind] <= k)  pick = f(ind - 1, k - arr[ind], arr, dp);
    
    return dp[ind][k] = pick | notpick;
}

bool subsetSumToK(int n, int K, vector<int> &arr) {
    // Write your code here.
//     vector<vector<int>> dp(n, vector<int> (k + 1, -1));
//     vector<vector<bool>> dp(n, vector<bool> (K + 1, 0));
    vector<bool> prev(K + 1, 0), curr(K + 1, 0);
//     return f(n - 1, k, arr, dp);
//     for (int ind = 0; ind < n; ind++) {
//         dp[ind][0] = true;
//     }
    prev[0] = true;
    curr[0] = true;
//     dp[0][arr[0]] = true;
    prev[arr[0]] = true;
    
    for (int ind = 1; ind < n; ind++) {
        for (int k = 1; k <= K; k++) {
//             bool notpick = dp[ind - 1][k];
//             bool pick = false; 
//             if (arr[ind] <= k)  pick = dp[ind - 1][k - arr[ind]];

//             dp[ind][k] = pick | notpick;
            bool notpick = prev[k];
            bool pick = false; 
            if (arr[ind] <= k)  pick = prev[k - arr[ind]];

            curr[k] = pick | notpick;
        }
        prev = curr;
    }
    
//     return dp[n - 1][K];
    return prev[K];
}
