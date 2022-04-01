#include<bits/stdc++.h>
//pre req=> buy and sell3
using namespace std;

class Solution {
    private:
    int fun(int ind, int tarans, vector<int>&arr, int n, int k, vector<vector<int>>&dp){
        if(ind==n || tarans==2*k) return 0;
        if(dp[ind][tarans] !=-1) return dp[ind][tarans];
        if(tarans%2==0){
            return dp[ind][tarans]=max(-arr[ind]+fun(ind+1, tarans+1, arr, n,k,dp), fun(ind+1, tarans, arr, n, k,dp));
        }else{
            return dp[ind][tarans]=max(arr[ind]+fun(ind+1,tarans+1, arr, n, k,dp), fun(ind+1, tarans, arr, n, k,dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2*k+1,0));
        for(int ind=n-1; ind>=0; ind--){
            for(int tarans=2*k-1; tarans>=0; tarans--){
                if(tarans%2==0){
                    dp[ind][tarans]=max(-prices[ind]+dp[ind+1][tarans+1], dp[ind+1][tarans]);
                }else{
                    dp[ind][tarans]=max(prices[ind]+dp[ind+1][tarans+1], dp[ind+1][tarans]);
                }
            }
        }
        return dp[0][0];
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/