//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int arr[], int n)
    {
          int globalans = 0, localans = 0;

    int onescount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            onescount++;
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 0)
        {
            localans++;
        }
        else
        {

            localans--;
        }
        globalans = max(globalans, localans);

        if (localans < 0)
        {
            localans = 0;
        }
    }

    return onescount + globalans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends