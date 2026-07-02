#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        unordered_set<string> visited;
        for(auto word : wordList){
            wordSet.insert(word);
        }

        if(!wordSet.count(endWord)) return 0;

        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        visited.insert(beginWord);
        while(!q.empty()){
            auto top = q.front();
            q.pop();

            if(top.first == endWord){
                return top.second;
            }
            for(int i = 0; i < top.first.length(); i++){
                char originalChar = top.first[i];

                for(char c = 'a'; c <= 'z'; c++){
                    if(c == originalChar) continue;

                    top.first[i] = c;

                    if(wordSet.find(top.first) != wordSet.end() && visited.find(top.first) == visited.end()){
                        visited.insert(top.first);
                        q.push({top.first,top.second + 1});
                    }
                }

                top.first[i] = originalChar;
            }
        }
        return 0;
    }
};
// @lc code=end

