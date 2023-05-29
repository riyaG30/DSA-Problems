//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  
  public:
      vector<string> ans;

    class trie {
    public:
        trie* ch[26];
        vector<string> al;
        trie() {
            for (int i = 0; i < 26; i++) {
                ch[i] = nullptr;
            }
        }
    };
    void printAllWords(trie* root) {
        for (string str : root->al) ans.push_back(str);
        for (int i = 0; i < 26; i++) {
            trie* child = root->ch[i];
            if (child != nullptr) printAllWords(child);
        }
    }

    int find(string s, trie* root) {
        for (int i = 0; i < s.length(); i++) {
            if (root->ch[s[i] - 'A'] == nullptr)
                return 0;
            root = root->ch[s[i] - 'A'];
        }
        printAllWords(root);
        return 1;
    }

    void build(vector<string>& a, int size, trie* root) {
        trie* temp = nullptr;
        for (int i = 0; i < size; i++) {
            temp = root;
            for (int j = 0; j < a[i].length(); j++) {
                if (isupper(a[i][j])) {
                    if (temp->ch[a[i][j] - 'A'] == nullptr)
                        temp->ch[a[i][j] - 'A'] = new trie();
                    temp = temp->ch[a[i][j] - 'A'];
                }
            }
            temp->al.push_back(a[i]);
        }
    }

    vector<string> CamelCase(int N, vector<string>& Dictionary, string Pattern) {
        trie* root = new trie();
        build(Dictionary, N, root);
        find(Pattern, root);

        sort(ans.begin(), ans.end());
        if (ans.empty()) ans.push_back("-1");
        return ans;
    }
};
   

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends