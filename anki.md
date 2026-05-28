# LeetCodeProbs

## Two Sum LC 1

<!-- notecardId: 1779910349511 -->
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
**Link**: [text](https://leetcode.com/problems/two-sum/)

%

**Pattern:** Hash Map

**Approach:** Iterate through the array, storing each number's index in a hash map. For each number, check if its complement (target - num) already exists in the map. If it does, return both indices.

**Key Insight:** Instead of a nested loop (O(n²)), use a hash map to look up the complement in O(1) as you go.

**Gotchas:** Each input has exactly one solution — no need to handle no-answer case. Can't use the same element twice.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Two Sum II — LC #167 | Array is sorted → use Two Pointers instead | No — upgrade |
| Two Sum III — LC #170 | Design a data structure → tradeoff add vs find | Yes |
| Two Sum IV — LC #653 | Input is a BST → DFS + hash set | Partial |
| 3Sum — LC #15 | Fix one element, Two Sum the rest | Yes + Two Pointers |
| 4Sum — LC #18 | Fix two elements, Two Sum the rest | Yes + Two Pointers |
| Subarray Sum Equals K — LC #560 | Prefix sum + hash map | Yes — generalization |

**How this pattern scales:**
- **Two Pointers** when input is sorted (no hash map needed)
- **Fix + reduce** strategy for 3Sum/4Sum (reduce to Two Sum each time)
- **Prefix sum** variant when dealing with subarrays instead of pairs

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { 
        unordered_map<int, int> hashTable;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hashTable.find(complement) != hashTable.end()) { 
                return {hashTable[complement], i}; //return indices of complement and current number
            }
            hashTable[nums[i]] = i; 
        }
        return {}; 
    }
};
```

## Longest Common Prefix LC 14

<!-- notecardId: 1779910349525 -->

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

**Link**: [text](https://leetcode.com/problems/longest-common-prefix/)

%

**Pattern:** Array Access | String Traversal

**Approach:** Iterate character by character across all strings simultaneously. Stop when a mismatch is found or the end of any string is reached. The longest common prefix is the substring up to that point.

**Key Insight:** The runtime is O(length of the first string) in the worst case (all strings are the same or the first string is a prefix for everything else) and O(1) is the best case (first character mismatch)

**Gotchas:** Don't forget to check for empty strings or the case where the first string is empty. Also, ensure you don't go out of bounds when checking characters

**Complexity:** Time: O(length of first string) | Space: O(1)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Longest Common Subsequence — LC #1143 | Characters don't need to be contiguous → DP | No — harder |
| Longest Common Substring — LC #718 | Must be contiguous but not prefix → DP/sliding | Partial |
| Valid Anagram — LC #242 | No prefix needed, just same chars → sort/hash | No — simpler |
| Group Anagrams — LC #49 | Group strings by sorted key → hash map | Partial |
| Word Search II — LC #212 | Prefix matching across a board → Trie | Yes — generalization |
| Implement Trie — LC #208 | Build the data structure used to solve this efficiently | Yes — upgrade |

**How this pattern scales:**
- **Trie** when you need repeated prefix lookups across many strings (scales LC #14's logic)
- **Vertical scan** (LC #14's approach) generalizes to any problem comparing characters column by column
- **Binary search on length** variant when strings are very long and you want to optimize comparisons


```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string> & strs){
        string prefix = "";
        if(strs.empty()) return prefix;
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){ //go through each string
                if(i >= strs[j].size() || strs[j][i] != c){ 
                    return prefix; //if we've reached the end of a string or found a mismatch, return the prefix found so far
                }
            }
            prefix += c; //add to prefix if all strings have the same char at this position
     
       }
       return prefix; 
    }
};
```

## Valid Anagram LC 242

<!-- notecardId: 1779910349526 -->

Given two strings s and t, return true if t is an anagram of s, and false otherwise.


Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

**Link**: [text](https://leetcode.com/problems/valid-anagram/)

%

**Pattern:** Hash Map | Sorting

**Approach:** Go through both strings and count the frequency of each character using a hash map. Then compare the frequency maps. Alternatively, sort both strings and check if they are equal.

**Key Insight:** First map the hash map for the first string, then decrement counts for the second string. If any count goes negative or if there are leftover counts, they are not anagrams. Sorting is simpler but less efficient.

**Gotchas:** Make sure to handle edge cases like empty strings. Also, consider the follow-up for Unicode characters - you might need a more general hash map that can handle a wider range of characters instead of just lowercase English letters.

**Complexity:** Time: O(n) for hash map approach, O(n log n) for sorting | Space: O(1) for sorting (if in-place), O(n) for hash map

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Group Anagrams — LC #49 | Group multiple strings by sorted key → hash map | Yes — generalization |
| Find All Anagrams in String — LC #438 | Sliding window over string to find anagram positions | Yes — upgrade |
| Permutation in String — LC #567 | Check if any permutation of s1 exists in s2 → sliding window | Yes — close variant |
| Valid Palindrome — LC #125 | Compare chars from both ends, not frequency count | No — different pattern |
| Longest Common Prefix — LC #14 | No frequency check, just shared prefix → string traversal | No — different pattern |
| Minimum Window Substring — LC #76 | Find smallest window containing all chars → sliding window + freq map | Yes — harder generalization |

**How this pattern scales:**
- **Sliding window + frequency map** when the problem asks about anagrams/permutations *inside* a larger string (LC #438, #567)
- **Sort and compare** is the simple O(n log n) version — upgrade to **frequency map** for O(n)
- **Hash map counting** generalizes to any problem checking character frequency equality across strings

```cpp
class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.length() != t.length()) return false; //check diff lengths, fast way to reject

        unordered_map<char, int> charCount; 
        for(char c : s){
            charCount[c]++;
        }
        for(char c : t){
            if(charCount.find(c) == charCount.end() || charCount[c] == 0){
                return false;
            }
            charCount[c]--;
        }
        return true;
    }
};
```
## Concatenation of Array LC 1929

<!-- notecardId: 1779910827169 -->

Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 

Constraints:

n == nums.length
1 <= n <= 1000
1 <= nums[i] <= 1000

**Link**: [text](https://leetcode.com/problems/concatenation-of-array/)

%

**Pattern:** Array Manipulation

**Approach:** Make a new array of size 2n and fill it by iterating through the original array twice. The first n elements are just the original array, and the next n elements are also the original array.

**Key Insight:** This is a straightforward problem that tests your ability to manipulate arrays. The key is to understand the indexing and how to fill the new array correctly.

**Gotchas:** No major gotchas here, just be careful with the indexing especially when filling the second half of the new array.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Build Array from Permutation — LC #1920 | Build result array from index mapping, no concatenation | Yes — same family |
| Running Sum of 1D Array — LC #1480 | Accumulate values instead of duplicating array | No — different pattern |
| Rotate Array — LC #189 | Shift elements by k positions → modular indexing | Partial — index math |
| Duplicate Zeros — LC #1089 | In-place duplication with shifting, not concatenation | Partial |
| Find the Index of the First Occurrence — LC #28 | Search within a concatenated-style string → KMP | No — different pattern |
| Product of Array Except Self — LC #238 | Build result array using index relationships | Partial — array construction |

**How this pattern scales:**
- **Modular indexing** (`i % n`) is the core trick — any problem asking you to simulate a "wrapped" or "repeated" array uses this
- **Array construction** pattern generalizes to problems where you build a result array by mapping indices from the input
- **Two-pass construction** when you can't do it in one loop — fill first half, then second half using `i - n`


```cpp
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(2 * nums.size());
        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[nums.size() + i] = nums[i];
        }
        return ans;
    }
};
```

## Sort Colors LC 75

<!-- notecardId: 1779933620914 -->

75. Sort Colors

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

**Link**: [text](https://leetcode.com/problems/sort-colors/)

%

**Pattern:** Two Pointers | Dutch National Flag

**Approach:** Use three pointers to partition the array into three sections: one for 0s, one for 1s, and one for 2s. Iterate through the array and swap elements to ensure that all 0s are at the beginning, all 1s are in the middle, and all 2s are at the end.

**Key Insight** is that you can maintain three regions in the array: [0, low) for 0s, [low, mid) for 1s, and [high, end) for 2s. By adjusting the pointers based on the current element, you can sort the array in one pass.

**Gotchas:** Be careful with the pointer movements, especially when swapping elements. Make sure to handle the case when you encounter a 1 correctly, as it doesn't require a swap but does require moving the mid pointer. When a 2 is found, you need to swap it with the element at the high pointer and decrement high, but you should not increment mid in this case because the swapped element needs to be evaluated. 

**Complexity:** Time: O(n) | Space : O(1)

```cpp
class Solution {
public:
    void sortColors(vector<int> & nums){
        int low = 0, mid = 0, high = nums.size() - 1;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;}
                // Note: we do not increment mid here because the element swapped from the end needs to be evaluated in the next iteration
            }
            }
};
```

## Contains Duplicate LC 217

<!-- notecardId: 1779943962914 -->

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109

**Link**: [text](https://leetcode.com/problems/contains-duplicate/)

%

**Pattern:** Hash Set

**Approach:** Iterate through the array and add each element to a hash set. If you encounter an element that is already in the set, return true. If you finish iterating without finding duplicates, return false.

**Key Insight:** A hash set allows for O(1) average time complexity for insertions and lookups, making it an efficient way to check for duplicates in a single pass through the array.

**Gotchas:** Be mindful of the space complexity, as using a hash set will require O(n) space in the worst case if all elements are unique. Also, consider edge cases such as an array with only one element, which should return false.

**Complexity:** Time: O(n) | Space : O(n)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& seen){
        unordered_set<int> seenVals;
        for(int i = 0; i < nums.size(); i++){
            if(seenVals.find(nums[i]) != seenVals.end()){
                return true; //duplicate found
            }
            seenVals.insert(nums[i]); //add current number to set
        }
        return false;
    }
};
```