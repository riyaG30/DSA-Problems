//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    struct Cell {
        int row;
        int col;
        int cost;

        Cell(int r, int c, int cst) : row(r), col(c), cost(cst) {}

        bool operator>(const Cell& other) const {
            return cost > other.cost;
        }
    };

    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = grid[0][0];

        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        pq.push(Cell(0, 0, dp[0][0]));

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            Cell curr = pq.top();
            pq.pop();

            int row = curr.row;
            int col = curr.col;
            int cost = curr.cost;

            if (cost > dp[row][col]) {
                continue;
            }

            for (const auto& dir : dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    int newCost = cost + grid[newRow][newCol];

                    if (newCost < dp[newRow][newCol]) {
                        dp[newRow][newCol] = newCost;
                        pq.push(Cell(newRow, newCol, newCost));
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends