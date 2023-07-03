//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  int lcs(string s, string st)
    {
        // your code here
        int x = s.size();
        int y = st.size();
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
    int longestPalinSubseq(string A) {
        //code here
        string B =A;
        reverse(B.begin(),B.end());
        return lcs(A,B);
    }
    int countMin(string str){
    //complete the function here
    int len = str.size();
    int pal =   longestPalinSubseq(str);
    return (len-pal);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends