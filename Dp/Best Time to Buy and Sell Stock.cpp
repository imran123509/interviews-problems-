#include<bits/stdc++.h>
//pre req=> Wildcard Matching
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int mi=0, idx=-1, mx=0;
        int n=prices.size();
        /*
        for(int i=n-1; i>=0; i--){
                mx=max(mx, mi-prices[i]);
            mi=max(mi, prices[i]);
            }

        return mx;
*/
        int mi=prices[0];
        int profit=0;
        for(int i=0; i<n; i++){
            int cost=prices[i]-mi;
            profit=max(profit, cost);
            mi=min(mi, prices[i]);
        }
        return profit;
        
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/