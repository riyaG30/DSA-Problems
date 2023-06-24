//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod = (int) 1e9+7;
  int solve(int a, int b,vector<vector<int>> &dp,vector<vector<int>>& grid)  // tabulation
    {
        for(int i = 0; i <a;i++)
        {
            for(int j  = 0; j <b; j++)
            {
                if(i >= 0 && j >= 0 && grid[i][j] == 1) dp[i][j] = 0;
               else if(i == 0 && j == 0)
                dp[0][0] = 1;
                else
                {
                    int up = 0,left = 0;
                    if(i >0)  up = dp[i-1][j];
                    if(j >0)  left = dp[i][j-1];
                    dp[i][j] = (up+left) % mod;
                }
                
            }
        }
        return dp[a-1][b-1];
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
       return solve(n,m,dp,grid);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends