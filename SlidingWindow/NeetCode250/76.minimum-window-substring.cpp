#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */
//MUST REVIEW THIS QUESTION AND SLIDING WINDOW PATTERN
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charFreq; //store t character frequency
        unordered_map<char, int> windowFreq; //store current window character frequency
        for(int i = 0; i < t.size(); i++){
            charFreq[t[i]]++;
        }
        int left = 0;
        int right = 0;
        int minStart; //starting index of the minimum window found so far
        int minLength = INT_MAX;
        int required = charFreq.size();
        int formed = 0; //number of unique characters in the current window that match the required frequency in t

        while(right < s.size()){
            char c = s[right]; //add character at right pointer to the window
            windowFreq[c]++;


            if(charFreq.count(c) && windowFreq[c] == charFreq[c]){ //if character is in t and frequency is equal, formed can be incrememented, because we have one more character that matches the required frequency in t
                formed++;
            }
            while(left <= right && formed == required){ //this is here, we want to shrink window as much as possible, while still maintaining the condition that all required characters are present in the window with the correct frequency
                if(right - left + 1 < minLength){ //if current window smaller than minLength, update minLength and minStart
                    minLength = right - left + 1;
                    minStart = left;
                }

            char leftChar = s[left]; //remove character at left pointer from the window
            windowFreq[leftChar]--; 
            if(charFreq.count(leftChar) && windowFreq[leftChar] < charFreq[leftChar]){
                formed--; //since frequency of leftChar in the window is now less than the required frequency in t, we decrement formed, because we no longer have all required characters with the correct frequency in the window
            }
            left++;  //move left pointer to the right to shrink the window
            }
            right++; //move right pointer to the right to expand the window
        }
        return minLength == INT_MAX ? "": s.substr(minStart, minLength);
    }
};
// @lc code=end

