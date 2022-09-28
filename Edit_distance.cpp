  public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
        if (j == 0) return i;
        if (i == 0) return j;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i - 1] == t[j - 1]) return dp[i][j] = f(i - 1, j - 1, s, t, dp);
        else {
            return dp[i][j] = 1 + min(f(i, j - 1, s, t, dp), min(f(i - 1, j, s, t, dp), f(i - 1, j - 1, s, t, dp)));
        }
    }
    
    int editDistance(string s, string t) {
        // Code here
        int m = s.size();
        int n = t.size();
        
        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        // return f(m, n, s, t, dp);
        
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 1; j <= n; j++) dp[0][j] = j;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[m][n];
        
    }
};
