#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
    private:
        struct TrieNode{
            TrieNode* children[26]; //each node has an array of 26 pointers to its children, each pointer corresponds to a letter of the alphabet
            //if the pointer is null, we know that there is no child node for that letter, if the pointer is not null, we know that there is a child node for that letter, and we can follow the pointer to the child node to continue searching for the next letter in the word
            bool isEnd; //need a marker for each node to indicate if it is the end of a word, because we can have a case where we have a word that is a prefix of another word, for example, "app" and "apple", 
            //in this case, we need to be able to distinguish between the two words, so we need a marker for each node to indicate if it is the end of a word, because if we reach the end of the word "app", we need to be able to return true for the search function, but if we reach the end of the word "apple", we need to be able to return false for the search function, because "app" is not a complete word, it is just a prefix of "apple", so we need a marker for each node to indicate if it is the end of a word
            TrieNode(){ //when initializing a node, just set it as empty for now, this will get filled when inserting something
                isEnd = false;
                for(int i = 0; i < 26; i++){
                    children[i] = nullptr;
                }
            }
        };

        TrieNode* root; //need to establish a root node for the trie, this will be the starting point for all operations 
        //on the trie, because all words in the trie will be stored as a path from the root node to a leaf node, so we need to establish a root node for the trie, this will be the starting point for all operations on the trie, because all words in the trie will be stored as a path from the root node to a leaf node
public:
    Trie() {
        root = new TrieNode(); 
    }
    
    void insert(string word) {
        TrieNode * curr = root; //start at the root every time
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){ //letter doesnt exist, so we need to create a new node fpr that letter, we can calculate the index of the letter in the children array by subtracting 'a' from the character, 
            //this will give us a number between 0 and 25, which corresponds to the index of the letter in the children array, for example, if c is 'a', then c - 'a' will be 0, which corresponds to the index of 'a' in the children array, if c is 'b', then c - 'a' will be 1, which corresponds to the index of 'b' in the children array, and so on
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a']; //this is how to traverse through the trie, we follow the pointer to the child node for the current letter, and then we continue to the next letter in the word, this will allow us to insert the word into the trie by creating new nodes for each letter in the word that does not already exist in the trie, 
            //and then we can mark the end of the word by setting the isEnd marker to true for the last node in the path of the word
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode * curr = root;
        for(char c : word){
            if(curr->children[c - 'a'] == nullptr){
                return false; //if the child doesnt exist, we know that this string will not be in the trie, so return false
            }
            curr = curr->children[c - 'a'];
        }
        if(curr->isEnd == false){ //if not isEnd, we have a situation like search is "app" but the word is "apple", in this case, we will reach the end of the search string "app", 
        //but we will not have reached the end of the word "apple", so we need to check if the isEnd marker is true for the last node in the path of the search string, if it is not true, 
        //then we know that the search string is just a prefix of a word in the trie, and it is not a complete word in the trie, so we need to return false
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
          TrieNode * curr = root;
        for(char c : prefix){
            if(curr->children[c - 'a'] == nullptr){
                return false; //same logic as search
            }
            curr = curr->children[c - 'a'];
        }
        return true; //if we have successfully traversed through the trie for all the letters in the prefix, then we know that there is a word in the trie that starts with the prefix, so we can return true, 
        //we do not need to check if the isEnd marker is true for the last node in the path of the prefix, because we are only checking if there is a word in the trie that starts with the prefix, and it does not matter if the prefix itself is a complete word in the trie or not, as long as there is a word in the trie that starts with the prefix, we can return true
        //dont need to check isEnd because we are only checking if there is a word in the trie that starts with the prefix, 
        //and it does not matter if the prefix itself is a complete word in the trie or not, as long as there is a word in the trie that starts with the prefix, we can return true
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

