//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool isPalidrome(int i, int j, const std::string &s) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
    int palindromicPartition(string s)
    {
        vector<int> dp(s.size() + 1, 0);
    int n = s.size();

    for (int i = n - 1; i >= 0; i--) {
        int mini = 1e9; // Initialize mini with a large value
        for (int j = i; j < n; j++) {
            if (isPalidrome(i, j, s)) {
                int cost = 1 + dp[j + 1];
                mini = min(mini, cost);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends