//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
        
        string temp = "";
        string ans = "";
        for(int i = s.length()-1; i >= 0; i--)
        {
            
            if(s[i] == '.')
            {
                reverse(temp.begin(),temp.end());
                ans = ans + temp + '.';
                temp = "";
            }
            else
            {
                temp = temp+s[i];
            }
        }
        
        // for the first elemnt
         reverse(temp.begin(),temp.end());
         ans = ans+temp;
         return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends