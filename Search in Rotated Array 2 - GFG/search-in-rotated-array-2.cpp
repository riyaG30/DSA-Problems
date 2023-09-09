//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& arr, int target) {
        // Code here
         int low = 0;
        int high = n-1;
        while(low <= high)
        {
            long long mid = (low+high)/2;
            if(arr[mid] ==  target) return true;
            if(arr[low] == arr[mid] && arr[high] == arr[mid])
            {
                low++;
                high--;
                continue;
            } 
            // checking for the sorted part
            // check left sorted or not
            if(arr[low] <= arr[mid])
            {
                if(arr[low] <= target && target <= arr[mid])
                {
                    high = mid-1;
                }
                else
                low = mid+1;
            }
            // means right sorted 
            else
            {
                if(arr[mid]<= target && target <= arr[high])
                {
                    low = mid+1;
                }
                else
                high = mid-1;
            }
        }
        return false; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends