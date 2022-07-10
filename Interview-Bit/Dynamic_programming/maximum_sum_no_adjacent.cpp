class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n);
	    dp[0] = arr[0];
	    dp[1] = max(arr[0],arr[1]);
	    for(int i=2;i<n;i++){
	        dp[i] = max(dp[i-1],arr[i]+dp[i-2]);
	    }
	    
	    return max(dp[n-1],dp[n-2]);
	}
};