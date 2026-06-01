#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
       if(s.length() > t.length()) return false;
       int ptr1 = 0;
       int ptr2 = 0;
       while (ptr1 < s.length() && ptr2 < t.length()){
            if(s[ptr1] == t[ptr2]){
                ptr1++;
                ptr2++;
            }
            else{
                ptr2++;
            }
       }
       return ptr1 == s.length();
    }

    /*
    answer to follow up question:
    To optimize for the follow-up, you would preprocess string t once, storing the indices of where every character appears.
For example, if t = "abacaba", you build a map/array of vectors:
'a' → [0, 2, 4, 6]
'b' → [1, 5]
'c' → [3]
Then, for every incoming string s, instead of scanning t linearly, you iterate through s and use Binary Search (std::upper_bound in C++) on these index lists to find the next valid matching character that comes after your current position in t.
New Time Complexity per query: O(MlogN), where M is the length of s and N is the length of t.
If s is very short (e.g., 5 characters) and t is very long (e.g., 1,000,000 characters), doing 5 binary searches is astronomically faster than scanning all 1,000,000 characters of t every single time.

    class SubsequenceChecker {
private:
    // A 2D vector where char_indices[0] holds all indices of 'a' in string t, 
    // char_indices[1] holds all indices of 'b', etc.
    vector<vector<int>> char_indices;

public:
    // Constructor: Preprocess string t once
    SubsequenceChecker(const string& t) {
        char_indices.resize(26);
        for (int i = 0; i < t.length(); i++) {
            char_indices[t[i] - 'a'].push_back(i);
        }
    }

    // Query function: Check any incoming string s against the preprocessed t
    bool isSubsequence(const string& s) {
        int current_t_idx = -1; // Tracks our current position in string t
        
        for (char c : s) {
            int char_bucket = c - 'a';
            const auto& indices = char_indices[char_bucket];
            
            // Binary search (upper_bound) to find the first index in 't' 
            // that appears AFTER our current_t_idx
            auto it = upper_bound(indices.begin(), indices.end(), current_t_idx);
            
            // If upper_bound returns the end iterator, it means this character 
            // does not appear later in string t
            if (it == indices.end()) {
                return false;
            }
            
            // Move our position in t forward to the matched index
            current_t_idx = *it;
        }
        
        return true;
    }
};
    */
};
// @lc code=end

