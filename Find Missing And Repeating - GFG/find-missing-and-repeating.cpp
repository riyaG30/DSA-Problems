//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int a; // missing number
        int b; // repeating number
        vector<int>ans;
        int res[n+1] = {0};
        for(int i = 0; i < n; i++)   // 1 3  3
        {
            res[arr[i]] += 1;     
        }
        
        for(int i = 1; i <=n;i++)  
        {
           if( res[i] == 0) a = i;
           if( res[i]== 2) b = i;
        }
        ans.push_back(b);
        ans.push_back(a);
        return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends