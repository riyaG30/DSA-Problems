//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int f(int i, int j, int* arr, vector<vector<int>> &dp)
{


    if(dp[i][j] != -1) return dp[i][j];
    if( i == j) return 0;
    int mini = 1e9;
    for (int k = i; k < j; k++) // partition of the array
    {
      int steps =
          (arr[i - 1] * arr[k] * arr[j]) + f(i, k, arr,dp) + f(k + 1, j, arr,dp);
      if(steps < mini) mini = steps;
    }
    return  dp[i][j] = mini;
}
    int matrixMultiplication(int n, int arr[])
    {
        // code here
          vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(1,n-1,arr,dp);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends