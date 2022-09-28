{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int ind, int wt[], int val[], int w, vector<vector<int>> &dp) {
        
        if (ind == 0) {
            if (wt[ind] <= w) return val[ind];
            return 0;
        }
        
        if (dp[ind][w] != -1) return dp[ind][w];
        
        int nottake = 0 + f(ind - 1, wt, val, w, dp);
        int take = INT_MIN;
        if (wt[ind] <= w) take = val[ind] + f(ind - 1, wt, val, w - wt[ind], dp);
        
        return dp[ind][w] = max(take, nottake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n, vector<int> (W + 1, -1));
        // vector<vector<int>> dp(n, vector<int> (W + 1, 0));
        //   return f(n - 1, wt, val, W, dp);
        
        vector<int> prev(W + 1, 0); // curr(W + 1, 0);
        
        for (int w = wt[0]; w <= W; w++) {
            // dp[0][w] = val[0];
            prev[w] = val[0];
        }
        
        for (int ind = 1; ind < n; ind++) {
            // for (int w = 0; w <= W; w++) {
            for (int w = W; w >= 0; w--) {
                // int nottake = 0 + dp[ind - 1][w];
                // int take = INT_MIN;
                // if (wt[ind] <= w) take = val[ind] + dp[ind - 1][w - wt[ind]];
                
                // dp[ind][w] = max(take, nottake);
                // int nottake = 0 + prev[w];
                // int take = INT_MIN;
                // if (wt[ind] <= w) take = val[ind] + prev[w - wt[ind]];
                
                // curr[w] = max(take, nottake);
                int nottake = 0 + prev[w];
                int take = INT_MIN;
                if (wt[ind] <= w) take = val[ind] + prev[w - wt[ind]];
                
                prev[w] = max(take, nottake);
            } 
            // prev = curr;
        } 
        
        // return dp[n - 1][W];
        return prev[W];
    }
};
