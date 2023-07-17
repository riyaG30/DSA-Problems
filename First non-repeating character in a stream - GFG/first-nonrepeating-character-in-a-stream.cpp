//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    unordered_map<char,int> count;
		    queue<char>q;
		    for(auto x : A)
		    {
		        // increase count
		        count[x]++;
		        
		        // queue me push kar do
		        q.push(x);
		        while(!q.empty())
		        {
		            if(count[q.front()] > 1)
		            // repeating character
		            q.pop();
		            else
		            {
		                // ans me push kara do
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty())

                    ans.push_back('#');		        
		    }
		    
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends