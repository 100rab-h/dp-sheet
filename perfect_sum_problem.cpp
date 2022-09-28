
	public:
	int mod = 1e9 + 7;
	
	int f(int ind, int s, int arr[], vector<vector<int>> &dp) {
	    if (ind == 0) {
	        if (s == 0 and arr[0] == 0) return 2;
	        if (s == 0 or arr[0] == s) return 1;
	        else return 0;
	    }
	    
	    if (dp[ind][s] != -1) return dp[ind][s];
	    
	    int nottake = f(ind - 1, s, arr, dp);
	    int take = 0;
	    if (arr[ind] <= s) take = f(ind - 1, s - arr[ind], arr, dp);
	    
	    return dp[ind][s] = (take + nottake) % mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        vector<vector<int>> dp(n, vector<int> (sum + 1, 0));
        // return f(n - 1, sum, arr, dp);
        
        for (int s = 0; s <= sum; s++) {
            if (s == 0 and arr[0] == 0) dp[0][s] = 2;
            else if (s == 0 or arr[0] == s) dp[0][s] = 1;
            
        }
        // dp[0][0] = 2;
        // dp[0][arr[0]] = 1;
        
        for (int ind = 1; ind < n; ind++) {
            for (int s = 0; s <= sum; s++) {
                int nottake = dp[ind - 1][s];
        	    int take = 0;
        	    if (arr[ind] <= s) take = dp[ind - 1][s - arr[ind]];
        	    
        	    dp[ind][s] = (take + nottake) % mod;
            }
        }
        
        return dp[n - 1][sum];
	}
	  
};
