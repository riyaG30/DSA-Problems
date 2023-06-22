//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &v) {
   // sort(v.begin(), v.end());
    map<int, int> mpp; // Declare and initialize mpp as a map
    
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
        if (v[i] > 5) {
            int change = v[i] - 5;
            if (change == 5) {
                if (mpp[5] <= 0) {
                    return false;
                }
                mpp[5]--;
            } else if (change == 10) {
                if (mpp[10] <= 0) {
                    if (mpp[5] < 2) {
                        return false;
                    }
                    mpp[5] -= 2;
                } else {
                    mpp[10]--;
                    if (mpp[5] <= 0) {
                        return false;
                    }
                    mpp[5]--;
                }
            } else if (change == 15) {
                if (mpp[10] > 0) {
                    mpp[10]--;
                    if (mpp[5] <= 0) {
                        return false;
                    }
                    mpp[5]--;
                } else if (mpp[5] >= 3) {
                    mpp[5] -= 3;
                } else {
                    return false;
                }
            }
        }
    }
    
    for (auto &it : mpp) {
        if (it.second < 0) {
            return false;
        }
    }
    
    return true;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends