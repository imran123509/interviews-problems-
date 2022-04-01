#include<bits/stdc++.h>
//pre req=> buy and sell4
using namespace std;

class Solution {
    private:
    int fun(int ind, int buy, int n,vector<int>&arr, vector<vector<int>>&dp){
        if(ind>=n) return 0;
        if(dp[ind][buy] !=-1) return dp[ind][buy];
        if(buy==1){
            return dp[ind][buy]=max(-arr[ind]+fun(ind+1,0, n, arr,dp), fun(ind+1, 1, n, arr,dp));
        }else{
            return dp[ind][buy]= max(arr[ind]+fun(ind+2, 1,n, arr,dp), fun(ind+1, 0, n, arr,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                if(buy==1){
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][0], dp[ind+1][1]);
                }else{
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][1], dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
        
    }
};


//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/