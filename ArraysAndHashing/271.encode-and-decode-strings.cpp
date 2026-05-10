#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 */

// @lc code=start
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result;
        for(string str : strs){
            result += to_string(str.length()) + "#" + str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int index = 0;
        // int miniStringLength = 0;
        // string newStr = "";
        while(index < s.length()){
           int delimiter = s.find('#', index);
           int length = stoi(s.substr(index, delimiter - index ));
            string newStr = s.substr(delimiter + 1, length);
            result.push_back(newStr);
            index = delimiter + length + 1;
        }
    return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// @lc code=end

