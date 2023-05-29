//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        deque<int> dq;  
  
  
    vector<int> maxes(n-k+1);
    // Process the first k elements of the array separately  
    for (int i = 0; i < k; i++) {  
        // Remove any element that is smaller than the current element  
        // from the back of the deque  
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {  
            dq.pop_back();  
        }  
  
        // Add the current element to the back of the deque  
        dq.push_back(i);  
    }  
  
    // Process the remaining elements of the array  
    for (int i = k; i < n; i++) {  
        // The first element in the deque is the maximum of the previous  
        // subarray, so store it in the maxes array  
        maxes[i-k] = arr[dq.front()];  
  
        // Remove any element that is smaller than the current element  
        // from the back of the deque  
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {  
            dq.pop_back();  
        }  
  
        // Remove any element that is outside the current window  
        // from the front of the deque  
        while (!dq.empty() && dq.front() <= i-k) {  
            dq.pop_front();  
        }  
  
        // Add the current element to the back of the deque  
        dq.push_back(i);  
    }  
  
    // Store the maximum of the last subarray  
    maxes[n-k] = arr[dq.front()];  
  
    return maxes;  
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends