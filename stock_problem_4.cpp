class Solution {
public:
    int f(int ind, int trans, int k, vector<int> &price, vector<vector<int>> &dp) {
        if (ind == price.size() or trans == 2 * k) return 0;
        
        if (dp[ind][trans] != -1) return dp[ind][trans];
        
        if (trans % 2 == 0) { // buy
            return dp[ind][trans] = max(-price[ind] + f(ind + 1, trans + 1, k, price, dp), f(ind + 1, trans, k, price, dp));
        } else {
            return dp[ind][trans] = max(price[ind] + f(ind + 1, trans + 1, k, price, dp), f(ind + 1, trans, k, price, dp));
        }
    }
    
    int maxProfit(int k, vector<int>& price) {
        int n = price.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2 * k + 1, -1));
        // return f(0, 0, k, price, dp);
        // vector<vector<int>> dp(n + 1, vector<int> (2 * k + 1, 0));
        
        vector<int> front(2 * k + 1, 0), curr(2 * k + 1, 0);
        
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int trans = 2 * k - 1; trans >= 0; trans--) {
                // if (trans % 2 == 0) { // buy
                //     dp[ind][trans] = max(-price[ind] + dp[ind + 1][trans + 1], dp[ind + 1][trans]);
                // } else {
                //     dp[ind][trans] = max(price[ind] + dp[ind + 1][trans + 1], dp[ind + 1][trans]);
                // }   
                if (trans % 2 == 0) { // buy
                    curr[trans] = max(-price[ind] + front[trans + 1], front[trans]);
                } else {
                    curr[trans] = max(price[ind] + front[trans + 1], front[trans]);
                }   
            }
            front = curr;
        }
        
        // return dp[0][0];
        return front[0];
    }
};



