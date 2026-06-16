#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2707 lang=cpp
 *
 * [2707] Extra Characters in a String
 */

// @lc code=start
class Solution {
private:


    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
        TrieNode* root;

    void insert(string word){
            TrieNode* curr = root;
            for(char c : word){
                if(curr->children[c - 'a'] == nullptr){
                    curr->children[c - 'a'] = new TrieNode();
                }
                curr = curr->children[c - 'a'];
            }
            curr->isEnd = true;
        }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> memo(s.length() + 1, 0);
        int charCt = 0;
        root = new TrieNode(); 
        for(string word : dictionary){
            insert(word);
        }

        for(int i = s.length() - 1; i >= 0; i--){ //start from the back of the string, this is a bottom up dp approach, we are building the solution from the end of the string to the beginning of the string, this way we can use the memoization array to store the minimum number of extra characters needed for each substring of the string, and we can use that information to build the solution for the entire string
            int charCt = memo[i + 1] + 1; //if we dont find a match in the trie, then we need to add 1 to the character count, because that character is an extra character that is not in the dictionary
            TrieNode* curr = root; //start at the root of the trie, we will use this pointer to traverse through the trie to check for matches
            //for substrings of the string, we will start from the current index i and check for matches for substrings of the string that start at index i, and we will continue to check for longer substrings of the string until we either find a match in the trie or we reach the end of the string, if we find a match in the trie for a substring of the string, then we can update the character count by taking the minimum of the current character count and the character count for the substring that starts at index j + 1, because if we have found a match for a substring of the string, then we can skip over that substring and just add the character count for the remaining substring that starts at index j + 1, this will allow us to build the solution for longer substrings of the string as we continue to iterate through the string from back to front
            for(int j = i; j < s.length(); j++){
                if(curr->children[s[j] - 'a'] == nullptr){ //if there is no match in the trie for the current character, then we can
                // break out of the loop, because there is no point in continuing to check for longer substrings if there is no match for the current character
                    break;
                }
                curr = curr->children[s[j] - 'a'];
                if(curr->isEnd){ //if we have found a match in the trie for a substring of the string, then we can update the character count by taking the minimum of the current character
                // count and the character count for the substring that starts at index j + 1, because if we have found a match for a substring of the string, then we can skip over that substring
                //and just add the character count for the remaining substring that starts at index j + 1
                    charCt = min(charCt, memo[j + 1]);
                }
            }
            memo[i] = charCt; //update the memoization array with the minimum number of extra characters needed for the substring that starts at index i, this will allow us to use this
            // information to build the solution for longer substrings of the string as we continue to iterate through the string from back to front

        }
        return memo[0];
    }
};
// @lc code=end

