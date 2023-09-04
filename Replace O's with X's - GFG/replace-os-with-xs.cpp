//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    
void bfs(int r,int c,vector<vector<int>>&visited,vector<vector<char>> &mat){
    if(visited[r][c])return ;
    queue<pair<int,int>>q;
    q.push({r,c});
    visited[r][c]=1;
    while(!q.empty()){
        int l=q.size();
        while(l>0){
            int r=q.front().first;
            int c=q.front().second;
            mat[r][c]='Y';
            if(r+1<mat.size() && !visited[r+1][c] && mat[r+1][c]=='O'){
                visited[r+1][c]=1;
                q.push({r+1,c});
            }
             if(c+1<mat[0].size() && !visited[r][c+1] && mat[r][c+1]=='O'){
                visited[r][c+1]=1;
                q.push({r,c+1});
            }
             if(r-1>=0 && !visited[r-1][c] && mat[r-1][c]=='O'){
                visited[r-1][c]=1;
                q.push({r-1,c});
            }
             if(c-1>=0 && !visited[r][c-1] && mat[r][c-1]=='O'){
                visited[r][c-1]=1;
                q.push({r,c-1});
            }
            q.pop();
            l--;
        }
    }
    return ;
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
       vector<vector<int>>visited(n,vector<int>(m,0));
       for(int i=0;i<mat[0].size();i++)if(mat[0][i]=='O')bfs(0,i,visited,mat);
       for(int i=0;i<mat[0].size();i++)if(mat[n-1][i]=='O')bfs(n-1,i,visited,mat);
       for(int i=0;i<n;i++)if(mat[i][0]=='O')bfs(i,0,visited,mat);
       for(int i=0;i<n;i++)if(mat[i][m-1]=='O')bfs(i,m-1,visited,mat);
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++)if(mat[i][j]=='O')mat[i][j]='X';
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++)if(mat[i][j]=='Y')mat[i][j]='O';
       }
       return mat;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends