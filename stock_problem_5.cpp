class Solution {
public:
    int f(int ind, int buy, vector<int> &price, vector<vector<int>> &dp) {
        if (ind >= price.size()) return 0;
        
        if (dp[ind][buy] != -1) return dp[ind][buy];
        
        if (buy) {
            return dp[ind][buy] = max(-price[ind] + f(ind + 1, 0, price, dp), f(ind + 1, 1, price, dp));
        } else {
            return dp[ind][buy] = max(price[ind] + f(ind + 2, 1, price, dp), f(ind + 1, 0, price, dp));
        }
    }
    
    int maxProfit(vector<int>& price) {
        int n = price.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        // return f(0, 1, price, dp);
        // vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        vector<int> front(2, 0), curr(2, 0);
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-price[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(price[ind] + dp[ind + 2][1], dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
