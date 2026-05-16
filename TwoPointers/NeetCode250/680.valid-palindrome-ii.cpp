#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
             if(s[left] != s[right]){
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1); //if the characters at left and right are not the same, we can check if by skipping the letter on the left or right we can get a palindrome. If either of those is true, return true. If not, return false.
             }
             left++;
             right--;
        }
        return true;
    }
    bool isPalindrome(string& s, int left, int right){ //make helper so can run this function within the main function for when deletion has to take place
        while(left < right){
             if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
        }
        return true;
    }
                 /*
s = "abcbxa"  (needs one skip)

Main loop:

left=0, right=5 → 'a' == 'a' ✓ → left=1, right=4
left=1, right=4 → 'b' == 'x' ✗ → mismatch!

Now we check two substrings:

isPalindrome(s, 2, 4) — skip left, check "cbx"

left=2, right=4 → 'c' == 'x' ✗ → return false

isPalindrome(s, 1, 3) — skip right, check "bcb"

left=1, right=3 → 'b' == 'b' ✓ → left=2, right=2
left=2, right=2 → loop ends
return true
             */
};
// @lc code=end

