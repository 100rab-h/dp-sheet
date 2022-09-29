
class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    // int f(int ind, int prev_ind, int n, int a[], vector<vector<int>> &dp) {
    //     if (ind == n) return 0;
        
    //     if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
        
    //     int nottake = 0 + f(ind + 1, prev_ind, n, a, dp);
    //     int take = INT_MIN;
    //     if (prev_ind == -1 or a[ind] > a[prev_ind]) take = 1 + f(ind + 1, ind, n, a, dp);
        
    //     return dp[ind][prev_ind + 1] = max(take, nottake);
    // }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
    //   vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    //   return f(0, -1, n, a, dp);
    // vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    
    // for (int ind = n - 1; ind >= 0; ind--) {
    //     for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
    //         int nottake = 0 + dp[ind + 1][prev_ind + 1];
    //         int take = INT_MIN;
    //         if (prev_ind == -1 or a[ind] > a[prev_ind]) take = 1 + dp[ind + 1][ind + 1];
            
    //         dp[ind][prev_ind + 1] = max(take, nottake);
    //     }
    // }
    // return dp[0][-1 + 1];
    
        vector<int> dp(n, 1);
        
        int ans = 1;
        for (int ind = 1; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (a[prev] < a[ind] and dp[prev] + 1 > dp[ind]) {
                    dp[ind] = dp[prev] + 1;
                    ans = max(ans, dp[ind]);
                }
            }
        }
        return ans;
        
        
    
    }
};
