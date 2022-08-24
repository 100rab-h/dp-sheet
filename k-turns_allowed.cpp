// Memoization Solution.

int mod = 1e9 + 7;
int f(int i, int j, int k, int dir, vector<vector<vector<vector<int>>>> &dp) {
    if (i == 0 and j == 0) return 1;
    if (i < 0 or j < 0) return 0;
    if (k == 0) {
        // if we are in row 0 and dir is row wise then we can go to point (0, 0).
        if (dir == 1 and i == 0) return 1;
        // if we are in col 0 and dir is col wise then we can go to point (0, 0).
        if (dir == 0 and j == 0) return 1;
        return 0;
    }
    
    if (dp[i][j][k][dir] != -1) return dp[i][j][k][dir];
    
    // if we are in row wise traversal and if we change row then turn will be incremented. 
    if (dir == 0) dp[i][j][k][dir] = (f(i, j - 1, k - 1, !dir, dp) + f(i - 1, j, k, dir, dp)) % mod;
    else dp[i][j][k][dir] = (f(i, j - 1, k, dir, dp) + f(i - 1, j, k - 1, !dir, dp)) % mod;
    
}

int fn(int i, int j, int k, vector<vector<vector<vector<int>>>> &dp) {
    
    // 1 - row wise traversal.
    // 0 - col wise traversal.
    return (f(i - 1, j, k, 0, dp) + f(i, j - 1, k, 1, dp)) % mod;
}

int kTurnsAround(int n, int m, int k)
{
	// write your code here
    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>> (m, vector<vector<int>> (k + 1, vector<int> (2, -1))));
    return fn(n - 1, m - 1, k, dp);
}
