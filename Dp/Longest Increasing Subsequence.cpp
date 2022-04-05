#include<bits/stdc++.h>
//pre req=> buy and sell stock with Transaction fee
using namespace std;
//tc (n*n)
//space complexity (n*n)+(n)
int fun(int ind, int pre_ind, int a[], int n, vector<vector<int>>dp){
	if(ind==n) return 0;
	if(dp[ind][pre_ind+1] !=-1) return dp[ind][pre_ind+1];
	int len=fun(ind+1, pre_ind, a, n,dp);
	if(len==-1 || a[ind]>a[pre_ind]){
		len=max(len, 1+fun(ind+1, ind, a, n,dp));
	}
	return dp[ind][pre_ind+1]=len;
}
int LIS(int a[], int n){
	vector<vector<int>>dp(n, vector<int>(n+1,-1));

	return fun(0,-1, a, n, dp);
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	cout<<LIS(a,n)<<endl;
}


//https://leetcode.com/problems/longest-increasing-subsequence/description/