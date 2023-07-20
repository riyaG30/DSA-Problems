//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        
        stack<int>st;
        for(auto val :a)
        {
            if(val > 0) // if the value is positive then just push it , nothing to be done
            st.push(val);
            
            //when -ve
            else
            {
                // all the left elements are positive and smaller
                while(st.size() >0 && st.top() > 0 && st.top() < -val)
                {
                    st.pop();
                }
                if(st.size() > 0 && st.top() == (-val))
                {
                    st.pop();
                }
                else if (st.size() >0 && st.top() > (-val))
                {
                    // the element will not be pushed, and previous will stay as the lement got aollided
                }
                else
                {
                    st.push(val);
                }
                
            }
        }
        vector<int> v;
        int n = st.size();
        while(n--)
        {
            int top = st.top();
            st.pop();
            v.push_back(top);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends