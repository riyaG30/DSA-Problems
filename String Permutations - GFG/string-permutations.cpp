//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void helper(int pos, vector<string> &str, string &s)
    {
        if(pos == s.size())
        {
            str.push_back(s);
            return;
        }
        for(int i = pos; i < s.size(); i++)
        {
            swap(s[i],s[pos]);
            helper(pos+1,str,s);
            // backtrACK    
            swap(s[i],s[pos]);
        }
        
    }
    vector<string> permutation(string s)
    {
        vector<string> str;
        helper(0,str,s);
        sort(str.begin(),str.end());
        return str;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends