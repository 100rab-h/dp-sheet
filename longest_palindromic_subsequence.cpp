
class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        // string B = string(A.rbegin(), A.rend());
        string B = A;
        reverse(B.begin(), B.end());
        int n = A.size();
        int m = n;
        
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i - 1] == B[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(curr[j - 1], prev[j]);
            }
            prev = curr;
        }
        
        return prev[m];
    }
};
