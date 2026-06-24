#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
    int isVowel(char c){
        if(c == 'a' || c == 'e' ||  c == 'i' ||  c == 'o' ||  c == 'u'){
            return 1;
        }
        else{
            return 0;
        }
    }
    int maxVowels(string s, int k) {
        int maxNum = 0;
        int currWindow = 0;
        for(int i = 0; i < k; i++){
            currWindow += isVowel(s[i]);
        }

        maxNum = max(maxNum, currWindow);

        for(int i = k; i < s.length(); i++){
            currWindow -= isVowel(s[i - k]);
            currWindow += isVowel(s[i]);
            maxNum = max(maxNum, currWindow);
        }

        return maxNum;
    }
};
// @lc code=end

