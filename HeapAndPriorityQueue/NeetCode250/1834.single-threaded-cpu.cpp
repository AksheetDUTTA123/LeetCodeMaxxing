#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 */

// @lc code=start
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> result;

        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i); //store index for all tasks
        }

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0]; //sort tasks by enqueue time, this will allow us to easily add tasks to the priority queue when they become available, because we can just iterate 
            //through the sorted tasks array and add tasks to the priority queue when their enqueue time is less than or equal to the current time, this will allow us to efficiently manage the 
            //tasks that are available to be executed at any given time, and we can use the priority queue to always execute the task with the shortest processing time first, which will allow us to minimize the overall processing time of all tasks
        });
        auto comparator = [](const vector<int>& v1, const vector<int>& v2){
            if(v1[1] == v2[1]){
                    return v1[2] > v2[2]; //lower index comes first
                }
                return v1[1] > v2[1]; //shorter processing time comes first
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> pq; 
        long long currentTime = 0; //this is to avoid integer overflow
        int currentIdx = 0; //track position in sorted tasks array(sorted by enqueue time), the currentIdx task is the next task that we need to add to the priority queue when 
        //its enqueue time is less than or equal to the current time, we can use this index to keep track of which tasks have been added to the priority queue and which tasks have not been added yet, this will allow us to efficiently manage the tasks that are available to be executed at any given time, and we can use the priority queue to always execute the task with the shortest processing time first, which will allow us to minimize the overall processing time of all tasks

        while (currentIdx < tasks.size() || !pq.empty()){ //as long as there are tasks that have not been added to the priority queue 
        //or there are tasks in the priority queue that have not been executed, we need to keep processing tasks
            if (pq.empty() && currentTime < tasks[currentIdx][0]){
                currentTime = tasks[currentIdx][0]; //if the priority queue is empty and the current time is less than the enqueue time of the next task, 
                //we need to fast forward the current time to the enqueue time of the next task
                //this becomes the new time and now tasks will populate into the pq
            }
            while(currentIdx < tasks.size() && tasks[currentIdx][0] <= currentTime){ //while there are still tasks that have an enqueue time less than or equal to the current time, we can add them to the priority queue,
                pq.push(tasks[currentIdx]);
                currentIdx++;
            }

    
                auto idx = pq.top();
                pq.pop();
                result.push_back(idx[2]);
                currentTime += idx[1]; //after executing the task, 
                //we need to increment the current time by the processing time of the task, because we have spent that amount of time executing the task, and then we can continue to add tasks to the priority queue and execute tasks until we have executed all tasks

        }
        return result;
    }
};
// @lc code=end

