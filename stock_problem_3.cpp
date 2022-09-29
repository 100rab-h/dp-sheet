class Solution {
public:
    int f(int ind, int buy, int cap, vector<int> &price, vector<vector<vector<int>>> &dp) {
        if (cap == 0) return 0;
        if (ind == price.size()) return 0;
        
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if (buy) return dp[ind][buy][cap] = max(-price[ind] + f(ind + 1, 0, cap, price, dp), f(ind + 1, 1, cap, price, dp));
        else return dp[ind][buy][cap] = max(price[ind] + f(ind + 1, 1, cap - 1, price, dp), f(ind + 1, 0, cap, price, dp));
    }
    
    int maxProfit(vector<int>& price) {
        int n = price.size();
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, -1)));
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        vector<vector<int>> front(2, vector<int> (3, 0)), curr(2, vector<int> (3, 0));
        
        // return f(0, 1, 2, price, dp);
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    // if (buy) dp[ind][buy][cap] = max(-price[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                    // else dp[ind][buy][cap] = max(price[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                    if (buy) curr[buy][cap] = max(-price[ind] + front[0][cap], front[1][cap]);
                    else curr[buy][cap] = max(price[ind] + front[1][cap - 1], front[0][cap]);
                }
            }
            front = curr;
        }
        
        // return dp[0][1][2];
        return front[1][2];
        
    }
};
