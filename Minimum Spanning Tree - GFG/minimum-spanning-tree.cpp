//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

	class DisjointSet{
    vector<int> rank, parent;
    public :
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1,0);
        for(int i = 0; i <= n; i++) // for one base indexing
        {
            parent[i] = i;
        }
    }
        int findUlt(int node)  //? finding ultimate parent
        {
            if(node == parent[node])

            {
                return node;
            }
            //! path compression
            return parent[node] =  findUlt(parent[node]);

        }
        void unionByRank(int u , int v)
        {
            int ulp_u = findUlt(u);
            int ulp_v = findUlt(v);
            if(ulp_u == ulp_v)
            {
                return ;
            }
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else{
                  parent[ulp_v] = ulp_u;
                  rank[ulp_u]++;
            }
        }
    
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.

    int spanningTree(int V, vector<vector<int>> adj[])
    {
         vector<pair<int,pair<int, int>>> edges;
    for(int i = 0; i <V; i++)
    {
        for(auto it : adj[i])
        {
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    DisjointSet ds(V);
    sort(edges.begin(),edges.end());
    int mstWt = 0;
    for(auto it : edges)
    {
        int wt = it.first;
        int v = it.second.second;
        int u = it.second.first;
        if(ds.findUlt(u) != ds.findUlt(v))
        {
            mstWt += wt;
            ds.unionByRank(u,v);
        }
    }
 return mstWt; 
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends