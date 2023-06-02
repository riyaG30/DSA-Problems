//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

  static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] < b[1];
    }
    vector<int> maxMeetings(int n,vector<int> &start,vector<int> &end){
        
         vector<vector<int>> v;
         vector<int> vtr;
        for(int i = 0; i <n; i++)
        {
           
            v.push_back({start[i],end[i],i+1});
            
        }
        sort(v.begin(),v.end(),cmp);
        int count  = 1;
        vtr.push_back(v[0][2]);
        int ansEnd = v[0][1];
        for(int i = 1; i < n;i++)
        {
            if(v[i][0] > ansEnd)
            {
                vtr.push_back(v[i][2]);
                
                ansEnd = v[i][1];
            }
        }
        sort(vtr.begin(),vtr.end());
        
        return vtr;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends