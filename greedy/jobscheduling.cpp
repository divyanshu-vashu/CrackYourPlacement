//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 


#include<iostream>
#include<vector>

using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
         sort(arr, arr + n, [](const Job &a, const Job &b) {
            return a.profit > b.profit;
        });
        
        // Find the maximum deadline to know the total number of available slots
        int max_deadline = 0;
        for (int i = 0; i < n; i++) {
            max_deadline = max(max_deadline, arr[i].dead);
        }
        
        // Create a slot array to track free time slots (0 means available, 1 means occupied)
        vector<int> slot(max_deadline + 1, -1);  // using -1 to mark unoccupied slots
        
        int count = 0, sum = 0; // Count of jobs done and total profit
        
        for (int i = 0; i < n; i++) {
            // Try to place the job at the latest possible time slot <= arr[i].dead
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    // Slot is available, schedule the job here
                    slot[j] = arr[i].id;
                    count++;
                    sum += arr[i].profit;
                    break;
                }
            }
        }
        
        return {count, sum};
    
    
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
/*

// Sort with a custom comparator
    sort(a.begin(), a.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        // Sort by the first element in increasing order
        // If the first elements are equal, sort the second element in decreasing order
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    });
*/