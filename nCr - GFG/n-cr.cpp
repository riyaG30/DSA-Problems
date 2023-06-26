//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
          if(r>n)
            return 0;
        else if(r == 1)
            return n;
        else if(n == r)
            return 1;
            vector<vector<int>> dp(r,vector<int>(n));
       
        for(int i = 0; i<n; i++)
            dp[0][i] = i+1;
        
        for(int i = 1; i<r; i++){
            for(int j = 1; j<n; j++){
                if(i>j)
                    dp[i][j] = 0;
                else if(i == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j-1])%1000000007;
            }
        }
        
        return dp[r-1][n-1]%1000000007;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends