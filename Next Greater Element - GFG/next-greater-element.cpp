//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n){
         
        vector<long long> v(n);
        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                v[s.top()] = nums[i];
                s.pop();
            }
            if(i<n){
                s.push(i);
            }
        }
        while(!s.empty()){
            v[s.top()]=-1;
            s.pop();
        }
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends