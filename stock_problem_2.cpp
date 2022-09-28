class Solution {
public:
    int f(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp) {
        if (ind == n) return 0;
        
        if (dp[ind][buy] != -1) return dp[ind][buy];
        
        if (buy) return dp[ind][buy] = max(-price[ind] + f(ind + 1, 0, price, n, dp), f(ind + 1, 1, price, n, dp));
        else return dp[ind][buy] = max(price[ind] + f(ind + 1, 1, price, n, dp), f(ind + 1, 0, price, n, dp));
    }
    
    int maxProfit(vector<int>& price) {
        int n = price.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        // return f(0, 1, price, n, dp);
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        vector<int> front(2, 0), curr(2, 0);
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                // if (buy) dp[ind][buy] = max(-price[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                // else dp[ind][buy] = max(price[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                if (buy) curr[buy] = max(-price[ind] + front[0], front[1]);
                else curr[buy] = max(price[ind] + front[1], front[0]);
            }
            front = curr;
        }
        
        // return dp[0][1];
        return front[1];
    }
};
