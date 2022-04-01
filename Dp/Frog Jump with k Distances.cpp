#include <bits/stdc++.h>

using namespace std;
//memoization solution:
//Time Complexity: O(N *K)
//Space Complexity: O(N)
/* Reason: We are using a recursion stack space(O(N)) and an array (again O(N)). Therefore total space complexity will be O(N) + O(N) ≈ O(N)
*/
int solveUtil(int ind, vector<int>& height, vector<int>& dp, int k){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    
    int mmSteps = INT_MAX;
        
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
      int jump = solveUtil(ind-j, height, dp, k)+ abs(height[ind]- height[ind-j]);
            mmSteps= min(jump, mmSteps);
        }
    }
    return dp[ind]= mmSteps;
    
}

//Tabulation approach
/*

Declare a dp[] array of size n.
First initialize the base condition values, i.e dp[0] as 0.
Set an iterative loop which traverses the array( from index 1 to n-1) and for every index calculate jumpOne and jumpTwo and set dp[i] = min(jumpOne, jumpTwo)
*/


/*

Time Complexity: O(N*K)

Reason: We are running two nested loops, where outer loops run from 1 to n-1 and the inner loop runs from 1 to K

Space Complexity: O(N)

Reason: We are using an external array of size ‘n’’.

*/

int solveUtil1(int n, vector<int>& height, vector<int>& dp, int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps = INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(height[i]- height[i-j]);
                mmSteps= min(jump, mmSteps);
            }
        }
        dp[i]= mmSteps;
    }
    return dp[n-1];
}

int solve(int n, vector<int>& height , int k){
    vector<int> dp(n,-1);
    return solveUtil(n-1, height, dp, k);
}

int main() {
int n, k;
cin>>n>>k;
  vector<int> height(n);
  for(auto &el : height) cin>>el;
  vector<int> dp(n,-1);
  cout<<solve(n,height,k);
}





//https://atcoder.jp/contests/dp/submissions/me