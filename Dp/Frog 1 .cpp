#include <bits/stdc++.h>

using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}
int main(){
	int n;
	cin>>n;
	vector<int> dp(n,-1);
	vector<int> a(n);
	for(auto &el : a) cin>>el;
	cout<<solve(n-1,a, dp)<<endl;
}



//https://atcoder.jp/contests/dp/tasks/dp_a