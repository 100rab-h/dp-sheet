
class Solution{
public:
    int f(int ind, int w, int wt[], int val[], vector<vector<int>> &dp) {
        if (ind == 0) {
            return (w / wt[ind]) * val[ind];
        }
        
        if (dp[ind][w] != -1) return dp[ind][w];
        
        int nottake = 0 + f(ind - 1, w, wt, val, dp);
        int take = 0;
        if (wt[ind] <= w) take = val[ind] + f(ind, w - wt[ind], wt, val, dp);
        
        return dp[ind][w] = max(take, nottake);
    }
    
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        // vector<vector<int>> dp(n, vector<int> (W + 1, -1));
        
        // vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        
        vector<int> prev(W + 1, 0); // curr(W + 1, 0);
        // return f(n - 1, W, wt, val, dp);
        for (int w = wt[0]; w <= W; w++) {
            // dp[0][w] = (w / wt[0]) * val[0];
            prev[w] = (w / wt[0]) * val[0];
        }
        
        for (int ind = 1; ind < n; ind++) {
            for (int w = 0; w <= W; w++) {
                // int nottake = 0 + dp[ind - 1][w];
                // int take = 0;
                // if (wt[ind] <= w) take = val[ind] + dp[ind][w - wt[ind]];
                
                // dp[ind][w] = max(take, nottake);
                int nottake = 0 + prev[w];
                int take = 0;
                // if (wt[ind] <= w) take = val[ind] + curr[w - wt[ind]];
                if (wt[ind] <= w) take = val[ind] + prev[w - wt[ind]];
                
                // curr[w] = max(take, nottake);
                prev[w] = max(take, nottake);
            }
            // prev = curr;
        }
        
        // return dp[n - 1][W];
        return prev[W];
    }
};
