//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node,vector<int> adjLs[],int vis[],vector<int>&ls)
  {
      vis[node] =1;
      ls.push_back(node);
      for(auto it : adjLs[node])
      {
          if(!vis[it])
          {
              dfs(it,adjLs,vis,ls);
          }
      }
      
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // converting it into a adjacency list
        vector<int> adjLs[V];
    
        for(int i = 0; i <V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(adj[i][j] == 1 && i != j)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
                
            }
            
        }
        
        // now adjacency list is ready
        int vis[V] = {0};
            vector<int> ls(V); // for storing dfs data
        int count = 0;
        for(int i = 0; i <V;i++)
        {
            if(!vis[i] )
        {
            count++;
            dfs(i,adjLs,vis,ls);
        }
        }
        
        
        
       
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends