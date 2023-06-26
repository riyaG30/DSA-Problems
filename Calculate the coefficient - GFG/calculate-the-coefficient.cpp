//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

#define ll long long int
class Solution{
    public:
    int permutationCoeff(int n, int k){
        //Code here
        ll mod = 1e9+7;
        ll p = 1;
        for(ll i  = 0; i <k;i++)
        {
            p = (p * (n - k + i + 1)) % mod;
        }
        return p ;
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Solution ob;
        int ans = ob.permutationCoeff(n,k);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends