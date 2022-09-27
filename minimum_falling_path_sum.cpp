class Solution {
public:
    int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
        if (j < 0 or j >= matrix[0].size()) return 1e9;
        if (i == 0) return matrix[i][j];
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int l1 = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
        int l2 = matrix[i][j] + f(i - 1, j, matrix, dp);
        int l3 = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
        
        return dp[i][j] = min(l1, min(l2, l3));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int ans = INT_MAX;
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // vector<vector<int>> dp(n, vector<int> (m, 0));
        vector<int> prev(m, 0), curr(m, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if (i == 0) dp[i][j] = matrix[i][j];
                if (i == 0) curr[j] = matrix[i][j];
                else {
                    int l1 = 1e9, l2 = 1e9, l3 = 1e9;
//                     if (i > 0 and j > 0) l1 = matrix[i][j] + dp[i - 1][j - 1];
//                     if (i > 0) l2 = matrix[i][j] + dp[i - 1][j];
//                     if (i > 0 and j + 1 < m) l3 = matrix[i][j] + dp[i - 1][j + 1];

//                     dp[i][j] = min(l1, min(l2, l3));
                    if (i > 0 and j > 0) l1 = matrix[i][j] + prev[j - 1];
                    if (i > 0) l2 = matrix[i][j] + prev[j];
                    if (i > 0 and j + 1 < m) l3 = matrix[i][j] + prev[j + 1];

                    curr[j] = min(l1, min(l2, l3));
                }
            }
            prev = curr;
        }
        
        
        
        
        for (int j = 0; j < m; j++) {
            int mini = prev[j];
            ans = min(mini, ans);
        }
        
        return ans;
    }
};
