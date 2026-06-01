#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3093 lang=cpp
 *
 * [3093] Longest Common Suffix Queries
 */

// @lc code=start
class Solution {
public:
struct TrieNode{
    int children[26];
    int bestIdx;
    int bestLen;
    TrieNode(){
        fill(begin(children), end(children), -1);
        bestLen = 1e9;
        bestIdx = 1e9;
    }
};
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        //look at the end, if we count from the reverse, it is a prefix
    vector<TrieNode> trie;
    trie.emplace_back();
    for(int i = 0; i < wordsContainer.size(); i++){
        int len = wordsContainer[i].length();
        int curr = 0;

        if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                trie[curr].bestLen = len;
                trie[curr].bestIdx = i;
            }

        for(int j = len - 1; j >= 0; j--){
            int charIdx = wordsContainer[i][j] - 'a';
            if(trie[curr].children[charIdx] == -1){
                    trie[curr].children[charIdx] = trie.size();
                    trie.emplace_back();
            }
            curr = trie[curr].children[charIdx];
            if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                trie[curr].bestLen = len;
                trie[curr].bestIdx = i;
            }
        }

    }

    vector<int> ans;
    ans.reserve(wordsQuery.size());
    for(const string& query : wordsQuery){
        int curr = 0;
        int len = query.length();
          for(int j = len - 1; j >= 0; j--){
            int charIdx = query[j] - 'a';
            if(trie[curr].children[charIdx] == -1){
                    break;
            }
            curr = trie[curr].children[charIdx];
    }
    ans.push_back(trie[curr].bestIdx);
    }
    return ans;
    }

};
// @lc code=end

