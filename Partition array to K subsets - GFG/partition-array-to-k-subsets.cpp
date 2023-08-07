//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool help(int i, int buckNum, int buckSum,int reqSum,int k,int nums[], vector<int> &alreadyPicked, int n)
{

    //  base conditions 
    if(buckSum == reqSum)
    {
        return help(0,buckNum+1,0,reqSum,k,nums,alreadyPicked,n);
    }
    if(buckSum > reqSum) return false;
    if(i == n) return false;
    if(buckNum > k) return true;


if(alreadyPicked[i] == 1)
{
    return help(i+1,buckNum,buckSum,reqSum,k,nums,alreadyPicked,n);
}
else
{
    // pick
    buckSum += nums[i];
    alreadyPicked[i] = 1;
    bool op1 = help(i+1,buckNum,buckSum,reqSum,k,nums,alreadyPicked,n);


    // skip
    // so first to backtrack and undo the changs
    buckSum -= nums[i];
     alreadyPicked[i] = 0;
       bool op2 = help(i+1,buckNum,buckSum,reqSum,k,nums,alreadyPicked,n);
        return op1 || op2;

}
}
    bool isKPartitionPossible(int nums[], int n, int k)
    {
          vector<int>alreadyPicked(n,0);
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        if(sum % k != 0) return false;
        int reqSum = sum/k;
       return  help(0,1,0,reqSum,k,nums,alreadyPicked,n);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends