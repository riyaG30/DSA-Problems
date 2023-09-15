//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f (int i, int arr[],int target,vector<vector<int>>dp)
{
    if(dp[i][target] != -1) return dp[i][target];
    if(i <0) return 0;
    if(i == 0) return (arr[0] == target);
   
    int not_take = f (i-1,arr,target,dp);
    
    int take = false;
    if(arr[i]<= target)   take = f(i-1,arr,target-arr[i],dp);
    return dp[i][target] = (take || not_take);
}
bool fun(int n, int arr[], int target) {
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(target + 1, false));

    // Initialize the first row
    for (int j = 0; j <= target; j++) {
        if (arr[0] == j) {
            dp[0][j] = true;
        }
    }

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= target; j++) {
            // If we can achieve the current sum j without including arr[i]
            dp[i][j] = dp[i - 1][j];

            // If arr[i] is less than or equal to j, check if we can achieve (j - arr[i])
            if (arr[i] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i]];
            }
        }
    }

    return dp[n - 1][target];
}
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum  = 0;
    
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        if(sum % 2 != 0) return 0;
        int target = sum /2;
         
        return fun(n,arr,target);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends