//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	 int lcs(int x, int y, string s, string st)
    {
        // your code here
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        // base cases
        for(int j = 0; j <= y;j++) dp[0][j] = 0;
         for(int i = 0; i<= x;i++) dp[i][0] = 0;
         // now express in form of nested loop
         for(int i = 1; i <= x; i++)
         {
             for(int j = 1; j <= y; j++)
             {
                 if(s[i-1] == st[j-1])
                 dp[i][j] = 1+dp[i-1][j-1];
                 else
                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
             }
         }
         return dp[x][y];
    }
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.size();
	    int m = str2.size();
	    return (n+m - 2*lcs(n,m,str1,str2));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends