#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> frequency; //store frequency numbers
        stack<string> strings; //store the string built so far, this is important when nesting occurs, 
        int num = 0; //to help with calculating frequencies
        string curr = ""; //starting current string is 0
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){ //if a number, we dont know how big it is, multiply previous by 10 and add new digit, needed since number is 1-300
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '['){ /*
            when a [ is there, that means the current string is done, frequency has also been obtained, so store them in their respective stacks, then reset the current string and frequency to start the new string inside the brackets, 
            when we encounter the closing bracket, we will know how many times to repeat the current string, and what the previous string was, so we can pop from both stacks and update the current string to be the previous string + the current string repeated frequency number of times, t
            this is important for nesting, because if there are multiple nested brackets, then when we encounter a closing bracket, we will only repeat the current string inside that specific bracket, and then add it to the previous string, which may also be inside another bracket, 
            but that is fine because when we encounter the closing bracket for that one, we will repeat the entire current string which includes the previous string that was just added to it
            */
            frequency.push(num);
            strings.push(curr);
            curr = "";
            num = 0;
            }
            else if (s[i] == ']'){
                //when a closing bracket is reached, current string is done, so then we take the top of the stack for frequency and string
                int ct = frequency.top();
                frequency.pop();
                string str = strings.top();
                strings.pop();
                
                string freqStr = "";
                //CURRENT STRING is repeated ct times, and then is added to the PREVIOUS STRING, which is str, this is important for nesting,
                // because if there are multiple nested brackets, then when we encounter a closing bracket, we will only repeat the current string inside that specific bracket, 
                //and then add it to the previous string, which may also be inside another bracket
                for(int i = 0; i < ct; i++){
                    freqStr += curr;
                }
                curr = str + freqStr;

            }
            else{
                curr += s[i]; //add to current string if it is a character
            }
        }
    return curr;
    }
};
// @lc code=end

