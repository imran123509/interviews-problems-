#include<bits/stdc++.h>
//pre req=> buy and sell
using namespace std;

class Solution {
    private:
    int fun(int ind, int buy, vector<int>&arr, int n, vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy] !=-1) return dp[ind][buy];
        long long profit=0;
        if(buy){
            profit=max(-arr[ind]+fun(ind+1, 0, arr, n,dp), fun(ind+1, 1,arr, n,dp));
        }else{
            profit=max(arr[ind]+fun(ind+1, 1,arr, n,dp), fun(ind+1, 0, arr, n,dp));
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        /*
        int n=prices.size();
        int sell=prices[0];
        int buy=prices[0];
        int ans=0;
        for(int i=1; i<n; i++){
            if(sell>prices[i]){
                ans +=sell-buy;
                sell=prices[i];
                buy=prices[i];
            }else if(sell<=prices[i]){
                sell=prices[i];
            }
        }
        ans +=sell-buy;
        return ans;
*/
        int n=prices.size();
        vector<vector<long>>dp(n+1, vector<long>(2,0));
        //return fun(0, 1, prices, n,dp);
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1; ind>=0; ind--){
           for(int buy=0; buy<=1; buy++){
               long long profit=0;
               if(buy){
                   profit=max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
               }
               else{
                   profit=max(prices[ind]+dp[ind+1][1], dp[ind+1][0]);
               }
               dp[ind][buy]=profit;
           }
        }
        return dp[0][1];
        
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/