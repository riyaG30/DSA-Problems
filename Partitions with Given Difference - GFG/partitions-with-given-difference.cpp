//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod =  1000000007;
  int perfectSum(vector<int>& arr, int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> dp(n,vector<int>(sum+1, 0));
        
        for(int i=0; i<n; i++){
            dp[i][0]=1;
        }
        if(arr[0]<=sum) dp[0][arr[0]]=1;
        if(arr[0]==0) dp[0][0]=2;
        
        for(int i=1; i<n; i++){
            for(int tar=0; tar<=sum; tar++){
                int ntake=dp[i-1][tar]%mod;
                int take=0; 
                if(arr[i]<=tar) take=dp[i-1][tar-arr[i]]%mod;
                dp[i][tar]=(take+ntake)%mod;
            }
        }
        return dp[n-1][sum]%mod;
	}

    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total = 0;
        for(auto &it : arr) total += it;
        if((total - d) < 0 || (total - d) % 2) return 0;
        return  perfectSum(arr,n,(total-d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends