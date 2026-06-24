#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
private:
    int palindrome(string& s, int l, int r){ //this function will count the number of 
    //palindromic substrings in the string s, given the left and right pointers
        int count = 0;
        while(l >= 0 && r < s.length()){ //this while loop will run until the left pointer 
        //is greater than or equal to 0 and the right pointer is less than the length of the string
            if(s[l] != s[r]) break;
            l--;
            r++;
            count++; //increment the count of palindromic substrings
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int ctr = 0;
        

        for(int i = 0; i < s.length(); i++){
            ctr += palindrome(s, i , i); //odd palindrome
            ctr += palindrome(s, i, i + 1); //even palindrome
        }
        return ctr;
    }
};
// @lc code=end

