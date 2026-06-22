#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
    private:
    vector<vector<string>> res;
public:
    bool isPalindrome(string &s, int start, int end){ //need a simple helper that checks if a substring is a palindrome or not
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backtracking(string& s, int index, vector<string>& curr){
        if(index == s.length()){
            res.push_back(curr);
            return;
        }

        
        for(int i = index; i < s.length(); i++){ //we want to check for all possible substrings starting from the index,
        // so we can have a loop that goes from the index to the end of the string, and for each substring, we can check if it is a palindrome or not, 
        //if it is a palindrome, then we can add it to the current partition and then recursively call the backtracking function with the next index after 
        //the end of the substring, this will allow us to find all possible partitions of the string that are palindromes, and if we reach the end of the string, 
        //then we can add the current partition to the result vector
            if(isPalindrome(s,index, i)){
                curr.push_back(s.substr(index, i - index + 1));
                backtracking(s, i + 1, curr);
                curr.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtracking(s, 0, curr);
        return res;
    }
};
// @lc code=end

