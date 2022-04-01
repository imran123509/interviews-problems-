#include <bits/stdc++.h>
// pre req => equal subset sum equal to target
using namespace std;
//memoize solution
/*
Time Complexity: O(N*K) + O(N)

Reason: There are N*K states therefore at max ‘N*K’ new problems will be solved and we are running a for loop for ‘N’ times to calculate the total sum

Space Complexity: O(N*K) + O(N)

Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*K)).
*/
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}

//tabulation solution

/*

Time Complexity: O(N*K) +O(N)

Reason: There are two nested loops that account for O(N*K) and at starting we are running a for loop to calculate totSum.

Space Complexity: O(N*K)

Reason: We are using an external array of size ‘N*K’. Stack Space is eliminated.
*/
bool canPartition1(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
        vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        
        if(arr[0]<=k)
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int target= 1; target<=k; target++){
                
                bool notTaken = dp[ind-1][target];
        
                bool taken = false;
                    if(arr[ind]<=target)
                        taken = dp[ind-1][target-arr[ind]];
            
                dp[ind][target]= notTaken||taken;
            }
        }
        
        return dp[n-1][k];

    } 
}

bool canPartition(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return subsetSumUtil(n-1,k,arr,dp);
    } 
}

int main() {

  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();
                                 
  if(canPartition(n,arr))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";
}