//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int arrmax(vector<int> v)
{
   int maxi = INT_MIN;
    for(auto x :v)
    {
        maxi = max(maxi,x);
    }
    return maxi;
}
int calc (vector<int> v, int h)
{
    int n  = v.size();
    long long total = 0;
    for(int i = 0; i <n;i++)
    {
           total += (int)ceil(double(v[i]) / double(h)); // Use std::ceil
    }
    return total;
}
    int Solve(int N, vector<int>& v, int h) {
         int low = 0, high = arrmax(v);
        while(low <= high)
        {
            long long mid = (low +high) /2;
            int total = calc(v,mid);
            if(total <= h)
            high= mid-1;
            else
            low = mid+1;
        }
        return low;
        
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends