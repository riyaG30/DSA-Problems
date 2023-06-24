//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& a) {
        // Code here
         vector<vector<int>> dp(n,vector<int>(n,-1));
         for(int j = 0; j <n; j++) // base caase initialization
          dp[n-1][j] = a[n-1][j];
          for(int i = n-2; i >= 0; i--)
          {
              for(int j = i; j >=0; j--)
              {
                  int d = a[i][j] + dp[i+1][j];
                  int dg = a[i][j] + dp[i+1][j+1];
                  dp[i][j] = min(d,dg);
              }
          }
          return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends