//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int divisor(vector<int> arr, int mid)
  {
      int sum = 0;
      for(int i = 0; i < arr.size();i++)
      {
          sum += ceil((double)(arr[i]) / (double)(mid));
      }
      return sum;
  }
    int smallestDivisor(vector<int>& arr, int K) 
    {
        
        int high = INT_MIN;
        int ans = 0;
        for(int i = 0; i < arr.size();i++)
        {
            high = max(high,arr[i]);
        }
        int low = 1;
        while(low <= high)
        {
            long long mid = (low+high)/2;
            if(divisor(arr,mid) <= K)
            {
                ans = mid;
                high = mid-1;
            }
            else 
            low = mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends