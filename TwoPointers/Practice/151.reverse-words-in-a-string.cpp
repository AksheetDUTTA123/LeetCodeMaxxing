#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        //this is the O(1) space solution, 
        //we will reverse the entire string, then reverse each word in the string, and then remove extra spaces
        std::reverse(s.begin(), s.end());
        int write = 0; //this is where we actually write the correct letter, read is like the one looking for the right char

        for(int read = 0; read < s.length(); read++){
            if(s[read] == ' '){ //if we find a space, we just keep reading until we find a non-space character,
            // because we want to remove extra spaces
                continue;
            }
            else{
                if(write > 0){
                    s[write] = ' '; //if write is greater than 0, 
                    //that means we have already written a word, so we need to add a space before the next word
                    write++;
                }
                int start = write;
                while(read < s.length() && s[read] != ' '){
                    s[write] = s[read]; //move te letter we are reading in to the write position, 
                    //this will remove extra spaces
                    write++;
                    read++;
                }
                std::reverse(s.begin() + start, s.begin() + write);
            }

        }
        s.resize(write);
        return s;
    }
};
// @lc code=end

