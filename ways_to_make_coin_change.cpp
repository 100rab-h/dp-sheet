#include<bits/stdc++.h>
long f(int ind, int tar, int *denomination, vector<vector<long>> &dp) {
    if (ind == 0) {
        return (tar % denomination[ind] == 0);
    }
    
    if (dp[ind][tar] != -1) return dp[ind][tar];
    
    long nottake = f(ind - 1, tar, denomination, dp);
    long take = 0;
    if (denomination[ind] <= tar) take = f(ind, tar - denomination[ind], denomination, dp);
    
    return dp[ind][tar] = take + nottake;
}

long countWaysToMakeChange(int *denomination, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long> (value + 1, -1));
    return f(n - 1, value, denomination, dp);
}
