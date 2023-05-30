//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    bool adjacentSearch(vector<vector<char>>& board, string word, int i, int j, int len) {
        if (len == word.length())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return false;
        if (board[i][j] != word[len])
            return false;

        board[i][j] = '*';
        bool ans =
            adjacentSearch(board, word, i - 1, j, len + 1) || // up
            adjacentSearch(board, word, i + 1, j, len + 1) || // down
            adjacentSearch(board, word, i, j - 1, len + 1) || // left
            adjacentSearch(board, word, i, j + 1, len + 1);   // right

        board[i][j] = word[len];
        return ans;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && adjacentSearch(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends