//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n = x.size();
        stack<char>st;   // [({[([{}])]})}
        for(int i = 0; i <n; i++)
        {
            if(x[i] == '(' || x[i] == '[' || x[i] == '{')
                 st.push(x[i]);
            else
            {
                if(st.empty()) return false;
                else
                {
                    if (st.empty())
                return false;
                    
                    char ch = st.top();
                    st.pop();
                    if((ch == '(' && x[i] != ')' )|| (ch == '[' && x[i] != ']') || (ch == '{' && x[i] != '}'))
                    return false;
                    
                }
            }
        }
        if(st.empty()) return true;
        else
        return false;
    }
// bool ispar(string x)
// {
//     int n = x.size();
//     stack<char> st;

//     for (int i = 0; i < n; i++)
//     {
//         if (x[i] == '(' || x[i] == '[' || x[i] == '{')
//         {
//             st.push(x[i]);
//         }
//         else
//         {
//             if (st.empty())
//                 return false;
//             else
//             {
//                 char ch = st.top();
//                 st.pop();
//                 if ((ch == '(' && x[i] != ')') || (ch == '[' && x[i] != ']') || (ch == '{' && x[i] != '}'))
//                     return false;
//             }
//         }
//     }

//     return st.empty();
// }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends