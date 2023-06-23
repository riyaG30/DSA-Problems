//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int k, vector<char> &tasks) {
   std::unordered_map<char, int> taskCount;
    int maxFrequency = 0;
    for (char task : tasks) {
        taskCount[task]++;
        maxFrequency = std::max(maxFrequency, taskCount[task]);
    }

    // Step 2: Calculate the number of tasks with max frequency
    int maxFrequencyCount = 0;
    for (const auto& entry : taskCount) {
        if (entry.second == maxFrequency) {
            maxFrequencyCount++;
        }
    }

    // Step 3: Calculate the least number of units of time
    int partitions = maxFrequency - 1;
    int emptySlots = partitions * (k - maxFrequencyCount + 1);
    int availableTasks = N - (maxFrequency * maxFrequencyCount);
    int idleSlots = std::max(0, emptySlots - availableTasks);
    int leastTime = N + idleSlots;

    return leastTime;
}

    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends