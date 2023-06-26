//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

     // memorization
        bool solve1(int ind,int target,vector<int> arr,vector<vector<int>> &dp)
        {
            if(target == 0) return true;
            if(ind == 0) return (arr[0] == target);
            if(dp[ind][target] != -1) return dp[ind][target];
            bool not_take = solve1(ind-1,target,arr,dp);
            bool take = false;
            if(target >= arr[ind])
            take = solve1(ind-1,target-arr[ind],arr,dp);
            return dp[ind][target] = (take || not_take);
        }
        bool solve(vector<int> arr, int target)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1));
    
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true; // for all the targets = 0, it will be true
    }
    
    dp[0][arr[0]] = true;
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool not_take = dp[i - 1][j];
            bool take = false;
            if (j >= arr[i])
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = (take || not_take);
        }
    }
    
    return dp[n - 1][target];
}

    bool isSubsetSum(vector<int>arr, int target){
        // code here 
        int n = arr.size();
        
        vector<vector<int>> dp(n,vector<int>((target+1),-1));
      // return solve1(n-1,target,arr,dp);   // memorization

      return solve(arr,target);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends