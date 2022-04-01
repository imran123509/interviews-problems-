#include<bits/stdc++.h>
//pre req=> lcs
using namespace std;
// memoization solution
/*

Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M)’. Stack Space is eliminated.
*/
int lcs(string &s1, string &s2){
    
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    int ans = 0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                ans = max(ans,val);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return ans;
    
}

int main() {

  string s1=  "ABCDGH";
  string s2= "ACDGHR";
                                 
  cout<<"The Length of Longest Common Substring is "<<lcs(s1,s2);
}


//https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1/