//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void help(int i, int k, int sum,int n, vector<int> &subset, vector<vector<int>> &ans)
{
    if( k == 0  )
    {
        if( sum == n)
        {
            ans.push_back(subset);
            return;
        }
        else
        {
            return;
        }
       
    }
     if( i == 10) return;
     if( sum > n)  return ;

    // pick
    sum += i;
    subset.push_back(i);
    help(i+1,k-1,sum,n,subset,ans);
    // backrtracking
    sum -= i;
    subset.pop_back();
      

      // notpick
      help(i+1,k,sum,n,subset,ans);

}
    vector<vector<int>> combinationSum(int k, int n) {
         vector<vector<int>> ans;
         vector<int>subset;
         int sum  = 0;
         help(1,k,sum,n,subset,ans);
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends