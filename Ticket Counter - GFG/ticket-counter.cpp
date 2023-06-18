//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int distributeTicket(int N, int K) {
     int s = 1;
        int e = N;
        while(s<=e){
            if(e - s>=K)
                s = s + K;
            else
                return e;
            if(e-s>=K)
                e = e - K;
            else
                return s;
        }
        return -1;
}

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends