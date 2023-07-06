//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool detect(int src,vector<int>adj[],int vis[])
  {
      vis[src] =1; 
      queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it :adj[node])
            {
                if(!vis[it])
                {
                    vis[it] =1;
                    q.push({it,node});
                    
                }
                // if it has been visited and it was not in the path
                else if(parent != it)
                {
                   return true; 
                }
            }
        }
        return false;
        
  }
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int N, vector<int> adj[]) {
        int vis[N] = {0};
        // now if there are multiple connected components
        for(int i = 0; i <N; i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis)) return true;
            }
        
            
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends