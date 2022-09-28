    public:
    
    // int f(int i, int j, string &s1, string &s2) {
    //     if (i = 0 or j = 0) return 0;
        
    //     if (s1[i - 1] == s2[j - 1]) return 1 + f(i - 1, j - 1, s1, s2);
    //     else return max(f(i - 1, j, s1, s2), f(i, j - 1, s1, s2));
    // }
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        // return f(n - 1, m - 1, s1, s2);
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        
        return ans;
    }
};
