//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>((w+1) , 0));
       for(int i = wt[0]; i <= w; i++ )
       {
           dp[0][i] = val[0];
       }
       for(int ind = 1 ; ind < n; ind++)
       {
           for(int j = 0; j <=w; j++)
           {
               int not_take = 0+ dp[ind-1][j];
               int take = 0;
               if(wt[ind] <= j)
               take = val[ind] + dp[ind-1][j-wt[ind]];
               dp[ind][j] = max(take,not_take);
           }
       }
       return dp[n-1][w];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends