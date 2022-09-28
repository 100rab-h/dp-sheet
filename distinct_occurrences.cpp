
class Solution
{
    public:
    int mod = 1e9 + 7;
    int f(int i, int j, string &S, string &T, vector<vector<int>> &dp) {
        if (j == 0) return 1;
        if (i == 0) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (S[i - 1] == T[j - 1]) return dp[i][j] = (f(i - 1, j - 1, S, T, dp) + f(i - 1, j, S, T, dp)) % mod;
        else return dp[i][j] = f(i - 1, j, S, T, dp);
    }
    
    int subsequenceCount(string S, string T)
    {
      //Your code here.
      int m = S.size();
      int n = T.size();
      
    //   vector<vector<int>> dp(m + 1, vector<int> (n + 1, - 1));
      vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
      
    //   return f(m, n, S, T, dp);
    
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S[i - 1] == T[j - 1]) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            else dp[i][j] = dp[i - 1][j];
        }
    }
    
    return dp[m][n];
    }
};
 
