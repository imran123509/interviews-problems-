#include<bits/stdc++.h>
//pre req=> buy and sell2
using namespace std;

class Solution {
    private:
    int fun(int ind, int buy, int cap,int n, vector<int>&arr, vector<vector<vector<int>>>&dp){
        if(cap==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][cap] !=-1){
            return dp[ind][buy][cap];
        }
        if(buy){
            return dp[ind][buy][cap]=max(-arr[ind]+fun(ind+1,0,cap,n,arr,dp), fun(ind+1,1,cap,n,arr,dp));
        }else{
            return dp[ind][buy][cap]=max(arr[ind]+fun(ind+1,1,cap-1,n, arr,dp), fun(ind+1,0,cap, n, arr,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        /*
        int n=prices.size();
        int dp[n+1][2][3];
        for(int i=0; i<=n; i++){
            dp[i][0][0]=dp[i][0][1]=0;
        }
        for(int i=0; i<3; i++){
            dp[n][0][i]=dp[n][1][i]=0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=1; j<3; j++){
                //buy phase
                dp[i][0][j]=max(dp[i+1][1][j]-prices[i], dp[i+1][0][j]);
                
                // sell phase
                dp[i][1][j]=max(dp[i+1][0][j-1]+prices[i], dp[i+1][1][j]);
            }
        }
        return dp[0][0][2];
*/
        int n=prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return fun(0, 1,2,n,prices,dp);
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
