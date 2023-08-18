//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k, vector<int>& arr){
         vector<int> dp(n+1,0);
      //  return f(0,n,k,arr,dp);
      dp[n] = 0;
      
    for(int ind = n-1; ind >=0; ind--)
    {
        int len = 0;
    int maxAns = -1e9;
    int maxi = -1e9;
    int sum = 0;
        for(int j = ind; j < min(n,ind+k); j++)
    {
        len++;
        maxi = max(maxi,arr[j]);
        sum = (len*maxi) + dp[j+1];
        maxAns = max(maxAns,sum);
    }
     dp[ind] = maxAns;
    }
    return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends