#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution {
public:
    string toGoatLatin(string sentence) {
                string res;
        stringstream ss(sentence);
        string word;
        int currWordCt = 0;
        while(ss >> word){
            currWordCt++;
            if(word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U'){
                res+= word + "ma" + string(currWordCt, 'a') + " ";
            }
            else{
                res += word.substr(1, word.length() -1) + word[0] + "ma" + string(currWordCt, 'a') + " ";
            }
        }
        return res.substr(0, res.length() - 1);
    }
};
// @lc code=end

