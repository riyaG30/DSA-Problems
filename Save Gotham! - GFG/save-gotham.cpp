//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int save_gotham(int arr[], int n);



int main() {
    
    int t;
    cin>> t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        cout << save_gotham(arr, n) << endl;
    }
    
	return 0;
}
// } Driver Code Ends


int save_gotham(int elements[], int n)
{
    vector<int> res(n, 0);
    stack<int>st;
    st.push(elements[n - 1]);
    for(int i = n - 2; i >= 0; i--) {
    while(!st.empty() && elements[i] >= st.top()) st.pop();
    res[i] = st.empty() ? 0 : st.top();
    st.push(elements[i]);
        }
        int ans=0;
        for(int i=0;i<res.size();i++)
            ans+=res[i];
        return ans;
}