#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3751 lang=cpp
 *
 * [3751] Total Waviness of Numbers in Range I
 */

// @lc code=start
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2 < 100){
            return 0;
        }
        int totalWaviness = 0;
        if(num1 < 100){
            num1 = 100;
        }
        for(int i  = num1; i <= num2; i++){
            string intComp = to_string(i);
            for(int j = 1; j < intComp.length() - 1;j++){
                if(intComp[j] > intComp[j + 1] && intComp[j] > intComp[j - 1]){
                    totalWaviness++;
                    continue;
                }
                if(intComp[j] < intComp[j + 1] && intComp[j] < intComp[j - 1]){
                    totalWaviness++;
                    continue;
                }
            }
        }
        return totalWaviness;
    }
};
// @lc code=end

