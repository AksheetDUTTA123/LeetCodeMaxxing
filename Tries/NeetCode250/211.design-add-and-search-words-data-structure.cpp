#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;


        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };

    TrieNode* root;

    bool SearchCheck(string& word, int start, TrieNode* ptr){ //need this helper function to do the recursive check for the search function, because we need to be able to check for the '.' character, which can match any letter, 
    //so we need to be able to check for all possible letters when we encounter a '.', and we can do this by recursively calling the SearchCheck function for each possible letter when we encounter a '.', this will allow us to check 
    //for all possible combinations of letters when we encounter a '.', and if any of those combinations match the word we are searching for, then we can return true, otherwise we can return false
        if(start == word.length()) return ptr->isEnd; //base case, if index is at end of word, check if it is the actual end or not

        char c = word[start]; //index to the character

        if (c == '.'){
            for(int i = 0; i < 26; i++){
                if (ptr->children[i] != nullptr){ //check for all possible matches for characters after the '.' character, if any of those matches return true, 
                //then we can return true for the search function, otherwise we can return false, this will allow us to check for all possible combinations of letters when we encounter a '.', and if any of those combinations match the word we are searching for, then we can return true, otherwise we can return false
                    if(SearchCheck(word, start + 1, ptr->children[i])) return true;
                }
            }
            return false;
        }
        else{
            if(ptr->children[c - 'a'] != nullptr){ //this is the case where we are at a letter, we just need to check if the child node for that letter exists, if it does, then we can continue to the next letter 
            //in the word by recursively calling the SearchCheck function with the child node for that letter, this will allow us to continue searching for the next letter in the word, and if we reach the end of the word and the isEnd marker 
            //is true for the last node in the path of the word, then we can return true for the search function, otherwise we can return false
               return SearchCheck(word, start + 1, ptr->children[c - 'a']);
            }
        return false;
        }
    }

    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) { //this is the same way to add a word to a trie like other questions, we just need to follow the path of the word in the trie, and create new nodes for each letter in the word that does not 
    //already exist in the trie, and then we can mark the end of the word by setting the isEnd marker to true for the last node in the path of the word
       TrieNode* curr = root;
    for(char c : word){
        if(curr->children[c - 'a'] == nullptr){
            curr->children[c - 'a'] = new TrieNode();
        }
        curr = curr -> children[c-'a'];
    }
    curr ->isEnd = true;
    }
    
    bool search(string word) {
        return SearchCheck(word, 0, root); //kick off recursion with this helper function, we start at index 0 of the word and the root of the trie, 
        //and then we can recursively check for each character in the word, and if we reach the end of the word and the isEnd marker is true for the 
        //last node in the path of the word, then we can return true for the search function, otherwise we can return false
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

