#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int count[26] = {0};
        for(char task : tasks){
            count[task - 'A']++; //need to track the count of each task
        }

        std::priority_queue<int> heap;
        for(int i = 0; i < 26; i++){
            if(count[i] > 0){
                heap.push(count[i]); //if the count of a task is greater than 0, we can add it to the heap, we want to use a max heap to always execute the task with the highest count first, 
                //because that will allow us to minimize the number of idle intervals, if we execute a task with a lower count first, then we might end up with more idle intervals later on when we have 
                //more tasks with higher counts that need to be executed
            }
        }

        int timer = 0; //this tracks the current time
        queue<pair<int, int>> waitingPeriod; //this is all the tasks that are in a cooldown mode, have to wait for timer to hit timer + n before we can add them back to the heap, 
        //we need to track the remaining count of the task and the time when we can add it back to the heap, so we can use a pair to store that information in the queue,
        while(!heap.empty() || !waitingPeriod.empty()){ //as long as there are tasks in the heap or there are tasks in the waiting period, we need to keep executing tasks or waiting for tasks to come out of the waiting period
            timer++; //increment clock by 1
            if(!heap.empty()){
                int remaining = heap.top() - 1; //this task is currently not in waitingPeriod, so we can execute it, we need to decrement the count of the task by 1,
                // because we have executed it once, and then we need to check if there are any remaining instances of the task that need to be executed,
                // if there are, then we need to add it to the waiting period,
                heap.pop();

                if(remaining > 0){
                    waitingPeriod.push({remaining, timer + n});
                }
            }

            if(!waitingPeriod.empty() && waitingPeriod.front().second == timer){ //if the task at the front of the waiting period has reached its cooldown time, 
            //then we can add it back to the heap, because we can execute it again
                heap.push(waitingPeriod.front().first);
                waitingPeriod.pop();
            }


        }
            return timer;
    }
};
// @lc code=end

