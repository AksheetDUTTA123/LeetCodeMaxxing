#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
private:

    struct TrieNode{
        TrieNode* children[26];
        string word;//store full word at end


        TrieNode(){
            word= "";
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }

    };

    void insert(string word){
        TrieNode * curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c-'a'];
        }
        curr->word= word;
    }

    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* curr, vector<string>& result){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;

        char currentChar = board[row][col];

        if (currentChar == '#' || curr->children[currentChar - 'a'] == nullptr) return; //if we have already visited this cell, or if there is no child node for the current character in the trie, 
        //then we can return, because there is no point in continuing to search for words in the board if we have already visited this cell, or if there is no child node for the current character in the trie,
        // because that means that there are no words in the trie that start with the current character, so we can return and stop searching for words in the board

        curr = curr->children[currentChar-'a']; //move down the trie to the child node for the current character, 
        //this will allow us to continue searching for words in the trie that start with the current character, and if we reach 
        //the end of a word in the trie, then we can add that word to the result vector, because we have found a word in the board that is in the trie

        if(curr->word != ""){ //found a word
            result.push_back(curr->word);
            curr->word = "";
        }

        board[row][col] = '#'; //mark as visited, we can also use a separate visited array, but this is more space efficient, we just need to make sure to unmark it after the dfs calls, 
        //this will allow us to avoid using extra space for a visited array, and we can just use the board itself to mark visited cells by changing the character to a special character like '#', and then we can change it back to the original character after the dfs calls, this will allow us to avoid using extra space for a visited array,
        // and we can just use the board itself to mark visited cells by changing the character to a special character like '#', and then we can change it back to the original character after the dfs calls
        dfs(board, row + 1, col,curr,  result);
        dfs(board, row - 1, col, curr,result);
        dfs(board, row, col + 1, curr,result);
        dfs(board, row, col - 1,curr, result);

        board[row][col] = currentChar; //need to unmark because we are doing a depth first search, and we need to be able to backtrack to the previous cell, 
        //so we need to unmark the current cell after the dfs calls, this will allow us to backtrack to the previous cell and continue searching for other words in the board
    }

    TrieNode *root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        root = new TrieNode();
        for(string s : words){
            insert(s);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(board, i, j, root, result); //running DFS through entire grid, this will allow us to find all the words in the board that are in the trie, because we will be searching for words in the trie that start with the characters in the board, and if we reach the end 
                //of a word in the trie, then we can add that word to the result vector, because we have found a word in the board that is in the trie
            }
        }
        return result;
    }
};
// @lc code=end

