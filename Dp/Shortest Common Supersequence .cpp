#include<bits/stdc++.h>
//pre req=> Minimum number of deletions and insertions
using namespace std;
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        int dp[n+1][m+1];
        for(int i=0; i<=n; i++) dp[i][0]=0;
        for(int i=0; i<=m; i++) dp[0][i]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n,j=m;
        string ans="";
        while(i>0 && j>0){
            if(X[i-1]==Y[j-1]){
                ans +=X[i-1];
                i--,j--;
            }else if(dp[i-1][j]>dp[i][j]){
                ans +=X[i-1];
                i--;
            }else{
                ans +=Y[j-1];
                j--;
            }
        }
        while(i>0){
            ans +=X[i-1];
            i--;
        }
        while(j>0){
            ans +=Y[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        int sz=ans.size();
        return sz;
        
    }
};

// { Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}

  // } Driver Code Ends
  
  //https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1#