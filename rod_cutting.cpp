
class Solution{
  public:
    int f(int ind, int N, int price[], vector<vector<int>> &dp) {
        if (ind == 0) return N * price[ind];
        
        if (dp[ind][N] != -1) return dp[ind][N];
        
        int nottake = f(ind - 1, N, price, dp);
        int take = 0;
        int rodLen = ind + 1;
        if (rodLen <= N) take = price[ind] + f(ind, N - rodLen, price, dp);
        
        return dp[ind][N] = max(take, nottake);
    }
  
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // vector<vector<int>> dp(n, vector<int> (n + 1, 0));
        vector<int> prev(n + 1, 0);  // curr(n + 1, 0);
        // return f(n - 1, n, price, dp);
        
        for (int N = 0; N <= n; N++) {
            // dp[0][N] = N * price[0];
            prev[N] = N * price[0];
        }
        
        for (int ind = 1; ind < n; ind++) {
            for (int N = 0; N <= n; N++) {
                // int nottake = dp[ind - 1][N];
                // int take = 0;
                // int rodLen = ind + 1;
                // if (rodLen <= N) take = price[ind] + dp[ind][N - rodLen];
                
                // dp[ind][N] = max(take, nottake);
                // int nottake = prev[N];
                // int take = 0;
                // int rodLen = ind + 1;
                // if (rodLen <= N) take = price[ind] + curr[N - rodLen];
                
                // curr[N] = max(take, nottake);
                int nottake = prev[N];
                int take = 0;
                int rodLen = ind + 1;
                if (rodLen <= N) take = price[ind] + prev[N - rodLen];
                
                prev[N] = max(take, nottake);
            }
            // prev = curr;
        }
        
        // return dp[n - 1][n];
        return prev[n];
    }
};
