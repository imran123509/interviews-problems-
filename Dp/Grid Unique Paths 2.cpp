#include <bits/stdc++.h>
// pre req => grid unique path
using namespace std;
//memoize solution
/*

Time Complexity: O(N*M)

Reason: At max, there will be N*M calls of recursion.

Space Complexity: O((M-1)+(N-1)) + O(N*M)

Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.
*/
int mazeObstaclesUtil(int i, int j, vector<vector<int> > &maze, vector<vector<int> > 
&dp) {
  if(i>0 && j>0 && maze[i][j]==-1) return 0; 
  if(i==0 && j == 0)
    return 1;
  if(i<0 || j<0)
    return 0;
  if(dp[i][j]!=-1) return dp[i][j];
    
  int up = mazeObstaclesUtil(i-1,j,maze,dp);
  int left = mazeObstaclesUtil(i,j-1,maze,dp);
  
  return dp[i][j] = up+left;
  
}

//Tabulation solution
/*
Time Complexity: O(N*M)

Reason: There are two nested loops

Space Complexity: O(N*M)

Reason: We are using an external array of size ‘N*M’’.
*/

int mazeObstaclesUtil1(int n, int m, vector<vector<int>> &maze,vector<vector<int>>
 &dp) 
{
  for(int i=0; i<n ;i++){
      for(int j=0; j<m; j++){
          
          //base conditions
          if(i>0 && j>0 && maze[i][j]==-1){
            dp[i][j]=0;
            continue;
          }
          if(i==0 && j==0){
              dp[i][j]=1;
              continue;
          }
          
          int up=0;
          int left = 0;
          
          if(i>0) 
            up = dp[i-1][j];
          if(j>0)
            left = dp[i][j-1];
            
          dp[i][j] = up+left;
      }
  }
  
  return dp[n-1][m-1];

  
}

int mazeObstacles(int n, int m, vector<vector<int> > &maze){
    vector<vector<int> > dp(n,vector<int>(m,-1));
    return mazeObstaclesUtil(n-1,m-1,maze,dp);
    
}

int main() {

  vector<vector<int> > maze{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = maze.size();
  int m = maze[0].size();
  
  cout<<mazeObstacles(n,m,maze);
}
