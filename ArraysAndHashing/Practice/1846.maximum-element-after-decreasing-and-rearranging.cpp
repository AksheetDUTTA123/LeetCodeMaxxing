#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1846 lang=cpp
 *
 * [1846] Maximum Element After Decreasing and Rearranging
 */

// @lc code=start
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    //     sort(arr.begin(), arr.end());
    //     if(arr[0] != 1){
    //         arr[0] = 1;
    //     }
    //     for(int i = 1; i < arr.size(); i++){
    //         if(arr[i] > arr[i-1] + 1){
    //             arr[i] = arr[i-1] + 1;
    //         }
    //     }
    //     return arr[arr.size()-1];
    int n = arr.size();
    vector<int> counts(arr.size() + 1, 0); //these are the counts of the numbers in the array, 
    //we will use this to find the maximum number that can be formed after rearranging and decrementing the numbers in the array
    for(int num : arr){
        counts[min(num, (n))]++; //we will count the number of times each number appears in the array, 
        //but we will cap the counts at n, because we cannot have a number greater than n in the final array after rearranging and decrementing.
    }
    int ans = 0;
    for(int i = 1; i < counts.size(); i++){
        ans = min(ans + counts[i], i); //we will add the counts of the current number to the previous number, and we will take the minimum of that and the current number, 
        //because we cannot have a number greater than the current number in the final array after rearranging and decrementing.
    }
    return ans;
     }
};
// @lc code=end

