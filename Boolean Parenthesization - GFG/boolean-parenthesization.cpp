//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int fn(int i, int j, bool isTrue, string& s, vector<vector<vector<long long>>>& dp) {
        if (i == j) {
            if (isTrue) {
                return s[i] == 'T';
            }
            return s[i] == 'F';
        }
        
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
            
        int res = 0;
            
        for (int k = i + 1; k < j; k += 2) {
            int lefttrue = fn(i, k - 1, true, s, dp);
            int leftfalse = fn(i, k - 1, false, s, dp);
            int righttrue = fn(k + 1, j, true, s, dp);
            int rightfalse = fn(k + 1, j, false, s, dp);
            
            int ltrt = (lefttrue * righttrue) % 1003;
            int ltrf = (lefttrue * rightfalse) % 1003;
            int lfrt = (leftfalse * righttrue) % 1003;
            int lfrf = (leftfalse * rightfalse) % 1003;
            
            if (s[k] == '&') {
                res = isTrue ? (res + ltrt) % 1003 : (res + ltrf + lfrt + lfrf) % 1003;
            } else if (s[k] == '|') {
                res = isTrue ? (res + ltrt + ltrf + lfrt) % 1003 : (res + lfrf) % 1003;
            } else {
                res = isTrue ? (res + ltrf + lfrt) % 1003 : (res + ltrt + lfrf) % 1003;
            }
        }
        
        return dp[i][j][isTrue] = res;
    
}
    int countWays(int N, string s){
         vector<vector<vector<long long > > > dp(
        N, vector<vector<long long > >(N, vector<long long >(N, -1)));
        return fn(0,N-1,1,s,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends