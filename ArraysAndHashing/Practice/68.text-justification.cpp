#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        string currLine = "";
        int i = 0;
        while(i < words.size()){
            int j = i;
            int lineLength = 0;
            
            //to start off, lets pack as much as we can to the line

            while(j < words.size() && lineLength + words[j].length() + (j-i) <= maxWidth){ //j - i accoutns for the spaces
                lineLength += words[j].length();
                j++;
            }

            int numWords = j - i; //need to check if its only word or not

            int totalSpaces = maxWidth - lineLength;

            string line = "";


            if(j == words.size() || numWords == 1){ //if its last line or line only has one word
                for(int k = i; k < j; k++){
                    line += words[k];
                    if(k < j - 1) line += " ";
                }
                line.append(maxWidth - line.length(), ' ');
            }
            else{ //normal cases where we have to put spaces like normal
            int spacePergap = totalSpaces / (numWords - 1);
            int extraSpaces = totalSpaces % (numWords - 1);

            for(int k = i; k < j; k++){
                    line += words[k];
                    if(k < j - 1){
                        int spacesToAdd = spacePergap + (k-i < extraSpaces ? 1 : 0);
                        line.append(spacesToAdd, ' ');
                    }
                }

            }
        res.push_back(line);
        i = j;
        }
        return res;
    }
};
// @lc code=end

