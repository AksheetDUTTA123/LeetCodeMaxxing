#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestRect = 0;
        stack<int> stk;
        
        // Push sentinel value to avoid empty stack checks
        // and simplify width calculation for bars that extend to the leftmost boundary
        stk.push(-1);
        
        for (int i = 0; i < heights.size(); i++) {
            // Pop bars that are taller than the current bar, since the current bar
            // limits how far right their rectangle can extend
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) { //while the current bar is shorter than the bar at the top of the stack, 
            //pop from the stack, because the current bar limits how far right the rectangle of the bar at the top of the stack can extend
                int height = heights[stk.top()];
                stk.pop();
                // Width is from the new top of stack (left boundary) to current index (right boundary)
                int width = i - stk.top() - 1;
                largestRect = max(largestRect, height * width);
            }
            // Current bar hasn't been bounded yet, push it for future processing
            stk.push(i);
        }

        // Remaining bars in the stack never found a shorter bar to their right
        // so their right boundary is the end of the array
        while (stk.top() != -1) {
            int height = heights[stk.top()];
            stk.pop();
            int width = heights.size() - stk.top() - 1;
            largestRect = max(largestRect, height * width);
        }

        return largestRect;
    }
};
// @lc code=end

