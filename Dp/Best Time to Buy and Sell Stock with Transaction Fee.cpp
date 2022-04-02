#include<bits/stdc++.h>
//pre req=> buy and sell stock with cooldown
using namespace std;

class Solution {
    private:
    int fun(int ind, int buy, vector<int>&arr, int n, int fee,vector<vector<int>>&dp){
        if(ind==n) return 0;
        if(dp[ind][buy] !=-1) return dp[ind][buy];
        if(buy){
           return dp[ind][buy]=max(-arr[ind]+fun(ind+1, 0, arr,n,fee,dp),fun(ind+1,1,arr,n,fee,dp));
        }else{
            return dp[ind][buy]=max(arr[ind]-fee+fun(ind+1,1,arr,n,fee,dp),fun(ind+1,0,arr,n,fee,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return fun(0,1,prices,n,fee,dp);
    }
};



//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/