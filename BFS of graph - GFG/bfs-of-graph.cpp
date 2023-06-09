//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // visited graph
        int visit[V] = {0};   //  initially make it 0
        visit[0] = 1;    // the 0th elemnt will be 1 as it is 0 based graph, and starting from 0
         queue<int> q; // it will store the elements
         q.push(0); // the first element will be stored
         
         
         vector<int> bfs;
         while(!q.empty()){
             int node = q.front();
             q.pop();
             bfs.push_back(node);
             // visiting the node which has been poped out, And xhecking its neighbours
             for(auto it : adj[node])
             {
                 if(!visit[it])
                 {
                     visit[it] = 1;
                     q.push(it);
                 }
             }
         }
         return bfs;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends