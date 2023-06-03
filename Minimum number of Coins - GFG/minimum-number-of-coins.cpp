//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        // code here
         vector<int> notes{ 2000,500,200,100,50,20,10,5,2,1 };
         vector <int>v;
         int i = 0;
         int sum = n;
         while(sum != 0 and  i < notes.size())
         {
             if(notes[i] <= sum )
             {
                 sum = sum-notes[i];
                 v.push_back(notes[i]);
             }
             else
             i++;
         }
         return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends