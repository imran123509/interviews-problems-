class Solution {
    private:
    //memoization approach
    int fun(int n, vector<int>&dp){
        if(n<=1) return n;
        if(n==2) return 1;
        if(dp[n] !=-1) return dp[n];
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
public:
    // tabulation approach
    int dp[31];
    int fib(int n) {
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3; i<=n; i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};


//https://leetcode.com/problems/fibonacci-number/description/