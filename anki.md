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

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Partition Array According to Given Pivot — LC #2161 | Partition into < pivot, = pivot, > pivot → same 3-way logic | Yes — direct generalization |
| Move Zeroes — LC #283 | Move all 0s to end, preserve order → single pointer | Partial — simpler partition |
| Remove Element — LC #27 | Remove specific value in-place → two pointer partition | Partial |
| Wiggle Sort II — LC #324 | Interleave smaller and larger halves → partition based | Partial — harder variant |
| Kth Largest Element — LC #215 | 3-way partition used in QuickSelect algorithm | Yes — core building block |
| Next Permutation — LC #31 | In-place rearrangement with pointer logic | No — different pattern |

**How this pattern scales:**
- **Dutch National Flag** is the foundation of **QuickSelect** and **3-way QuickSort** — mastering it unlocks LC #215 and sorting interview questions
- **2-way partition** (Move Zeroes, Remove Element) is the simpler version — upgrade to 3-way when you have three distinct categories
- **k-way partition** when there are more than 3 categories — use counting sort instead of pointer swapping

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

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Contains Duplicate II — LC #219 | Duplicate must be within k indices apart → sliding window + hash set | Yes — upgrade |
| Contains Duplicate III — LC #220 | Duplicate within k indices AND value diff ≤ t → sorted set/bucket sort | Partial — harder |
| Find the Duplicate Number — LC #287 | Only one duplicate, can't use extra space → Floyd's cycle detection | No — different pattern |
| Missing Number — LC #268 | Find missing instead of duplicate → XOR or math | Partial — same family |
| Single Number — LC #136 | Find element with no duplicate → XOR trick | No — different pattern |
| Longest Consecutive Sequence — LC #128 | Find longest run of consecutive numbers → hash set | Yes — generalization |

**How this pattern scales:**
- **Hash set** is the core trick — any problem asking "have I seen this before?" in O(1) uses this
- **Sliding window + hash set** when duplicates must satisfy a distance or range constraint (LC #219, #220)
- **Sorting** is the O(n log n) fallback — if you can't use extra space, sort and check adjacent elements instead

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
## Remove Element LC 27
<!-- notecardId: 1779978629229 -->

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

**Link**: [text](https://leetcode.com/problems/remove-element/)

%

**Pattern:** Two Pointers | In-place Modification

**Approach:** Use two pointers to iterate through the array. One pointer (slow) keeps track of the position to place the next non-val element, while the other pointer (fast) iterates through the array. When fast finds an element that is not equal to val, it is copied to the slow pointer's position, and slow is incremented.

**Key Insight:** This approach allows you to modify the array in-place without needing extra space. The slow pointer effectively "compacts" the array by overwriting elements that should be removed.

**Gotchas:** Be careful with the pointer movements. The fast pointer should always move forward, while the slow pointer only moves when a non-val element is found. Also, remember to return the count of non-val elements, which is the position of the slow pointer at the end. Doing std::erase or similar operations would be inefficient, as it would require shifting elements multiple times.

**Complexity:** Time: O(n) | Space: O(1)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Remove Duplicates from Sorted Array — LC #26 | Remove duplicates instead of a value → same two pointer write-head | Yes — direct variant |
| Remove Duplicates from Sorted Array II — LC #80 | Allow up to 2 duplicates → same write-head with count tracking | Yes — upgrade |
| Move Zeroes — LC #283 | Move 0s to end instead of removing → same pointer but preserve zeros | Yes — close variant |
| Sort Colors — LC #75 | Partition into 3 groups instead of 2 → Dutch National Flag | Partial — harder |
| Find the Index of First Occurrence — LC #28 | Search within string instead of removing → KMP/two pointer | No — different pattern |
| Remove Nth Node From End of List — LC #19 | Same removal idea but on a linked list → fast/slow pointer | Partial — same intent |

**How this pattern scales:**
- **Write-head pointer** (`k`) is the core trick — one pointer iterates, one pointer tracks where to write next. Any in-place array modification problem uses this
- **Two pointer partition** generalizes to Sort Colors, QuickSort partitioning, and Dutch National Flag
- **Linked list removal** is the same intent but requires prev/next pointer manipulation instead of index swapping

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0; //pointer for position to place next non-val element
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != val){ //if current element is not val, copy it to slow pointer's position
            nums[slow] = nums[fast];
            slow++;
        }
        }
        return slow; //slow pointer now represents the count of non-val elements
    }
};
```

## Sort an Array LC 912
<!-- notecardId: 1779980391380 -->

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104

**Link**: [text](https://leetcode.com/problems/sort-an-array/)

%

**Pattern:** Sorting | Divide and Conquer

**Approach:** Implement a sorting algorithm such as Merge Sort or Quick Sort to sort the array in O(n log n) time complexity. Merge Sort is a stable sorting algorithm that divides the array into halves, sorts each half recursively, and then merges the sorted halves. Quick Sort is an in-place sorting algorithm that partitions the array around a pivot and recursively sorts the partitions. I used counting sort since the constraints allow for it in terms of space complexity and it runs more time-efficiently O(n + k) where k is the range of input values. If space complexity is prioritized, heap sort is better as it is O(log n) space while still being in time bounds of O(n log n).

**Key Insight:** The choice of sorting algorithm can depend on the constraints of the problem. Merge Sort is a good choice for stable sorting and when you need guaranteed O(n log n) time, while Quick Sort can be faster on average but has a worst-case of O(n^2). Counting Sort is optimal for small ranges of integers.

**Gotchas:** Be careful with edge cases such as empty arrays or arrays with duplicate values. Also, ensure that your implementation of the sorting algorithm is correct and efficient.

**Complexity:** Time: O(n log n) for Merge Sort or Quick Sort, O(n + k) for Counting Sort | Space: O(n) for Merge Sort, O(log n) for Quick Sort, O(k) for Counting Sort

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Sort Colors — LC #75 | Sort only 3 distinct values → Dutch National Flag, no recursion needed | Partial — simpler |
| Kth Largest Element in Array — LC #215 | Don't need full sort, just find kth → QuickSelect (partition only) | Yes — core building block |
| Merge Sorted Array — LC #88 | Merge two already sorted arrays → merge step of MergeSort only | Yes — direct variant |
| Sort List — LC #148 | Same sorting but on a linked list → MergeSort preferred over QuickSort | Partial — same idea |
| Maximum Gap — LC #164 | Sort then find max gap between adjacent elements → radix/bucket sort | Partial — sort variant |
| Count of Smaller Numbers After Self — LC #315 | Modified merge sort to count inversions during merge step | Yes — generalization |

**How this pattern scales:**
- **MergeSort** is the safe O(n log n) guaranteed choice — use when stability or worst-case matters
- **QuickSort** averages O(n log n) but degrades to O(n²) on bad pivots — randomized pivot selection fixes this
- **QuickSelect** is QuickSort's partition step applied to find kth element without fully sorting — LC #215 is the direct application
- **Counting/Radix sort** when values are bounded integers — drops to O(n) but only works for specific input types

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int> & nums) {
        //Counting sort implementation
        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());

        int range = maxElement - minElement + 1;
        vector<int> count(range, 0); //track number of occurence of each element between min and max element

        for(int num : nums){
            count[num - minElement]++;
        }
        for int j = 0; //use as index.
        for(int i = 0; i < range; i++){
            while(count[i]-- > 0){ //until freq is 0 for a num, add that num to vector, it is sorted because at each index , goes from lowest to highest (we subtract by min to get a range)
                nums[j++] = minElement + i; //add the num back to the original vector, we can do this in place since we are overwriting the original vector and we know how many times each num occurs from the count array
            }
        }
        return nums;
    }
};
```

## Group Anagrams LC 49

<!-- notecardId: 1779982194021 -->

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

**Link**: [text](https://leetcode.com/problems/group-anagrams/)

%

**Pattern:** Hash Map

**Approach:** Use a hash map to group anagrams together. The key can be a sorted version of the string or a frequency count of characters. For each string, compute the key and add the original string to the list of anagrams corresponding to that key in the hash map.

**Key Insight:** Anagrams will have the same sorted character sequence or the same frequency count of characters. By using this as a key in a hash map, you can efficiently group all anagrams together.

**Gotchas:** Be careful with the key generation. Sorting the string is straightforward but can be inefficient for long strings. Using a frequency count can be more efficient but requires careful implementation to ensure the key is unique for each anagram group.

**Complexity:** Time: O(n * k) for frequency count and O(1) for hash table indexing/storing | Space: O(n * k) for sorting the sorted anagrams

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Anagram — LC #242 | Check if two strings are anagrams → same char frequency logic, no grouping | Yes — foundation |
| Find All Anagrams in String — LC #438 | Find all anagram positions inside a string → sliding window + freq map | Partial — upgrade |
| Permutation in String — LC #567 | Check if any permutation of s1 exists in s2 → sliding window | Partial — close variant |
| Minimum Window Substring — LC #76 | Smallest window containing all chars → sliding window + freq map | Partial — harder |
| Word Pattern — LC #290 | Map pattern to words bijectively → hash map grouping | Partial — same grouping idea |
| Longest Substring Without Repeating Characters — LC #3 | Track unique chars in window → hash set instead of freq map | No — different pattern |
| Top K Frequent Elements — LC #347 | Group by frequency instead of anagram key → hash map + heap | Partial — same grouping structure |

**How this pattern scales:**
- **Sorted key** (`sort(word)`) is the simple grouping key — works in O(n log n) per word
- **Frequency tuple** (`[2,0,0,...,1]`) is the O(n) upgrade — use a 26-length count array as the hash map key instead of sorting
- **Grouping by computed key** is the general pattern — any problem asking you to cluster items by a shared property uses this hash map structure

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringMap;
        for (auto str : strs){
        int count[26] = {0};
        for (char c: str){
            count[c - 'a']++; //this makes the array for the string, how many occurences of each letter in the string
        }

        string key = "";
        for(int i = 0; i < 26; i++){
            key += '#' + to_string(count[i]);
        }
        stringMap[key].push_back(str);
        }
        vector<vector<string>> resultVec;
        for(auto str: stringMap){
            resultVec.push_back(move(str.second));
        }
        return resultVec;
    }
};
```

## Top K Frequent Elements LC 347

<!-- notecardId: 1779985135134 -->

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

**Link**: [text](https://leetcode.com/problems/top-k-frequent-elements/)

%

**Pattern:** Hash Map + Heap | Bucket Sort

**Approach:** Use a hash map to count the frequency of each element. Then, use a min-heap (priority queue) to keep track of the top k elements based on their frequency. Alternatively, you can use bucket sort by creating an array of lists where the index represents the frequency and the list at that index contains the elements with that frequency.

**Key Insight:** The hash map allows you to count frequencies in O(n) time. Using a min-heap of size k ensures that you only keep the top k elements, resulting in O(n log k) time complexity. Bucket sort can achieve O(n) time complexity by leveraging the fact that the maximum frequency cannot exceed n.

**Gotchas:** Be careful with edge cases, such as when k is equal to the number of unique elements. Also, ensure that your heap or bucket sort implementation correctly handles ties in frequency.

**Complexity:** Time: O(n log k) for heap approach, O(n) for bucket sort | Space: O(n) for hash map and heap/buckets

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Group Anagrams — LC #49 | Group by anagram key instead of frequency → hash map grouping | Partial — same structure |
| Kth Largest Element in Array — LC #215 | Kth largest value not frequency → QuickSelect or heap | Partial — same heap idea |
| Sort Characters By Frequency — LC #451 | Sort all chars by frequency instead of top k → bucket sort or heap | Yes — direct variant |
| Top K Frequent Words — LC #692 | Same but with strings, tie-break alphabetically → heap with custom comparator | Yes — upgrade |
| K Closest Points to Origin — LC #973 | Kth smallest distance instead of frequency → heap or QuickSelect | Partial — same k-selection |
| Find K Pairs with Smallest Sums — LC #373 | K smallest pairs from two arrays → min heap | Partial — same heap pattern |
| Word Frequency — LC #192 | Count word frequency in a file → hash map counting | Yes — foundation |

**How this pattern scales:**
- **Hash map + heap** is the standard O(n log k) approach — count frequencies first, then use a min-heap of size k to track top k
- **Bucket sort** is the O(n) optimal approach — index buckets by frequency (max frequency = n), then read from the top down
- **QuickSelect** is the O(n) average approach — same as LC #215 but applied to frequency values instead of raw values
- **Custom comparator heap** when there's a tiebreaker condition (LC #692 alphabetical) — same structure, just more complex comparison logic

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // //first method, do a minHeap
        // unordered_map<int, int> freq;
        // for(int num:nums){
        //     freq[num]++; //adding the frequency to each number in the map

        // }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; //declare the minHeap, order is type, then container, then greater(minHeap) or less(maxHeap)
        // for(auto& [num, count] : freq){ //iterate thru the map
        //     minHeap.push({count, num}); //push the count and then the number into the minHeap, minHeap orders by first element of the pair, which is the count.
        //     if(minHeap.size() > k){ //over k, pop the smallest element, falls outside the top k
        //         minHeap.pop();
        //     }
        // }

        // vector<int> res;
        // while(!minHeap.empty()){ //go through the k elements
        //     res.push_back(minHeap.top().second); //push the second value, which is the actual number
        //     minHeap.pop();
        // }
        // return res;

        //second method, bucket sort
        unordered_map<int, int> freq;
        for(int num:nums){
            freq[num]++; //adding the frequency to each number in the map
        }
        vector<vector<int>> buckets(nums.size()+ 1); //make the buckets, the size is the size of the nums vector at worst case(frequency 1 for each number), and +1 because frequency is the index
        for(auto& [num, count] : freq){
            buckets[count].push_back(num); //push the number into the bucket associated with that count, which is what was found within the map
        }
        vector<int> res;
        for(int i = buckets.size() - 1; i >= 0 && res.size() < k; i--){ //start from the end of buckets, as this is the highest frequency values, go down until k elements are found
            for(int num : buckets[i]){
                res.push_back(num);
            }
        }
        return res;
    }
};
```

## Encode and Decode Strings LC 271

<!-- notecardId: 1779985218534 -->

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

 

Example 1:

Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
Example 2:

Input: dummy_input = [""]
Output: [""]
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] contains any possible characters out of 256 valid ASCII characters.
 

Follow up: Could you write a generalized algorithm to work on any possible set of characters?

**Link**: [text](https://leetcode.com/problems/encode-and-decode-strings/)

%

**Pattern:** String Manipulation | Delimiter Encoding

**Approach:** To encode a list of strings, you can use a delimiter to separate the strings. A common approach is to prefix each string with its length followed by a special character (e.g., '#') to indicate the end of the length and the start of the string. For example, "Hello" would be encoded as "5#Hello". To decode, you can read the length until you encounter the delimiter, then read that many characters to get the original string.

**Key Insight:** The key is to choose a delimiter that does not appear in the strings themselves, or to use a length prefix to avoid ambiguity. This way, you can reliably encode and decode any list of strings, regardless of their content.

**Gotchas:** Be careful with edge cases, such as empty strings or strings that contain the delimiter. Using a length prefix helps to avoid issues with delimiters appearing in the strings. Also, ensure that your encoding and decoding logic is consistent and correctly handles all cases. For the follow up, you can use a more complex encoding scheme that handles any character, such as escaping special characters or using a binary format.

**Complexity:** Time: O(n) for both encoding and decoding, where n is the total length of all strings | Space: O(n) for the encoded string and the decoded list

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Serialize and Deserialize Binary Tree — LC #297 | Same encode/decode idea but on a tree structure → DFS + delimiter | Yes — direct generalization |
| Serialize and Deserialize BST — LC #449 | Same as #297 but exploit BST properties for more compact encoding | Yes — upgrade |
| Design TinyURL — LC #535 | Encode URLs to short keys → hash map bidirectional mapping | Partial — same encoding idea |
| String Compression — LC #443 | Compress by counting consecutive chars → run-length encoding | Partial — different encoding scheme |
| UTF-8 Validation — LC #393 | Validate a multi-byte encoding scheme → bit manipulation | No — different pattern |
| Decode String — LC #394 | Decode a compressed string with counts → stack based | Partial — decoding focus |
| Design HashMap — LC #706 | Build underlying structure used in encoding solutions | No — different pattern |

**How this pattern scales:**
- **Length-prefix encoding** (`4#word`) is the core trick — prepend the length so the decoder knows exactly how many characters to read, avoiding delimiter collisions entirely
- **Delimiter encoding** is the naive approach but breaks when the delimiter appears in the string — length-prefix is always safer
- **Serialize/deserialize pattern** generalizes from strings → arrays → trees → graphs, each adding complexity to the encoding scheme
- **Bidirectional map** when you need both encode and decode to be O(1) — store both directions in separate hash maps

```cpp
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
```
## Longest Consecutive Subsequence LC 128


<!-- notecardId: 1779987349739 -->

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

**Link**: [text](https://leetcode.com/problems/longest-consecutive-sequence/)

%

**Pattern:** Hash Set

**Approach:** Use a hash set to store the unique elements of the array. Then, iterate through the array and for each element, check if it is the start of a sequence (i.e., if the previous element is not in the set). If it is the start, keep checking for the next consecutive elements in the set and count the length of the sequence. Update the maximum length found.

**Key Insight:** By using a hash set, you can achieve O(1) average time complexity for lookups, allowing you to efficiently check for the presence of consecutive elements. The key is to only start counting when you find the beginning of a sequence, which ensures that each element is processed at most once.

**Gotchas:** Be careful with edge cases, such as an empty array or an array with all identical elements. Also, ensure that your implementation correctly identifies the start of a sequence and counts the length accurately.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Longest Consecutive Sequence in Matrix — LC #2123 | Same consecutive logic but in a 2D grid → BFS/DFS + hash set | Yes — generalization |
| Contains Duplicate — LC #217 | Just check existence in hash set, no sequence building | Yes — foundation |
| Missing Number — LC #268 | Find the one gap in a consecutive sequence → math or XOR | Partial — same consecutive idea |
| Find All Numbers Disappeared in Array — LC #448 | Find all gaps in consecutive range → hash set or index marking | Partial — close variant |
| Longest Arithmetic Subsequence — LC #1027 | Consecutive by arithmetic difference not +1 → DP + hash map | Partial — harder generalization |
| Longest String Chain — LC #1048 | Build chains of strings differing by one char → DP + hash map | Partial — same chain building idea |
| Number of Islands — LC #200 | Group connected components instead of consecutive numbers → BFS/DFS | No — different pattern |
| Patience Sorting / LIS — LC #300 | Longest increasing not necessarily consecutive → DP or binary search | No — different pattern |

**How this pattern scales:**
- **Hash set + only start from sequence beginnings** (`n-1 not in set`) is the key O(n) trick — without this check you revisit elements and blow up to O(n²)
- **Union Find** is an alternative approach — treat each number as a node and union consecutive numbers, sequence length = component size
- **Consecutive sequence logic** generalizes from numbers → strings (LC #1048) → arithmetic differences (LC #1027) by changing what "consecutive" means
- **"Start of sequence" optimization** is the transferable insight — any time you're building chains, only start from the true beginning to avoid redundant work

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //I initially considered using bucket sort, but lets try hash map

        unordered_set<int> LCS(nums.begin(), nums.end()); //go thru the nums array, add to the set
        int longest = 0; //use this to track the longest sequence
        for (int num : LCS){ //go thru the set
        int currentNum = 0; //start the number we are at
        int currentStreak = 0; //start streak at 0
        if(LCS.find(num-1) == LCS.end()){ 
            currentNum = num; //mark the number at where the streak starts
            currentStreak = 1; //set streak to 1 since no number comes before, this marks beginning of streak
            //ensure previous # is not there, start subsequence
            while(LCS.find(currentNum + 1)!= LCS.end()){ //keep streak going when the next number is found in the set, and if it isnt, we know the streak ends, dont go in while loop
                currentStreak++; //increment streak
                currentNum++; //we move to the next number in the streak
            }
        } 
        longest = max(longest, currentStreak); //if currentStreak is longer than the previous longest, update the longest to currentStreak
        }
        return longest; //at the end, return the LCS length
    }
};
```

## Range Sum Query 2D - Immutable LC 304

<!-- notecardId: 1779987349742 -->

Given a 2D matrix matrix, handle multiple queries of the following type:

Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:

NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.

 Side note: Image here is useful, use the link to view as it will be easier.

Example 1:


Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]

Explanation
NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
-104 <= matrix[i][j] <= 104
0 <= row1 <= row2 < m
0 <= col1 <= col2 < n
At most 104 calls will be made to sumRegion.

**Link**: [text](https://leetcode.com/problems/range-sum-query-2d-immutable/)

%

**Pattern:** Prefix Sum | Dynamic Programming | 2D Array

**Approach:** Precompute a 2D prefix sum array where prefix[i+1][j+1] contains the sum of all elements from the top-left corner (0,0) to (i+1)(j+1). This allows you to calculate the sum of any submatrix in O(1) time using the formula: `sumRegion = prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1]`. Handle edge cases where row1 or col1 is 0 to avoid out-of-bounds access.

**Key Insight:** By precomputing the prefix sums, you can answer any sumRegion query in constant time. The key is to understand how to use the prefix sums to calculate the sum of a submatrix efficiently, which involves adding and subtracting the appropriate prefix sums to account for the area of interest.

**Gotchas:** Be careful with the indexing when creating the prefix sum array, as it is typically 1-based to simplify calculations. Also, ensure that you handle edge cases correctly when row1 or col1 is 0, as this can lead to out-of-bounds access if not handled properly.

**Complexity:** Time: O(m*n) for precomputation, O(1) for each query | Space: O(m*n) for the prefix sum array

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Range Sum Query — LC #303 | Same prefix sum but 1D array instead of 2D matrix | Yes — foundation |
| Range Sum Query Mutable — LC #307 | Same but array is mutable → Binary Indexed Tree / Segment Tree | Partial — upgrade |
| Matrix Block Sum — LC #1314 | Sum of all elements within distance k → 2D prefix sum with window | Yes — direct variant |
| Submatrix Sum Equals K — LC #1074 | Find number of submatrices summing to k → 2D prefix sum + hash map | Yes — generalization |
| Maximal Square — LC #221 | Find largest square of 1s → 2D DP with similar prefix idea | Partial — same 2D thinking |
| Count Vowels Permutation — LC #1220 | Accumulate counts across states → 1D prefix-style DP | No — different pattern |
| Number of Submatrices That Sum to Target — LC #1074 | Reduce 2D to 1D prefix sum per row pair → hash map | Yes — harder generalization |

**How this pattern scales:**
- **2D prefix sum** formula `P[i][j] = grid[i][j] + P[i-1][j] + P[i][j-1] - P[i-1][j-1]` is the core trick — memorize this and the query formula cold
- **Query formula** `P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]` is inclusion-exclusion — draw a diagram if you forget it in an interview
- **1D → 2D extension** is the general pattern — any 1D prefix sum problem can be asked in 2D form, so always consider if the 2D version exists
- **Mutable upgrade** → when the array can change, prefix sum breaks and you need a **Segment Tree** or **Binary Indexed Tree (Fenwick Tree)** instead

```cpp
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        //have to build prefix sum table here
        prefixSum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for(int i = 0; i < matrix.size(); i++){
         for(int j = 0; j < matrix[0].size(); j++){
            prefixSum[i+1][j+1] = matrix[i][j] + prefixSum[i][j+1] + prefixSum[i+1][j] - prefixSum[i][j];
         }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        sum = prefixSum[row2+1][col2+1] - prefixSum[row1][col2+1] -  prefixSum[row2+1][col1] + prefixSum[row1][col1]; 
        return sum;
    }

    private:
    vector<vector<int>> prefixSum;
};
```

## Design Hash Set LC 705

<!-- notecardId: 1779988800028 -->

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.

**Link**: [text](https://leetcode.com/problems/design-hashset/)

%

**Pattern:** Hash Table | Separate Chaining | Open Addressing | Array

**Approach:** Use an array of bools to check if a key is in the Hash Table. The index of the array can be determined by the key itself since the constraints allow for a direct mapping (0 to 10^6). For add, set the index to true. For remove, set it to false. For contains, check if the index is true.

**Key Insight:** Since the keys are limited to a specific range (0 to 10^6), we can use a simple array to implement the HashSet without worrying about collisions. This allows for O(1) time complexity for add, remove, and contains operations.

**Gotchas:** Be careful with the size of the array, as it needs to accommodate all possible keys. Also, ensure that the add, remove, and contains methods correctly manipulate the boolean values in the array. Be sure to mention open addressing or separate chaining if the constraints were different and collisions were possible. Some details about those: - **Separate Chaining**: Use a list or another data structure at each index to handle collisions. When adding a key, check if it already exists in the list and add it if not. When removing, remove it from the list. When checking for contains, check if it exists in the list. - **Open Addressing**: Use a probing method (linear, quadratic, or double hashing) to find the next available slot in case of a collision. When adding, if the index is occupied, probe for the next slot until you find an empty one. When removing, mark the slot as deleted but do not remove it entirely to avoid breaking the probing sequence. When checking for contains, probe until you find the key or an empty slot.

**Complexity:** Time: O(1) for add, remove, and contains | Space: O(n) where n is the range of possible keys (10^6)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Design HashMap — LC #706 | Store key-value pairs instead of just keys → same bucketing + chaining | Yes — direct upgrade |
| Contains Duplicate — LC #217 | Use a hash set to detect duplicates → consumer of this data structure | Yes — foundation |
| Longest Consecutive Sequence — LC #128 | Hash set lookups to build sequences → consumer of this data structure | Yes — application |
| Two Sum — LC #1 | Hash map for complement lookup → same underlying hash logic | Partial — map variant |
| Design HashMap — LC #706 | Same design but with value storage added | Yes — direct extension |
| LRU Cache — LC #146 | Hash map + doubly linked list for eviction policy → next level design | Partial — upgrade |
| Find Duplicate File in System — LC #609 | Group by hash key → same bucketing idea at a higher level | Partial — same concept |

**How this pattern scales:**
- **Array of buckets + chaining** (linked list or vector per bucket) is the standard implementation — `bucket = key % size`, collision resolution via chaining
- **Open addressing** is the alternative — probe for the next empty slot instead of chaining, harder to implement but better cache performance
- **Load factor** is the key design consideration — when `elements / buckets` exceeds ~0.7, resize and rehash to maintain O(1) average operations
- **Design HashMap (LC #706)** is the immediate next step — exact same structure, just store `{key, value}` pairs in each bucket instead of just keys

```cpp
class MyHashSet {
public:
    MyHashSet() {
        //boolArr[1000001] = {false};
    }
    
    void add(int key) {
        boolArr[key] = true;
    }
    
    void remove(int key) {
        boolArr[key] = false;
    }
    
    bool contains(int key) {
        return boolArr[key];
    }

private:
bool boolArr[1000001] = {false};
};
```

## Product of Array Except Self LC 238

<!-- notecardId: 1779989167090 -->

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

**Link**: [text](https://leetcode.com/problems/product-of-array-except-self/)

%

**Pattern:** Prefix Product | Suffix Product | Dynamic Programming

**Approach:** Create two arrays, one for prefix products and one for suffix products. The prefix product at index i is the product of all elements before i, and the suffix product at index i is the product of all elements after i. Then, the answer for each index i can be calculated as the product of prefix[i] and suffix[i]. To achieve O(1) extra space, you can use the output array to store the prefix products and then calculate the suffix products on the fly while iterating from the end of the array.

**Key Insight:** The key is to realize that the product of all elements except the current one can be broken down into the product of all elements before it (prefix) and the product of all elements after it (suffix). By precomputing these products, you can efficiently calculate the result for each index without using division.

**Gotchas:** Be careful with edge cases, such as when the input array contains zeros, as this will affect the product calculations. Also, ensure that you correctly handle the indexing when calculating prefix and suffix products to avoid off-by-one errors.

**Complexity:** Time: O(n) | Space: O(1) (excluding the output array)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Trapping Rain Water — LC #42 | Prefix max and suffix max instead of prefix/suffix product → same two-pass build | Yes — same structure |
| Maximum Product Subarray — LC #152 | Track running product but reset on zeros → prefix product idea | Partial — close variant |
| Subarray Product Less Than K — LC #713 | Sliding window over products instead of prefix build | Partial — product focus |
| Range Sum Query — LC #303 | Prefix sum instead of prefix product → simpler version of same pattern | Yes — foundation |
| Minimum Suffix Array — LC #2167 | Build suffix structure for range queries → same suffix thinking | Partial — generalization |
| Sum of Total Strength of Wizards — LC #2281 | Prefix sum of prefix sums → double prefix build | Partial — harder extension |
| Find Pivot Index — LC #724 | Left sum equals right sum → prefix sum from both sides | Yes — same two-pass idea |

**How this pattern scales:**
- **Prefix + suffix two-pass** is the core pattern — first pass builds left context, second pass folds in right context, result needs both. Any problem where each element depends on everything to its left AND right uses this
- **O(1) space optimization** — instead of storing the full suffix array, carry a running suffix variable from right to left in the second pass and multiply directly into the result array
- **Zero handling** is the critical gotcha — if the array contains one zero, only that index has a nonzero product. Two or more zeros → all products are zero. Handle before building prefix/suffix
- **Logarithms** are an alternative — `log(a*b) = log(a) + log(b)` converts products into sums, making prefix sum applicable, but introduces floating point precision issues

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //look at left and right, array store left products and another array stores right products
        //genius idea, calculate left array, and then right array only needs to store a number, then multiply with left array
        vector<int> ans;
        ans.push_back(1); //first number going from left side will always be 1;
        int leftTrack = 1;
        for(int i = 1; i < nums.size(); i++){
            leftTrack *= nums[i-1]; //as you keep going, keep multiplying by the one you just moved past
            ans.push_back(leftTrack); //push it back to array, goes untul end of the array
        }
        int rightTrack = 1; //start going from the right
        //right element of ans is correct, start from before
    for(int i = nums.size()-2; i >-1;  i--){ //why -2? b/c -1 is to get to the index of last element, and -2 because -1 will always be the same as 
    //the left array's final value
            rightTrack *= nums[i+1]; //iterate from right to left, as you move left, multiply the value on the right you moved on from
            ans[i] = rightTrack * ans[i]; //observation that ans = left * right, ans before multipliying is left
        }
        return ans;
    }
};
```

## Design Hash Map LC 706

<!-- notecardId: 1780084082324 -->

Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:

Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]
 

Constraints:

0 <= key, value <= 106
At most 104 calls will be made to put, get, and remove.

**Link**: [text](https://leetcode.com/problems/design-hashmap/)

%

**Pattern:** Hash Table | Separate Chaining | Open Addressing | Array

**Approach:** Use an array of pairs to implement the hash map. The index of the array can be determined by the key itself since the constraints allow for a direct mapping (0 to 10^6). For put, set the index to the value. For get, return the value at the index or -1 if it does not exist. For remove, set the index to a special value (e.g., -1) to indicate that it has been removed.

**Key Insight:** Since the keys are limited to a specific range (0 to 10^6), we can use a simple array to implement the HashMap without worrying about collisions. This allows for O(1) time complexity for put, get, and remove operations.

**Gotchas:** Be careful with the size of the array, as it needs to accommodate all possible keys. Also, ensure that the put, get, and remove methods correctly manipulate the values in the array. Be sure to mention open addressing or separate chaining if the constraints were different and collisions were possible. Some details about those: - **Separate Chaining**: Use a list or another data structure at each index to handle collisions. When adding a key-value pair, check if the key already exists in the list and update it if so; otherwise, add a new pair. When removing, remove the pair from the list. When checking for contains, check if the key exists in the list. - **Open Addressing**: Use a probing method (linear, quadratic, or double hashing) to find the next available slot in case of a collision. When adding, if the index is occupied by a different key, probe for the next slot until you find an empty one or one with the same key. When removing, mark the slot as deleted but do not remove it entirely to avoid breaking the probing sequence. When checking for contains, probe until you find the key or an empty slot.

**Complexity:** Time: O(1) for put, get, and remove | Space: O(n) where n is the range of possible keys (10^6)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Design HashSet — LC #705 | Store only keys, no values → simpler version of same bucketing | Yes — foundation |
| Two Sum — LC #1 | Use hash map for complement lookup → consumer of this data structure | Yes — direct application |
| LRU Cache — LC #146 | Hash map + doubly linked list for O(1) eviction → next level design | Partial — upgrade |
| LFU Cache — LC #460 | Hash map + frequency tracking → harder cache design | Partial — harder upgrade |
| Insert Delete GetRandom O(1) — LC #380 | Hash map + array for O(1) random access → combined data structure design | Partial — same design thinking |
| Time Based Key-Value Store — LC #981 | Hash map with versioned values → binary search on timestamps per key | Yes — direct extension |
| Design Twitter — LC #355 | Hash map to store user tweets + heap for feed → system design application | Partial — applied design |

**How this pattern scales:**
- **Array of buckets + chaining** is the same core as LC #705 — only difference is each bucket stores `{key, value}` pairs instead of just keys
- **Separate chaining vs open addressing** — chaining (vectors/linked lists per bucket) is easier to implement in interviews; open addressing has better cache performance in practice
- **Resize and rehash** when load factor exceeds ~0.7 — allocate a larger bucket array and reinsert all existing pairs to maintain O(1) average
- **Design pattern ladder** → HashSet → HashMap → LRU Cache → LFU Cache — each builds directly on the previous, so knowing this problem cold makes the harder design problems approachable

```cpp
class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        arr[key] = {true, value};
    }
    
    int get(int key) {
        if(arr[key].first == false) return -1;
        return arr[key].second;
    }
    
    void remove(int key) {
        arr[key] = {false, -1};
    }

private:
std::pair<bool, int> arr[1000001] = {{false, -1}};
};
```

## Best Time to Buy and Sell Stock II LC 122

<!-- notecardId: 1780084534030 -->

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

**Link**: [text](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

%

**Pattern:** Greedy | Dynamic Programming

**Approach:** Iterate through the price array and sum up all positive differences between consecutive days. This works because any time there is a price increase from one day to the next, you can profit by buying on the first day and selling on the second day. By summing all these positive differences, you effectively capture all profitable transactions.

**Key Insight:** The key insight is that you can treat every increase in price as an opportunity to profit. Instead of trying to find the best single buy/sell pair, you can simply add up all the increases, which will give you the maximum profit.

**Gotchas:** Be careful with edge cases, such as when the price array is strictly decreasing, which would result in zero profit. Also, ensure that you are only summing positive differences to avoid subtracting from your profit.

**Complexity:** Time: O(n) | Space: O(1)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Best Time to Buy and Sell Stock — LC #121 | Only one transaction allowed → track global min and max profit | Yes — foundation |
| Best Time to Buy and Sell Stock III — LC #123 | At most two transactions → DP with transaction state tracking | Partial — upgrade |
| Best Time to Buy and Sell Stock IV — LC #188 | At most k transactions → generalized DP with k states | Partial — harder upgrade |
| Best Time to Buy and Sell Stock with Cooldown — LC #309 | Must wait one day after selling → DP with cooldown state | Partial — constraint added |
| Best Time to Buy and Sell Stock with Fee — LC #714 | Pay a fee per transaction → same greedy but subtract fee on each sell | Yes — direct variant |
| Jump Game — LC #55 | Greedy decision at each step → same greedy accumulation idea | Partial — same greedy thinking |
| Maximum Subarray — LC #53 | Accumulate gains, reset on loss → Kadane's mirrors the greedy here | Partial — same accumulation |

**How this pattern scales:**
- **Greedy accumulation** is the core trick — add every positive difference `prices[i] - prices[i-1]` since unlimited transactions means capturing every upward move is always optimal
- **DP with states** is the upgrade when constraints are added — `hold`, `sold`, `cooldown` states for LC #309; `k transactions` for LC #188
- **Stock problem ladder** → LC #121 → LC #122 → LC #309 → LC #714 → LC #123 → LC #188 — each adds one constraint on top of the previous, always start from the simplest version in an interview
- **Greedy vs DP** — LC #122 is rare in that greedy works perfectly; as soon as a constraint is added (cooldown, fee, max k) greedy breaks and you must switch to DP

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size() -1 ; i++){
            if (prices[i+1] > prices[i]){
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};
```

## Majority Element LC 169

<!-- notecardId: 1780342739799 -->

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
The input is generated such that a majority element will exist in the array.
 

Follow-up: Could you solve the problem in linear time and in O(1) space?

**Link**: [text](https://leetcode.com/problems/majority-element/)

%

**Pattern:** Boyer-Moore Voting Algorithm | Hash Map

**Approach:** The Boyer-Moore Voting Algorithm is an efficient way to find the majority element in linear time and constant space. The algorithm maintains a candidate for the majority element and a count. It iterates through the array, updating the candidate and count based on whether the current element matches the candidate. If the count drops to zero, it selects a new candidate. By the end of the iteration, the candidate will be the majority element.

**Key Insight:** The key insight is that if you pair each occurrence of the majority element with a different element, the majority element will still have at least one occurrence left unpaired. This is why the Boyer-Moore algorithm works: it effectively cancels out pairs of different elements, leaving the majority element as the last candidate standing.

**Gotchas:** Be careful with edge cases, such as when the majority element is at the beginning or end of the array. Also, ensure that you correctly update the candidate and count during the iteration.

**Complexity:** Time: O(n) | Space: O(1)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Majority Element II — LC #229 | Find all elements appearing more than n/3 times → Boyer-Moore with two candidates | Yes — direct upgrade |
| Find the Duplicate Number — LC #287 | One duplicate in array → Floyd's cycle detection, no counting | No — different pattern |
| Single Number — LC #136 | Element appearing once not majority → XOR trick | No — different pattern |
| Top K Frequent Elements — LC #347 | Find k most frequent not just majority → hash map + heap | Partial — frequency counting |
| Check Array Formation Through Concatenation — LC #1640 | Verify element presence and order → hash map lookup | No — different pattern |
| Random Pick with Weight — LC #528 | Weight-based selection → prefix sum not frequency counting | No — different pattern |
| Find Winner on a Tic Tac Toe Game — LC #1275 | Count moves per player → simple frequency counting | Partial — same counting idea |

**How this pattern scales:**
- **Boyer-Moore Voting Algorithm** is the core trick — maintain a candidate and a count, increment on match decrement on mismatch, reset candidate when count hits zero. O(n) time O(1) space
- **Hash map counting** is the O(n) time O(n) space fallback — simpler to derive under pressure but uses extra space
- **Sorting** is the O(n log n) fallback — majority element always occupies `nums[n/2]` after sorting since it appears more than n/2 times
- **Two candidate upgrade** → LC #229 extends Boyer-Moore to track two candidates simultaneously for the n/3 threshold — same algorithm, one more candidate variable

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int counter = 1;
        for (int i = 1; i < nums.size(); i++){
            if(nums[i] != candidate){
                if(counter == 0){
                candidate = nums[i];
                counter = 0;
                }
                else{
                    counter--;
                }
            }
            else{
                counter++;
            }
        }
        return candidate;
    }
};
```

## Majority Element II LC 229

<!-- notecardId: 1780343247492 -->

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?

**Link**: [text](https://leetcode.com/problems/majority-element-ii/)

%

**Pattern:** Boyer-Moore Voting Algorithm | Hash Map

**Approach:** The Boyer-Moore Voting Algorithm can be extended to find all elements that appear more than n/3 times. In this case, you need to maintain two candidates and their corresponding counts. As you iterate through the array, you update the candidates and counts based on whether the current element matches either candidate. If the count for a candidate drops to zero, you replace that candidate with the current element and reset the count. After the first pass, you will have at most two candidates. You then need to do a second pass to verify which of these candidates actually appear more than n/3 times.

**Key Insight:** The key insight is that there can be at most two elements that appear more than n/3 times in an array. This is because if there were three such elements, they would have to occupy more than n positions, which is impossible. Therefore, by tracking two candidates and their counts, you can efficiently find the majority elements.

**Gotchas:** Be careful with edge cases, such as when the array has fewer than three elements. Also, ensure that you correctly update the candidates and counts during the iteration, and remember to verify the candidates in a second pass.

**Complexity:** Time: O(n) | Space: O(1)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Majority Element — LC #169 | Only one majority element at n/2 threshold → single candidate Boyer-Moore | Yes — foundation |
| Find All Numbers Disappeared in Array — LC #448 | Find missing not majority → index marking or hash set | No — different pattern |
| Top K Frequent Elements — LC #347 | Find k most frequent not threshold based → hash map + heap | Partial — frequency counting |
| Single Number — LC #136 | Find element appearing once → XOR trick not voting | No — different pattern |
| Single Number II — LC #137 | Find element appearing once among thrice-repeated → bit manipulation | No — different pattern |
| Check If Array Is Good — LC #1422 | Verify frequency conditions on array → hash map counting | Partial — same counting idea |
| Find Duplicate File in System — LC #609 | Group by content hash → frequency grouping | Partial — same grouping idea |

**How this pattern scales:**
- **Boyer-Moore with two candidates** is the core upgrade from LC #169 — track two candidate/count pairs, eliminate in groups of 3 instead of 2, then verify both candidates in a second pass
- **Verification pass is mandatory** — unlike LC #169 where a majority element is guaranteed, LC #229 has no guarantee that two such elements exist, so always verify candidate counts exceed n/3 after the voting pass
- **General k threshold** → for elements appearing more than n/k times, maintain k-1 candidates using the same Boyer-Moore logic — interview follow-up worth knowing
- **Hash map fallback** is O(n) time O(n) space — count all frequencies then filter those exceeding n/3, simpler to derive but misses the O(1) space insight interviewers look for

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> totalVals(2);// 2 majority numbers tops 
        int count1 = 0;
        int count2 = 0;
        totalVals[0] = -1*10^10; //set as val that cannot be reached
        totalVals[1] = -1*10^10;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == totalVals[0]){
                count1++; // if same as first majority number, incremenent counter
            }
            else if(nums[i] == totalVals[1]){
                count2++; // if same as second majority number, incremenent counter
            }
            else{
                if(count1 == 0){
                    totalVals[0] = nums[i]; //if not the same and counter at 0, we know this is not the majority number, so replace with new number and reset counter
                    count1 = 1; 
                }
                else if(count2 == 0){
                    totalVals[1] = nums[i]; //if not the same and counter at 0, we know this is not the majority number, so replace with new number and reset counter
                    count2 = 1;
                }
                else{
                    count1--; //this is the trick, if we find a number that is not the same as either majority number, we know this number is not the majority number, so we have to decrement both counters
                    count2--;
                }
            }
        }

        //beginning of second pass
        int totalCount1= 0; //set counter for totalVals 0
        int totalCount2 = 0;//set counter for totalVals 1
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == totalVals[0]){
                totalCount1++; //if totalVals 0 found, increment ctr
            }
            else if (nums[i] == totalVals[1]){
                totalCount2++; //if totalVals 1 found, increment ctr
            }
        }
        if(totalCount2 <= nums.size() /3){
            totalVals.erase(totalVals.begin() + 1); //if totalVals 1 not majority, remove from vector. Start from end to avoid index issues
        }
        if(totalCount1 <= nums.size() /3){
            totalVals.erase(totalVals.begin()); //if totalVals 0 not majority, remove from vector.
        }
        return totalVals;
    }
};
```

## Valid Sudoku LC 36

<!-- notecardId: 1780344057419 -->



Code

Testcase
Testcase

Test Result
36. Valid Sudoku
Solved
Medium

Topics
conpanies icon
Companies
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit 1-9 or '.'.

**Link**: [text](https://leetcode.com/problems/valid-sudoku/)

%

**Pattern:** Hash Set | Matrix

**Approach:** Use three hash sets to track the digits seen in each row, column, and 3x3 sub-box. As you iterate through the board, for each filled cell, check if the digit has already been seen in the corresponding row, column, or sub-box. If it has, return false. If not, add the digit to the respective sets. If you finish iterating through the board without finding any duplicates, return true.

**Key Insight:** The key insight is that you can use hash sets to efficiently track the presence of digits in rows, columns, and sub-boxes. By encoding the row, column, and sub-box information into the hash set keys, you can quickly check for duplicates without needing nested loops.

**Gotchas:** Be careful with the indexing when determining which sub-box a cell belongs to. The sub boxes can be stored in a 3 by 3 array of hash tables, and then to index, row = row / 3 and col = col / 3. Also, ensure that you only check filled cells (i.e., those that are not '.').

**Complexity:** Time: O(1) since the board size is fixed at 9x9 | Space: O(1) for the same reason

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Sudoku Solver — LC #37 | Actually fill in the board instead of just validating → backtracking on top of same validation logic | Yes — direct upgrade |
| N-Queens — LC #51 | Place queens with no conflicts → same "no duplicates in row/col/box" constraint via backtracking | Partial — same constraint checking |
| Valid Tic Tac Toe State — LC #794 | Validate board state for smaller grid → same row/col checking logic | Partial — simpler variant |
| Word Search — LC #79 | Search grid with visited tracking → same 2D grid indexing | No — different pattern |
| Set Matrix Zeroes — LC #73 | Modify matrix based on cell values → same grid traversal | No — different pattern |
| Find Winner on Tic Tac Toe — LC #1275 | Count moves per row/col → same hash set per line idea | Partial — same structure |
| Unique Paths — LC #62 | 2D grid traversal → DP not constraint checking | No — different pattern |

**How this pattern scales:**
- **Hash set per row, col, box** is the core trick — three arrays of hash sets, one per constraint type, check and insert simultaneously in a single pass
- **Box index formula** `(row / 3) * 3 + (col / 3)` is the key insight to memorize cold — maps any cell to its 0-8 box index in O(1), or could use a 2D array of hash sets indexed by `(row / 3, col / 3)`
- **Backtracking upgrade** → LC #37 (Sudoku Solver) layers backtracking on top of this exact validation logic — try a digit, validate, recurse, undo if invalid. Knowing LC #36 cold means the validation step of LC #37 is already solved
- **Constraint propagation** is the optimized approach for LC #37 — instead of blind backtracking, eliminate candidates using row/col/box sets before guessing, drastically reducing search space

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxes[3][3];
    for(int i= 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if(board[i][j] == '.'){
                continue;
            }
            else if(rowSet[i].find(board[i][j]) == rowSet[i].end() && colSet[j].find(board[i][j]) == colSet[j].end() && boxes[i/3][j/3].find(board[i][j]) == boxes[i/3][j/3].end()){
                rowSet[i].insert(board[i][j]);
                colSet[j].insert(board[i][j]);
                boxes[i/3][j/3].insert(board[i][j]);

            }
            else{
                return false;
            }
        }
    }

    return true;

    }
};
```

## Subarray Sum Equals K LC 560

<!-- notecardId: 1780344879148 -->

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

**Link**: [text](https://leetcode.com/problems/subarray-sum-equals-k/)

%

**Pattern:** Prefix Sum | Hash Map

**Approach:** Use a hash map to store the cumulative sum of the elements up to the current index. As you iterate through the array, calculate the cumulative sum and check if there is a previous cumulative sum that equals the current cumulative sum minus k. If such a sum exists in the hash map, it means there is a subarray that sums to k, and you can add the count of that cumulative sum to your result. Finally, update the hash map with the current cumulative sum. 

**Key Insight:** The key insight is that if the cumulative sum up to index j is S, and there was a previous cumulative sum S-k at index i, then the subarray from index i+1 to j sums to k. By using a hash map to track the frequency of cumulative sums, you can efficiently count the number of valid subarrays in a single pass.

**Gotchas:** Be careful with edge cases, such as when the cumulative sum itself equals k, which means a valid subarray starts from index 0. Also, ensure that you correctly update the hash map with the cumulative sums and their counts.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Two Sum — LC #1 | Find two indices summing to target → same "have I seen complement" hash map lookup | Yes — foundation |
| Continuous Subarray Sum — LC #523 | Subarray sum divisible by k → prefix sum + modulo + hash map | Yes — direct variant |
| Subarray Sum Divisible by K — LC #974 | Count subarrays with sum divisible by k → prefix sum mod k + hash map | Yes — close variant |
| Range Sum Query — LC #303 | Precompute prefix sums for repeated queries → same prefix sum build | Yes — same structure |
| Binary Subarrays With Sum — LC #930 | Count subarrays with exact binary sum → same prefix sum + hash map | Yes — direct variant |
| Path Sum III — LC #437 | Same subarray sum idea but on a tree → DFS + prefix sum hash map | Yes — generalization |
| Minimum Size Subarray Sum — LC #209 | Find shortest subarray exceeding sum → sliding window instead of hash map | Partial — positive nums only |
| Count of Range Sum — LC #327 | Count subarrays within a sum range → merge sort + prefix sum | Partial — harder generalization |

**How this pattern scales:**
- **Prefix sum + hash map** is the core trick — store frequency of each prefix sum seen so far, for each new prefix sum check if `prefixSum - k` exists in the map. O(n) time O(n) space
- **Modulo variant** → when the problem asks divisible by k instead of equal to k, store `prefixSum % k` in the map instead — LC #523 and LC #974 are direct applications
- **Tree generalization** → LC #437 (Path Sum III) applies the exact same prefix sum hash map logic but runs it via DFS, passing the map down the recursion and cleaning it up on the way back
- **Sliding window limitation** → sliding window only works when all values are positive (shrinking the window guarantees sum decreases). Prefix sum + hash map works for negative numbers too — always prefer it when negatives are possible

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalSubarrays = 0; //track the number of total possible subarrays that sum to k
        int currentSum = 0; //incrementing sum of the entire array
        unordered_map<int, int> preFixSumMinusK; //map to track number of times a prefix sum has been seen so far
        preFixSumMinusK.insert({0, 1}); //sum 0 has been seen once, this is the base case
        for(int i = 0; i < nums.size(); i++){ //go through the entire array
            currentSum += nums[i]; //add the current number to the current sum
            if(preFixSumMinusK.find(currentSum - k) != preFixSumMinusK.end()){ //check if the current sum - k has been seen before, if so, add the number of times it has been seen to the total subarrays
            //if currentSum - k has been seen before, then there are preFixSumMinusK[currentSum - k] number of subarrays that sum to k, because if currentSum - k has been seen before, then there are preFixSumMinusK[currentSum - k] number of subarrays that sum to currentSum - k, and if we add the current number to those subarrays, then they will sum to k
                totalSubarrays += preFixSumMinusK[currentSum - k];
            }
                preFixSumMinusK[currentSum]++; //always increment the times currentSum has been seen, this is important for making future possible subarrays that sum up to k
        }
        return totalSubarrays;

    }
};
```

## First Missing Positive LC 41

<!-- notecardId: 1780345064348 -->

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1

**Link**: [text](https://leetcode.com/problems/first-missing-positive/)

%

**Pattern:** Array Indexing | In-place Hashing

**Approach:** The idea is to use the input array itself as a hash map to track which positive integers are present. First, we can ignore all numbers that are less than or equal to 0 and greater than n (the length of the array) since they cannot be the first missing positive. Then, for each number in the array, if it is in the range [1, n], we can mark its presence by negating the value at the index corresponding to that number (i.e., nums[num - 1]). Finally, we can iterate through the array again to find the first index that has a positive value, which indicates that the index + 1 is the first missing positive integer.

**Key Insight:** The key insight is that since we are looking for the first missing positive integer, it must be in the range [1, n+1]. By using the array itself to track presence, we can achieve O(n) time complexity and O(1) space complexity without needing extra data structures.

**Gotchas:** Be careful with the indexing when marking presence. Remember to check if the number is within the valid range before trying to mark it. Also, ensure that you handle duplicates correctly, as they should not affect the marking process. You need to check if the value at the index you want to swap is already in the correct position to avoid infinite loops.

**Complexity:** Time: O(n) | Space: O(1)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Missing Number — LC #268 | Find missing in range 0 to n → XOR or math, no index marking needed | Yes — simpler foundation |
| Find All Numbers Disappeared in Array — LC #448 | Find all missing in range 1 to n → same index marking trick, collect all | Yes — direct variant |
| Find the Duplicate Number — LC #287 | Find duplicate not missing → Floyd's cycle detection or index marking | Partial — same index idea |
| First Missing Positive — LC #41 | Find smallest missing positive → index marking with negation | Yes — hardest in family |
| Set Matrix Zeroes — LC #73 | Mark cells in place without losing info → same in-place marking idea | Partial — same constraint |
| Longest Consecutive Sequence — LC #128 | Find longest run of consecutive numbers → hash set instead of index marking | Partial — consecutive family |
| Couples Holding Hands — LC #765 | Rearrange elements to correct positions → same "element belongs at index" idea | Partial — placement idea |
| Cyclic Sort Pattern | Sort by placing each number at its correct index → direct generalization of index marking | Yes — generalization |

**How this pattern scales:**
- **Index as a hash map** is the core trick — since the answer must be in range 1 to n+1, use the array itself as a presence marker by negating values at index `num - 1`. O(n) time O(1) space
- **Three step pattern** → (1) ignore out of range values, (2) mark presence by negating at correct index, (3) scan for first positive index — this exact sequence solves LC #448 too
- **Cyclic sort generalization** → instead of negating, swap each element to its correct index position `nums[i] - 1`. Cyclic sort is cleaner and generalizes to the whole missing/duplicate number family
- **O(1) space constraint** is the key signal — any time a problem says "constant extra space" on an array of integers in a known range, index marking or cyclic sort is almost certainly the intended approach

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){ //go thru the nums array
            while(nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i]- 1] != nums[i]){ //check validity for if you can swap
            //1 or greater (positive) less than/equal to nums size (so it can be indexed properly in a 1-indexed array)
            //and check if the value at the index you want to swap to if nums[6] = 3, check if nums[2] has 3 in it or not already
                swap(nums[i], nums[nums[i]- 1]);
            }
        }
        for(int i= 0; i < nums.size(); i++ ){ //validation loop
            if(nums[i] != i+1){ //check if index has the right value, remember c++ vectors are 0 indexed, so have to check i + 1
                       return i+1;
            }
        }
        return nums.size() + 1; //if everything is correct, then nums.size() + 1 is just return, if array size 9 has 1-9, then 10 is returned
    }
};
```

## Valid Parentheses LC 20

<!-- notecardId: 1780362590830 -->

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

**Link**: [text](https://leetcode.com/problems/valid-parentheses/)

%

**Pattern:** Stack

**Approach:** Use a stack to keep track of the opening brackets. As you iterate through the string, when you encounter an opening bracket, push it onto the stack. When you encounter a closing bracket, check if the stack is not empty and if the top of the stack is the corresponding opening bracket. If it is, pop the stack; otherwise, return false. After processing all characters, if the stack is empty, return true; otherwise, return false.

**Key Insight:** The key insight is that the most recent opening bracket must be closed first, which is a natural fit for a stack data structure. By pushing opening brackets onto the stack and popping them when a matching closing bracket is found, you can easily ensure that the brackets are properly nested and ordered.

**Gotchas:** Be careful with edge cases, such as when the string starts with a closing bracket or when there are unmatched opening brackets left in the stack at the end. Also, ensure that you correctly match each type of bracket (i.e., '(' with ')', '{' with '}', and '[' with ']').

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Minimum Add to Make Parentheses Valid — LC #921 | Count minimum insertions to balance → track open count instead of stack | Partial — same balance idea |
| Longest Valid Parentheses — LC #32 | Find longest valid substring → DP or stack with indices | Partial — harder variant |
| Generate Parentheses — LC #22 | Generate all valid combinations → backtracking with open/close counts | Partial — same validity rules |
| Remove Invalid Parentheses — LC #301 | Remove minimum brackets to make valid → BFS or backtracking | Partial — same validity rules |
| Valid Parenthesis String — LC #678 | Wildcards can be open close or empty → greedy with min/max open count | Partial — upgrade |
| Decode String — LC #394 | Stack to track nested encoding context → same stack nesting idea | Yes — same stack pattern |
| Basic Calculator — LC #224 | Evaluate expression with parentheses → stack for operator and operand context | Yes — direct generalization |
| Simplify Path — LC #71 | Stack to process nested directory tokens → same push/pop on structure | Yes — same stack idea |

**How this pattern scales:**
- **Stack + hash map** is the core trick — map each closing bracket to its opener, push openers onto stack, pop and verify on closing brackets. Single pass O(n) time O(n) space
- **Balance counter** is the O(1) space simplification when only one bracket type exists — increment on open decrement on close, invalid if ever negative
- **Stack for nesting** generalizes far beyond brackets — any problem involving nested structures (expressions, directories, encoded strings) uses a stack to track context across levels
- **Greedy min/max range** → LC #678 (Valid Parenthesis String) replaces the stack with a range of possible open counts, tracking minimum and maximum valid states simultaneously — worth knowing as the hardest variant

```cpp
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
            char top = stk.top();
            stk.pop();
            if(
                (s[i] == ')' && top != '(')|| 
                (s[i] == ']' && top != '[') ||
                (s[i] == '}' && top != '{')
            ){
                return false;
            }
        }
        }
            return stk.empty();
    }
};
```

## Generate Parentheses LC 22

<!-- notecardId: 1780371457088 -->

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

**Link**: [text](https://leetcode.com/problems/generate-parentheses/)

%

**Pattern:** Backtracking

**Approach:** Use backtracking to generate all possible combinations of parentheses. Start with an empty string and at each step, you can either add an opening parenthesis '(' if you still have one available, or add a closing parenthesis ')' if it would not lead to an invalid sequence (i.e., you can only add a closing parenthesis if there are more opening parentheses than closing parentheses in the current string). Continue this process until you have used all n pairs of parentheses, at which point you can add the valid combination to the result list.

**Key Insight:** The key insight is that at any point in the generation process, the number of closing parentheses cannot exceed the number of opening parentheses, and you cannot add more than n opening parentheses. This ensures that you only generate valid combinations without needing to check for validity after the fact.

**Gotchas:** Be careful with the base case for the recursion, which is when the current string has used all n pairs of parentheses. Also, ensure that you correctly manage the counts of opening and closing parentheses to avoid generating invalid combinations.

**Complexity:** Time: O(4^n / sqrt(n)) | Space: O(n) for the recursion stack

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Parentheses — LC #20 | Validate existing string instead of generating → stack matching | Yes — foundation |
| Remove Invalid Parentheses — LC #301 | Remove minimum brackets to make valid → BFS or backtracking on existing string | Partial — same validity rules |
| Valid Parenthesis String — LC #678 | Wildcards add ambiguity → greedy min/max range instead of backtracking | Partial — same rules harder |
| Letter Combinations of a Phone Number — LC #17 | Generate all combinations from a digit mapping → same backtracking build | Yes — same pattern |
| Permutations — LC #46 | Generate all orderings of elements → same backtracking template | Yes — same pattern |
| Combination Sum — LC #39 | Generate combinations summing to target → same backtracking with pruning | Yes — same pattern |
| N-Queens — LC #51 | Place queens with no conflicts → same backtracking with constraint pruning | Partial — harder variant |
| Palindrome Partitioning — LC #131 | Partition string into valid palindromes → same backtracking build and validate | Partial — same structure |

**How this pattern scales:**
- **Backtracking template** is the core pattern — choose, recurse, unchoose. Add open bracket if `open < n`, add close bracket if `close < open`. Prune invalid states before recursing not after
- **Pruning is everything** — the reason this is O(4^n / √n) instead of O(2^2n) is that invalid states are pruned immediately. Any backtracking problem lives or dies by how early you can prune
- **Backtracking family ladder** → LC #22 → LC #46 (Permutations) → LC #39 (Combination Sum) → LC #51 (N-Queens) — each adds more complex constraint checking but the choose/recurse/unchoose skeleton never changes
- **Catalan number** is the count of valid combinations for n pairs — C(n) = (2n choose n) / (n+1). Worth knowing if an interviewer asks how many valid strings exist for a given n

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        backtracking(answer, "", 0, 0, n);
        return answer;
    }

private:
    void backtracking(vector<string>& answer, string current, int open, int close, int n){
        if(current.size() == 2*n){
            answer.push_back(current);
            return;
        }
        if(open < n){
            backtracking(answer, current + "(", open + 1, close, n);
        }
        if(close < open){
            backtracking(answer, current + ")", open, close + 1, n);
        }
    }
};
```

## Simplify Path LC 71

<!-- notecardId: 1780372745733 -->

You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.

 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.

**Link**: [text](https://leetcode.com/problems/simplify-path/)

%

**Pattern:** Stack | String Manipulation

**Approach:** Use a stack to process the components of the path. Split the input path by the '/' delimiter to get individual components. Iterate through these components and apply the following rules: if the component is empty or a single period '.', skip it; if it is a double period '..', pop from the stack if it's not empty (to go back to the parent directory); otherwise, push the component onto the stack as it represents a valid directory name. After processing all components, join the elements in the stack with '/' to form the simplified path, and ensure it starts with a '/'.

**Key Insight:** The key insight is that the stack can be used to keep track of the current directory structure as you process each component of the path. By pushing valid directory names onto the stack and popping when you encounter '..', you can effectively navigate through the directory structure and build the simplified path.

**Gotchas:** Be careful with edge cases, such as when the path starts with multiple slashes or when there are multiple consecutive slashes. Also, ensure that you handle the case where the stack is empty when trying to pop for '..', which means you are already at the root directory. Finally, remember to join the stack elements correctly to form the final path. This is the weird part, so to do it, create a vector and then push the stack elements into the vector, then reverse the vector and join with '/'.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Parentheses — LC #20 | Stack to match brackets instead of path tokens → same push/pop on structure | Yes — same stack pattern |
| Decode String — LC #394 | Stack to track nested encoding levels → same context tracking via stack | Yes — same stack idea |
| Basic Calculator — LC #224 | Stack to track operators and operands in nested expressions → same nesting logic | Yes — same stack pattern |
| Evaluate Reverse Polish Notation — LC #150 | Stack to evaluate postfix tokens → same token processing via stack | Yes — direct variant |
| Design File System — LC #1166 | Build a file system supporting path creation and lookup → same path parsing | Partial — upgrade |
| Find Duplicate File in System — LC #609 | Parse file paths to group duplicates → same path splitting idea | Partial — same parsing |
| Flatten Nested List Iterator — LC #341 | Flatten nested structure → same stack based traversal | Partial — same nesting idea |
| Text Justification — LC #68 | Process tokens left to right with decisions at each step → same token processing | No — different pattern |

**How this pattern scales:**
- **Stack + string split** is the core trick — split path by `/`, process each token, push valid directory names, pop on `..`, ignore `.` and empty strings. Rejoin stack with `/` at the end
- **Token processing pattern** generalizes to any problem where you scan left to right and need to undo a previous decision — stack lets you "go back" in O(1)
- **Deque upgrade** → when you need to reconstruct the path efficiently without reversing, use a deque and append to the back — same logic, cleaner join
- **Design File System (LC #1166)** is the direct upgrade — instead of just simplifying a path you actually need to store and retrieve values at paths, requiring a Trie or hash map on top of the same path parsing logic

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        std::stringstream ss(path);
        std::string token;
        while(getline(ss, token, '/')){
            // dir.push(token);            
            if(token.empty() || token == "."){
                continue; // . means we are in current directory, dont add to stack
            }
            else if(token == ".."){
                if(!dir.empty()){
                    dir.pop(); //pop because go back to parent.
                }
            }
            else{
                dir.push(token); //normal dir, add to dir stack
            }
        }
        vector<string> parts;
        while(!dir.empty()) {
            parts.push_back(dir.top());
            dir.pop();
        }
        
        string result = "";
        for(int i = parts.size() - 1; i >= 0; i--) {
            result += "/" + parts[i];
        }
    return result.empty() ? "/" : result; 
    }
};
```

## Largest Rectangle in Histogram LC 84

<!-- notecardId: 1780374823009 -->

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


**Link**: [text](https://leetcode.com/problems/largest-rectangle-in-histogram/)

%

**Pattern:** Stack

**Approach:** Use a stack to keep track of the indices of the histogram bars. Iterate through the heights array, and for each bar, pop from the stack until you find a bar that is shorter than the current bar. For each popped index, calculate the area of the rectangle that can be formed with the height of the bar at that index and the width determined by the current index and the index of the new top of the stack. Keep track of the maximum area found. After processing all bars, pop any remaining indices from the stack and calculate their areas as well.

**Key Insight:** The key insight is that the stack helps you efficiently find the nearest smaller bar to the left and right of each bar, which allows you to calculate the maximum area for rectangles that can be formed with each bar as the height. By maintaining a stack of indices, you can ensure that you are always calculating areas for valid rectangles.

**Gotchas:** Be careful with the edge case when the stack is empty, which means that the current bar is the smallest so far and can extend all the way back to the beginning. Also, remember to process any remaining bars in the stack after iterating through the heights array to ensure you account for all possible rectangles.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Maximal Rectangle — LC #85 | Same histogram logic applied row by row on a 2D matrix → build histogram per row then apply LC #84 | Yes — direct generalization |
| Trapping Rain Water — LC #42 | Water trapped between bars instead of rectangle area → same monotonic stack left/right boundary idea | Yes — same stack pattern |
| Maximum Rectangle in Binary Matrix — LC #85 | Reduce to histogram problem row by row → LC #84 as a subroutine | Yes — direct application |
| Daily Temperatures — LC #739 | Find next warmer day → same monotonic stack next greater element | Partial — same stack idea |
| Next Greater Element — LC #496 | Find next greater element for each position → same monotonic stack | Partial — foundation |
| Sum of Subarray Minimums — LC #907 | Sum of minimums across all subarrays → same monotonic stack left/right boundary | Yes — same structure |
| Maximum Width Ramp — LC #962 | Find widest ramp between indices → monotonic stack with two pointer scan | Partial — same stack idea |

**How this pattern scales:**
- **Monotonic stack** is the core trick — maintain a stack of increasing bar heights. When a shorter bar is encountered pop taller bars and compute their maximum rectangle using the current index as the right boundary
- **Sentinel values** simplify implementation — append a `0` at the end of heights to flush all remaining bars from the stack without special casing the end of the array
- **Left/right boundary pattern** → the stack implicitly tracks the nearest smaller bar to the left for each popped bar. This "nearest smaller element" idea is the same mechanism used in Trapping Rain Water and Sum of Subarray Minimums
- **2D generalization** → LC #85 (Maximal Rectangle) runs LC #84 as a subroutine on each row's cumulative height array — the entire solution is just building histograms row by row and calling the same monotonic stack logic

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largestRect = 0;
        stack<int> stk;
        
        // Push sentinel value to avoid empty stack checks
        // and simplify width calculation for bars that extend to the leftmost boundary
        stk.push(-1);
        
        for (int i = 0; i < heights.size(); i++) {
            // Pop bars that are taller than the current bar, since the current bar
            // limits how far right their rectangle can extend
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) { //while the current bar is shorter than the bar at the top of the stack, 
            //pop from the stack, because the current bar limits how far right the rectangle of the bar at the top of the stack can extend
                int height = heights[stk.top()];
                stk.pop();
                // Width is from the new top of stack (left boundary) to current index (right boundary)
                int width = i - stk.top() - 1;
                largestRect = max(largestRect, height * width);
            }
            // Current bar hasn't been bounded yet, push it for future processing
            stk.push(i);
        }

        // Remaining bars in the stack never found a shorter bar to their right
        // so their right boundary is the end of the array
        while (stk.top() != -1) {
            int height = heights[stk.top()];
            stk.pop();
            int width = heights.size() - stk.top() - 1;
            largestRect = max(largestRect, height * width);
        }

        return largestRect;
    }
};
```

## Evaluate Reverse Polish Notation LC 150

<!-- notecardId: 1780375083681 -->


You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

**Link**: [text](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

%

**Pattern:** Stack

**Approach:** Use a stack to evaluate the expression. Iterate through the tokens, and for each token, if it is an operand (number), push it onto the stack. If it is an operator, pop the top two operands from the stack, apply the operator to these operands in the correct order (the second popped operand is the left operand), and push the result back onto the stack. After processing all tokens, the final result will be the only element remaining in the stack.

**Key Insight:** The key insight is that Reverse Polish Notation (RPN) allows for straightforward evaluation using a stack because the operators come after their operands. By pushing operands onto the stack and applying operators as they are encountered, you can efficiently compute the result without needing to worry about operator precedence or parentheses.

**Gotchas:** Be careful with the order of operands when applying the operator, especially for subtraction and division. The second popped operand is the left operand, and the first popped operand is the right operand. Also, ensure that you handle integer division correctly, truncating towards zero as specified in the problem.

**Complexity:** Time: O(n) | Space: O(n)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Basic Calculator — LC #224 | Evaluate infix expression with parentheses → stack for operators and operands | Yes — same stack pattern |
| Basic Calculator II — LC #227 | Infix with +−×÷ no parentheses → stack with operator precedence | Yes — direct variant |
| Basic Calculator III — LC #772 | Infix with parentheses and all operators → recursive descent or stack | Yes — hardest variant |
| Simplify Path — LC #71 | Stack to process directory tokens → same token processing via stack | Yes — same stack idea |
| Valid Parentheses — LC #20 | Stack to match bracket tokens → same push/pop on tokens | Partial — simpler variant |
| Decode String — LC #394 | Stack to track nested encoding context → same stack nesting idea | Partial — same stack pattern |
| Expression Add Operators — LC #282 | Add operators between digits to hit target → backtracking + expression evaluation | Partial — evaluation focus |
| Convert Expression to RPN — Shunting Yard | Convert infix to postfix → operator stack with precedence rules | Yes — inverse of LC #150 |

**How this pattern scales:**
- **Operand stack** is the core trick — push numbers onto stack, on every operator pop two operands apply the operator and push the result back. Single pass O(n) time O(n) space
- **Operator precedence disappears in RPN** — this is the entire point of postfix notation, operators appear exactly when they should be applied so no precedence tracking is needed. This is why RPN is simpler than infix evaluation
- **Infix evaluation upgrade** → LC #224 and LC #227 add precedence handling back — use two stacks (one for operands, one for operators) and apply operators based on precedence rules when a lower precedence operator is encountered
- **Shunting Yard algorithm** is the inverse — converts infix to RPN using an operator stack. Worth knowing as a follow-up since it completes the full picture of expression parsing

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> tokenStk;
        for(int i = 0; i < tokens.size(); i++){
        if(tokens[i] != "+" &&
        tokens[i] != "-" &&
        tokens[i] != "*" &&
        tokens[i] != "/" 
        )  {
            tokenStk.push(std::stoi(tokens[i]));
            continue;
        }

            int num1 = tokenStk.top();
            tokenStk.pop();
            int num2 = tokenStk.top();
            tokenStk.pop();
        if(tokens[i] == "+"){
            tokenStk.push(num1+num2);
        }
        else if(tokens[i] == "-"){
            tokenStk.push(num2-num1);
        }
        else if(tokens[i] == "*"){
            tokenStk.push(num1*num2);
        }
        else{
            tokenStk.push(num2/num1);
        }
        }

        return tokenStk.top();
    }
};
```

## Min Stack LC 155

<!-- notecardId: 1780375464978 -->

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

**Link**: [text](https://leetcode.com/problems/min-stack/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use two stacks to implement the MinStack. The first stack will be used to store all the elements of the stack, while the second stack will keep track of the minimum values. When pushing a new value onto the main stack, compare it with the current minimum (the top of the min stack). If the new value is smaller than or equal to the current minimum, also push it onto the min stack. When popping from the main stack, if the popped value is the same as the top of the min stack, pop from the min stack as well. This way, the top of the min stack always represents the minimum element in the main stack. Another way to do this is to store the minimum value at the time of each push in the main stack itself, so that you can retrieve it in O(1) time without needing a separate min stack.

**Key Insight:** The key insight is that by maintaining a separate stack (or embedding the minimum value in the main stack), you can keep track of the minimum element at all times without needing to search through the stack, allowing for O(1) retrieval of the minimum.

**Gotchas:** Be careful when pushing values onto the min stack to ensure that you only push values that are less than or equal to the current minimum. Also, when popping from the main stack, make sure to check if the popped value is the current minimum and pop from the min stack accordingly to maintain the correct minimum value.

**Complexity:** Time: O(1) for all operations | Space: O(n) in the worst case if all elements are the same and are pushed onto the min stack

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Max Stack — LC #716 | Track maximum instead of minimum → same auxiliary stack idea | Yes — direct variant |
| Sliding Window Maximum — LC #239 | Track maximum in a sliding window → monotonic deque instead of aux stack | Partial — same tracking idea |
| Design Stack With Increment Operation — LC #1381 | Increment bottom k elements → lazy increment array instead of aux stack | Partial — same design pattern |
| Valid Parentheses — LC #20 | Stack for matching brackets → same push/pop structure | No — different pattern |
| Evaluate Reverse Polish Notation — LC #150 | Stack for expression evaluation → same push/pop structure | No — different pattern |
| Basic Calculator — LC #224 | Stack tracking running state at each nesting level → same "snapshot per level" idea | Partial — same aux state idea |
| Queue Using Stacks — LC #232 | Simulate queue using two stacks → same multi-stack design thinking | Partial — same design family |
| Stock Price Fluctuation — LC #2034 | Track min and max of streaming prices → sorted set instead of aux stack | Partial — same min/max tracking |

**How this pattern scales:**
- **Auxiliary stack** is the core trick — maintain a second stack that only pushes when the new value is less than or equal to the current minimum. O(1) push pop and getMin, O(n) space
- **Space optimization** → instead of a full auxiliary stack store pairs `{value, currentMin}` on a single stack — same O(1) operations but cleaner implementation with one stack instead of two
- **Monotonic deque upgrade** → when the window slides (elements leave from the front) a stack is no longer sufficient — LC #239 (Sliding Window Maximum) uses a deque to efficiently track the maximum as elements enter and leave
- **"Snapshot per level" pattern** → Basic Calculator uses the same idea of saving state (running sum, sign) onto a stack when entering a nested parenthesis level and restoring it on exit — same auxiliary state tracking, different context

```cpp
class MinStack {
public:
//     MinStack() {
//         //dont have to do anything here
//     }
    
//     void push(int val) {
//         stk.push(val);
//         if(pastMin.empty() || pastMin.top() >= val){
//             pastMin.push(val);
//         }
//     }
    
//     void pop() {

//         int top = stk.top();
//         stk.pop();
//         if(pastMin.top() == top){
//             pastMin.pop();
//         }
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         return pastMin.top();
//     }

// private:
// stack<int> stk;
// stack<int> pastMin;

    MinStack() {
        //dont have to do anything here
    }
    
    void push(int val) {
        if (val <= min || stk.empty()){
            min = val;
        }
        stk.push({val, min});
        // if(pastMin.empty() || pastMin.top() >= val){
        //     pastMin.push(val);
        // }
    }
    
    void pop() {
        stk.pop();
        if(!stk.empty()){
            min = stk.top().second;
        }
        else{
            min = INT_MAX;
        }
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }

private:
stack<pair<int, int>> stk;
int min = INT_MAX;
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
```

## Implement Stack using Queues LC 225

<!-- notecardId: 1780375638858 -->

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, top, and empty.
All the calls to pop and top are valid.
 

Follow-up: Can you implement the stack using only one queue?

**Link**: [text](https://leetcode.com/problems/implement-stack-using-queues/)

%

**Pattern:** Queue Simulation

**Approach:** Use two queues to simulate the behavior of a stack. For the push operation, enqueue the new element into the first queue. Then, dequeue all elements from the first queue and enqueue them into the second queue, effectively reversing the order of the elements. Finally, swap the names of the two queues so that the first queue always contains the elements in stack order. For pop and top operations, simply dequeue from the first queue to get the top element of the stack. The empty operation checks if the first queue is empty. If you want to implement the stack using only one queue, you can enqueue the new element and then rotate the queue by dequeuing and enqueuing all elements except the newly added one, which will move it to the front of the queue.

**Key Insight:** The key insight is that by using two queues and reversing the order of elements during the push operation, you can maintain the LIFO order required for a stack. This allows you to implement stack operations using only queue operations.

**Gotchas:** Be careful with the order of operations when pushing elements to ensure that the stack order is maintained. Also, remember to swap the queues after each push to keep the first queue as the main storage for stack elements. When implementing with one queue, be mindful of the rotation step to ensure that the newly added element becomes the new top of the stack.

**Complexity:** Time: O(n) for push (due to reversing the queue), O(1) for pop, top, and empty | Space: O(n) for storing the elements in the queues

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Implement Queue Using Stacks — LC #232 | Simulate queue using two stacks → inverse of this problem, same two structure idea | Yes — direct inverse |
| Min Stack — LC #155 | Augment stack with min tracking → same stack design family | Partial — same design thinking |
| Design Circular Queue — LC #622 | Implement queue with fixed size array → array based not stack based | Partial — same queue design |
| Design Circular Deque — LC #641 | Double ended queue with fixed size → same circular array idea | Partial — same design family |
| Max Stack — LC #716 | Augment stack with max tracking → same auxiliary structure idea | Partial — same design thinking |
| Design Hit Counter — LC #362 | Queue to track hits in time window → same queue as sliding window | No — different pattern |
| Moving Average from Data Stream — LC #346 | Queue to maintain sliding window average → same fixed window queue idea | No — different pattern |

**How this pattern scales:**
- **Single queue rotation** is the core trick — after pushing a new element rotate all previous elements behind it by dequeuing and re-enqueuing one by one. O(n) push O(1) pop — cleaner than two queue approach
- **Two queue approach** is the alternative — push to queue 2, drain queue 1 into queue 2, swap references. Same O(n) push O(1) pop but requires managing two queue references
- **Push heavy vs pop heavy** tradeoff — you can alternatively make push O(1) and pop O(n) by rotating on pop instead of push. Choose based on which operation is called more frequently
- **Design problem ladder** → LC #225 → LC #232 → LC #622 → LC #641 — each builds on the previous, moving from simulated structures to purpose built ones with additional constraints like fixed size or double ended access

```cpp
class MyStack {
// public:
//     MyStack() {
//         //not necessary to do anything here
//     }
    
//     void push(int x) {
//         q2.push(x);
//         while(!q1.empty()){
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1,q2);
//     }
    
//     int pop() {
//         int val =  q1.front();
//         q1.pop();
//         return val;
//     }
    
//     int top() {
//         return q1.front();
//     }
    
//     bool empty() {
//         return (q1.empty() && q2.empty());
//     }
// private:
// std::queue<int> q1;
// std::queue<int> q2; //maybe treat this as the top

public:
    MyStack() {
        //not necessary to do anything here
    }
    
    void push(int x) {
        q1.push(x);
        for(int i = 0; i < q1.size()-1; i++){
            int val = q1.front();
            q1.pop();
            q1.push(val);
        }
    }
    
    int pop() {
        int val =  q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return (q1.empty());
    }
private:
std::queue<int> q1; //only one queue
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

## Implement Queue using Stacks LC 232

<!-- notecardId: 1780376276505 -->

mplement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

**Link**: [text](https://leetcode.com/problems/implement-queue-using-stacks/)

%

**Pattern:** Stack Simulation

**Approach:** Use two stacks to simulate the behavior of a queue. The first stack (input stack) is used for enqueueing new elements, while the second stack (output stack) is used for dequeueing elements. For the push operation, simply push the new element onto the input stack. For pop and peek operations, if the output stack is empty, pop all elements from the input stack and push them onto the output stack, effectively reversing their order. Then, pop or peek from the output stack to get the front element of the queue. The empty operation checks if both stacks are empty. This approach ensures that each element is moved at most twice (once to the input stack and once to the output stack), resulting in amortized O(1) time complexity for each operation.

**Key Insight:** The key insight is that by using two stacks and reversing the order of elements when moving them from the input stack to the output stack, you can maintain the FIFO order required for a queue. This allows you to implement queue operations using only stack operations.

**Gotchas:** Be careful to only move elements from the input stack to the output stack when the output stack is empty. This ensures that you maintain the correct order of elements and achieve amortized O(1) time complexity. Also, remember to check both stacks for emptiness when implementing the empty operation.

**Complexity:** Time: Amortized O(1) for all operations | Space: O(n) for storing the elements in the stacks

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Implement Stack Using Queues — LC #225 | Inverse problem simulate stack using queues → rotate queue on every push | Yes — direct inverse |
| Min Stack — LC #155 | Augment stack with min tracking → same auxiliary stack design | Partial — same design family |
| Design Circular Queue — LC #622 | Purpose built queue with fixed size array → no stack simulation needed | Partial — same queue design |
| Design Circular Deque — LC #641 | Double ended fixed size queue → same circular array idea | Partial — same design family |
| Moving Average from Data Stream — LC #346 | Sliding window average over stream → queue as sliding window | Partial — queue application |
| Design Hit Counter — LC #362 | Count hits in last 300 seconds → queue to track time window | Partial — same queue idea |
| Snake Game — LC #353 | Deque to track snake body → same front/back queue operations | Partial — queue application |
| Sliding Window Maximum — LC #239 | Monotonic deque for window max → same deque operations under constraints | No — different pattern |

**How this pattern scales:**
- **Two stack amortized O(1)** is the core trick — push to inbox stack always, pop from outbox stack when needed. When outbox is empty drain entire inbox into outbox. Each element moves at most twice so amortized O(1) per operation
- **Amortized analysis** is the key concept interviewers probe here — worst case single pop is O(n) but averaged across all operations it's O(1). Being able to explain why is more important than the implementation itself
- **Lazy transfer** is the transferable pattern — instead of keeping both stacks in sync on every operation, defer the expensive reorganization until absolutely necessary. Same idea appears in lazy propagation in segment trees
- **Design ladder** → LC #232 → LC #622 (Circular Queue) → LC #641 (Circular Deque) → LC #239 (Sliding Window Maximum) — each adds one constraint on top of the previous, moving from simulated to purpose built to constrained window structures

```cpp
class MyQueue {
    //solution 1, working but inefficient push
// public:
//     MyQueue() {
//         //dont need to do anything ehre
//     }
    
//     void push(int x) {
//         //say s1 is the main stack
//         while(!s1.empty()){
//             int val = s1.top();
//             s1.pop();
//             s2.push(val);
//         }
//         s1.push(x);
//         while(!s2.empty()){
//             int val = s2.top();
//             s2.pop();
//             s1.push(val);
//         }

//     }
    
//     int pop() {
//         int val = s1.top();
//         s1.pop();
//         return val;
//     }
    
//     int peek() {
//         return s1.top();
//     }
    
//     bool empty() {
//         return s1.empty();
//     }
// private:
// stack<int> s1;
// stack<int> s2;

public:
    MyQueue() {
        //dont need to do anything ehre
    }
    
    void push(int x) {
        input.push(x); //main stack for push, add to input

    }
    
    int pop() {
        if(output.empty()){ //if output empty, move everything from input into output, will be in reverse order
            while(!input.empty()){
                output.push(input.top()); //reverse order so front of stack will be front of the queue
                input.pop();
            }
        }
        int val = output.top(); //this is now the front of the queue, pop off and return
        output.pop(); //only time pop is called is when popping from output stack, so output size can decrease
        return val;
    }
    
    int peek() {
    if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return (output.empty() && input.empty());
    }
private:
stack<int> input; //push
stack<int> output; //pop and peek
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

## Decode String LC 394

<!-- notecardId: 1780412161745 -->

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

**Link**: [text](https://leetcode.com/problems/decode-string/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to store the strings and frequencies. There are 4 cases to be aware of. If there is a number, then you don't know how big it is until you hit the opening bracket, so you keep multipliying the previous by 10 and adding new digits. This is necessary because the integer can be in rage 1 to 300. When you hit an opening bracket, push the current string and frequency onto the stack and reset them. When you hit a closing bracket, pop from the stack to get the previous string and frequency, and append the current string repeated frequency times to the previous string. When you hit a letter, just add it to the current string.

**Key Insight:** The key insight is that the nested structure of the encoded string can be effectively managed using a stack. By pushing the current state (string and frequency) onto the stack when encountering an opening bracket and popping it when encountering a closing bracket, you can correctly build the decoded string in a structured manner.

**Gotchas:** Be careful with the order of operations when pushing and popping from the stack. When you pop from the stack, you need to append the current string repeated frequency times to the previous string, not the other way around. Also, make sure to reset the current string and frequency after pushing onto the stack when you encounter an opening bracket. Nesting is the trickiest part of this question. For example, in "3[a2[c]]", when you hit the first closing bracket, you need to pop and get "a" and 3, but the current string is "acc" because of the nested "2[c]". So you need to append "acc" repeated 3 times to "a", not just "a" repeated 3 times. The stack works because it allows you to keep track of the previous string and frequency at each level of nesting, so when you pop, you have all the information you need to correctly build the decoded string.

**Complexity:** Time: O(n * k) where n is the length of the input string and k is the maximum frequency (since you may have to repeat a string k times) | Space: O(n * k) in the worst case if you have a string that needs to be repeated many times

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Parentheses — LC #20 | Match brackets without decoding → same stack nesting structure | Yes — foundation |
| Encode and Decode Strings — LC #271 | Encode/decode without nesting → length prefix, no stack needed | Partial — same encoding idea |
| Basic Calculator — LC #224 | Evaluate nested arithmetic expressions → same stack save/restore per level | Yes — same stack pattern |
| Simplify Path — LC #71 | Process path tokens with stack → same token by token stack processing | Partial — same stack idea |
| Flatten Nested List Iterator — LC #341 | Flatten nested structure iteratively → same stack based nesting traversal | Yes — same nesting pattern |
| Number of Atoms — LC #726 | Parse chemical formula with nested groups → same stack save/restore per bracket | Yes — direct variant |
| Remove All Adjacent Duplicates — LC #1047 | Stack to track and remove adjacent chars → same character stack idea | Partial — simpler variant |
| Evaluate Reverse Polish Notation — LC #150 | Stack to evaluate postfix tokens → same operand stack pattern | Partial — same stack family |

**How this pattern scales:**
- **Stack save/restore per bracket level** is the core trick — when `[` is encountered push current string and current count onto stack, reset both, build inner string. When `]` is encountered pop saved string and count, repeat inner string count times and append to saved string
- **Two stack approach** — maintain separate stacks for counts and strings. Count stack tracks repetition at each nesting level, string stack tracks the accumulated string before each `[`
- **Recursive descent** is the clean alternative — treat each `[...]` block as a recursive call, return the decoded string up the call stack. Cleaner to reason about but uses implicit call stack instead of explicit stack
- **Nesting pattern generalizes** → Number of Atoms (LC #726) applies the exact same bracket save/restore logic but tracks element counts in a hash map instead of a string — same skeleton, different payload

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<int> frequency; //store frequency numbers
        stack<string> strings; //store the string built so far, this is important when nesting occurs, 
        int num = 0; //to help with calculating frequencies
        string curr = ""; //starting current string is 0
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){ //if a number, we dont know how big it is, multiply previous by 10 and add new digit, needed since number is 1-300
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '['){ /*
            when a [ is there, that means the current string is done, frequency has also been obtained, so store them in their respective stacks, then reset the current string and frequency to start the new string inside the brackets, 
            when we encounter the closing bracket, we will know how many times to repeat the current string, and what the previous string was, so we can pop from both stacks and update the current string to be the previous string + the current string repeated frequency number of times, t
            this is important for nesting, because if there are multiple nested brackets, then when we encounter a closing bracket, we will only repeat the current string inside that specific bracket, and then add it to the previous string, which may also be inside another bracket, 
            but that is fine because when we encounter the closing bracket for that one, we will repeat the entire current string which includes the previous string that was just added to it
            */
            frequency.push(num);
            strings.push(curr);
            curr = "";
            num = 0;
            }
            else if (s[i] == ']'){
                //when a closing bracket is reached, current string is done, so then we take the top of the stack for frequency and string
                int ct = frequency.top();
                frequency.pop();
                string str = strings.top();
                strings.pop();
                
                string freqStr = "";
                //CURRENT STRING is repeated ct times, and then is added to the PREVIOUS STRING, which is str, this is important for nesting,
                // because if there are multiple nested brackets, then when we encounter a closing bracket, we will only repeat the current string inside that specific bracket, 
                //and then add it to the previous string, which may also be inside another bracket
                for(int i = 0; i < ct; i++){
                    freqStr += curr;
                }
                curr = str + freqStr;

            }
            else{
                curr += s[i]; //add to current string if it is a character
            }
        }
    return curr;
    }
};
```

## Baseball Game LC 682

<!-- notecardId: 1780413607450 -->

You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.
 

Constraints:

1 <= operations.length <= 1000
operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record.

**Link**: [text](https://leetcode.com/problems/baseball-game/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to keep track of the scores. For each operation, perform the corresponding action on the stack. If the operation is an integer, push it onto the stack. If it's "+", pop the top two scores, sum them, push the result back onto the stack, and also push the two popped scores back onto the stack. If it's "D", pop the top score, double it, and push it back onto the stack along with the original score. If it's "C", simply pop the top score from the stack. After processing all operations, sum up all the scores in the stack to get the final result.

**Key Insight:** The key insight is that the stack data structure allows you to easily manage the scores and perform the required operations in a last-in-first-out manner. This is particularly useful for handling the "C" operation, which invalidates the previous score, and the "+" and "D" operations, which depend on the previous scores.

**Gotchas:** Be careful when handling the "+" operation to ensure that you correctly pop the top two scores, sum them, and then push both the original scores and the new score back onto the stack. Also, make sure to handle the "D" operation correctly by doubling the top score and pushing both the original and doubled scores back onto the stack. Finally, remember to sum all the scores in the stack at the end to get the final result.

**Complexity:** Time: O(n) where n is the number of operations (each operation is processed once, and summing the stack at the end takes O(n)) | Space: O(n) in the worst case if all operations are integers and no "C" operations

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Parentheses — LC #20 | Stack to match brackets instead of scores → same push/pop on tokens | Yes — same stack pattern |
| Evaluate Reverse Polish Notation — LC #150 | Stack to evaluate postfix operators → same token by token stack processing | Yes — same stack pattern |
| Remove All Adjacent Duplicates — LC #1047 | Stack to remove adjacent matching chars → same conditional push/pop | Partial — same stack idea |
| Decode String — LC #394 | Stack to track nested encoding context → same save/restore per level | Partial — same stack family |
| Mini Parser — LC #385 | Parse nested integers with stack → same token processing via stack | Partial — same parsing idea |
| Design Stack With Increment — LC #1381 | Augmented stack with bulk increment → same stack design family | Partial — same design idea |
| Next Greater Element — LC #496 | Monotonic stack to find next greater → same stack but with ordering constraint | No — different pattern |

**How this pattern scales:**
- **Stack as running history** is the core trick — each operation either adds to history (integer, `+`, `D`) or removes from it (`C`). Stack lets you access and undo the most recent entry in O(1)
- **Token parsing pattern** — split input into tokens, process each token with a switch/if-else, push results onto stack. Same skeleton used in LC #150 (RPN) and LC #224 (Basic Calculator)
- **Undo via stack** generalizes to any problem where operations can be reversed — the stack implicitly maintains a history of states, and popping is equivalent to undoing the last operation
- **Simplest stack problem in the family** → LC #682 is the easiest entry point into the stack token processing family. The ladder goes LC #682 → LC #150 → LC #227 → LC #224 — each adds operator precedence or nesting complexity on top of the same core token loop

```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> stk;
        int total = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int holder1 = stk.top();
                stk.pop();
                int holder2 = stk.top();
                int sum = holder1 + holder2;
                stk.push(holder1);
                stk.push(sum);
            }
            else if(operations[i] == "D"){
                stk.push(2 * stk.top());
            }
            else if(operations[i] == "C"){
                stk.pop();
            }
            else{
                stk.push(stoi(operations[i]));
            }
        }
        while(stk.size() > 0){
            total += stk.top();
            stk.pop();
        }
        return total;
    }
};
```
## Asteroid Collision LC 735

<!-- notecardId: 1780414502836 -->

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
Example 4:

Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
Output: [-6,2,4]
Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 makes the asteroid -1 explode and then continues going right, without reaching asteroid 4.
 

Constraints:

2 <= asteroids.length <= 104
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

**Link**: [text](https://leetcode.com/problems/asteroid-collision/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to keep track of the asteroids that are still in play. Iterate through the list of asteroids and for each asteroid, check if it will collide with the top of the stack (i.e., if the current asteroid is moving left and the top of the stack is moving right). If there is a collision, compare their sizes and determine which one will explode. If the current asteroid is larger, pop the top of the stack and continue checking for collisions with the new top. If they are the same size, pop the top of the stack and do not push the current asteroid. If there is no collision, simply push the current asteroid onto the stack. After processing all asteroids, the stack will contain only those that have survived.

**Key Insight:** The key insight is that the stack data structure allows you to easily manage the asteroids and perform the required collision checks in a last-in-first-out manner. This is particularly useful for handling the collisions between asteroids moving in opposite directions.

**Gotchas:** Be careful when handling the collision logic to ensure that you correctly compare the sizes of the asteroids and determine which one should be popped from the stack. Also, make sure to continue checking for collisions with the new top of the stack after popping an asteroid, as there may be multiple collisions in a row. Finally, remember to return the contents of the stack as the final result after processing all asteroids. Something a bit tricky to see is that if the current asteroid is moving right, it will never collide with the top of the stack, because the top of the stack will also be moving right (since if it were moving left, it would have already collided with a previous asteroid and been popped). So you only need to check for collisions when the current asteroid is moving left.

**Complexity:** Time: O(n) where n is the number of asteroids (each asteroid is processed once, and in the worst case, each asteroid could cause a collision with every other asteroid) | Space: O(n) in the worst case if all asteroids are moving in the same direction and none collide

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Parentheses — LC #20 | Match opposing bracket pairs → same collision/cancellation via stack | Yes — same stack pattern |
| Remove All Adjacent Duplicates — LC #1047 | Remove matching adjacent pairs → same push/pop cancellation idea | Yes — direct variant |
| Remove All Adjacent Duplicates II — LC #1209 | Remove k adjacent duplicates → same stack with count tracking | Yes — upgrade |
| Daily Temperatures — LC #739 | Find next warmer day → same monotonic stack next greater element | Partial — same stack idea |
| Next Greater Element — LC #496 | Find next greater for each element → same right-to-left stack scan | Partial — same stack family |
| Trapping Rain Water — LC #42 | Left/right boundary tracking → same opposing direction comparison | No — different pattern |
| Buildings With an Ocean View — LC #1762 | Keep buildings not blocked from right → same "survival" stack logic | Yes — direct variant |
| Score of Parentheses — LC #856 | Nested scoring via stack → same push/pop with value tracking | Partial — same stack family |

**How this pattern scales:**
- **Collision simulation via stack** is the core trick — iterate left to right, push positive asteroids, when negative asteroid encountered pop and compare with stack top until collision resolves. Three outcomes: incoming destroyed, stack top destroyed, mutual destruction
- **Three outcome handling** is the key implementation detail — (1) incoming asteroid destroyed: stop processing (2) stack top destroyed: keep popping (3) equal size: pop and stop. Missing any case causes subtle bugs
- **Cancellation pattern** generalizes → Remove All Adjacent Duplicates (LC #1047) is the same push/check/cancel loop but cancels on equality instead of opposing signs. Any problem where new elements can cancel or consume previous ones uses this stack structure
- **Monotonic stack variant** → when elements don't cancel but instead you want to find the next element that "beats" the current one (Daily Temperatures, Next Greater Element) the same stack is used but elements are popped to record answers rather than to simulate destruction

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Stack to keep track of surviving asteroids
        // The stack maintains order from left to right (bottom to top)
        stack<int> past;

        // Process each asteroid from left to right
        for(int i = 0; i < asteroids.size(); i++){
            
            // Case 1: Current asteroid is moving LEFT (negative)
            if(asteroids[i] < 0){
                
                // Subcase 1.1: Stack empty OR top asteroid also moving left
                // No collision possible since both move same direction
                if(past.empty() || past.top() < 0){
                    past.push(asteroids[i]);
                }
                
                // Subcase 1.2: Current left-moving asteroid is LARGER than top right-moving asteroid
                else if(abs(asteroids[i]) > past.top()){
                    // Keep destroying right-moving asteroids that are smaller
                    while(!past.empty() && past.top() > 0 && abs(asteroids[i]) > past.top()){
                        past.pop();
                    }
                    
                    // After destroying all smaller asteroids, check the new top
                    if(past.empty() || past.top() < 0){
                        // All right-moving asteroids destroyed, current survives
                        past.push(asteroids[i]);
                    }
                    else if(past.top() > 0 && abs(asteroids[i]) == past.top()){
                        // Equal size: both are destroyed (pop the right-moving one)
                        past.pop();
                    }
                    // If past.top() > 0 && abs(asteroids[i]) < past.top()
                    // Current asteroid is destroyed, do nothing
                }
                
                // Subcase 1.3: Current left-moving asteroid is SMALLER than top right-moving asteroid
                else if(abs(asteroids[i]) < past.top()){
                    // Current asteroid is destroyed, move to next asteroid
                    continue;
                }
                
                // Subcase 1.4: Current left-moving asteroid is EQUAL to top right-moving asteroid
                else{ // equal
                    if(!past.empty() && past.top() > 0 && abs(asteroids[i]) == past.top()){
                        // Both explode - just remove the top right-moving asteroid
                        past.pop();
                    }
                }
            }
            
            // Case 2: Current asteroid is moving RIGHT (positive)
            // No collision possible yet (future left-moving asteroids might collide)
            else{
                past.push(asteroids[i]);
            }
        }
        
        // Build result vector from stack (stack gives reverse order)
        vector<int> ans(past.size());
        int index = past.size() - 1;  // Start from the last index
        
        // Pop from stack and fill from end to beginning to maintain original order
        while(!past.empty()){
            ans[index--] = past.top();  // Place top asteroid at current index, then decrement
            past.pop();
        }
        
        return ans;
    }
};
```
## Daily Temperatures LC 739

<!-- notecardId: 1780414881404 -->

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

**Link**: [text](https://leetcode.com/problems/daily-temperatures/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to keep track of the indices of the temperatures. Iterate through the list of temperatures and for each temperature, check if it is warmer than the temperature at the index on the top of the stack. If it is, pop the index from the stack and calculate the number of days by taking the difference between the current index and the popped index, and store this in the answer array at the popped index. Continue this process until the stack is empty or the current temperature is not warmer than the temperature at the index on top of the stack. Finally, push the current index onto the stack. After processing all temperatures, any indices remaining in the stack will have an answer of 0 since there are no warmer future days. Remember to store indices in the stack, and not the actual temperatures, since temperatures is stored in an array and we need to calculate the difference in days using indices.

**Key Insight:** The key insight is that the stack data structure allows you to efficiently keep track of the indices of the temperatures that have not yet found a warmer future day. By comparing the current temperature with the temperature at the index on top of the stack, you can determine when a warmer day has been found and update the answer array accordingly.

**Gotchas:** Be careful to store indices in the stack instead of the actual temperatures, as you need to calculate the number of days by taking the difference between indices. Also, make sure to continue popping from the stack until you find a temperature that is not warmer than the current temperature or until the stack is empty. Finally, remember to initialize the answer array with 0s, since any indices remaining in the stack after processing all temperatures will have an answer of 0.

**Complexity:** Time: O(n) where n is the number of temperatures (each temperature is processed once, and each index is pushed and popped from the stack at most once) | Space: O(n) in the worst case if all temperatures are in decreasing order and all indices are stored in the stack

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Next Greater Element I — LC #496 | Find next greater across two arrays → same monotonic stack, no index math | Yes — simpler foundation |
| Next Greater Element II — LC #503 | Circular array next greater → same stack but iterate twice with modulo | Yes — direct upgrade |
| Next Greater Element III — LC #556 | Next greater permutation of digits → no stack, digit rearrangement | No — different pattern |
| Asteroid Collision — LC #735 | Elements cancel each other → same stack pop on conflict | Partial — same stack family |
| Largest Rectangle in Histogram — LC #84 | Find nearest smaller bar on both sides → same monotonic stack boundaries | Yes — same pattern |
| Trapping Rain Water — LC #42 | Left/right boundary tracking → monotonic stack or two pointer | Partial — same boundary idea |
| Sum of Subarray Minimums — LC #907 | Sum minimums across all subarrays → same left/right nearest smaller boundary | Yes — same structure |
| Online Stock Span — LC #901 | Count consecutive days price was lower → same monotonic stack span counting | Yes — direct variant |

**How this pattern scales:**
- **Monotonic decreasing stack** is the core trick — maintain stack of indices with decreasing temperatures. When a warmer day is found pop all cooler indices and record their answer as current index minus popped index
- **Store indices not values** — storing indices instead of temperatures is what lets you compute the distance answer in O(1). A common mistake is storing temperatures and losing the position information
- **Next greater element family** → LC #739 → LC #496 → LC #503 is the cleanest ladder. LC #739 finds distance to next greater, LC #496 finds the value of next greater, LC #503 adds circular wrapping — same monotonic stack, three different output types
- **Left and right boundary extension** → when a problem needs both the nearest smaller/greater on the left AND right (LC #84, LC #907), run the same monotonic stack twice — once left to right for right boundaries, once right to left for left boundaries
- **Circular array trick** → for LC #503 iterate through the array twice using `i % n` as the index — same stack logic handles the wrap-around without any special casing

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0); //store the result vector
        stack<int> days; //stack to keep track of the indices of the days
        for(int i = 0; i < temperatures.size(); i++){
            while(!days.empty() && temperatures[i] > temperatures[days.top()]){ //while the current temp is greater than the temp of the day at the top of the stack, a warmer day has been found
            //the reason we have a while loop is because there may be multiple days in the stack that are colder than the current day, so pop all of those off and then update the answer for all of those days
               int prevIndex = days.top(); //index of previous day with a colder temp
               days.pop(); //pop it off the stack
               answer[prevIndex] = i - prevIndex; //the number of days until a warmer day is the difference between the current index and the previous index

        }
        days.push(i); //push current day into the stack, use stack to check if a warmer day for that specific day will come
    }
    return answer;
    }

};
```
## Car Fleet LC 853

<!-- notecardId: 1780415092812 -->

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer arrays position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a single car or a group of cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:

There is only one car, hence there is only one fleet.
Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]

Output: 1

Explanation:

The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.

**Link**: [text](https://leetcode.com/problems/car-fleet/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to keep track of the time it takes for each car to reach the target. First, pair up the position and speed of each car and sort them based on their starting position in descending order (from closest to target to farthest). Then, iterate through the sorted list of cars and calculate the time it takes for each car to reach the target using the formula `time = (target - position) / speed`. If the stack is empty or if the time for the current car is greater than the time at the top of the stack, push the current time onto the stack. If the time for the current car is less than or equal to the time at the top of the stack, it means that this car will catch up to the fleet represented by the top of the stack before reaching the target, so we do not push it onto the stack. Finally, the number of fleets will be equal to the size of the stack.

**Key Insight:** The key insight is that by sorting the cars based on their starting position and using a stack to keep track of the time it takes for each car to reach the target, we can easily determine when a car will catch up to a fleet and when it will form a new fleet. The stack allows us to efficiently manage the fleets as we iterate through the cars.

**Gotchas:** Be careful to sort the cars in descending order of their starting position, as we want to process the cars from closest to the target to farthest. Also, make sure to correctly calculate the time it takes for each car to reach the target and compare it with the time at the top of the stack to determine if it will catch up to an existing fleet or form a new fleet. The time comparison is a bit tricky, but know that if a car is going too fast, it can slow down and join a fleet, but if it is going too slow, it will never catch up to the fleet in front of it, so it will form its own fleet.

**Complexity:** Time: O(n log n) due to sorting the cars based on their starting position | Space: O(n) in the worst case if all cars form their own fleet and are stored in the stack

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Daily Temperatures — LC #739 | Find next warmer day → same monotonic stack next greater element | Partial — same stack family |
| Asteroid Collision — LC #735 | Elements cancel on collision → same stack absorption idea | Partial — same stack pattern |
| Next Greater Element I — LC #496 | Find next greater value across arrays → same monotonic stack | Partial — same stack family |
| Largest Rectangle in Histogram — LC #84 | Find nearest smaller bar boundaries → same monotonic stack | Partial — same stack idea |
| Meeting Rooms II — LC #253 | Count overlapping intervals instead of merging fleets → sort + heap | No — different pattern |
| Merge Intervals — LC #56 | Merge overlapping intervals → sort + linear scan | Partial — same sort first idea |
| Task Scheduler — LC #621 | Schedule tasks with cooldown constraints → greedy frequency count | No — different pattern |
| Queue Reconstruction by Height — LC #406 | Sort then insert by second key → same sort by one key first idea | Partial — same sort strategy |

**How this pattern scales:**
- **Sort by position descending + monotonic stack** is the core trick — compute each car's time to reach target, iterate from closest to furthest, push times onto stack and pop when a car behind arrives no later than the car ahead (it joins that fleet)
- **Time to target formula** `time = (target - position) / speed` converts the problem from a spatial simulation into a simple comparison of arrival times — this reduction is the key insight
- **Stack as fleet tracker** — each element remaining on the stack after processing represents one distinct fleet. The answer is simply `stack.size()`
- **Sort direction matters** — sorting descending by position (closest to target first) ensures that when you process a car you already know the fleet ahead of it. Sorting ascending would require looking ahead instead of behind
- **Greedy absorption pattern** → any car that arrives no later than the fleet ahead joins it and can never overtake — this greedy observation is what makes a single pass sufficient. Same greedy "absorb if you catch up" logic appears in merge intervals problems

```cpp
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car(position.size()); //first stores position, second stores speed
        stack<double> fleet; //arrival times of the fleet, order will go from earliest at the bottom and latest at top of the stack
    
        for(int i = 0; i < position.size(); i++){
            car[i]= {position[i],speed[i]};
        }
        sort(car.begin(), car.end()); //sort, position A car can only catch cars that start ahead of it
        for(int i = car.size() - 1; i >= 0; i--){ //start from back since this will guarantee the lowest arrival time, so stack goes from low to high(at the top)
            double arrivalTime = (target - car[i].first)/(double)car[i].second;
            if(fleet.empty()){
                fleet.push(arrivalTime);
            }
            else{
                if(arrivalTime <= fleet.top()){
                    continue; //joins the top of the fleet, slows down, so number of fleets stay the same
                }
                else{
                    fleet.push(arrivalTime); //if arrival time is more than top of the stack
                    //then wont reach previous fleet, will create a new fleet
                }
            }
        }
        return fleet.size();
        //in theory, a stack is not needed, just store the latest arrivalTime instead, as that is what the top of the stack stores anyways
    }
};
```
## Maximum Frequency Stack LC 895

<!-- notecardId: 1780415523618 -->

Design a stack-like data structure to push elements to the stack and pop the most frequent element from the stack.

Implement the FreqStack class:

FreqStack() constructs an empty frequency stack.
void push(int val) pushes an integer val onto the top of the stack.
int pop() removes and returns the most frequent element in the stack.
If there is a tie for the most frequent element, the element closest to the stack's top is removed and returned.
 

Example 1:

Input
["FreqStack", "push", "push", "push", "push", "push", "push", "pop", "pop", "pop", "pop"]
[[], [5], [7], [5], [7], [4], [5], [], [], [], []]
Output
[null, null, null, null, null, null, null, 5, 7, 5, 4]

Explanation
FreqStack freqStack = new FreqStack();
freqStack.push(5); // The stack is [5]
freqStack.push(7); // The stack is [5,7]
freqStack.push(5); // The stack is [5,7,5]
freqStack.push(7); // The stack is [5,7,5,7]
freqStack.push(4); // The stack is [5,7,5,7,4]
freqStack.push(5); // The stack is [5,7,5,7,4,5]
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,5,7,4].
freqStack.pop();   // return 7, as 5 and 7 is the most frequent, but 7 is closest to the top. The stack becomes [5,7,5,4].
freqStack.pop();   // return 5, as 5 is the most frequent. The stack becomes [5,7,4].
freqStack.pop();   // return 4, as 4, 5 and 7 is the most frequent, but 4 is closest to the top. The stack becomes [5,7].
 

Constraints:

0 <= val <= 109
At most 2 * 104 calls will be made to push and pop.
It is guaranteed that there will be at least one element in the stack before calling pop.

**Link**: [text](https://leetcode.com/problems/maximum-frequency-stack/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to keep track of the elements in the order they were added, and a hash map to keep track of the frequency of each element. Additionally, maintain a variable to keep track of the maximum frequency. When pushing an element, update its frequency in the hash map and push it onto the stack. When popping an element, pop from the stack until you find an element that has the maximum frequency. Decrease its frequency in the hash map and return it. If after popping an element, there are no more elements with the current maximum frequency, decrease the maximum frequency by one.

**Key Insight:** The key insight is that by using a stack to maintain the order of elements and a hash map to track their frequencies, we can efficiently determine which element to pop based on the maximum frequency. The stack allows us to easily access the most recently added elements, while the hash map allows us to quickly update and check the frequency of each element.

**Gotchas:** Be careful to update the maximum frequency correctly after popping an element. If the popped element was the only one with the maximum frequency, you need to decrease the maximum frequency by one. Also, make sure to handle the case where multiple elements have the same maximum frequency, in which case you should pop the most recently added one (the one closest to the top of the stack). If in the stack the number that had the maximumFrequency is popped, then we need to check if there are any more numbers with the same maximumFrequency, if not, we need to decrease the maximumFrequency by 1, because now the new maximumFrequency will be 1 less than the previous maximumFrequency. This is a bit tricky to see, but it is important to maintain the correct maximumFrequency after popping an element and it will only decrease by 1.

**Complexity:** Time: O(1) for both push and pop operations (amortized) | Space: O(n) in the worst case if all elements are unique and stored in the stack and hash map

```cpp
class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
    int freqNum = ++freq[val];
    maxFreq = max(freqNum, maxFreq);
    stkVal[freqNum].push(val);
    }
    
    int pop() {
    int val = stkVal[maxFreq].top();
    stkVal[maxFreq].pop();
    if(stkVal[maxFreq].empty()){
        maxFreq--;
    }
    freq[val]--;
    return val;
    }
private:
int maxFreq = 0;
unordered_map<int, int> freq;
unordered_map<int, stack<int>> stkVal;
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
```


## Online Stock Span LC 901

<!-- notecardId: 1780415953098 -->

Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.

**Link**: [text](https://leetcode.com/problems/online-stock-span/)

%

**Pattern:** Stack with Auxiliary Data Structure

**Approach:** Use a stack to keep track of the prices and their corresponding spans. When a new price is added, pop from the stack until you find a price that is greater than the current price. The span for the current price will be the sum of the spans of all the popped prices plus one (for the current price itself). Then, push the current price and its span onto the stack. This way, the stack will always maintain prices in decreasing order, and you can efficiently calculate the span for each new price.

**Key Insight:** The key insight is that by using a stack to maintain the prices in decreasing order, you can efficiently calculate the span for each new price by summing the spans of all the prices that are less than or equal to it. The stack allows you to easily access the most recent prices and their spans, which is essential for calculating the span for the current price.

**Gotchas:** Be careful to correctly calculate the span for the current price by summing the spans of all the popped prices plus one. Also, make sure to push the current price and its span onto the stack after popping the smaller prices. The stack should always maintain prices in decreasing order, so if you encounter a price that is greater than the current price, you should stop popping and calculate the span based on the remaining top of the stack. The clever solution is that once a span is calculated, future calculations can then use that span to skip over multiple entries in the stack at once, which is what allows the next() function to run in O(1) amortized time.

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Daily Temperatures — LC #739 | Find days until next warmer day → same monotonic stack, store index not span | Yes — direct variant |
| Next Greater Element I — LC #496 | Find next greater value across two arrays → same monotonic stack foundation | Yes — foundation |
| Next Greater Element II — LC #503 | Circular array next greater → same stack with modulo index wrapping | Partial — same family |
| Largest Rectangle in Histogram — LC #84 | Nearest smaller bar on both sides → same left/right boundary via stack | Partial — same boundary idea |
| Car Fleet — LC #853 | Group cars that catch up → same stack absorption when condition met | Partial — same stack family |
| Sliding Window Maximum — LC #239 | Maximum in sliding window → monotonic deque instead of stack | Partial — same tracking idea |
| Sum of Subarray Minimums — LC #907 | Sum minimums across all subarrays → same left/right nearest smaller boundary | Yes — same structure |
| Stock Price Fluctuation — LC #2034 | Track min/max of streaming prices → sorted set instead of stack | No — different pattern |

**How this pattern scales:**
- **Monotonic stack storing (price, span) pairs** is the core trick — when a new price arrives pop all stack entries with price less than or equal to current price, accumulate their spans into the current span, then push the new (price, accumulated span) pair
- **Span accumulation is the key upgrade from LC #739** — instead of storing raw indices and computing distance by subtraction, store the span directly and sum it during pops. This handles the online streaming nature without needing to store all historical prices
- **Online vs offline distinction** — LC #739 processes the full array at once (offline), LC #901 processes one price at a time (online/streaming). The stack structure is identical but span accumulation replaces index subtraction because historical indices are unavailable
- **Compressed history** → by storing accumulated spans instead of individual prices the stack never grows beyond O(n) but in practice stays much smaller — consecutive decreasing prices get compressed into a single entry on the next higher price
- **Streaming pattern** → any problem processing elements one at a time where each query depends on all previous elements uses this online stack approach. The key design question is always what to store per stack entry to answer queries in O(1)

```cpp
class StockSpanner {
public:
    StockSpanner() {
        //dont need to do anything here
    }
    
    int next(int price) {
        int countCheck= 1;
            while(!Stk.empty() && price >= Stk.top().first){
                countCheck += Stk.top().second;
                Stk.pop();
            }
            Stk.push({price, countCheck});
            return countCheck;
    }
private:
    stack<pair<int, int>> Stk; //insight, score both the price and the span, 
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
```
## Reverse String LC 344

<!-- notecardId: 1780418911456 -->

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.

**Link**: [text](https://leetcode.com/problems/reverse-string/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one starting at the beginning of the array and the other starting at the end of the array. Swap the characters at these two pointers and then move the pointers towards each other until they meet or cross. This will reverse the string in place. 

**Key Insight:** The key insight is that by using two pointers to swap characters from the start and end of the array, you can reverse the string in place without needing any additional memory. This approach is efficient and straightforward for reversing an array of characters.

**Gotchas:** Be careful to correctly move the pointers towards each other after each swap. The loop should continue until the pointers meet or cross, which means you should check for `left < right` as the loop condition. Also, make sure to swap the characters at the correct indices and to handle edge cases such as an array of length 1, which is already reversed.

**Complexity:** Time: O(n) where n is the length of the string (each character is swapped at most once) | Space: O(1) since the reversal is done in place without using extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Reverse Words in a String — LC #151 | Reverse words not characters → split trim reverse rejoin | Partial — same two pointer idea |
| Reverse Words in a String III — LC #557 | Reverse each word individually not whole string → two pointer per word | Yes — direct variant |
| Reverse Vowels of a String — LC #345 | Reverse only vowels using two pointers → same inward scan with condition | Yes — direct variant |
| Valid Palindrome — LC #125 | Check if string reads same both ways → same inward two pointer comparison | Yes — same pattern |
| Reverse Linked List — LC #206 | Reverse a linked list instead of array → prev/curr pointer swap instead of index swap | Partial — same reversal idea |
| Rotate Array — LC #189 | Rotate array by k positions → reverse whole then reverse parts | Yes — reversal as building block |
| Two Sum II — LC #167 | Two pointers on sorted array → same inward scan different condition | Partial — same two pointer family |
| Palindrome Linked List — LC #234 | Check palindrome on linked list → reverse second half then compare | Partial — reversal as subroutine |

**How this pattern scales:**
- **Two pointer inward scan** is the core trick — left pointer at start right pointer at end swap and move inward until they meet. O(n) time O(1) space
- **Reversal as a building block** → Rotate Array (LC #189) uses three reversals to achieve rotation — reverse whole array, reverse first k elements, reverse remaining. Knowing reverse cold makes this derivable in seconds
- **Condition based reversal** → Reverse Vowels (LC #345) adds a skip condition to the two pointer scan — same inward movement but only swap when both pointers land on vowels. Any selective reversal problem uses this same conditional two pointer pattern
- **Palindrome connection** → Valid Palindrome (LC #125) is the same inward two pointer scan but comparing instead of swapping. If you can reverse a string you already understand the pointer movement needed to check palindromes

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
            for(int i = 0; i < (s.size() / 2); i++){
                swap(s[i],s[(s.size() - 1) - i]);
            }
        }
};
```

## Container with Most Water LC 11

<!-- notecardId: 1780419102948 -->

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 
Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

**Link**: [text](https://leetcode.com/problems/container-with-most-water/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one starting at the beginning of the array and the other starting at the end of the array. Calculate the area formed by the lines at these two pointers and update the maximum area if necessary. Then, move the pointer that points to the shorter line towards the other pointer, since moving the taller line would not increase the area. Continue this process until the two pointers meet.

**Key Insight:** The key insight is that the area of water contained between two lines is determined by the shorter line, so to maximize the area, you should move the pointer that points to the shorter line. This way, you have a chance to find a taller line that could potentially increase the area. The two-pointer approach allows you to efficiently explore all possible pairs of lines without needing to check every combination, resulting in an O(n) time complexity.

**Gotchas:** Be careful to correctly calculate the area using the formula `area = min(height[left], height[right]) * (right - left)`. Also, make sure to update the maximum area after each calculation. The loop should continue until the two pointers meet, which means you should check for `left < right` as the loop condition. Additionally, remember that moving the taller line will not increase the area, so only move the pointer that points to the shorter line.

**Complexity:** Time: O(n) where n is the length of the height array (each element is visited at most once by either pointer) | Space: O(1) since we are using only a constant amount of extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Trapping Rain Water — LC #42 | Water trapped between all bars not just two → same two pointer but accumulate | Yes — direct upgrade |
| Two Sum II — LC #167 | Two pointers on sorted array summing to target → same inward scan different condition | Yes — same two pointer pattern |
| 3Sum — LC #15 | Fix one element two pointer the rest → same inward scan inside outer loop | Yes — same pattern |
| Largest Rectangle in Histogram — LC #84 | Largest rectangle not largest water container → monotonic stack instead | Partial — same area idea |
| Maximum Area of Island — LC #695 | Max area in 2D grid → BFS/DFS not two pointer | No — different pattern |
| Sum of Two Integers — LC #371 | Combine two values without arithmetic → bit manipulation | No — different pattern |
| Minimize Maximum Pair Sum — LC #1877 | Pair smallest with largest to minimize max sum → same two pointer inward scan | Yes — same pattern |
| Boats to Save People — LC #881 | Pair lightest with heaviest under weight limit → same two pointer greedy | Yes — direct variant |

**How this pattern scales:**
- **Two pointer greedy** is the core trick — start with widest possible container, always move the pointer at the shorter bar inward. Moving the taller bar can only decrease area so it is never optimal to move it
- **Greedy correctness proof** → moving the shorter bar is the only way to potentially find a taller bar that compensates for the reduced width. This greedy argument is worth stating explicitly in interviews as it shows you understand why the approach works not just that it works
- **Width vs height tradeoff** → the area formula `min(h[l], h[r]) * (r - l)` has two competing factors. Two pointer works here because fixing the width reduction means height can only improve by moving the shorter side — this tradeoff reasoning generalizes to Trapping Rain Water and Boats to Save People
- **Upgrade to Trapping Rain Water** → LC #42 uses the same two pointer inward scan but instead of tracking the maximum area it accumulates trapped water at each step using prefix max from both sides. Same pointer movement, fundamentally different accumulation logic

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaVal = 0;
        int leftSide = 0;
        int rightSide = height.size() - 1;
        while(leftSide < rightSide){
            maxAreaVal = max(maxAreaVal, min(height[leftSide], height[rightSide]) * (rightSide - leftSide));
            if(height[leftSide] < height[rightSide]){
                leftSide++;
            }
            else{
                rightSide--;
            }
        }
        return maxAreaVal;
    }
};
```

## 3Sum LC 15

<!-- notecardId: 1780419447874 -->

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

**Link**: [text](https://leetcode.com/problems/3sum/)

%

**Pattern:** Two Pointers

**Approach:** First, sort the input array. Then, iterate through the array with an index `i` from 0 to `n-3`. For each index `i`, use two pointers `left` and `right` to find pairs of numbers that sum up to `-nums[i]`. The `left` pointer starts at `i+1` and the `right` pointer starts at the end of the array. If the sum of the three numbers is less than zero, move the `left` pointer to the right. If the sum is greater than zero, move the `right` pointer to the left. If the sum is zero, add the triplet to the result list and move both pointers while skipping duplicates.

**Key Insight:** The key insight is that by sorting the array and using a two-pointer approach, you can efficiently find all unique triplets that sum up to zero. Sorting allows you to easily skip duplicates and ensures that the two-pointer technique works correctly. The two-pointer technique reduces the time complexity from O(n^3) to O(n^2) by avoiding the need for a third nested loop.

**Gotchas:** Be careful to skip duplicate values for the index `i` to avoid adding duplicate triplets to the result. Also, after finding a valid triplet, make sure to move both pointers and skip any duplicate values to ensure that you only add unique triplets to the result. The condition for skipping duplicates is crucial for passing all test cases, especially when the input array contains multiple identical numbers. The reason the first for loop goes from i to i - 3 is because in the final loop we are using two pointers, left and right, and we need to make sure that there are at least two more elements after i to form a triplet. If i goes beyond n - 3, then there won't be enough elements left to form a triplet.

**Complexity:** Time: O(n^2) where n is the length of the input array (sorting takes O(n log n) and the two-pointer search takes O(n^2)) | Space: O(1) if we don't count the space used for the output list, otherwise O(k) where k is the number of unique triplets found

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Two Sum — LC #1 | Two elements summing to target → hash map no sorting needed | Yes — foundation |
| Two Sum II — LC #167 | Two elements on sorted array → same two pointer no fix step | Yes — direct foundation |
| 3Sum Closest — LC #16 | Find triplet sum closest to target → same fix + two pointer track minimum diff | Yes — direct variant |
| 3Sum Smaller — LC #259 | Count triplets summing less than target → same fix + two pointer count window | Yes — direct variant |
| 4Sum — LC #18 | Four elements summing to target → same fix two + two pointer inner loop | Yes — direct upgrade |
| 4Sum II — LC #454 | Four arrays one element each summing to zero → hash map of pair sums | Partial — different structure |
| Combination Sum — LC #39 | All combinations summing to target with reuse → backtracking not two pointer | No — different pattern |
| Trapping Rain Water — LC #42 | Two pointer tracking boundaries → same inward scan different accumulation | Partial — same two pointer family |

**How this pattern scales:**
- **Sort + fix + two pointer** is the core trick — sort the array, fix one element with outer loop, run two pointer inward scan on the remaining subarray. O(n²) time O(1) space
- **Duplicate skipping is mandatory** — after fixing an element skip duplicates in the outer loop. After a valid triplet is found skip duplicates on both pointers. Missing either skip produces duplicate triplets and is the single most common bug on this problem
- **kSum generalization** → 3Sum fixes one element and reduces to 2Sum. 4Sum fixes two elements and reduces to 2Sum. For any kSum fix k-2 elements recursively and run two pointer at the innermost level — O(n^(k-1)) time
- **Hash map vs two pointer** → Two Sum uses hash map because the array is unsorted. 3Sum sorts first making two pointer possible and more space efficient. The decision between hash map O(n) space and two pointer O(1) space always hinges on whether the array is or can be sorted

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sums;
        sort(nums.begin(), nums.end()); //need to sort, common rule for two ptr, n log n
        for(int i = 0; i < nums.size()- 2; i++){
            if(i > 0 && nums[i] == nums[i-1]){ //if i pointer is the same, then keep going to avoid duplicates
                continue;
            }
            int left = i + 1; //start the window right after i
            int right = nums.size() - 1; //go till the end
            while(left < right){ //keep going until right and left meet at same place, all combos been looked at
                if(nums[i] + nums[left] + nums[right] == 0){ //if match, add triplet
                    sums.push_back({nums[i], nums[left], nums[right]});
                    left++; //must rememebr to keep going left
                    right--; //and going right, to check more possible combos
                    while(left < right && nums[left]== nums[left - 1]){
                        left++; //if the next left is same as old left, keep going right
                    }
                    while(left < right && nums[right]== nums[right+1]){ 
                        right--; //if new right is the same as the old right, keep moving left
                    }
                }
                else if(nums[i] + nums[left] + nums[right] < 0){
                    left++; //if less than 0, need to increase the sum, move left pointer to the right 
                }
                else{
                    right--; //if greater than 0, need to decrease the sum, move right pointer to the left
                }
            }
        }
        return sums;
    }
};
```
## 4-Sum LC 18

<!-- notecardId: 1780419983349 -->

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

**Link**: [text](https://leetcode.com/problems/4sum/)

%

**Pattern:** Two Pointers

**Approach:** First, sort the input array. Then, iterate through the array with two nested loops to fix the first two elements of the quadruplet. For each pair of fixed elements, use two pointers to find pairs of numbers that sum up to `target - (nums[i] + nums[j])`. The `left` pointer starts at `j+1` and the `right` pointer starts at the end of the array. If the sum of the four numbers is less than the target, move the `left` pointer to the right. If the sum is greater than the target, move the `right` pointer to the left. If the sum is equal to the target, add the quadruplet to the result list and move both pointers while skipping duplicates.

**Key Insight:** The key insight is that by sorting the array and using a two-pointer approach, you can efficiently find all unique quadruplets that sum up to the target. Sorting allows you to easily skip duplicates and ensures that the two-pointer technique works correctly. The two-pointer technique reduces the time complexity from O(n^4) to O(n^3) by avoiding the need for two additional nested loops.

**Gotchas:** Be careful to skip duplicate values for the indices `i` and `j` to avoid adding duplicate quadruplets to the result. Also, after finding a valid quadruplet, make sure to move both pointers and skip any duplicate values to ensure that you only add unique quadruplets to the result. The condition for skipping duplicates is crucial for passing all test cases, especially when the input array contains multiple identical numbers.

**Complexity:** Time: O(n^3) where n is the length of the input array (sorting takes O(n log n) and the three nested loops take O(n^3)) | Space: O(1) if we don't count the space used for the output list, otherwise O(k) where k is the number of unique quadruplets found

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Two Sum — LC #1 | Two elements summing to target → hash map no sorting needed | Yes — foundation |
| Two Sum II — LC #167 | Two elements on sorted array → same two pointer no fix step | Yes — direct foundation |
| 3Sum — LC #15 | Three elements summing to zero → fix one + two pointer, one less fix step | Yes — direct foundation |
| 3Sum Closest — LC #16 | Closest triplet sum to target → same fix + two pointer track min diff | Partial — same family |
| 4Sum II — LC #454 | One element from each of four arrays → hash map of pair sums not sorting | Partial — different structure |
| Combination Sum — LC #39 | All combinations summing to target with reuse → backtracking not two pointer | No — different pattern |
| Subarray Sum Equals K — LC #560 | Contiguous subarray summing to k → prefix sum + hash map | No — different pattern |
| kSum General Pattern | Fix k-2 elements recursively reduce to two pointer → generalizes entire family | Yes — direct generalization |

**How this pattern scales:**
- **Sort + fix two + two pointer** is the core trick — sort the array, fix first element with outer loop, fix second element with inner loop, run two pointer inward scan on remaining subarray. O(n³) time O(1) space
- **Two levels of duplicate skipping** — skip duplicates on both fix loops AND on both pointers after finding a valid quadruplet. Four separate skip conditions total — missing any one produces duplicate quadruplets
- **Overflow handling** — with four integers summing together the total can easily exceed `INT_MAX`. Always cast to `long long` before summing in C++: `(long long)nums[i] + nums[j] + nums[l] + nums[r]`
- **kSum recursive template** → 4Sum is the last problem worth solving iteratively. For k > 4 implement a recursive kSum that fixes one element and calls kSum(k-1) until k == 2 then runs two pointer. O(n^(k-1)) time generalizes cleanly
- **4Sum II distinction** → LC #454 has one element from each of four separate arrays making sorting + two pointer impractical. Instead hash all pair sums from arrays A+B then check complement in arrays C+D — completely different approach despite similar name

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> sums;
    if(nums.size() < 4){
        return sums;
    }
        sort(nums.begin(), nums.end()); //need to sort, common rule for two ptr, n log n
        for(int i = 0; i < nums.size()- 3; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1; j < nums.size() - 2; j++){
            if(nums[j] == nums[j-1] && j>i+1){ //if i pointer is the same, then keep going to avoid duplicates
                continue;
            }
            int left = j + 1; //start the window right after i
            int right = nums.size() - 1; //go till the end
            while(left < right){ //keep going until right and left meet at same place, all combos been looked at
                if((long long)nums[i] + nums[j] + nums[left] + nums[right] == target){ //if match, add triplet
                    sums.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++; //must rememebr to keep going left
                    right--; //and going right, to check more possible combos
                    while(left < right && nums[left]== nums[left - 1]){
                        left++; //if the next left is same as old left, keep going right
                    }
                    while(left < right && nums[right]== nums[right+1]){ 
                        right--; //if new right is the same as the old right, keep moving left
                    }
                }
                else if((long long)nums[i] + nums[j] + nums[left] + nums[right] < target){
                    left++; //if less than 0, need to increase the sum, move left pointer to the right 
                }
                else{
                    right--; //if greater than 0, need to decrease the sum, move right pointer to the left
                }
            }
        }
        }
        return sums;
    }
};
```
## Remove Duplicates from Sorted Array LC 26

<!-- notecardId: 1780420209969 -->

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 
 Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

**Link**: [text](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one to iterate through the array and the other to keep track of the position of the last unique element. The first pointer (i) will traverse the array from the second element to the end, while the second pointer (j) will keep track of the index of the last unique element found. Whenever a new unique element is found (i.e., `nums[i] != nums[j]`), increment j and update `nums[j]` with the new unique element. Finally, return j + 1 as the number of unique elements.

**Key Insight:** The key insight is that since the array is sorted, all duplicates will be adjacent to each other. This allows us to use a two-pointer technique to efficiently remove duplicates in place without needing extra space. The second pointer (j) effectively compresses the array by overwriting duplicate values with unique values as we find them.

**Gotchas:** Be careful to initialize the second pointer (j) correctly and to return j + 1 at the end, since j is an index and the number of unique elements is one more than the last index. Also, make sure to start the first pointer (i) from the second element (index 1) since the first element is always unique. The condition for finding a new unique element is crucial and should be `nums[i] != nums[j]` to ensure that you only update the position of unique elements. Also, do not use erase here for an optimal solution because erasing elements from a vector is O(n) and would lead to an O(n^2) solution. Instead, we overwrite duplicates with unique values and return the count of unique elements.

**Complexity:** Time: O(n) where n is the length of the input array (each element is visited at most once) | Space: O(1) since we are modifying the array in place without using extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Remove Duplicates from Sorted Array II — LC #80 | Allow up to 2 duplicates → same write-head but check two positions back | Yes — direct upgrade |
| Remove Element — LC #27 | Remove specific value not duplicates → same write-head different condition | Yes — direct variant |
| Move Zeroes — LC #283 | Move zeros to end preserve order → same write-head keep zeros at back | Yes — close variant |
| Merge Sorted Array — LC #88 | Merge two sorted arrays in place → same in-place write but from the back | Partial — same in-place idea |
| Find the Duplicate Number — LC #287 | Find duplicate not remove it → Floyd's cycle detection or index marking | No — different pattern |
| Sort Colors — LC #75 | Partition into three groups → Dutch National Flag three pointer | Partial — same in-place idea |
| Squares of a Sorted Array — LC #977 | Square and sort in place → two pointer from both ends | Partial — same two pointer family |
| Longest Consecutive Sequence — LC #128 | Find longest run without modifying array → hash set | No — different pattern |

**How this pattern scales:**
- **Write-head pointer** is the core trick — one pointer `i` iterates through the array, one pointer `k` tracks the next position to write. Only write when `nums[i] != nums[k-1]`. O(n) time O(1) space
- **k duplicates allowed generalization** → LC #80 allows 2 duplicates by checking `nums[i] != nums[k-2]` instead of `nums[k-1]`. For k allowed duplicates check `nums[i] != nums[k - allowedCount]` — same one line change generalizes to any k
- **In-place from the back** → when merging or filling from the end (LC #88) reverse the write-head direction to avoid overwriting unprocessed elements. Same pointer concept, opposite direction
- **Write-head family ladder** → LC #26 → LC #80 → LC #27 → LC #283 — each problem is the same write-head skeleton with a different write condition. Knowing LC #26 cold means all four are derivable from the same template

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // for(int i = nums.size() - 2; i >= 0; i--){ //this soltuion is non-optimal but it does work.
        //     int duplicatePtr = i+1; 
        //     if(nums[i] == nums[duplicatePtr]){
        //         nums.erase(nums.begin() + duplicatePtr);
        //     }
        // }
        // return nums.size();

    //optimal solution requires two ptr approach
    if(nums.empty()) {
        return 0;
    }
    int write = 1; //write marks the index where the next unique value should be placed
    for(int read = 1; read < nums.size(); read++){ //read is scanning for each unique value
        if(nums[read] != nums[read -1]){
            nums[write] = nums[read];
            write++;
        }
    }
    return write;
    }
};
```

## Trapping Rain Water LC 42

<!-- notecardId: 1780420840490 -->

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

**Link**: [text](https://leetcode.com/problems/trapping-rain-water/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one starting at the beginning of the array and the other starting at the end of the array. Keep track of the maximum height seen from the left and right sides. At each step, move the pointer that points to the shorter bar inward. If the current bar is shorter than the maximum height seen from that side, it can trap water, and you can calculate the trapped water by subtracting the current bar's height from the maximum height. Continue this process until the two pointers meet.

**Key Insight:** The key insight is that the amount of water trapped at any position is determined by the shorter of the two bars on either side. By using two pointers and keeping track of the maximum heights from both sides, you can efficiently calculate the trapped water without needing to check every possible pair of bars. This approach allows you to solve the problem in O(n) time with O(1) extra space.

**Gotchas:** Be careful to update the maximum heights from both sides correctly as you move the pointers inward. The condition for moving the pointers is crucial: always move the pointer that points to the shorter bar, because moving the taller bar cannot increase the amount of trapped water. Also, make sure to calculate the trapped water correctly by using the difference between the maximum height and the current bar's height.

**Complexity:** Time: O(n) where n is the length of the input array (each element is visited at most once by either pointer) | Space: O(1) since we are using only a constant amount of extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Container With Most Water — LC #11 | Maximum water between two bars only → same two pointer greedy inward scan | Yes — simpler foundation |
| Largest Rectangle in Histogram — LC #84 | Largest rectangle not trapped water → monotonic stack nearest smaller boundary | Partial — same bar array |
| Product of Array Except Self — LC #238 | Prefix and suffix product not prefix and suffix max → same two pass build | Yes — same structure |
| Daily Temperatures — LC #739 | Next warmer day → same monotonic stack but store index not water | Partial — same stack family |
| Sum of Subarray Minimums — LC #907 | Sum minimums across subarrays → same left/right boundary via monotonic stack | Partial — same boundary idea |
| Maximal Rectangle — LC #85 | Largest rectangle in binary matrix → histogram per row + LC #84 subroutine | No — different pattern |
| Pour Water — LC #755 | Simulate water drops falling one at a time → greedy left/right scan per drop | Partial — same water idea |
| Candy — LC #135 | Distribute minimum candies satisfying neighbor constraints → same two pass left then right | Yes — same two pass structure |

**How this pattern scales:**
- **Two pointer O(1) space** is the optimal approach — maintain left and right pointers with running max from each side. Move the pointer at the shorter max inward, add difference between running max and current height as trapped water. Same greedy argument as LC #11
- **Prefix/suffix max arrays** is the O(n) space approach — precompute left max and right max arrays, trapped water at each index is `min(leftMax[i], rightMax[i]) - height[i]`. Easier to derive under pressure, same time complexity
- **Monotonic stack approach** is the third option — process bars left to right, when a taller bar is found pop shorter bars and compute horizontal water trapped between current bar and new stack top. Useful when you need to extend to 2D
- **Two pass structure generalizes** → Candy (LC #135) uses the exact same left pass then right pass skeleton — first pass satisfies left neighbor constraint, second pass satisfies right neighbor constraint, same idea of building prefix and suffix arrays and combining them

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        //O(n) memory would be more inefficient here, you would store the maxL and maxR from each 
        if(height.empty()) return 0;
        int result = 0;
        int l = 0;
        int r = height.size() - 1;
        int MaxL = height[l];
        int MaxR = height[r];
        while(l < r){
            if(MaxL < MaxR){ //if the maxL is less than maxR, then we know that the maxL is the limiting factor for how much water can be trapped at the current left pointer. 
            //This is because the water level at the left pointer cannot exceed the height of the tallest bar to the left, right side can potentially hold more water. 
            //If we were to move the right pointer instead, we might miss out on trapping water at the left pointer, since the maxL is the smaller of the two.
                l++;
                MaxL = max(MaxL, height[l]);
                result += MaxL - height[l]; //The amount of water trapped at the current left pointer is the difference between the maxL and the height of the current bar at the left pointer. We add this to our result, and then move the left pointer to the right to continue checking for more trapped water.
                //think of result being the depth, kind of like a basin, and the height of the current bar is the floor of the basin. The maxL is the ceiling of the basin, so the difference between them is how much water can be trapped in that basin.
            }
            else{
               r--;
                MaxR = max(MaxR, height[r]);
                result += MaxR - height[r];
            }
    }
            return result;
    }
};
```
## Merge Sorted Array LC 88

<!-- notecardId: 1780421778684 -->

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

**Link**: [text](https://leetcode.com/problems/merge-sorted-array/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one for each array, starting from the end of the valid elements in nums1 and the end of nums2. Compare the elements at these pointers and place the larger one at the end of nums1. Move the pointer of the array from which you took the element. Continue this process until all elements from nums2 have been merged into nums1.

**Key Insight:** The key insight is that since nums1 has enough space to hold all elements from both arrays, we can merge the arrays starting from the end. This way, we avoid overwriting any elements in nums1 that have not yet been compared. By comparing the elements from the end, we can efficiently place the larger elements in their correct positions without needing extra space.

**Gotchas:** Be careful to handle the case where nums2 has remaining elements after nums1 has been fully merged. In this case, you need to copy the remaining elements from nums2 into the beginning of nums1. Also, make sure to compare the correct elements at each step and to move the pointers correctly after placing an element.

**Complexity:** Time: O(m + n) where m and n are the lengths of the valid elements in nums1 and nums2 respectively (each element is visited at most once) | Space: O(1) since we are merging in place without using extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Merge Two Sorted Lists — LC #21 | Linked lists instead of arrays → merge forward from head to tail using a dummy node | Yes — identical linear merge logic |
| Squares of a Sorted Array — LC #977 | Input has negative numbers making squares a "V" shape → use two pointers at boundaries to fill a new array from back to front | Yes — same reverse-filling mechanic |
| Merge k Sorted Lists — LC #23 | Merging $k$ sorted streams instead of 2 → requires a Min-Heap (Priority Queue) or Divide & Conquer | Partial — scales the merge sub-problem |
| Interval List Intersections — LC #986 | Comparing interval overlaps instead of single elements → advanced pointer with the smaller endpoint | Partial — same synchronized two-pointer parallel scan |
| Remove Duplicates from Sorted Array — LC #26 | Single sorted array, overwriting duplicates → fast and slow pointer tracking write-position moving forward | Partial — same in-place array modification |
| Intersection of Two Arrays II — LC #350 | Finding common elements instead of merging → advance pointer with smaller value, collect duplicates | Yes — same parallel two-pointer scanning |

**How this pattern scales:**
- **Two-pointer reverse-fill O(1) space** is the optimal approach for in-place array merges. By initializing three pointers—one at the end of the initialized elements of `nums1`, one at the end of `nums2`, and a write pointer at the absolute end of `nums1`—you can safely place the largest elements first without overwriting unprocessed data. 
- **Temporary array buffer O(m + n) space** is the standard forward approach. You copy `nums1` to a new array and merge forward into the original `nums1`. This is easier to visualize under pressure but fails the in-place memory constraint.
- **K-way Merge scalability** is the direct extension of this pattern. When scaling from 2 arrays to $k$ arrays, a simple pointer comparison becomes too slow ($O(k)$ per element). The pattern scales by replacing the manual `if/else` pointer comparison with a Min-Heap (Priority Queue) of size $k$ to extract the minimum/maximum element in $O(\log k)$ time.
- **In-place array manipulation generalizes** → Whenever a problem requires modifying an array in-place based on sorted data or boundary conditions, always consider working **backwards from the end**. Moving from right to left often transforms an $O(n)$ space requirement into an $O(1)$ space solution because the "empty" or "safe" space naturally sits at the end of the allocated memory blocks.

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //need three pointers for this question
        //go right to left for indexing purposes here
        int ptrNums1 = m - 1; //nums1 position
        int ptrWrite = m + n - 1; //current write position
        int ptrNums2 = n - 1; //nums2 position
        while(ptrWrite >= 0 && ptrNums1 >= 0 && ptrNums2 >= 0){
            int maxNum = max(nums1[ptrNums1], nums2[ptrNums2]);
            if(nums1[ptrNums1] > nums2[ptrNums2]){
                ptrNums1--;
            }
            else{
                ptrNums2--;
            }
            nums1[ptrWrite] = maxNum;
            ptrWrite--;
        }
        while (ptrNums2 >= 0){
            nums1[ptrWrite] = nums2[ptrNums2];
            ptrNums2--;
            ptrWrite--;
        }
    }
};
```

## Valid Palindrome LC 125

<!-- notecardId: 1780422124834 -->

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

**Link**: [text](https://leetcode.com/problems/valid-palindrome/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one starting at the beginning of the string and the other starting at the end of the string. Move both pointers towards the center while skipping non-alphanumeric characters. At each step, compare the characters at the two pointers (after converting them to lowercase). If they are not equal, return false. If the pointers cross each other, return true.

**Key Insight:** The key insight is that a palindrome reads the same forward and backward, so by using two pointers to compare characters from both ends of the string, you can efficiently determine if the string is a palindrome. By skipping non-alphanumeric characters and converting uppercase letters to lowercase, you can ensure that the comparison is case-insensitive and ignores irrelevant characters.

**Gotchas:** Be careful to correctly identify and skip non-alphanumeric characters. You can use the `isalnum()` function in C++ to check if a character is alphanumeric. Also, make sure to convert uppercase letters to lowercase before comparing them. The condition for moving the pointers should be based on whether the characters are alphanumeric, and the comparison should be case-insensitive.

**Complexity:** Time: O(n) where n is the length of the input string (each character is visited at most once by either pointer) | Space: O(1) since we are using only a constant amount of extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Palindrome II — LC #680 | Allowed to delete at most one character → on first mismatch, branch to check if remaining left or right substring is a palindrome | Yes — direct extension with a one-time branch |
| Reverse String — LC #344 | Modify string in-place instead of validating → swap elements at left and right pointers while shrinking inward | Yes — identical inward-moving structure |
| Palindrome Linked List — LC #234 | Nodes cannot be read backwards easily → use fast/slow pointers to find middle, reverse the second half, then compare forward | Partial — same symmetry check but requires list manipulation |
| Longest Palindromic Substring — LC #5 | Find the largest palindrome instead of validating one → expand outward from $2n-1$ potential centers instead of shrinking inward | Partial — reverse directional mechanics |
| Palindrome Number — LC #9 | Numeric input without string conversion → use arithmetic modulo and division to reverse the integer (or half of it) to check symmetry | Partial — same math logic applied to digits instead of characters |

**How this pattern scales:**
- **Two-pointer inward convergence O(1) space** is the optimal strategy for validating sequence symmetry. By placing a pointer at the beginning and end, you verify the matching criteria and step inward. The loop safely terminates when the pointers cross in the middle.
- **On-the-fly filtering avoids O(n) memory allocation**. Instead of preprocessing the input into a clean string (which takes extra space), scale the two-pointer approach by adding nested loops to skip invalid characters (like spaces or punctuation) dynamically during the scan.
- **Branching handles tolerance/faults** → When a problem introduces an "allowance" for errors (like LC #680 allowing one deletion), the pattern scales from a strict greedy check to a limited exploration. Upon a mismatch, you tentatively skip the left character OR the right character and evaluate the remaining sub-problems. This scales gracefully to "K-deletions" via recursion with a depth limit of K.
- **Inward vs. Outward duality generalizes** → Palindrome problems broadly split into two behaviors: **Shrinking** (Inward Two-Pointer) for validation/checking, and **Expanding** (Outward Two-Pointer) for searching/generation. If you are looking to *find* palindromes within a larger body of text (like LC #5 or LC #647), you flip the pattern to start at a center index and push the pointers outward as long as the symmetry holds.

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char &c : s){
            if(isalnum(static_cast<unsigned char>(c))){
                result += tolower(c);
            }
        }
        for(int i = 0; i < result.size() / 2; i++){
            if(result[i] != result[(result.size()-1) - i]){
                return false;
            }
        }
        return true;
    }
};
```

## Two Sum II - Input Array Is Sorted LC 167

<!-- notecardId: 1780422894430 -->

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
 

Constraints:

2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers is sorted in non-decreasing order.
-1000 <= target <= 1000
The tests are generated such that there is exactly one solution.

**Link**: [text](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one starting at the beginning of the array and the other starting at the end of the array. Calculate the sum of the elements at these two pointers. If the sum is equal to the target, return the indices (adjusted for 1-indexing). If the sum is less than the target, move the left pointer to the right to increase the sum. If the sum is greater than the target, move the right pointer to the left to decrease the sum. Continue this process until you find the solution.

**Key Insight:** The key insight is that since the array is sorted, you can efficiently find the two numbers that add up to the target by using a two-pointer technique. By starting with one pointer at the beginning and one at the end, you can adjust the pointers based on whether the current sum is too low or too high, which allows you to find the solution in linear time. A hash map would be inefficient here because it would require O(n) space, while the two-pointer approach only requires O(1) extra space.

**Gotchas:** Be careful to adjust the returned indices for 1-indexing, as the problem specifies that the array is 1-indexed. Also, make sure to handle the case where the sum of the two pointers is equal to the target correctly by returning the appropriate indices. The condition for moving the pointers should be based on whether the current sum is less than or greater than the target.

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Two Sum — LC #1 | Unsorted array → requires a Hash Map for $O(n)$ space or manual sorting first to achieve $O(n \log n)$ time | Partial — same objective, but array lacks the sorted property |
| 3Sum — LC #15 | Find unique triplets summing to zero → sort the array, use a loop to fix the first element, then run Two Sum II on the remaining suffix while skipping duplicates | Yes — direct nested extension |
| 4Sum — LC #18 | Find unique quadruplets summing to target → use two nested loops to fix the first two elements, then run Two Sum II on the remaining suffix | Yes — scales up the k-Sum problem |
| 3Sum Closest — LC #16 | Find a triplet sum closest to target → instead of looking for an exact match, track and update the minimum absolute difference at every pointer step | Yes — identical pointer movement logic |
| Two Sum Less Than K — LC #1099 | Find the maximum sum strictly less than $K$ → when `sum < K`, record/maximize the running result and advance `left` to try for a larger sum | Yes — identical pointer movement based on bounds |
| Boats to Save People — LC #881 | Pair elements to minimize groups given a weight limit → sort elements, greedily try to pair heaviest (`right`) and lightest (`left`). If they exceed limit, heaviest goes alone (`right--`) | Yes — greedy monotonic decision making |

**How this pattern scales:**
- **Two-pointer boundary convergence O(1) space** is the optimal strategy when searching pairs in a sorted sequence. Monotonicity is the key: if the current `sum < target`, moving the `left` pointer rightward is guaranteed to only increase or maintain the sum. If `sum > target`, moving the `right` pointer leftward is guaranteed to only decrease or maintain the sum. This eliminates a full dimension of search space, collapsing an $O(n^2)$ brute-force search into $O(n)$.
- **Nesting to solve k-Sum problems generalizes dynamically** → The Two Sum II pattern acts as the foundational base case for all higher-order k-Sum problems. To solve a 3Sum, 4Sum, or $k$-Sum problem, you use $k-2$ nested loops to systematically fix elements, reducing the remaining search space to a standard 2Sum problem handled in $O(n)$ time. This yields a general time complexity scaling of $O(n^{k-1})$.
- **Duplicate management via pointer skipping** → When scaling this pattern to combinatorial problems requiring unique combinations (like 3Sum/4Sum), the pattern expands to include skip-phases. After a match is recorded, or during pointer increments, internal `while` loops must be added to advance pointers past identical neighboring elements (`nums[l] == nums[l+1]`) to prevent duplicate results.
- **Optimization of inequalities over exact matches** → The pattern scales seamlessly from strict equality targets (`== target`) to boundary optimization problems (min, max, or closest). Because the direction of pointer movement is strictly dictated by whether the current sum is too small or too large, the exact same control flow works whether you are hunting an exact number, optimizing a capacity limit, or minimizing a delta.

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        vector<int> ans(2);
        while(numbers[index1] + numbers[index2] != target){
            if(numbers[index1] + numbers[index2] < target){
                index1++;
            }
            else{
                index2--;
            }
        }
        ans[0] = index1 + 1;
        ans[1] = index2 + 1;
        return ans;
    }
};
```
## Rotate Array LC 189

<!-- notecardId: 1780423901771 -->

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?

**Link**: [text](https://leetcode.com/problems/rotate-array/)

%

**Pattern:** Two Pointers

**Approach:** One optimal approach to rotate the array in-place with O(1) extra space is to use the reversal algorithm. The idea is to reverse the entire array, then reverse the first k elements, and finally reverse the remaining n-k elements. This effectively rotates the array to the right by k steps.

**Key Insight:** The key insight is that rotating an array to the right by k steps can be achieved by reversing the order of the elements. By first reversing the entire array, you bring the last k elements to the front. Then, by reversing the first k elements, you restore their original order, and by reversing the remaining n-k elements, you restore their original order as well. This method allows you to rotate the array in-place without needing extra space for a temporary array.

**Gotchas:** Be careful to handle the case where k is greater than the length of the array. In such cases, you should take k modulo the length of the array to ensure that you are rotating by the correct number of steps. Also, make sure to implement the reverse function correctly, as it is a crucial part of this algorithm.

**Complexity:** Time: O(n) where n is the length of the input array (each element is visited a constant number of times during the reversals) | Space: O(1) since we are rotating the array in-place without using extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Reverse Words in a String — LC #151 | Words separated by spaces need their order swapped → reverse the entire string globally, then reverse characters within each individual word in-place | Yes — identical block-reversal structure |
| Rotate List — LC #61 | Linked list instead of an array → cannot use random-access pointers; connect tail to head to form a cycle, traverse $N - (k \pmod N)$ steps, then break the link | Partial — same cyclical shift logic but uses pointer re-linking |
| Reverse Words in a String III — LC #557 | Reverse characters of each word but keep word order intact → scan for space delimiters and reverse localized sub-segments only, skipping the global reversal | Yes — utilizes the same localized reverse subroutine |
| Cyclic Sort (e.g., First Missing Positive) — LC #41 | Elements must be placed at their specific index value (`nums[i] == i + 1`) rather than shifted by a fixed offset → use continuous in-place swapping chain | Partial — uses index-destination mapping rather than uniform shifting |

**How this pattern scales:**
- **Three-Step Block Reversal O(1) space** is the optimal strategy for block shifting or rotating linear sequences. By reversing the entire array, you move the target blocks to their relative correct side (front vs. back). Reversing the sub-segments individually then "restores" their original, non-inverted reading order. This avoids allocating a secondary array buffer.
- **Modulo Arithmetic handles boundaries and scaling**. Whenever a transformation involves cyclic shifting or wrapping around boundaries where the offset $k$ can exceed array size $n$, applying `k = k % n` standardizes the displacement. If `k % n == 0`, the operation can instantly terminate as a no-op.
- **Cyclic Replacements (Index Hopping)** is the alternative $O(1)$ space strategy. Instead of block reversing, you treat the array as a set of cycles where each element hops to its destination index `(i + k) % n`. Using a temporary variable to hold the displaced element, you resolve one full cyclic chain before moving to the next. This scales using the Greatest Common Divisor (GCD) of $n$ and $k$ to determine the exact number of independent cycles.
- **Global-to-Local processing generalizes** → The concept of transforming a dataset globally and then selectively undoing or refining that transformation on localized sub-segments is a powerful pattern. It transforms seemingly complex $O(n)$ space sliding-window buffer problems into elegant, in-place multi-pass algorithms.

```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size()){
            k = k % nums.size();
        }
        for(int i = 0; i < nums.size() / 2; i++){
            swap(nums[i], nums[(nums.size() - 1) - i]);
        }
        //need to reverse for each half
        for(int i = 0; i < k/2; i++){
            swap(nums[i], nums[(k - 1) - i]);
        }
        int left = k;
        int right = nums.size() - 1;
        while(left < right){
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }
};
```

## Valid Palindrome II LC 680

<!-- notecardId: 1780424838928 -->

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
 
Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.

**Link**: [text](https://leetcode.com/problems/valid-palindrome-ii/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one starting at the beginning of the string and the other starting at the end of the string. Move both pointers towards the center while comparing characters. If a mismatch is found, you have two options: skip the left character or skip the right character. For each option, check if the resulting substring (after skipping) is a palindrome. If either option results in a palindrome, return true. If neither option works, return false.

**Key Insight:** The key insight is that a string can be a palindrome if at most one character is removed. By using two pointers to compare characters from both ends, you can efficiently identify the first point of mismatch. At that point, you have a choice to skip either the left or right character, and you only need to check the resulting substring for palindrome validity. This allows you to determine if the original string can become a palindrome with at most one deletion.

**Gotchas:** Be careful to correctly implement the logic for checking if the resulting substring is a palindrome after skipping a character. You can create a helper function that takes two pointers and checks if the substring between them is a palindrome. Also, make sure to handle edge cases, such as when the input string is already a palindrome or when it has only one character.

**Complexity:** Time: O(n) where n is the length of the input string (each character is visited at most once by either pointer, and the palindrome check also takes O(n) in the worst case) | Space: O(1) since we are using only a constant amount of extra space

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Valid Palindrome — LC #125 | Strict validation with no error tolerance → simple inward two-pointer scan with no branching on mismatch | Yes — foundational base case |
| Valid Palindrome III — LC #1216 (Premium) | Allowed to delete up to $K$ characters instead of just 1 → scales branching to a 2D Dynamic Programming table or memoized recursion | Yes — the exact $K$-depth scaling of this pattern |
| Valid Palindrome IV — LC #2330 (Premium) | Allowed to *change* up to 2 characters instead of deleting them → track a modification count during a strict inward scan without branching | Partial — same budget tracking but simpler index progression |
| Minimum Insertion Steps to Make a String Palindrome — LC #1312 | Find minimum insertions (equivalent to minimum deletions) to force a palindrome → full optimization over all pairs via Longest Palindromic Subsequence (LPS) DP | Partial — transitions from greedy tracking to global DP alignment |
| Longest Palindromic Subsequence — LC #516 | Find length of longest non-contiguous palindromic character set → 2D DP processing outer boundaries inward | Partial — uses the same outer-to-inner structural subproblems |

**How this pattern scales:**
- **Greedy prefix/suffix stripping combined with one-time branching O(1) space** is the optimal strategy for single-fault tolerance. You step inward greedily as long as characters match. The moment a mismatch occurs (`s[l] != s[r]`), you branch into two independent sub-problems: check if the remaining substring is a palindrome by skipping the left character (`l + 1` to `r`), or by skipping the right character (`l` to `r - 1`).
- **Branching factor scales exponentially to $K$-deletions**. When the allowance scales from 1 deletion to $K$ deletions, a pure greedy decision tree scales to $O(2^K \cdot N)$ via recursion. You maintain a `budget` variable; each mismatch decrements the budget and spawns two branches. If the budget drops below 0, that branch terminates as false.
- **Dynamic Programming collapses the search space when $K$ is large**. If $K$ approaches $N$, the recursive branching tree becomes too redundant. The pattern scales by converting the two-pointer state variables `(l, r)` into a 2D DP table `dp[i][j]`, which tracks the minimum deletions required to make the substring `s[i...j]` a palindrome. The state transition is defined as: 
  $$\text{if } s[i] == s[j]: dp[i][j] = dp[i+1][j-1]$$
  $$\text{else}: dp[i][j] = 1 + \min(dp[i+1][j], dp[i][j-1])$$
- **State-space reduction before branching generalizes** → Even when forced to use an $O(N^2)$ DP or an expensive recursive strategy for edit-distance style problems, you should always use the two-pointer technique to strip identical prefix/suffix characters first. Reducing the string length to only the "inner conflict zone" dramatically optimizes real-world execution time and minimizes memory overhead.

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
             if(s[left] != s[right]){
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1); //if the characters at left and right are not the same, we can check if by skipping the letter on the left or right we can get a palindrome. If either of those is true, return true. If not, return false.
             }
             left++;
             right--;
        }
        return true;
    }
    bool isPalindrome(string& s, int left, int right){ //make helper so can run this function within the main function for when deletion has to take place
        while(left < right){
             if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
        }
        return true;
    }
                 /*
s = "abcbxa"  (needs one skip)

Main loop:

left=0, right=5 → 'a' == 'a' ✓ → left=1, right=4
left=1, right=4 → 'b' == 'x' ✗ → mismatch!

Now we check two substrings:

isPalindrome(s, 2, 4) — skip left, check "cbx"

left=2, right=4 → 'c' == 'x' ✗ → return false

isPalindrome(s, 1, 3) — skip right, check "bcb"

left=1, right=3 → 'b' == 'b' ✓ → left=2, right=2
left=2, right=2 → loop ends
return true
             */
};
```

## Boats to Save People LC 881

<!-- notecardId: 1780425476512 -->

You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 104
1 <= people[i] <= limit <= 3 * 104

**Link**: [text](https://leetcode.com/problems/boats-to-save-people/)

%

**Pattern:** Two Pointers

**Approach:** Sort the array of people by weight. Use two pointers, one starting at the beginning of the array (lightest person) and the other starting at the end of the array (heaviest person). If the sum of the weights of the two people at these pointers is less than or equal to the limit, it means they can share a boat, so move both pointers inward. If the sum exceeds the limit, it means the heavier person must go alone, so move only the right pointer inward. In either case, increment the boat count. Continue this process until all people have been assigned to boats.

**Key Insight:** The key insight is that to minimize the number of boats, you should always try to pair the heaviest person with the lightest person. If they can share a boat, you save space for another person. If they cannot share a boat, the heaviest person must go alone, and you can still try to pair the next heaviest person with the lightest remaining person. This greedy approach works because sorting ensures that you are always making the optimal pairing decisions.

**Gotchas:** Be careful to sort the array of people before applying the two-pointer technique. Also, make sure to correctly handle the case where the sum of the weights at the two pointers is exactly equal to the limit, as this means they can share a boat. The condition for moving the pointers should be based on whether the sum is less than or equal to the limit.

**Complexity:** Time: O(n log n) due to the sorting step, where n is the number of people | Space: O(1) if the sorting is done in-place, otherwise O(n) for the sorting algorithm's space complexity

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Minimize Maximum Pair Sum in Array — LC #1877 | Perfect pairs required for all elements → sort and strictly pair index $i$ with $n-1-i$ without any solo exceptions or condition-skipping | Yes — identical strict extreme-pairing logic |
| Assign Cookies — LC #455 | Two distinct sorted arrays (children and cookies) → move both pointers forward in the same direction to maximize matches | Partial — greedy matching but uses parallel forward pointers instead of inward boundaries |
| Bag of Tokens — LC #948 | Trade tokens for score (loss of power) or power (loss of score) → sort tokens, consume smallest to gain score, redeem largest to gain power | Yes — greedy boundary exploitation using two pointers |
| Two Sum II - Input Array Is Sorted — LC #167 | Find exact pair matching a target sum → step inward from boundaries based on whether the current sum is too low or too high | Yes — boundary convergence dictated by a capacity limit |
| Capacity To Ship Packages Within D Days — LC #1011 | Pack items into ships but order *cannot* be changed → cannot sort; requires Binary Search on the answer combined with a greedy simulation | No — lack of sorting breaks the two-pointer extreme pairing |

**How this pattern scales:**
- **Greedy extreme pairing via sorting O(n log n)** is the optimal strategy for matching problems within a single collection where capacity limits apply. Sorting exposes a monotonic relationship: the largest element is always your primary bottleneck. Attempting to pair the absolute largest element (`right`) with the absolute smallest element (`left`) guarantees the most efficient utilization of space. If they cannot fit together, the largest element is completely unpairable and must be processed alone.
- **Dimensional constraints dictate algorithmic complexity**. The "at most 2 items per container" constraint is the secret pivot that allows an $O(n \log n)$ greedy approach to yield a mathematically perfect solution. If this constraint scales up to allow 3 or more items, or arbitrary numbers of items per container, the problem transforms into the classic **Bin Packing Problem**, which is NP-hard and requires Backtracking, 2D Dynamic Programming, or heuristic approximations.
- **Inward Convergence vs. Parallel Forward Scanning**. This pattern highlights the two main branches of two-pointer greedy matching:
  1. *Inward Convergence (LC #881, LC #167):* Pointers start at opposite ends of a single sorted array to balance trade-offs between the largest and smallest elements.
  2. *Parallel Forward Scanning (LC #455, LC #88):* Pointers start at index 0 of two independent sorted arrays and move concurrently in the same direction to align complementary data sets.
- **Bottleneck Elimination generalizes** → This framework extends to any resource-allocation problem where you must satisfy a set of demands. By constantly pairing the most constrained demand (the heaviest weight, the highest cost) with the least constrained resource (the lightest weight, the lowest cost), you either solve the bottleneck efficiently or isolate it instantly, monotonically reducing the remaining problem size step by step.

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCt= 0;
        sort(people.begin(), people.end());
        int boatPtr1 = 0; //this can be the first member of the boat
        int boatPtr2 = people.size() - 1; //if below the limit, check the second to see if can be added in the boat
        while(boatPtr1 <= boatPtr2){
            if(people[boatPtr1] + people[boatPtr2] <= limit){
//                 Greedy logic: Always try to pair the heaviest person with the lightest.

                // If they fit together → both board, both pointers move inward
                // If they don't fit → heavy person goes alone, only heavy moves inward
                boatPtr1++; //The heaviest person is the hardest to pair. 
                //The best possible partner for them is the lightest person. 
                //If even the lightest person can't pair with them, nobody can — so they take a boat alone.
            }
            boatPtr2--;
            boatCt++;
        }
        return boatCt;

    }
};
```

## Merge Strings Alternately LC 1768

<!-- notecardId: 1780426039574 -->

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

**Link**: [text](https://leetcode.com/problems/merge-strings-alternately/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers, one for each string, to iterate through both strings simultaneously. At each step, append the character from the first string (if available) and then the character from the second string (if available) to the result string. Continue this process until you have iterated through both strings completely.

**Key Insight:** The key insight is that you can merge two strings by iterating through them in parallel using two pointers. By checking the bounds of each string at every step, you can ensure that you only append characters that exist, and you can handle cases where the strings are of different lengths seamlessly.

**Gotchas:** Be careful to check the bounds of both strings at each step to avoid out-of-range errors. You should also ensure that you append characters in the correct order (first from `word1`, then from `word2`) and handle the case where one string is longer than the other by appending the remaining characters after one pointer has reached the end.

**Complexity:** Time: O(n + m) where n and m are the lengths of the two input strings | Space: O(n + m) for the resulting merged string

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Merge Sorted Array — LC #88 | Elements must be merged in sorted order from two arrays → advance the pointer with the smaller value, writing from back to front | Partial — same parallel pointer traversal but with conditional logic |
| Merge Two Sorted Lists — LC #21 | Linked list inputs merged by sorted value → traverse both lists forward, altering node pointers to link the smaller node next | Partial — parallel list traversal rather than uniform alternation |
| Zip Strings — (Common Interview Variation) | Alternating characters but can truncate instead of appending leftovers → terminate the loop early when the first string runs out | Yes — identical interleave mechanism |
| String Compression — LC #443 | Compress consecutive repeating characters in-place → use a read pointer and a write pointer moving at different speeds across a single string | No — different pointer mechanics (Fast/Slow vs. Parallel) |

**How this pattern scales:**
- **Two-pointer parallel synchronized scan O(n + m) time** is the optimal strategy for merging or interleaving two independent sequences. By managing an independent pointer for each string (`p1` and `p2`), you read elements forward step-by-step. This structural template decouples the progression of the data streams, enabling uniform processing regardless of differences in the lengths of the inputs.
- **Uniform alternation vs. Conditional progression**. The pattern scales based on what drives the pointer increments:
  1. *Structural Alternation (LC #1768):* The pointers move forward in a strict, predictable round-robin turn-taking pattern (`p1`, then `p2`, then `p1`...) until a boundary condition is met.
  2. *Value-Driven Progression (LC #88, LC #21):* The pointers compete. At each step, a conditional evaluation (`if (word1[p1] < word2[p2])`) decides which single pointer is permitted to advance.
- **Exhaustion phase handling for asymmetric datasets**. When linear inputs vary in length, the primary synchronized loop inevitably breaks when the shorter stream is completely exhausted. The pattern scales by implementing a clean cleanup strategy: you drop out of the interleaved phase and use bulk operations or independent secondary loops to append the remaining trailing segment of the longer collection in a single action.
- **Stream interleaving generalizes** → This basic pattern serves as the foundation for complex multi-stream processing pipelines. Whether you are multiplexing network packets from different channels, zipping columns together in a tabular data framework, or blending audio tracks, tracking independent read cursors across separate data buffers allows you to stitch information together linearly without wasting memory on intermediate storage structures.

```cpp
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string result = "";
            while (i < word1.size() || i < word2.size()) {
        if (i < word1.size()) result += word1[i];
        if (i < word2.size()) result += word2[i];
        i++;
    }
    return result;
//     int ptr1 = 0;
// int ptr2 = 0;
//         string result = "";
// while(ptr1 < word1.size() && ptr2 < word2.size()){
// result += word1[ptr1];
// result += word2[ptr2];
// ptr1++;
// ptr2++;
//         }
// if(ptr1 == word1.size() && ptr2 < word2.size()){
// while(ptr2 < word2.size()){
// result += word2[ptr2];
// ptr2++;
//         }
//         }
// else if(ptr1 < word1.size() && ptr2 == word2.size()){
// while(ptr1 < word1.size()){
// result += word1[ptr1];
// ptr1++;
//         }
//         }
// else{
// return result;
//         }
// return result;
//     }
    }
};
```
## Longest Substring without Repeating Characters LC 3

<!-- notecardId: 1780455896415 -->

Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

**Link**: [text](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use a sliding window approach with two pointers to maintain a window of characters that contains no duplicates. Start both pointers at the beginning of the string. Move the right pointer to expand the window and add characters to a hash set to track which characters are currently in the window. If you encounter a duplicate character, move the left pointer to shrink the window until the duplicate character is removed from the set. Keep track of the maximum length of the window at each step.

**Key Insight:** The key insight is that you can maintain a dynamic window of unique characters by using two pointers and a hash set. The right pointer expands the window by adding new characters, while the left pointer contracts the window when a duplicate is found. This allows you to efficiently find the longest substring without repeating characters in linear time.

**Gotchas:** Be careful to update the maximum length of the substring at each step after moving the right pointer. Also, make sure to remove characters from the hash set when moving the left pointer to ensure that it accurately reflects the current window of unique characters. Also, at the end, you have to check of the final substring mader by the right pointer is the longest one, since the loop only checks for the longest substring when a duplicate is found, but the longest substring could be at the end of the string and not have a duplicate after it.

**Complexity:** Time: O(n) where n is the length of the input string (each character is visited at most twice by the left and right pointers) | Space: O(min(m, n)) where m is the size of the character set and n is the length of the string (the hash set can grow up to the size of the longest substring without duplicates)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Longest Substring with At Most Two Distinct Characters — LC #159 | Allow up to 2 distinct chars → same sliding window shrink when distinct count exceeds 2 | Yes — direct upgrade |
| Longest Substring with At Most K Distinct Characters — LC #340 | Allow up to k distinct chars → same window shrink when distinct count exceeds k | Yes — direct generalization |
| Minimum Window Substring — LC #76 | Smallest window containing all target chars → same sliding window different shrink condition | Yes — same pattern |
| Find All Anagrams in String — LC #438 | Fixed size window matching char frequency → same hash map window but fixed size | Yes — same pattern |
| Permutation in String — LC #567 | Check if any permutation exists in string → same fixed size frequency window | Yes — direct variant |
| Longest Repeating Character Replacement — LC #424 | Replace up to k chars to maximize repeating window → sliding window with max freq tracking | Yes — upgrade |
| Fruit Into Baskets — LC #904 | At most 2 distinct values in subarray → exact restatement of LC #159 | Yes — disguised variant |
| Substring with Concatenation of All Words — LC #30 | Window must contain all words exactly once → same sliding window with word frequency map | Partial — harder variant |

**How this pattern scales:**
- **Sliding window + hash map** is the core trick — expand right pointer always, shrink left pointer when a duplicate is found by moving left past the last occurrence of the duplicate character. O(n) time O(min(n,m)) space where m is charset size
- **Jump optimization** — instead of moving left one step at a time store the last seen index of each character and jump left directly to `lastSeen[char] + 1`. Reduces constant factor significantly for large windows
- **At most k distinct generalization** → LC #159 and LC #340 replace the "no duplicates" condition with "at most k distinct characters." Same window expand/shrink skeleton, just change the shrink condition from duplicate detected to `distinctCount > k`
- **Sliding window decision tree** → fixed size window (LC #438, #567) vs variable size window (LC #3, #76). Fixed size slides one step at a time. Variable size expands greedily and shrinks until valid. LC #3 is the cleanest variable size example to learn first

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int longest = 0;
        int leftW = 0;
        //int currLongest= 0;
        for(int i = 0; i < s.size(); i++){
            if(seen.find(s[i]) != seen.end() && seen[s[i]] >= leftW){ //alr seen that element before, seen after leftWindow marker
                longest = max(longest, i - leftW); //update longest before moving leftW, because current longest is from leftW to i, so length is i - leftW
                leftW = seen[s[i]] + 1; //move leftW to the right of the last seen index of the current character, start a new substring that doesnt include repeated char
                //clean optimization instead of having to iterate until you find the repeat
            }
           seen[s[i]] = i; //update the last seen index of the current character
        }
        return max(longest, (int)s.size() - leftW); //after loop, check if the longest substring is from leftW to the end of the string, if so, update longest accordingly
        //This is necessary because if the longest substring is at the end of the string, it would not have been update in the loop since the loop only updates longest when a repeat is found, 
        //and if the longest substring is at the end, there would be no repeat to trigger the update.

    }
};
```

## Minimum Window Substring LC 76

<!-- notecardId: 1780456914376 -->

Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

**Link**: [text](https://leetcode.com/problems/minimum-window-substring/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use a sliding window approach with two pointers to maintain a window of characters in string `s` that contains all characters of string `t`. Create a frequency map for the characters in `t` to keep track of how many of each character you need. Move the right pointer to expand the window and update the frequency map accordingly. When the window contains all characters of `t`, move the left pointer to shrink the window while still maintaining all required characters. Keep track of the minimum length of such a window throughout the process.

**Key Insight:** The key insight is that you can use a sliding window to efficiently find the minimum substring that contains all characters of another string. By maintaining a frequency map and two pointers, you can expand and contract the window dynamically based on whether it currently satisfies the condition of containing all required characters. This allows you to find the optimal solution in linear time.

**Gotchas:** Be careful to correctly update the frequency map when moving the right pointer to expand the window and when moving the left pointer to shrink the window. You should also ensure that you only update the minimum length of the window when it currently contains all required characters. Additionally, make sure to handle edge cases, such as when `t` is longer than `s` or when there are no valid windows. If there is a successful substring, and then you shift left and the substring doesnt satisfy the condition anymore, your formed counter will have to recrement, the left pointer will have to increment, and your right pointer will have to keep moving until you find a new valid substring, and then you can update the minimum length again.

**Complexity:** Time: O(m + n) where m is the length of string `s` and n is the length of string `t` (each character in `s` is visited at most twice by the left and right pointers, and building the frequency map for `t` takes O(n)) | Space: O(m + n) for the frequency maps and the resulting substring

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Longest Substring Without Repeating Characters — LC #3 | Variable window no duplicate constraint → same expand/shrink skeleton simpler condition | Yes — foundation |
| Find All Anagrams in String — LC #438 | Fixed size window exact frequency match → same hash map window fixed not variable | Yes — same pattern |
| Permutation in String — LC #567 | Check if any permutation exists → same fixed size frequency window | Yes — direct variant |
| Longest Substring with At Most K Distinct — LC #340 | At most k distinct chars → same window shrink when distinct count exceeds k | Yes — same family |
| Minimum Size Subarray Sum — LC #209 | Minimum length subarray summing to target → same shrink when valid simpler condition | Yes — same structure |
| Substring with Concatenation of All Words — LC #30 | Window must contain all words exactly once → same frequency map but word level | Partial — harder variant |
| Sliding Window Maximum — LC #239 | Maximum value in fixed size window → monotonic deque not frequency map | No — different pattern |
| Minimum Window Subsequence — LC #727 | Target must appear as subsequence not substring → two pointer not sliding window | Partial — harder variant |

**How this pattern scales:**
- **Have/need counters** is the core trick — maintain a `need` map of required character frequencies and a `have` counter of how many characters are currently satisfied. Expand right always, shrink left when `have == need` recording minimum window each time. O(n) time O(m) space where m is charset size
- **Satisfied character tracking** — only increment `have` when a character's frequency in the window exactly meets its required frequency. Only decrement `have` when shrinking causes a character to drop below its required frequency. This avoids recounting the entire map on every window change
- **Template for all variable window problems** → LC #76 is the hardest and most general variable window problem. Every simpler sliding window problem (LC #3, #209, #340) is a special case with a simpler validity condition. Mastering LC #76's have/need framework means all simpler variants are trivially derived
- **Fixed vs variable window** → when the target length is known use a fixed window (LC #438, #567). When the target length is unknown use variable window with expand/shrink (LC #76, #3). This distinction determines the entire approach before writing a single line

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> charFreq; //store t character frequency
        unordered_map<char, int> windowFreq; //store current window character frequency
        for(int i = 0; i < t.size(); i++){
            charFreq[t[i]]++;
        }
        int left = 0;
        int right = 0;
        int minStart; //starting index of the minimum window found so far
        int minLength = INT_MAX;
        int required = charFreq.size();
        int formed = 0; //number of unique characters in the current window that match the required frequency in t

        while(right < s.size()){
            char c = s[right]; //add character at right pointer to the window
            windowFreq[c]++;


            if(charFreq.count(c) && windowFreq[c] == charFreq[c]){ //if character is in t and frequency is equal, formed can be incrememented, because we have one more character that matches the required frequency in t
                formed++;
            }
            while(left <= right && formed == required){ //this is here, we want to shrink window as much as possible, while still maintaining the condition that all required characters are present in the window with the correct frequency
                if(right - left + 1 < minLength){ //if current window smaller than minLength, update minLength and minStart
                    minLength = right - left + 1;
                    minStart = left;
                }

            char leftChar = s[left]; //remove character at left pointer from the window
            windowFreq[leftChar]--; 
            if(charFreq.count(leftChar) && windowFreq[leftChar] < charFreq[leftChar]){
                formed--; //since frequency of leftChar in the window is now less than the required frequency in t, we decrement formed, because we no longer have all required characters with the correct frequency in the window
            }
            left++;  //move left pointer to the right to shrink the window
            }
            right++; //move right pointer to the right to expand the window
        }
        return minLength == INT_MAX ? "": s.substr(minStart, minLength);
    }
};
```

## Best Time to Buy and Sell Stock LC 121

<!-- notecardId: 1780457297500 -->

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

**Link**: [text](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use two pointers to represent the buying day and the selling day. Initialize the buying pointer at the first day and the selling pointer at the second day. Iterate through the array of prices, updating the buying pointer to the lowest price seen so far and calculating the profit if you were to sell on the current day. Keep track of the maximum profit encountered during this process.

**Key Insight:** The key insight is that to maximize profit, you want to buy at the lowest price and sell at the highest price that comes after it. By using two pointers, you can efficiently track the minimum price (buying day) and calculate potential profits as you iterate through the prices. This allows you to find the maximum profit in a single pass through the array.

**Gotchas:** Be careful to update the buying pointer only when you find a new minimum price. When calculating profit, always use the current price as the selling price and the minimum price found so far as the buying price. Also, ensure that you return 0 if no profit can be made (i.e., if the prices are in descending order).

**Complexity:** Time: O(n) where n is the length of the input array (each price is visited once) | Space: O(1) for the variables used to track minimum price and maximum profit

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Best Time to Buy and Sell Stock II — LC #122 | Unlimited transactions → greedy accumulate every positive difference | Partial — upgrade |
| Best Time to Buy and Sell Stock III — LC #123 | At most two transactions → DP with two buy/sell state pairs | Partial — harder upgrade |
| Best Time to Buy and Sell Stock IV — LC #188 | At most k transactions → generalized DP with k state pairs | Partial — hardest upgrade |
| Best Time to Buy and Sell Stock with Cooldown — LC #309 | Must wait one day after selling → DP with cooldown state | Partial — constraint added |
| Best Time to Buy and Sell Stock with Fee — LC #714 | Pay fee per transaction → same greedy as LC #122 subtract fee on sell | Partial — direct variant |
| Maximum Subarray — LC #53 | Maximum sum contiguous subarray → Kadane's mirrors min tracking logic | Yes — same structure |
| Maximum Profit in Job Scheduling — LC #1235 | Schedule non overlapping jobs for max profit → DP + binary search | No — different pattern |
| Jump Game — LC #55 | Greedy decision at each step → same single pass scan different condition | Partial — same greedy family |

**How this pattern scales:**
- **Track running minimum** is the core trick — single pass, maintain the minimum price seen so far, compute profit at each step as `price - minSoFar`, track global maximum profit. O(n) time O(1) space
- **Kadane's algorithm connection** → Maximum Subarray (LC #53) is structurally identical — convert prices to daily differences `diff[i] = prices[i] - prices[i-1]`, then maximum subarray sum on differences equals maximum profit. Both problems reduce to the same running min/max tracking
- **Stock problem ladder** → LC #121 → LC #122 → LC #309 → LC #714 → LC #123 → LC #188 — each adds one constraint forcing progressively more complex state tracking. LC #121 is the only one where greedy with a single variable suffices
- **DP state design for harder variants** → LC #123 and LC #188 require explicit state machines. For k transactions define states `hold[i]` and `cash[i]` for each transaction count. LC #121 is the degenerate case with k=1 where the state machine collapses to a single running minimum

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyTime = 0;
        int sellTime = 1;
        int maxProfit = 0;
        for(; sellTime < prices.size(); sellTime++){
            if(prices[buyTime] < prices[sellTime]){
                maxProfit = max(maxProfit, prices[sellTime] - prices[buyTime]); //if price at buy is less than sell, then profit could be made, check if it is the biggest so far
            }
            else{
                buyTime = sellTime; //found a cheaper price, so this becomes the new buy price
            }
        }
        return maxProfit;
    }
};
```

## Minimum Size Subarray Sum LC 209

<!-- notecardId: 1780458451455 -->

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).
 
**Link**: [text](https://leetcode.com/problems/minimum-size-subarray-sum/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use a sliding window approach with two pointers to maintain a window of contiguous elements in the array. Start both pointers at the beginning of the array and keep expanding the right pointer to increase the sum of the current window. When the sum of the window is greater than or equal to the target, move the left pointer to shrink the window while still maintaining the condition. Keep track of the minimum length of such a window throughout the process.

**Key Insight:** The key insight is that you can use a sliding window to efficiently find the minimum length of a contiguous subarray that meets a certain sum condition. By maintaining a running sum of the current window and adjusting the left and right pointers accordingly, you can find the optimal solution in linear time.

**Gotchas:** Be careful to update the minimum length of the subarray at each step after moving the right pointer. Also, make sure to handle edge cases, such as when there is no valid subarray that meets the condition. If there is a valid subarray, and then you shift left and the sum of the subarray doesnt satisfy the condition anymore, your left pointer will have to keep moving until you find a new valid subarray, and then you can update the minimum length again.

**Complexity:** Time: O(n) where n is the length of the input array (each element is visited at most twice by the left and right pointers) | Space: O(1) for the variables used to track the current sum and minimum length

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Minimum Window Substring — LC #76 | Minimum window containing all target chars → same shrink when valid framework | Yes — direct generalization |
| Longest Substring Without Repeating Characters — LC #3 | Maximum window with no duplicates → same expand/shrink different condition | Yes — same family |
| Subarray Sum Equals K — LC #560 | Exact sum not minimum length → prefix sum + hash map, negatives allowed | Partial — different approach |
| Maximum Size Subarray Sum Equals K — LC #325 | Maximum length subarray summing to k → prefix sum + hash map | Partial — inverse problem |
| Fruit Into Baskets — LC #904 | Minimum window with at most 2 distinct → same shrink when invalid pattern | Yes — same structure |
| Maximum Average Subarray I — LC #643 | Fixed size window maximum average → fixed not variable window | Partial — same window family |
| Count Number of Nice Subarrays — LC #1248 | Count subarrays with exactly k odd numbers → prefix sum + hash map | No — different pattern |
| Minimum Operations to Reduce X to Zero — LC #1658 | Minimum elements from ends summing to x → inverse sliding window max middle | Yes — disguised variant |

**How this pattern scales:**
- **Shrink when valid** is the core trick — expand right pointer always, shrink left pointer while `windowSum >= target` recording minimum length each time the condition holds. O(n) time O(1) space
- **Positive numbers only limitation** — sliding window works here because all values are positive guaranteeing that shrinking the window reduces the sum. As soon as negatives are introduced shrinking no longer guarantees reduction and prefix sum + hash map becomes necessary
- **Binary search alternative** — build prefix sum array then binary search for the smallest subarray ending at each index with sum >= target. O(n log n) time O(n) space. Worth mentioning as a follow-up showing you know multiple approaches
- **Inverse sliding window** → Minimum Operations to Reduce X (LC #1658) reframes as finding the maximum middle subarray summing to `total - x` — same sliding window but inverted. Recognizing disguised sliding window problems by inverting the objective is a high value interview skill
- **Shrink vs expand decision** → shrink when valid (LC #209) finds minimum windows. Expand until invalid (LC #3, LC #76) finds maximum windows. This distinction determines the entire loop structure before writing a single line

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int leftPtr= 0;
        int total = 0;
        int minLen = INT_MAX;
        for(int i = 0; i< nums.size(); i++){
            total += nums[i];

            while(total >= target){
                minLen = min(minLen, i - leftPtr + 1);
                total -= nums[leftPtr];
                leftPtr++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
```

## Contains Duplicate II LC 219

<!-- notecardId: 1780458948659 -->

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105

**Link**: [text](https://leetcode.com/problems/contains-duplicate-ii/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use a sliding window approach with two pointers to maintain a window of the last `k` elements in the array. Use a hash set to track the unique elements in the current window. As you iterate through the array, add the current element to the set and check if it already exists. If it does, return true. If the size of the set exceeds `k`, remove the element that is sliding out of the window (the left pointer) from the set.

**Key Insight:** The key insight is that you only need to check for duplicates within a window of size `k`. By maintaining a hash set of the last `k` elements, you can efficiently determine if a duplicate exists within that range. This allows you to solve the problem in linear time.

**Gotchas:** Be careful to remove the element that is sliding out of the window from the hash set when the size exceeds `k`. Also, ensure that you are checking for duplicates before adding the current element to the set, as adding it first would always result in a duplicate. Additionally, handle edge cases where `k` is 0 or when the array has fewer than 2 elements.

**Complexity:** Time: O(n) where n is the length of the input array (each element is visited once) | Space: O(min(n, k)) for the hash set storing the last `k` elements

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Contains Duplicate — LC #217 | Just check existence no distance constraint → hash set no window needed | Yes — foundation |
| Contains Duplicate III — LC #220 | Duplicate within k indices AND value diff ≤ t → sorted set bucket sort | Partial — harder upgrade |
| Longest Substring Without Repeating Characters — LC #3 | Maximum window with no duplicates → same sliding window hash map | Yes — same pattern |
| Two Sum — LC #1 | Find two indices summing to target → hash map complement lookup | Partial — same hash map idea |
| Find the Duplicate Number — LC #287 | One duplicate no index constraint → Floyd's cycle detection or index marking | No — different pattern |
| Subarray Product Less Than K — LC #713 | Product constraint on window → same sliding window different condition | Yes — same window family |
| Number of Sub-arrays of Size K and Average ≥ Threshold — LC #1343 | Fixed size window average check → fixed not variable window | Partial — same window family |
| Sliding Window Maximum — LC #239 | Maximum value in fixed size window → monotonic deque not hash map | No — different pattern |

**How this pattern scales:**
- **Sliding window + hash map** is the core trick — maintain a window of size at most k using a hash map. For each new element check if it already exists in the map. If yes return true. If no add it and remove the element leaving the window when size exceeds k. O(n) time O(k) space
- **Hash set suffices here** — unlike LC #1 which needs to store indices, LC #219 only needs to know if a value exists within the current window. A hash set of size k is cleaner than a full hash map for this reason
- **Fixed window sliding** — the window slides exactly one step at a time making this a fixed size window problem disguised as a variable window. Add new element check condition remove oldest element. This fixed slide pattern is simpler than the expand/shrink pattern of LC #3 and LC #76
- **Upgrade to LC #220** → Contains Duplicate III adds a value difference constraint `|nums[i] - nums[j]| <= t` on top of the index constraint. Hash set no longer works because you need to find values within a range — use a sorted set (C++ `std::set`) with `lower_bound` or bucket sort with bucket size t+1
- **Contains Duplicate ladder** → LC #217 → LC #219 → LC #220 — each adds one constraint. LC #217 checks existence, LC #219 adds index distance, LC #220 adds value distance. Each constraint forces a more sophisticated data structure

```cpp

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //main idea, use an unordered set here for O(1) lookup, very cheeky

        unordered_set<int> window;
        for(int i = 0; i < nums.size(); i++){
            if(window.count(nums[i])) return true;

            window.insert(nums[i]);

            if(window.size() > k){
                window.erase(nums[i-k]);
            }
        }
        return false;
    }
};

```

## Sliding Window Maximum LC 239

<!-- notecardId: 1780459385593 -->

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length


**Link**: [text](https://leetcode.com/problems/sliding-window-maximum/)

%

**Pattern:** Sliding Window, Monotonic Queue

**Approach:** Use a deque (double-ended queue) to maintain the indices of the elements in the current window. The deque will store indices in decreasing order of their corresponding values in the array. As you iterate through the array, remove indices from the back of the deque while the current element is greater than or equal to the elements at those indices. This ensures that the front of the deque always contains the index of the maximum element for the current window. When the left pointer moves out of the window, remove its index from the front of the deque if it is present.

**Key Insight:** The key insight is that by maintaining a monotonic decreasing queue of indices, you can efficiently track the maximum element in the current window. The front of the deque will always represent the index of the maximum element, and by removing indices of smaller elements as you iterate, you ensure that the deque remains valid for each window.

**Gotchas:** Be careful to remove indices from the back of the deque when the current element is greater than or equal to the elements at those indices. Also, ensure that you remove the index of the left pointer from the front of the deque when it moves out of the window. Additionally, handle edge cases where `k` is 1 or when the array has only one element.

**Complexity:** Time: O(n) where n is the length of the input array (each element is added and removed from the deque at most once) | Space: O(k) for the deque storing indices of the current window

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Sliding Window Minimum — LC variant | Track minimum instead of maximum → same monotonic deque flip comparison | Yes — direct variant |
| Min Stack — LC #155 | Track running minimum with O(1) access → same monotonic structure no sliding | Partial — same tracking idea |
| Contains Duplicate II — LC #219 | Fixed window duplicate check → hash set window no deque needed | Partial — same window family |
| Minimum Window Substring — LC #76 | Variable window all chars present → frequency map not monotonic deque | No — different pattern |
| Jump Game VI — LC #1696 | Maximum score path with window constraint → same monotonic deque DP optimization | Yes — direct generalization |
| Longest Continuous Subarray With Absolute Diff ≤ Limit — LC #1438 | Track both max and min in window → two monotonic deques simultaneously | Yes — direct upgrade |
| Maximum Number of Robots Within Budget — LC #2398 | Sliding window with max cost constraint → same monotonic deque for window max | Yes — same pattern |
| Stock Price Fluctuation — LC #2034 | Track min and max of streaming prices → sorted set not deque | Partial — same min/max tracking |

**How this pattern scales:**
- **Monotonic decreasing deque** is the core trick — maintain a deque of indices in decreasing order of their values. For each new element pop from the back while the back element is smaller than the current element. Pop from the front when the front index falls outside the window. Front of deque is always the current window maximum. O(n) time O(k) space
- **Deque stores indices not values** — storing indices is what allows checking if the front element has left the window in O(1). Storing values loses position information making expiry detection impossible
- **Monotonic deque vs monotonic stack** → stack handles "next greater element" problems where elements only enter from one end. Deque handles sliding window problems where elements expire from the front — use deque whenever the window slides and old elements must be evicted
- **DP optimization pattern** → Jump Game VI (LC #1696) uses the exact same monotonic deque to optimize a DP transition — instead of scanning all previous k states in O(k) the deque maintains the maximum in O(1). Any DP with a sliding window maximum transition can be optimized this way
- **Two deque upgrade** → Longest Continuous Subarray With Absolute Diff ≤ Limit (LC #1438) maintains two monotonic deques simultaneously — one for max one for min — shrinking the window when `max - min > limit`. Same deque operations, doubled structure

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //this is a deque problem, because maintain max value while being able to remove from front and back of deque
        deque<int> window;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(!window.empty() && window.front() <= i - k){
                window.pop_front(); //if index at front of the deque is out of the window  (i - k), remove from deque
            }
            while(!window.empty() && nums[window.back()] < nums[i]){
                window.pop_back(); //if current number is greater than the number at the back of the deque, remove the back of the deque, because it can never be the maximum if there is a greater number in the window
            }
            window.push_back(i); //store the index within the deque
            if(i >= k - 1){
                result.push_back(nums[window.front()]); //store the actual value within the answer vector
            }
        }
        return result;
    }
};
```

## Longest Repeating Character Replacement LC 424

<!-- notecardId: 1780459933679 -->

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

**Link**: [text](https://leetcode.com/problems/longest-repeating-character-replacement/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use a sliding window approach with two pointers to maintain a window of characters in the string. Keep track of the frequency of each character in the current window using a hash map. The key insight is that the length of the longest valid substring can be determined by the formula: `windowLength - maxFreq <= k`, where `maxFreq` is the count of the most frequent character in the current window. If this condition is satisfied, it means we can replace at most `k` characters to make all characters in the window the same. Expand the right pointer to increase the window size and update the frequency map. If the condition is not satisfied, move the left pointer to shrink the window until it becomes valid again.

**Key Insight:** The key insight is that the number of characters that need to be replaced to make all characters in the window the same is equal to the length of the window minus the count of the most frequent character. By maintaining this count and ensuring it does not exceed `k`, you can efficiently find the longest valid substring.

**Gotchas:** Be careful to update the frequency map correctly when expanding and shrinking the window. Also, ensure that you are calculating the maximum frequency of any character in the current window at each step, as this is crucial for determining whether the window is valid. Additionally, handle edge cases where `k` is 0 or when the string has only one character. Something to keep in mind is that when shifting the left pointer, maxFrequency is not decremented, because the window can still be valid even if the count of the most frequent character decreases, as long as the condition `windowLength - maxFreq <= k` is still satisfied.

**Complexity:** Time: O(n) where n is the length of the input string (each character is visited at most twice by the left and right pointers) | Space: O(1) for the frequency map since there are only 26 uppercase English letters

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Longest Substring Without Repeating Characters — LC #3 | No replacements allowed → same sliding window simpler shrink condition | Yes — foundation |
| Minimum Window Substring — LC #76 | Minimum window containing target chars → same frequency map different shrink condition | Yes — same pattern |
| Max Consecutive Ones III — LC #1004 | Flip at most k zeros in binary array → same window shrink when zeros exceed k | Yes — direct variant |
| Longest Subarray of 1s After Deleting One Element — LC #1493 | Delete exactly one element → same window with one zero allowed | Yes — close variant |
| Longest Substring with At Most K Distinct — LC #340 | At most k distinct chars → same window shrink when distinct count exceeds k | Yes — same family |
| Minimum Number of Operations to Make Array Continuous — LC #2009 | Make array continuous with minimum replacements → sort + sliding window | Partial — same replacement idea |
| Permutation in String — LC #567 | Fixed size window exact frequency match → same frequency map fixed window | Partial — same map idea |
| Encode String with Shortest Length — LC #471 | Minimize encoded string length → DP not sliding window | No — different pattern |

**How this pattern scales:**
- **Max frequency tracking** is the core trick — maintain a frequency map of characters in the window and track `maxFreq` (the most frequent character count). Window is valid when `windowSize - maxFreq <= k`. Shrink left when invalid. O(n) time O(1) space since charset is fixed at 26
- **maxFreq never decreases optimization** — a subtle but important insight: `maxFreq` only needs to increase to find a longer valid window. Even if the actual max frequency drops when shrinking you don't need to recompute it — a smaller maxFreq can never produce a longer window than previously seen so shrinking by one step suffices
- **Binary array generalization** → Max Consecutive Ones III (LC #1004) is the exact same problem with a binary alphabet — `maxFreq` is always the count of 1s and k is the number of allowed flips. Same `windowSize - maxFreq <= k` validity condition, different alphabet size
- **Shrink by one insight** — unlike LC #76 which shrinks aggressively until valid, LC #424 only ever shrinks by one step at a time because we only care about finding a longer window than the current best. This means the window size never decreases making the sliding truly monotonic
- **Validity condition** `windowSize - maxFreq <= k` is the core formula to memorize — it captures "how many characters need to be replaced to make the window uniform" in O(1) using just the window size and the dominant character count

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int l = 0;
        int maxFreq = 0;
        int longest = 0;
        for(int i = 0; i < s.size(); i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq, freq[s[i]]);
            while((i - l + 1) - maxFreq > k){ //need to update window, will shrink
            freq[s[l]]--;
            l++;
            }
            longest = max(longest, i - l + 1);
        }
        return longest;
    }
};
```

## Permutation in String LC 567

<!-- notecardId: 1780461196544 -->

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

**Link**: [text](https://leetcode.com/problems/permutation-in-string/)

%

**Pattern:** Sliding Window, Two Pointers

**Approach:** Use a sliding window approach with two pointers to maintain a window of characters in `s2` that is the same length as `s1`. Keep track of the frequency of each character in the current window using a hash map. Compare the frequency map of the current window with the frequency map of `s1`. If they match, it means the current window is a permutation of `s1`, and you can return true. If they do not match, move the right pointer to expand the window and update the frequency map accordingly. When the window size exceeds the length of `s1`, move the left pointer to shrink the window and update the frequency map until it matches again or you exhaust all possibilities.

**Key Insight:** The key insight is that a permutation of `s1` will have the same frequency of characters as `s1`. By maintaining a sliding window of the same length as `s1` and comparing frequency maps, you can efficiently determine if any substring of `s2` is a permutation of `s1`.

**Gotchas:** Be careful to update the frequency map correctly when expanding and shrinking the window. Also, ensure that you are comparing the frequency maps at the right times — only when the window size matches `s1`'s length. Additionally, handle edge cases where `s1` is longer than `s2`, in which case you can immediately return false. At the beginning, start with the first window of size `s1.length()` and compare frequency maps before entering the loop to handle the case where the first window is already a permutation.

**Complexity:** Time: O(n) where n is the length of `s2` (each character is visited at most twice by the left and right pointers) | Space: O(1) for the frequency maps since there are only 26 lowercase English letters

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Find All Anagrams in String — LC #438 | Return all anagram start indices not just boolean → same fixed window collect positions | Yes — direct variant |
| Minimum Window Substring — LC #76 | Minimum variable window containing all chars → same frequency map variable not fixed size | Yes — same pattern |
| Longest Substring Without Repeating Characters — LC #3 | Variable window no duplicates → same sliding window simpler condition | Yes — same family |
| Longest Repeating Character Replacement — LC #424 | Variable window with k replacements → same frequency map different validity condition | Yes — same family |
| Valid Anagram — LC #242 | Check two strings of same length → same frequency map no sliding needed | Yes — foundation |
| Group Anagrams — LC #49 | Group all anagrams together → sorted key or frequency tuple hash map | Partial — same frequency idea |
| Scramble String — LC #87 | Check if string is scrambled version → DP or recursion with memoization | No — different pattern |
| String Permutation — general | Generate all permutations → backtracking not sliding window | No — different pattern |

**How this pattern scales:**
- **Fixed size sliding window + have/need counters** is the core trick — window size is always `len(s1)`. Slide one character at a time, add incoming character on right, remove outgoing character on left, maintain `have` count of satisfied characters. Return true when `have == need`. O(n) time O(1) space since charset fixed at 26
- **Have/need counter optimization** — same framework as LC #76 but simpler since window size is fixed. Only update `have` when a character crosses its required threshold in either direction — increment when frequency hits exactly required, decrement when it drops below
- **Fixed vs variable window decision** — the moment the problem specifies an exact target length (here `len(s1)`) the window is fixed size and slides one step at a time. Variable window expand/shrink is only needed when the target length is unknown
- **LC #567 → LC #438 upgrade** — the only difference is LC #438 collects all valid window start indices instead of returning a boolean on first match. Same fixed window loop, just append `left` to result whenever `have == need` instead of returning immediately
- **Frequency array vs hash map** — since input is lowercase English letters only, a 26-element integer array is faster and cleaner than a hash map. Reduces constant factor significantly and simplifies the have/need counting logic

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> s1char; //character and frequency
                unordered_map<char, int> s2char; //character and frequency

        for(int i = 0; i < s1.size(); i++){s1char[s1[i]]++;}
        for(int i = 0; i < s1.size(); i++){
            s2char[s2[i]]++; //go up until the size of s1, then we will start sliding the window
        }
        if(s1char == s2char){
            return true;
        }

        for(int i = s1.size(); i < s2.size(); i++){
             s2char[s2[i]]++;
             s2char[s2[i - s1.size()]]--;
             if(s2char[s2[i - s1.size()]] == 0){
                s2char.erase(s2[i - s1.size()]);
             }
                     if(s1char == s2char){
            return true;
        }
        }
        return false;

    }
};
```

## Find k Closest Elements LC 658

<!-- notecardId: 1780461360167 -->

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3

Output: [1,2,3,4]

Example 2:

Input: arr = [1,1,2,3,4,5], k = 4, x = -1

Output: [1,1,2,3]

 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104

**Link**: [text](https://leetcode.com/problems/find-k-closest-elements/)

%

**Pattern:** Two Pointers

**Approach:** Use two pointers to maintain a window of size `k` in the sorted array. Start with the left pointer at the beginning of the array and the right pointer at the end of the array. Calculate the distance of the elements at both pointers from `x`. If the element at the left pointer is closer to `x` than the element at the right pointer, move the right pointer inward to shrink the window from the right. Otherwise, move the left pointer inward to shrink the window from the left. Continue this process until the window size is reduced to `k`. The remaining elements in the window will be the `k` closest elements to `x`.

**Key Insight:** The key insight is that since the array is sorted, the closest elements to `x` will be clustered together. By using two pointers to compare the distances of the elements at the edges of the current window, you can efficiently narrow down to the `k` closest elements without needing to sort or calculate distances for all elements.

**Gotchas:** Be careful to handle edge cases where `x` is smaller than all elements in the array or larger than all elements in the array. In these cases, the closest elements will simply be the first `k` or last `k` elements of the array, respectively. Additionally, ensure that you are comparing the absolute distances correctly and that you are moving the pointers in the right direction based on which element is closer to `x`.

**Complexity:** Time: O(n - k) where n is the length of the input array (in the worst case, you may need to move both pointers across the entire array until only `k` elements remain) | Space: O(k) for the output list of closest elements

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| K Closest Points to Origin — LC #973 | Closest points in 2D space → heap or QuickSelect on distance | Partial — same k closest idea |
| Find Closest Value in BST — LC #270 | Single closest value in BST → binary search on tree | Partial — same closest idea |
| Search in Rotated Sorted Array — LC #33 | Binary search with rotation → same binary search different condition | Partial — same binary search family |
| Kth Smallest Element in Sorted Matrix — LC #378 | Kth smallest across sorted matrix → binary search on value or heap | Partial — same k selection |
| Median of Two Sorted Arrays — LC #4 | Median across two sorted arrays → binary search on partition | Partial — same sorted array idea |
| Sliding Window Maximum — LC #239 | Maximum in fixed size window → monotonic deque not binary search | No — different pattern |
| Top K Frequent Elements — LC #347 | K most frequent not closest → hash map + heap or bucket sort | No — different pattern |
| Find K Pairs with Smallest Sums — LC #373 | K smallest pair sums from two arrays → min heap | Partial — same k selection |

**How this pattern scales:**
- **Binary search on left boundary** is the optimal O(log n) trick — instead of searching for x directly binary search for the left boundary of the k-element window. Compare `x - arr[mid]` vs `arr[mid + k] - x` to decide whether the window shifts left or right. Whichever side x is closer to wins
- **Two pointer alternative** is O(n) — start with left at 0 and right at n-1, shrink from the farther side until window size equals k. Easier to derive under pressure but suboptimal for large arrays
- **Comparison formula** `x - arr[mid] <= arr[mid + k] - x` is the key insight to memorize — left side is distance from x to left boundary candidate, right side is distance from x to element just outside window on the right. Less than or equal favors the left to handle ties correctly per problem specification
- **Left boundary binary search generalizes** → any problem asking for a window of fixed size k in a sorted array that optimizes some distance metric uses this same binary search on the left boundary approach. The only thing that changes is the comparison formula
- **Heap alternative** → find x with binary search then use a max heap of size k to collect the k closest elements by distance. O(n log k) time — worse than binary search but easier to adapt when the array is not sorted or distances are more complex

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int start = 0;
        int end = arr.size() - 1;
        while (end - start + 1 > k){
            if(x - arr[start] <= arr[end] - x){
                end--;  // Left is closer or equal → remove right element
            }
            else{
                start++; // Right is closer → remove left element
            }
        }
        return std::vector<int>(arr.begin() + start, arr.begin() + start + k);
    }
};
```
## Median of Two Sorted Arrays LC 4

<!-- notecardId: 1780503031420 -->

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

**Link**: [text](https://leetcode.com/problems/median-of-two-sorted-arrays/)

%

**Pattern:** Binary Search

**Approach:** Use binary search to partition the two sorted arrays such that the left partition contains the same number of elements as the right partition (or one more if the total number of elements is odd). The key is to find the correct partition point in both arrays where all elements in the left partitions are less than or equal to all elements in the right partitions. Once the correct partition is found, the median can be calculated based on the maximum of the left partitions and the minimum of the right partitions.

**Key Insight:** The key insight is that the median can be found by partitioning the two arrays into two halves. By using binary search on the smaller array, you can efficiently find the correct partition point that satisfies the conditions for the median. This approach avoids the need to merge the arrays and allows you to find the median in logarithmic time.

**Gotchas:** Be careful to handle edge cases where one of the arrays is empty. In such cases, the median will simply be the median of the non-empty array. Additionally, ensure that you are correctly calculating the maximum of the left partitions and the minimum of the right partitions, especially when the total number of elements is odd. Also, remember to always perform binary search on the smaller array to maintain the O(log(min(m,n))) time complexity. nums1 always has to be the shorter array to ensure that the binary search is performed on the smaller array, which guarantees the logarithmic time complexity.

**Complexity:** Time: O(log(min(m, n))) where m and n are the lengths of the two input arrays (binary search is performed on the smaller array) | Space: O(1) for the variables used to store partition indices and median values

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Find K Closest Elements — LC #658 | Binary search on window boundary in one sorted array → same partition idea simpler | Partial — same binary search family |
| Kth Smallest Element in Sorted Matrix — LC #378 | Kth smallest across sorted matrix rows → binary search on value not partition | Partial — same kth element idea |
| Find K-th Smallest Pair Distance — LC #719 | Kth smallest distance between pairs → binary search on answer + sliding window | Partial — same binary search on answer |
| Split Array Largest Sum — LC #410 | Minimize largest subarray sum → binary search on answer + greedy validation | Partial — same binary search on answer |
| Median of a Data Stream — LC #295 | Median updates dynamically → two heaps not binary search | No — different pattern |
| Search in Rotated Sorted Array — LC #33 | Binary search with rotation constraint → same binary search different condition | Partial — same binary search family |
| Kth Largest Element in Array — LC #215 | Kth largest in unsorted array → QuickSelect or heap | No — different pattern |
| Merge k Sorted Lists — LC #23 | Merge not find median → heap or divide and conquer | No — different pattern |

**How this pattern scales:**
- **Binary search on partition** is the core O(log min(m,n)) trick — binary search on the smaller array to find a partition point such that all elements on the left of both partitions are less than all elements on the right. Median is derived from the four boundary elements maxLeft1, maxLeft2, minRight1, minRight2
- **Partition invariant** — `maxLeft1 <= minRight2` and `maxLeft2 <= minRight1` must both hold. If `maxLeft1 > minRight2` move partition left in array 1. If `maxLeft2 > minRight1` move partition right. When both hold the correct partition is found
- **Even vs odd total length** — when total length is odd median is `min(minRight1, minRight2)`. When even median is `(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0`. Handle both cases explicitly
- **Always binary search the smaller array** — ensures O(log min(m,n)) time and simplifies boundary handling. If `nums1` is longer swap the arrays before starting
- **Binary search on answer pattern generalizes** → Split Array Largest Sum (LC #410) and Find K-th Smallest Pair Distance (LC #719) use the same "binary search on the answer space then validate" idea — instead of searching for a partition index you search for the answer value directly and validate feasibility with a greedy or sliding window check

```cpp
class Solution {
public:
//This is a hard problem, definitely one of the hardest problems on LeetCode. The key to solving this problem is to use binary search to find the correct partition of the two arrays. We want to partition the two arrays into two halves such that the left half of the first array and the left half of the second array together contain the same number of elements as the right half of the first array and the right half of the second array. We can then calculate the median based on the maximum of the left halves and the minimum of the right halves. The time complexity of this solution is O(log(min(m, n))) where m and n are the lengths of the two arrays, because we are doing binary search on the shorter array.
//REVIEW THIS QUESTION
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) { //nums1 always has to be the shorter array because we are doing binary search on the first array, so we want to minimize the number of operations we have to do. If nums1 is the longer array, we can just swap the two arrays and call the func again.
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0;
        int right = nums1.size();
        while(left <= right){
            int mid1 = left + (right - left) / 2; //binary search the first array, find index of the first half of the array.
            int mid2 = (nums1.size() + nums2.size() + 1) / 2 - mid1; //we want to split the two arrays into two halves, so we need to find the index of the second half of the second array. We can do this by taking the total length of the two arrays, adding 1 to it (to account for odd lengths), and then dividing by 2 to get the index of the second half of the second array. We then subtract mid1 from this index to get the index of the second half of the first array.
            int left1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1]; //if mid1 is 0, then there are no elements in the left half of the first array, so we can set left1 to be negative infinity to ensure that it does not affect the median calculation. Otherwise, we can set left1 to be the last element of the left half of the first array, which is nums1[mid1 - 1];
            int left2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int right1 = mid1 == nums1.size() ? INT_MAX : nums1[mid1];
            int right2 = mid2 == nums2.size() ? INT_MAX : nums2[mid2];
            if(left1 <= right2 && left2 <= right1){ //need to check if left half of the first array is less than the second half of the second array, and if the first half of the second array is less than the second half of the first array. If both of these conditions are true, then we have found the correct partition of the two arrays, and we can calculate the median based on the maximum of the left halves and the minimum of the right halves. If the total length of the two arrays is even, then the median is the average of the maximum of the left halves and the minimum of the right halves. If the total length of the two arrays is odd, then the median is simply the maximum of the left halves, since there will be one extra element in one of the halves.
                if((nums1.size() + nums2.size()) % 2 == 0){
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
                else{
                    return (max(left1, left2));
                }
            }
                else if(left1 > right2){ //if the left half of the first array is greater than the right half of the second array, then we need to move the partition in the first array to the left, which means we need to decrease mid1. This is because we want to find a smaller value in the left half of the first array that can be paired with a larger value in the right half of the second array to satisfy the condition for finding the median.
                    right = mid1 - 1;
                }
                else{
                    left = mid1 + 1;
                }
            }
        return 0.0;
        }
};
```

## Search in Rotated Sorted Array LC 33

<!-- notecardId: 1780503470170 -->

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

**Link**: [text](https://leetcode.com/problems/search-in-rotated-sorted-array/)

%

**Pattern:** Binary Search

**Approach:** Use binary search to find the target in the rotated sorted array. The key is to determine which half of the array is properly sorted at each step of the binary search. If the left half is sorted, check if the target lies within that half; if it does, continue searching in that half, otherwise search in the right half. If the right half is sorted, check if the target lies within that half; if it does, continue searching in that half, otherwise search in the left half. This way, you can effectively narrow down the search space while maintaining O(log n) time complexity. 

**Key Insight:** The key insight is that in a rotated sorted array, at least one half of the array will always be sorted. By comparing the target with the boundary values of the sorted half, you can determine which half to continue searching in. This allows you to maintain the efficiency of binary search even in the presence of rotation.

**Gotchas:** Be careful to handle edge cases where the target is not present in the array, or when the target is at the boundaries of the sorted halves. Additionally, ensure that you are correctly identifying which half of the array is sorted at each step, as this is crucial for determining the correct search direction. Also, remember to check for the target in both halves if necessary, especially when the target is equal to one of the boundary values.

**Complexity:** Time: O(log n) where n is the length of the input array (binary search is performed on the entire array) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search in Rotated Sorted Array II — LC #81 | Array may contain duplicates → same approach but skip duplicates when nums[left] == nums[mid] | Yes — direct upgrade |
| Find Minimum in Rotated Sorted Array — LC #153 | Find minimum not target → same rotation detection different goal | Yes — same pattern |
| Find Minimum in Rotated Sorted Array II — LC #154 | Duplicates allowed → same as LC #153 but skip equal elements | Yes — direct upgrade |
| Binary Search — LC #704 | Standard binary search no rotation → same left/right/mid skeleton simpler condition | Yes — foundation |
| Search a 2D Matrix — LC #74 | Binary search on flattened 2D matrix → same binary search no rotation | Partial — same family |
| Peak Index in Mountain Array — LC #852 | Find peak in bitonic array → same rotation style binary search | Partial — same binary search idea |
| Find K Closest Elements — LC #658 | Binary search on window boundary → same binary search different condition | Partial — same family |
| Median of Two Sorted Arrays — LC #4 | Binary search on partition across two arrays → same partition idea harder | Partial — same binary search family |

**How this pattern scales:**
- **Identify sorted half first** is the core trick — at every step one half of the array is guaranteed to be sorted. Check if `nums[left] <= nums[mid]` to identify the sorted half, then determine if target falls within that half to decide which side to discard. O(log n) time O(1) space
- **Two cases to handle explicitly** — (1) left half sorted: target in `[nums[left], nums[mid])` → go left, else go right. (2) right half sorted: target in `(nums[mid], nums[right]]` → go right, else go left. Drawing these two cases before coding eliminates all boundary confusion
- **Duplicates upgrade** → LC #81 adds duplicates which breaks the sorted half identification when `nums[left] == nums[mid]`. Fix by incrementing left and decrementing right when equal — degrades worst case to O(n) but maintains O(log n) average
- **Rotation point connection** → LC #153 (Find Minimum) finds the rotation point directly — the minimum element is always the inflection point where sorted order breaks. LC #33 implicitly uses the same rotation structure but searches for a target instead
- **Binary search on answer vs binary search on index** → LC #33 searches for a target index in a rotated array. Problems like LC #410 (Split Array) binary search on the answer value space instead. Both use the same left/right/mid skeleton but the search space is fundamentally different

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[left]){ //if mid is greater than or equal to left, then the left half of the array is sorted.
                if(nums[mid] > target  && target >= nums[left]){ //if target is less than mid and greater than or equal to left, then the target must be in the left half of the array
                    right = mid -1;
                }
                else{ //if the target is greater than mid or less than left, then the target must be in the right half of the array
                    left = mid + 1;
                }
            }
            else{ // if mid is less than left, then the right half of the array is sorted
                if(nums[mid] < target && target <= nums[right]){ //if target is greater than mid and less than or equal to right, then the target must be in the right half of the array
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
```

## Search Insert Position LC 35

<!-- notecardId: 1780505019101 -->

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104

**Link**: [text](https://leetcode.com/problems/search-insert-position/)

%

**Pattern:** Binary Search

**Approach:** Use binary search to find the target in the sorted array. If the target is found, return its index. If the target is not found, the LEFT pointer will indicate the position where the target can be inserted while maintaining the sorted order. This is because when the binary search concludes without finding the target, the LEFT pointer will have moved past all elements that are less than the target, making it the correct insertion point.

**Key Insight:** The key insight is that the binary search algorithm can be used not only to find the target but also to determine the correct insertion point when the target is not present in the array. By returning the left pointer at the end of the search, you can efficiently find the index where the target should be inserted without needing to perform additional checks or iterations.

**Gotchas:** Be careful to handle edge cases where the target is smaller than all elements in the array (in which case it should be inserted at index 0) or larger than all elements in the array (in which case it should be inserted at the end of the array). Additionally, ensure that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results.

**Complexity:** Time: O(log n) where n is the length of the input array (binary search is performed on the entire array) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Search — LC #704 | Find exact target not insert position → same skeleton return -1 if not found | Yes — foundation |
| Search in Rotated Sorted Array — LC #33 | Binary search with rotation → same left/right/mid skeleton extra sorted half check | Yes — same family |
| Find First and Last Position — LC #34 | Find leftmost and rightmost occurrence → same binary search run twice with different conditions | Yes — direct upgrade |
| Find Minimum in Rotated Sorted Array — LC #153 | Find minimum in rotated array → same binary search rotation detection | Partial — same family |
| Kth Missing Positive Number — LC #1539 | Find kth missing in sorted array → binary search on missing count | Partial — same insert idea |
| Count of Smaller Numbers After Self — LC #315 | Count elements smaller than each → binary search insert position per element | Partial — same insert idea |
| Median of Two Sorted Arrays — LC #4 | Binary search on partition across two arrays → same partition idea much harder | Partial — same family |
| Capacity to Ship Packages — LC #1011 | Binary search on answer not index → same left/right/mid different search space | Partial — same binary search family |

**How this pattern scales:**
- **Left boundary binary search** is the core trick — when target is not found `left` naturally lands at the correct insert position. Standard binary search template: `while left <= right`, `mid = (left + right) // 2`, move `right = mid - 1` when `nums[mid] >= target`, move `left = mid + 1` when `nums[mid] < target`. Return `left`
- **Why left is the answer** — when the loop exits `left > right` and `left` points to the first element greater than target which is exactly where target would be inserted to maintain sorted order. This termination invariant is worth understanding deeply not just memorizing
- **Leftmost occurrence generalization** → LC #34 (Find First and Last Position) uses the exact same left boundary search for the first occurrence. For the last occurrence flip the condition to find the right boundary. LC #35 is the degenerate case where you only need the left boundary
- **Binary search on answer** → Capacity to Ship Packages (LC #1011) and Split Array Largest Sum (LC #410) use the same `while left <= right` skeleton but search over the answer space not array indices. LC #35 is the purest form of the template making it the ideal problem to internalize before tackling answer-space binary search problems
- **Off by one is the main pitfall** — using `mid = left + (right - left) / 2` prevents integer overflow in C++. Using `right = mid` instead of `right = mid - 1` creates infinite loops. These are the two implementation bugs that cause most wrong submissions on binary search problems

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        //int returnIdx = 0;
        while(left <= right){
            int currIndex = left + (right - left)/2;
            if(nums[currIndex] == target){
                return currIndex;
            }
            else if(nums[currIndex] < target){
                left = currIndex + 1;
            }
            else{
                right = currIndex - 1;
            }
        }
        return left; //left is the index where the target would be inserted, 
        //because if the target is not found in the array, left will end up being the index of the first element that is greater than the target, 
        //which is where the target should be inserted to maintain the sorted order of the array.

        /*
        Key Pattern:

Notice that left always ends up at the correct insertion position:

When target is smaller than all elements → left stays 0
When target belongs between two elements → left points to where it should go
When target is larger than all elements → left becomes nums.size()
        */

    }
};
```

## Sqrt(x) LC 69

<!-- notecardId: 1780505307837 -->

Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1

**Link**: [text](https://leetcode.com/problems/sqrtx/)

%

**Pattern:** Binary Search

**Approach:** Use binary search to find the largest integer `mid` such that `mid * mid <= x`. Start with `left` at 0 and `right` at `x`. Calculate the midpoint `mid` and check if `mid * mid` is equal to `x`, less than `x`, or greater than `x`. If it is equal, return `mid`. If it is less than `x`, move the `left` pointer to `mid + 1` to search in the right half. If it is greater than `x`, move the `right` pointer to `mid - 1` to search in the left half. Continue this process until the pointers cross each other. The largest integer that satisfies the condition will be at the position of the 'left' pointer when the loop ends as we know the returned integer is rounded down.

**Key Insight:** The key insight is that the square root of a number `x` must be less than or equal to `x` itself. Therefore, you can use binary search within the range of 0 to `x` to efficiently find the largest integer whose square is less than or equal to `x`. This approach avoids the need for more complex mathematical functions and allows you to achieve logarithmic time complexity.

**Gotchas:** Be careful to handle edge cases where `x` is 0 or 1, as the square root of these numbers is the number itself. Additionally, ensure that you are correctly updating the `left` and `right` pointers during the binary search to avoid infinite loops or incorrect results. 

**Complexity:** Time: O(log x) where x is the input number (binary search is performed on the range from 0 to x) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search Insert Position — LC #35 | Lower bound binary search on array → same left convergence different search space | Yes — same pattern |
| First Bad Version — LC #278 | First true in boolean predicate → same lower bound binary search on answer | Yes — direct variant |
| Koko Eating Bananas — LC #875 | Minimum eating speed satisfying constraint → same binary search on answer with feasibility check | Yes — same pattern |
| Capacity to Ship Packages — LC #1011 | Minimum capacity to ship within days → same lower bound on answer space | Yes — same pattern |
| Find Peak Element — LC #162 | Find peak in unsorted array → binary search on slope not value | Partial — same binary search family |
| Pow(x, n) — LC #50 | Compute x raised to power n → fast exponentiation not binary search | Partial — same math idea |
| Valid Perfect Square — LC #367 | Check if n is a perfect square → same binary search on answer boolean result | Yes — direct variant |
| Integer Break — LC #343 | Break integer for maximum product → math/DP not binary search | No — different pattern |

**How this pattern scales:**
- **Binary search on answer space** is the core trick — search on `[0, x]` for the largest integer m such that `m * m <= x`. When loop terminates `right` points to the floor of the square root. O(log x) time O(1) space
- **Right converges to the answer here** — unlike LC #35 where `left` is the answer, here you want the largest valid value so `right` converges to the answer. When `mid * mid <= x` move left boundary up (mid is valid, try larger). When `mid * mid > x` move right boundary down (mid is invalid, must go smaller)
- **Overflow handling** — `mid * mid` can overflow `int` for large x. Always cast to `long long` before multiplying: `(long long)mid * mid`. Missing this causes silent wrong answers on large inputs
- **Upper bound vs lower bound** → LC #35 finds the first position satisfying a condition (lower bound, `left` is answer). LC #69 finds the last position satisfying a condition (upper bound, `right` is answer). These are the two fundamental binary search on answer patterns — every binary search problem is one or the other
- **Feasibility check pattern** → Koko Eating Bananas (LC #875) and Capacity to Ship (LC #1011) replace `mid * mid <= x` with a more complex feasibility function but the binary search skeleton is identical — search on answer space, validate with condition, converge left or right accordingly

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int answer = 0;
        while(left <= right){
            int mid = left + (right - left) / 2; //dont forget the (right - left) / 2
            if((long long)mid * mid == x){ //remember (long long) since big number, need it to avoid overflow
                return mid;
            }
            else if ((long long)mid * mid < x){
                answer = mid;
                left = mid + 1;
            }
            else{
                //cant be a potential answer, since we only want lower numbers
                right = mid - 1;
            }
        }
        return answer;
    }
};
```

## Search a 2D Matrix LC 74

<!-- notecardId: 1780505721532 -->

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104

**Link**: [text](https://leetcode.com/problems/search-a-2d-matrix/)

%

**Pattern:** Binary Search, 2D Matrix

**Approach:** Treat the 2D matrix as a flattened sorted array and use binary search to find the target. Calculate the midpoint index in the flattened array and convert it back to 2D indices to access the corresponding element in the matrix. Compare the element at the midpoint with the target and adjust the search range accordingly until you find the target or exhaust the search space.

**Key Insight:** The key insight is that the given 2D matrix can be treated as a single sorted array due to the properties of the matrix. By using binary search on this conceptual flattened array, you can efficiently find the target in logarithmic time. The conversion between the 1D index and the 2D indices is crucial for accessing the correct elements in the matrix during the search. If you look at it from a 2D, find the row first, then do a binary search in that row, it is also O(log(m) + log(n)) = O(log(m*n)), but the flattened approach is cleaner and more elegant.

**Gotchas:** Be careful to correctly convert between the 1D index and the 2D indices. The row index can be calculated as `mid / n` and the column index can be calculated as `mid % n`, where `n` is the number of columns in the matrix. Additionally, ensure that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results.

**Complexity:** Time: O(log(m * n)) where m is the number of rows and n is the number of columns in the matrix (binary search is performed on the conceptual flattened array) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search a 2D Matrix II — LC #240 | Rows and columns sorted independently not row-chained → staircase search from top right | No — different approach |
| Binary Search — LC #704 | Standard binary search on 1D array → same skeleton LC #74 reduces to this | Yes — foundation |
| Search Insert Position — LC #35 | Lower bound binary search on 1D array → same convergence idea | Yes — same family |
| Find Minimum in Rotated Sorted Array — LC #153 | Binary search on rotated 1D array → same mid calculation different condition | Partial — same family |
| Koko Eating Bananas — LC #875 | Binary search on answer space → same skeleton different search space | Partial — same binary search family |
| Set Matrix Zeroes — LC #73 | Modify matrix based on cell values → same 2D index math no binary search | No — different pattern |
| Spiral Matrix — LC #54 | Traverse matrix in spiral order → index math no binary search | No — different pattern |
| Range Sum Query 2D — LC #304 | Prefix sum on 2D matrix → same 2D index flattening idea | Partial — same index math |

**How this pattern scales:**
- **Flatten 2D index to 1D** is the core trick — treat the entire matrix as a virtual 1D sorted array of size `m * n`. Convert mid index to row and column using `row = mid / n` and `col = mid % n`. Standard binary search runs on `[0, m*n - 1]`. O(log mn) time O(1) space
- **Row and column formula** `row = mid / n` and `col = mid % n` is the key to memorize cold — division gives the row, modulo gives the column. This is the same index flattening used in any problem that maps a 1D index onto a 2D grid
- **LC #74 vs LC #240 distinction** is critical — LC #74 guarantees each row continues from the last making full 1D binary search valid. LC #240 only guarantees rows and columns are independently sorted making 1D binary search invalid. Staircase search (start top right move left on greater move down on smaller) is the correct approach for LC #240
- **Two step binary search alternative** — first binary search on first column to find the correct row O(log m), then binary search within that row O(log n). Total O(log m + log n) = O(log mn) same asymptotic complexity but two passes instead of one
- **Index flattening generalizes** → any problem mapping between 1D and 2D coordinates uses `row = i / cols` and `col = i % cols`. This appears in Spiral Matrix, Set Matrix Zeroes, and any grid problem where you iterate with a single counter

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //need two log searches, search once by finding exactly which row it is
        //and then, look through the row do binary search to find it
        int start = 0;
        int targetRow = -1;
        int end = matrix.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][matrix[0].size() - 1]){ //if the target is between the first and last element of the row, target must be in this row
                targetRow = mid;
                break;
            }
            else if(matrix[mid][matrix[0].size() - 1] < target){ //need to compare the last element of the row, because if the target is greater than the last element of the row, must be in a row below
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }

            }
            if(targetRow < 0) return false; //couldnt be found, return false

            int left = 0;
            int right = matrix[0].size() - 1;
            while(left <= right){
            int mid = left + (right - left)/2;
            if(target == matrix[targetRow][mid]){
                return true;
            }
            else if(matrix[targetRow][mid] < target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }

            }
            return false;

            
    }
};
```

## Search in Rotated Sorted Array II LC 81

<!-- notecardId: 1780521072685 -->

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104
 

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?

**Link**: [text](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

%

**Pattern:** Binary Search with Duplicates

**Approach:** Use binary search to find the target in the rotated sorted array that may contain duplicates. The presence of duplicates can make it difficult to determine which half of the array is sorted. To handle this, if the left, middle, and right elements are equal, you can skip the duplicates by incrementing the left pointer and decrementing the right pointer. This allows you to continue the binary search process while effectively ignoring the duplicate values.

**Key Insight:** The key insight is that when duplicates are present, the standard binary search approach for a rotated sorted array can fail to identify the sorted half of the array. By checking if the left, middle, and right elements are equal, you can safely skip over the duplicates without missing the target. This ensures that you can still achieve logarithmic time complexity in most cases, although in the worst case (when all elements are duplicates) it can degrade to linear time.

**Gotchas:** Be careful to handle edge cases where the target is not present in the array, or when the target is at the boundaries of the sorted halves. Additionally, ensure that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results. The presence of duplicates can lead to situations where the binary search does not effectively narrow down the search space, so it is crucial to implement the logic for skipping duplicates correctly.

**Complexity:** Time: O(log n) on average, but can degrade to O(n) in the worst case when all elements are duplicates | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search in Rotated Sorted Array — LC #33 | No duplicates → same sorted half identification always works | Yes — foundation |
| Find Minimum in Rotated Sorted Array — LC #153 | Find minimum not target → same rotation detection different goal | Yes — same pattern |
| Find Minimum in Rotated Sorted Array II — LC #154 | Duplicates allowed find minimum → same skip equal elements trick | Yes — direct variant |
| Binary Search — LC #704 | Standard binary search no rotation → same skeleton simpler condition | Yes — foundation |
| Search a 2D Matrix — LC #74 | Binary search on flattened 2D matrix → same binary search no rotation | Partial — same family |
| Peak Index in Mountain Array — LC #852 | Find peak in bitonic array → same rotation style binary search | Partial — same binary search idea |
| Count of Range Sum — LC #327 | Count ranges in sorted structure → merge sort not binary search | No — different pattern |
| Find Duplicate Number — LC #287 | Find duplicate in unsorted array → Floyd's cycle or index marking | No — different pattern |

**How this pattern scales:**
- **Skip duplicates when ambiguous** is the core upgrade from LC #33 — when `nums[left] == nums[mid]` you cannot determine which half is sorted so increment left and decrement right by one. This degrades worst case to O(n) when all elements are equal but maintains O(log n) average
- **Three cases instead of two** — (1) `nums[left] == nums[mid]`: ambiguous, shrink both boundaries by one. (2) `nums[left] < nums[mid]`: left half sorted, check if target in range. (3) `nums[left] > nums[mid]`: right half sorted, check if target in range. Drawing all three cases before coding eliminates boundary confusion
- **Worst case O(n) is unavoidable** — for input like `[1,1,1,1,1,2,1,1,1]` you cannot determine which half contains the target without linear scanning. This is a fundamental limitation when duplicates are present and worth stating explicitly in interviews
- **LC #154 connection** → Find Minimum in Rotated Sorted Array II applies the exact same `nums[left] == nums[mid]` skip trick but searches for the minimum inflection point instead of a target. Same fix, different goal
- **Duplicates as the universal complication** → across binary search problems duplicates always introduce ambiguity in the comparison step. The fix is always some form of boundary shrinking or skipping — LC #81 does `left++ right--`, LC #154 does `right--`. Pattern: when duplicates make the condition ambiguous shrink conservatively

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return true;
            }

            //key point here, if there are duplicates, we can't determine which half of the array is sorted, so we can just move the left and right pointer until duplicates arent there
            //key note: duplicates exist in this problem!
            if(nums[mid] == nums[left] && nums[mid] == nums[right]){
                left++;
                right--;
            }
            else if(nums[mid] >= nums[left]){ //if mid is greater than or equal to left, then the left half of the array is sorted.
                if(nums[mid] > target  && target >= nums[left]){ //if target is less than mid and greater than or equal to left, then the target must be in the left half of the array
                    right = mid -1;
                }
                else{ //if the target is greater than mid or less than left, then the target must be in the right half of the array
                    left = mid + 1;
                }
            }
            else{ // if mid is less than left, then the right half of the array is sorted
                if(nums[mid] < target && target <= nums[right]){ //if target is greater than mid and less than or equal to right, then the target must be in the right half of the array
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
```

## Find minumum in Rotated Sorted Array LC 153

<!-- notecardId: 1780521760362 -->

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
All the integers of nums are unique.
nums is sorted and rotated between 1 and n times.

**Link**: [text](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

%

**Pattern:** Binary Search, Rotation Detection

**Approach:** Use binary search to find the minimum element in the rotated sorted array. The key is to determine which half of the array is properly sorted at each step of the binary search. If the left half is sorted, then the minimum must be in the right half; if the right half is sorted, then the minimum must be in the left half. By comparing the middle element with the rightmost element, you can determine which half is sorted and narrow down the search space accordingly.

**Key Insight:** The key insight is that in a rotated sorted array, the minimum element is the only element that is smaller than its previous element. By using binary search and comparing the middle element with the rightmost element, you can determine which half of the array is sorted and where the minimum element lies. This allows you to efficiently find the minimum element in logarithmic time.

**Gotchas:** Be careful to handle edge cases where the minimum element is at the beginning or end of the array. Additionally, ensure that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results. The presence of duplicates can complicate the logic for determining which half is sorted, so make sure to account for that if it is a possibility in a related problem. The trick in the problem (what makes it different from other binary search questions) is to compare with the right element, and not the left. Because we are trying to find the minimum, we want to compare with the right element, because if the middle element is greater than the right element, then the minimum must be in the right half. If we compared with the left element, we would not be able to determine which half is sorted correctly.

**Complexity:** Time: O(log n) where n is the length of the input array (binary search is performed on the entire array) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Find Minimum in Rotated Sorted Array II — LC #154 | Duplicates allowed → same approach skip equal elements when ambiguous | Yes — direct upgrade |
| Search in Rotated Sorted Array — LC #33 | Search for target not minimum → same rotation detection different goal | Yes — same pattern |
| Search in Rotated Sorted Array II — LC #81 | Search with duplicates → same skip equal elements trick | Yes — same family |
| Binary Search — LC #704 | Standard binary search no rotation → same skeleton simpler condition | Yes — foundation |
| Find Peak Element — LC #162 | Find peak not minimum → same binary search on slope different direction | Partial — same binary search idea |
| Peak Index in Mountain Array — LC #852 | Find peak in bitonic array → same slope based binary search | Partial — same family |
| Rotate Array — LC #189 | Rotate array by k positions → reversal trick not binary search | No — different pattern |
| Minimum in Sorted and Rotated using Binary Search | Classic rotation problem → direct application of LC #153 logic | Yes — same pattern |

**How this pattern scales:**
- **Compare mid to right boundary** is the core trick — if `nums[mid] > nums[right]` the minimum is in the right half (rotation point is right of mid). If `nums[mid] <= nums[right]` the minimum is in the left half including mid. Converge until `left == right`. O(log n) time O(1) space
- **Why compare to right not left** — comparing `nums[mid]` to `nums[right]` cleanly identifies which half contains the inflection point. Comparing to `nums[left]` introduces ambiguity when the array is not rotated since `nums[left] <= nums[mid]` holds for both sorted and left-half-sorted cases
- **Left converges to minimum** — when loop terminates `left == right` and both point to the minimum element. Same lower bound convergence as LC #35 but the condition drives convergence toward the rotation point instead of a target value
- **Duplicates upgrade** → LC #154 adds `nums[mid] == nums[right]` as a third case where you cannot determine which half contains the minimum. Fix by decrementing right by one — same conservative boundary shrinking as LC #81
- **Rotation point connection** → the minimum element IS the rotation point — it is the only element where `nums[i] < nums[i-1]`. LC #33 implicitly uses this same inflection point to identify sorted halves. Knowing where the rotation point is immediately tells you which half of any query target lies in

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){ //have to compare with right and not left because if mid is greater than right, then we know that the minimum value must be in the right half of the array. 
            //If we compared with left, we wouldn't be able to determine which half of the array contains the minimum value because the left half could still be sorted and contain the minimum value, or it could be rotated and contain the minimum value as well. 
            //By comparing with right, we can determine that the minimum value must be in the right half of the array if mid is greater than right, and if mid is less than or equal to right, then the minimum value must be in the left half of the array.

                left = mid + 1; //min is in the right half
            }
            else{
                right = mid; //min is in the left half
            }
            /*
            Your assumption that "if left half is sorted, minimum must be in right half" is FALSE when:

            The array isn't rotated (minimum at left)
            The rotation point is in the right half (left half is sorted but minimum is actually at the very left)
            
            */

        }
        return nums[left];
    }
};
```

## Guess Number Higher or Lower LC 374

<!-- notecardId: 1780521760365 -->

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked (the number I picked stays the same throughout the game).

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

-1: Your guess is higher than the number I picked (i.e. num > pick).
1: Your guess is lower than the number I picked (i.e. num < pick).
0: your guess is equal to the number I picked (i.e. num == pick).
Return the number that I picked.

 

Example 1:

Input: n = 10, pick = 6
Output: 6
Example 2:

Input: n = 1, pick = 1
Output: 1
Example 3:

Input: n = 2, pick = 1
Output: 1
 

Constraints:

1 <= n <= 231 - 1
1 <= pick <= n

**Link**: [text](https://leetcode.com/problems/guess-number-higher-or-lower/)

%

**Pattern:** Binary Search on Answer Space

**Approach:** Use binary search to find the picked number by calling the `guess` API. Start with `left` at 1 and `right` at n. Calculate the midpoint `mid` and call `guess(mid)`. If the result is 0, return `mid` as the picked number. If the result is -1, it means the picked number is lower than `mid`, so move the `right` pointer to `mid - 1`. If the result is 1, it means the picked number is higher than `mid`, so move the `left` pointer to `mid + 1`. Continue this process until you find the picked number.

**Key Insight:** The key insight is that the `guess` API provides feedback that allows you to effectively perform a binary search on the range of possible numbers. By adjusting the search range based on whether the guess is too high, too low, or correct, you can efficiently narrow down to the picked number in logarithmic time.

**Gotchas:** Be careful to handle edge cases where the picked number is at the boundaries of the search range (1 or n). Additionally, ensure that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results. The use of `mid = left + (right - left) / 2` is important to prevent integer overflow when calculating the midpoint.

**Complexity:** Time: O(log n) where n is the range of numbers (binary search is performed on the range from 1 to n) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Search — LC #704 | Direct array comparison no external API → same left/right/mid skeleton | Yes — foundation |
| Search Insert Position — LC #35 | Lower bound binary search on array → same left convergence pattern | Yes — same family |
| First Bad Version — LC #278 | First true in boolean predicate API → same binary search on external condition | Yes — direct variant |
| Find Peak Element — LC #162 | Find peak using slope comparison → same binary search different condition | Partial — same family |
| Koko Eating Bananas — LC #875 | Binary search on answer with feasibility check → same answer space search | Partial — same pattern |
| Guess the Word — LC #843 | Guess word with limited attempts → minimax not binary search | No — different pattern |
| Find K Closest Elements — LC #658 | Binary search on window boundary → same binary search different condition | Partial — same family |
| Sqrt(x) — LC #69 | Binary search on answer space → same right convergence upper bound | Partial — same pattern |

**How this pattern scales:**
- **Binary search on external predicate** is the core trick — instead of comparing `nums[mid]` to a target directly call the `guess(mid)` API which returns -1 0 or 1. Same left/right/mid skeleton unchanged. O(log n) time O(1) space
- **Three way comparison** — `guess(mid) == 0` found answer return mid. `guess(mid) == -1` target is lower move right boundary down. `guess(mid) == 1` target is higher move left boundary up. Mapping API return values to pointer movements before coding eliminates all direction confusion
- **API abstraction pattern** → LC #374 and LC #278 (First Bad Version) both replace direct array access with an external API call. The binary search skeleton is identical — the only change is swapping `nums[mid] == target` for an API call. Any problem hiding its comparison behind a function call uses this same pattern
- **Black box binary search** → when the search condition cannot be evaluated directly (external API, expensive computation, unknown function) binary search still applies as long as the condition is monotonic — false false false ... true true true or decreasing/increasing. LC #374 is the simplest example of this black box pattern
- **Binary search on answer space** → LC #69 and LC #875 apply the same external condition idea but search on a value space instead of an index space. The predicate replaces direct comparison in both cases — same abstraction, different search domain

```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while(left <= right){
            int mid = left + (right - left)/2;
        if(guess(mid) == 0){
            return mid;
        }
        else if(guess(mid) == 1){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
        }
        return -1;
    }
};
```

## Split Array Largest Sum LC 410

<!-- notecardId: 1780522524461 -->

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)

**Link**: [text](https://leetcode.com/problems/split-array-largest-sum/)

%

**Pattern:** Binary Search on Answer Space, Feasibility Check

**Approach:** Use binary search to find the minimum largest sum of splitting the array into k subarrays. The search space for the largest sum is between the maximum element in the array (lower bound) and the sum of all elements in the array (upper bound). For each midpoint in this search space, perform a feasibility check to determine if it is possible to split the array into k or fewer subarrays without exceeding the midpoint as the largest sum. If it is feasible, move the upper bound down; if it is not feasible, move the lower bound up. Continue this process until the lower and upper bounds converge.

**Key Insight:** The key insight is that the largest sum of any subarray must be at least the maximum element in the array and at most the sum of all elements in the array. By using binary search on this range, you can efficiently find the minimum largest sum. The feasibility check is crucial for determining whether a given largest sum can be achieved with k or fewer subarrays, which allows you to narrow down the search space effectively.

**Gotchas:** Be careful to handle edge cases where k is equal to the length of the array (in which case the largest sum is simply the maximum element) or where k is 1 (in which case the largest sum is the sum of all elements). Additionally, ensure that your feasibility check correctly counts the number of subarrays needed to achieve a given largest sum and that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results.

**Complexity:** Time: O(n log m) where n is the length of the input array and m is the range of possible largest sums (from max element to sum of all elements) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Koko Eating Bananas — LC #875 | Minimize eating speed → same binary search on answer feasibility check | Yes — direct variant |
| Capacity to Ship Packages — LC #1011 | Minimum ship capacity → same binary search on answer greedy validation | Yes — direct variant |
| Divide Chocolate — LC #1231 | Maximize minimum sweetness → same binary search flip feasibility direction | Yes — direct variant |
| Minimum Number of Days to Make Bouquets — LC #1482 | Binary search on days → same feasibility check pattern | Yes — same pattern |
| Painter's Partition Problem | Minimize maximum painter time → exact restatement of LC #410 | Yes — direct variant |
| Find K Closest Elements — LC #658 | Binary search on window boundary → same binary search different condition | Partial — same family |
| Median of Two Sorted Arrays — LC #4 | Binary search on partition → same binary search on index space | Partial — same family |
| Largest Rectangle in Histogram — LC #84 | Monotonic stack not binary search | No — different pattern |

**How this pattern scales:**
- **Binary search on answer space** is the core trick — search on `[max(nums), sum(nums)]` for the minimum largest subarray sum. For each candidate mid run a greedy feasibility check counting how many subarrays are needed. If count <= k mid is feasible move right boundary down. O(n log(sum - max)) time O(1) space
- **Greedy feasibility check** — iterate through array accumulating sum, increment subarray count and reset when adding next element would exceed mid. If total subarrays needed <= k the capacity mid is feasible. This greedy is always optimal because splitting earlier never increases the maximum sum
- **Minimize maximum vs maximize minimum** — LC #410 minimizes the maximum subarray sum. LC #1231 (Divide Chocolate) maximizes the minimum piece sweetness. Both use binary search on answer but the feasibility direction flips — minimize maximum moves right boundary down on feasible, maximize minimum moves left boundary up on feasible
- **Binary search on answer template**:
  1. Define answer space `[lo, hi]`
  2. Write feasibility check `canDo(mid)` in O(n)
  3. Binary search converging on tightest feasible value
  4. Return `left` for minimize problems `right` for maximize problems
- **Identifying binary search on answer problems** — signal words: "minimum maximum", "maximum minimum", "at most k groups", "within d days". Any time a problem asks to optimize a value subject to a count constraint or vice versa, binary search on answer + greedy feasibility is almost certainly the intended approach

```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
    int left = *max_element(nums.begin(), nums.end());
    int right = accumulate(nums.begin(), nums.end(), 0); //max capacity
    int smallestSubarraySum = 0;
    while(left < right){
        int mid = left + (right - left)/2;
        if(splitCheck(nums, k, mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    
    }
    return left;

    }
private:

    bool splitCheck(vector<int>& nums, int k, int maxSum){
        int subArrayCt =1;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > maxSum){
                subArrayCt++;
                sum = nums[i];
                if(subArrayCt > k) return false;
            }
            else{
                sum += nums[i];
            }
        }
        return subArrayCt <= k;

    }
};
```

## Binary Search LC 704

<!-- notecardId: 1780528270682 -->

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
 

Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.

**Link**: [text](https://leetcode.com/problems/binary-search/)

%

**Pattern:** Binary Search

**Approach:** Use binary search to find the target in the sorted array. Start with `left` at 0 and `right` at the last index of the array. Calculate the midpoint `mid` and compare `nums[mid]` with the target. If they are equal, return `mid`. If `nums[mid]` is less than the target, move the `left` pointer to `mid + 1`. If `nums[mid]` is greater than the target, move the `right` pointer to `mid - 1`. Continue this process until the target is found or the pointers cross each other.

**Key Insight:** The key insight is that binary search efficiently narrows down the search space by halving it at each step. By comparing the middle element with the target, you can determine which half of the array to continue searching in, leading to a logarithmic time complexity.

**Gotchas:** Be careful to handle edge cases where the target is at the beginning or end of the array. Additionally, ensure that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results. The use of `mid = left + (right - left) / 2` is important to prevent integer overflow when calculating the midpoint.

**Complexity:** Time: O(log n) where n is the length of the input array (binary search is performed on the entire array) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search Insert Position — LC #35 | Target may be missing → instead of returning -1, return the insertion index `left` where the element would logically sit | Yes — identical binary search structure |
| Find First and Last Position of Element in Sorted Array — LC #34 | Array contains duplicates; find boundary bounds → use modified binary search conditions to continue searching left/right even after finding a match | Yes — binary search template with boundary clamping |
| Search in Rotated Sorted Array — LC #33 | Array is rotated at an unknown pivot point → identify which half of the array is uniformly sorted before checking target boundaries | Partial — adds pre-conditional checks to standard binary search |
| First Bad Version — LC #278 | API-driven boolean search space (`true`/`false`) instead of numerical values → minimize API calls by finding the first index where state changes | Yes — standard binary search on a monotonic boolean array |
| Peak Index in a Mountain Array — LC #852 | Unsorted overall, but follows a strict increasing-then-decreasing structure → compare `nums[mid]` to `nums[mid + 1]` to determine peak direction | Partial — uses localized trend analysis instead of a target value |
| Search a 2D Matrix — LC #74 | 2D matrix where rows are lined up end-to-end sorted → flatten the matrix indices mathematically (`row = mid / cols`, `col = mid % cols`) to perform standard 1D binary search | Yes — identical pattern via index mapping |

**How this pattern scales:**
- **Divide and conquer search space reduction O(log n)** is the core mechanic. By checking the exact midpoint (`mid = left + (right - left) / 2`), you exploit the sorted nature of the data to eliminate half of the remaining elements in $O(1)$ constant time. This reduces an $O(n)$ linear scan to logarithmic complexity, allowing you to search billions of items in roughly 30 operations.
- **Overflow prevention in index calculations**. When scaling up to massive datasets or systems with fixed register sizes, computing the midpoint as `(left + right) / 2` can trigger an integer overflow if the sum exceeds the maximum limit of a 32-bit integer. The pattern standardizes to `left + (right - left) / 2` to safely guarantee all intermediate arithmetic stays within bounds.
- **Loop termination and boundary conditions dictate variations**. The structure changes based on the search intent:
  1. *Strict Search (`while (left <= right)`):* Used when hunting for an exact value. Halves are inclusive, and a missing element results in pointers crossing, terminating safely.
  2. *Boundary Search (`while (left < right)`):* Used when seeking a threshold, pivot, or insertion index. The search space shrinks down until `left == right`, converging directly onto the target index without explicit midpoint matching.
- **Monotonicity generalizes beyond explicit arrays** → Binary search scales seamlessly to abstract spaces where an explicit collection doesn't exist, known as **Binary Search on the Answer** (e.g., LC #1011, LC #875). As long as a problem domain exhibits a predictable, continuous monotonic property (e.g., "if velocity $v$ is sufficient to complete the journey, any velocity greater than $v$ is also guaranteed to complete it"), you can binary search for the optimal solution across a theoretical range of minimum and maximum possible values.

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
    while(left <= right){
        int currIndex = left + (right - left) / 2;
        if(nums[currIndex] == target){
            return currIndex;
        }
        else if(nums[currIndex] < target){
            left = currIndex+ 1;
        }
        else{
            right = currIndex - 1;
        }
}
        return -1;
    }
};
```

## Koko Eating Bananas LC 875

<!-- notecardId: 1780528510631 -->

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23
 

Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

**Link**: [text](https://leetcode.com/problems/koko-eating-bananas/)

%

**Pattern:** Binary Search on Answer Space, Feasibility Check

**Approach:** Use binary search to find the minimum eating speed `k` that allows Koko to finish all the bananas within `h` hours. The search space for `k` is between 1 (the slowest speed) and the maximum number of bananas in any pile (the fastest speed). For each candidate `k`, perform a feasibility check to determine if Koko can eat all the bananas within `h` hours at that speed. If it is feasible, move the upper bound down; if it is not feasible, move the lower bound up. Continue this process until the lower and upper bounds converge.

**Key Insight:** The key insight is that the eating speed `k` must be at least 1 and at most the maximum pile size. By using binary search on this range, you can efficiently find the minimum speed. The feasibility check is crucial for determining whether a given speed allows Koko to finish in time, which allows you to narrow down the search space effectively.

**Gotchas:** Be careful to handle edge cases where `h` is equal to the length of `piles` (in which case the minimum speed is simply the maximum pile size) or where `h` is much larger than the total number of bananas (in which case the minimum speed is 1). Additionally, ensure that your feasibility check correctly calculates the total hours needed to eat all the bananas at a given speed and that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results.

**Complexity:** Time: O(n log m) where n is the number of piles and m is the range of possible eating speeds (from 1 to max pile size) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Capacity To Ship Packages Within D Days — LC #1011 | Must ship packages in strict linear order without reordering → calculate minimum ship capacity using an identical binary search range with a linear packing simulation | Yes — identical abstract boundary matching |
| Split Array Largest Sum — LC #410 | Split contiguous array into $m$ subarrays to minimize the maximum sum → binary search the maximum subarray sum threshold, using a greedy checker to count partitions | Yes — same optimization setup over a continuous range |
| Minimum Time to Complete Trips — LC #2226 | Find maximum time/speed allowed under a constraint → flip the binary search logic to maximize a valid answer rather than minimizing a threshold cost | Yes — same framework but optimizes for upper bound |
| Find Minimum in Rotated Sorted Array — LC #153 | Finding an actual element in a modified physical array → binary search over concrete structural index boundaries rather than a conceptual answer range | No — structural binary search, not binary search on the answer |

**How this pattern scales:**
- **Binary Search on the Answer space O(n log m)** is the optimal strategy when you need to find a minimum or maximum optimization threshold, but the input data cannot be sorted or searched directly. Instead of searching the array, you identify a conceptual, continuous range of possible answers (from `minimum_possible_speed = 1` to `maximum_possible_speed = max(piles)`). You then binary search this speed range, reducing the search space logarithmically.
- **The Monotonic Feasibility Function is the core engine**. For every midpoint candidate speed `mid` generated by the binary search, you run a secondary linear helper function ($O(n)$ time) to simulate Koko eating the piles. This function counts total hours spent: 
  $$\text{hours} = \sum \lceil \text{pile} / \text{mid} \rceil$$
  Because the relationship is perfectly monotonic—increasing the eating speed is guaranteed to either decrease or maintain the total hours spent—you can confidently discard half of your answer space based on whether the total hours fall within the deadline `h`.
- **Handling integer division rounding constraints**. When simulating rates or distributions (like eating candies, shipping weights, or partitioning lines), standard integer truncation (`pile / mid`) can corrupt the feasibility check. The pattern scales by implementing ceiling division safely without floating-point inaccuracies using the integer formula: `(pile + mid - 1) / mid`.
- **Abstract optimization problems generalize via monotonic properties** → This framework completely transforms how you approach complex optimization problems. Whenever a question asks for a minimum or maximum value to satisfy a condition, look for a monotonic rule: *"If an answer of size $X$ is valid, does that guarantee that every value greater than $X$ is also valid?"* If yes, you can bypass complex combinatorial logic entirely and use this template to wrap a simple greedy checking subroutine inside a powerful binary search wrapper.

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //the trick is that you are binary searching the eating speed, not the piles
        int left = 1;
        int right = *max_element(piles.begin(), piles.end()); //max element returns the pointer, dereference ptr to get the value
        int answer = right;
        while(left < right){
            int mid = left + (right - left)/2; //eating speed can be between 1 and max of the piles, so we can binary search between those two values to find the minimum eating speed that allows Koko to finish eating all the bananas within h hours.
            int hoursNeeded = 0;
            for(int p:piles){
                hoursNeeded += (p + mid - 1) / mid; //the (p + mid - 1) / mid is a common way to calculate the ceiling of p/mid without using floating point division. It works by adding mid - 1 to p before dividing by mid, which effectively rounds up the division result when p is not perfectly divisible by mid.
            }
            if(hoursNeeded <= h){
                answer = mid; //not hoursneeded, we need to return the minimum eating speed, so if hours needed is less than or equal to h, we can try to find a smaller eating speed, so we set right to mid. If hours needed is greater than h, we need to increase the eating speed, so we set left to mid + 1.
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return answer;
    }
};
```

## Time Based Key-Value Store LC 981

<!-- notecardId: 1780530679230 -->

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 

Example 1:

Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
 

Constraints:

1 <= key.length, value.length <= 100
key and value consist of lowercase English letters and digits.
1 <= timestamp <= 107
All the timestamps timestamp of set are strictly increasing.
At most 2 * 105 calls will be made to set and get.

**Link**: [text](https://leetcode.com/problems/time-based-key-value-store/)

%

**Pattern:** Binary Search on Timestamp

**Approach:** Use a hash map to store the key and a list of (timestamp, value) pairs. When setting a value, append the (timestamp, value) pair to the list for that key. When getting a value, perform a binary search on the list of (timestamp, value) pairs for the given key to find the largest timestamp that is less than or equal to the requested timestamp. Return the corresponding value for that timestamp.

**Key Insight:** The key insight is that since the timestamps for each key are strictly increasing, you can use binary search to efficiently find the correct value for a given timestamp. By storing the (timestamp, value) pairs in a list for each key, you can quickly retrieve the value associated with the largest timestamp that is less than or equal to the requested timestamp.

**Gotchas:** Be careful to handle edge cases where the requested timestamp is smaller than the smallest timestamp for that key (in which case you should return an empty string) or larger than the largest timestamp for that key (in which case you should return the value associated with the largest timestamp). Additionally, ensure that you are correctly implementing the binary search to find the appropriate timestamp and that you are correctly updating the hash map when setting values.

**Complexity:** Time: O(log n) for the get operation where n is the number of (timestamp, value) pairs for the given key (due to binary search) | Space: O(m) where m is the total number of (timestamp, value) pairs stored across all keys

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search Insert Position — LC #35 | Find insertion point in a standard flat array → exact same floor/ceiling binary search index search, but operates on a single array without a hash map wrapper | Yes — core index-finding engine |
| Stock Price Fluctuation — LC #2034 | Values fluctuate out of order and require min/max tracking across all time → use a hash map for current prices combined with a balanced BST (`std::multiset`) or min/max heaps to dynamically sort values | No — requires tracking absolute global extremes rather than localized historical snapshots |
| Design Hit Counter — LC #362 | Count hits in the last 5 minutes → use a queue or bucketed array of fixed size 300 to continuously roll over timestamp entries in $O(1)$ time | No — relies on a rolling chronological window rather than retrieval of random historical data |
| Snapshot Array — LC #1146 | Track full array states at specific snapshot IDs → store a list of `(snapshot_id, value)` pairs for each individual index, then binary search the list during a read | Yes — structural twin, mapping unique state IDs to historical records |

**How this pattern scales:**
- **Nested Binary Search within a Hash Map O(log N) retrieval** is the optimal design pattern for managing time-series or versioned databases. The hash map handles structural isolation by mapping a unique identification string (`key`) to its dedicated historical timeline in $O(1)$ time. That timeline is stored as a monotonically increasing array of structures or pairs ordered by time `(timestamp, value)`, allowing you to binary search historical states with logarithmic efficiency.
- **Floor Search logic extracts the most relevant historical snapshot**. When a database is queried for a historical state at a specific `timestamp`, an exact match is rarely guaranteed. The pattern scales by altering standard binary search into a **floor search** template:
  1. If `timeline[mid].timestamp <= target_timestamp`, you record this value as a viable candidate and advance `left = mid + 1` to see if a newer, more relevant record exists before the deadline.
  2. If `timeline[mid].timestamp > target_timestamp`, the record is from the future, so you discard it by moving `right = mid - 1`.
- **Handling out-of-bounds initialization extremes**. When querying historical sequences, boundary conditions can cause errors if not handled safely. If the requested `timestamp` is older than the very first record in the key's history array (`target_timestamp < timeline[0].timestamp`), a valid historical state does not exist yet. The system must immediately abort the binary search and return an empty string `""` to prevent indexing errors.
- **Log-Structured Merge-Trees and version control generalize from this template** → This data structure is the fundamental architecture powering production systems like Git commits, financial ledger auditing, and database isolation levels (MVCC - Multi-Version Concurrency Control). By decoupling structural entity tracking (the Hash Map) from chronological state mutations (the Binary Searched Array), you build an immutable tracking engine capable of restoring the exact state of any variable at any fraction of a second in the past.

```cpp
class TimeMap {
public:
    TimeMap() {
        //dont need to do anything here
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeMap.find(key) == timeMap.end()){
            return "";
        }
        int left = 0;
        int right = timeMap[key].size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(timeMap[key].at(mid).first == timestamp){
                return timeMap[key].at(mid).second;
            }
            else if(timeMap[key].at(mid).first < timestamp){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right >= 0 ? timeMap[key].at(right).second : "";
    }
private:
    unordered_map<string, vector<pair<int, string>>> timeMap;
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
```

## Capacity To Ship Packages Within D Days LC 1011

<!-- notecardId: 1780530998777 -->

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500

**Link**: [text](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

%

**Pattern:** Binary Search on Answer Space, Feasibility Check

**Approach:** Use binary search to find the minimum ship capacity that allows all packages to be shipped within `days` days. The search space for the ship capacity is between the maximum weight of a single package (the lower bound) and the sum of all package weights (the upper bound). For each candidate capacity, perform a feasibility check to determine if it is possible to ship all packages within `days` days at that capacity. If it is feasible, move the upper bound down; if it is not feasible, move the lower bound up. Continue this process until the lower and upper bounds converge.

**Key Insight:** The key insight is that the ship capacity must be at least the weight of the heaviest package and at most the total weight of all packages. By using binary search on this range, you can efficiently find the minimum capacity. The feasibility check is crucial for determining whether a given capacity allows all packages to be shipped within the specified number of days, which allows you to narrow down the search space effectively.

**Gotchas:** Be careful to handle edge cases where `days` is equal to the length of `weights` (in which case the minimum capacity is simply the maximum weight) or where `days` is 1 (in which case the minimum capacity is the sum of all weights). Additionally, ensure that your feasibility check correctly calculates the total number of days needed to ship all packages at a given capacity and that you are correctly updating the left and right pointers during the binary search to avoid infinite loops or incorrect results.

**Complexity:** Time: O(n log m) where n is the number of packages and m is the range of possible ship capacities (from max weight to sum of all weights) | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Koko Eating Bananas — LC #875 | Items (piles) can be partially consumed across hours → helper function calculates division rates rather than contiguous linear block grouping | Yes — identical abstract binary search framework |
| Split Array Largest Sum — LC #410 | Split a contiguous array into $m$ subarrays to minimize the maximum sum → identical problem disguised under mathematical terminology instead of a shipping metaphor | Yes — exact structural twin |
| Path With Minimum Effort — LC #1631 | Find a path from top-left to bottom-right of a 2D grid minimizing the maximum absolute difference between consecutive cells → binary search the threshold effort level, running a BFS/DFS to verify connectivity | Yes — applies the abstract binary search strategy to graph traversal |
| Book Allocation Problem — (Common Interview Variation) | Allocate contiguous books to $M$ students minimizing the maximum pages read → exact same contiguous grouping logic and range evaluation | Yes — identical logic template |

**How this pattern scales:**
- **Binary Search on the Answer space O(n log m) with contiguous constraints** is the optimal strategy when you need to minimize a maximum load threshold, and the elements **cannot be reordered or sorted**. Sorting the input array is a trap; the sequential, contiguous nature of the dataset must be preserved. Instead, you binary search the *capacity itself* across a continuous search space ranging from `max_element(weights)` (minimum capacity to carry the single heaviest item) to `sum(weights)` (maximum capacity to carry all items in one trip).
- **The Sequential Greedy Simulation acts as the validator**. For every candidate capacity `mid` generated by the binary search, an $O(n)$ greedy helper function scans the weights linearly. It accumulates weights into a single "day" or "bucket." The moment adding the next item exceeds `mid`, the simulation seals the current day, increments the `day_count`, and starts a fresh accumulator. 
- **Monotonic pass/fail feedback loops drive the search**. The validity function produces a monotonic pattern over the capacity range (e.g., `[False, False, True, True, True]`). If a capacity of `mid` successfully ships the cargo within the `days` deadline (`day_count <= days`), it is proven viable. Because any capacity *larger* than `mid` is also guaranteed to succeed, you record `mid` as a candidate solution and aggressively discard the entire right upper half by shifting `right = mid - 1`.
- **Optimization of contiguous resource partitioning generalizes** → This design framework adapts seamlessly to load balancing, network packet routing, worker schedule optimization, or assembly line partitioning. Whenever you are tasked with breaking down a fixed, sequential stream of tasks or payloads among a limited set of processors or time windows, wrapping a greedy linear packing simulator inside a logarithmic binary search engine bypasses the need for complex, expensive combinatorial allocation algorithms.

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(), weights.end(), 0); //max capacity that can be shipped in an entire day 
        int left = *max_element(weights.begin(), weights.end()); //minimum capacity must be the max weight in the weights array, or else it cannot be shipped at all.
        while(left < right){
            int mid = left + (right - left)/2; //capacity trying to ship with
            int daysNeeded = 1;
            int currentLoad = 0;
            for (int w : weights){ //go through the weights and see how many days it would take to ship with the current capacity (mid)
                if(currentLoad + w> mid){
                    daysNeeded++;
                    currentLoad = w;
                }
                else{
                    currentLoad += w;
                }
            }

            if(daysNeeded <= days){
                right = mid;

            }
            else{
                left = mid + 1;
            }

        }
        return left;
    }
};
```

## Find in Mountain Array LC 1095

<!-- notecardId: 1780531195227 -->

(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.

 

Example 1:

Input: mountainArr = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.
Example 2:

Input: mountainArr = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
 

Constraints:

3 <= mountainArr.length() <= 104
0 <= target <= 109
0 <= mountainArr.get(index) <= 109

**Link**: [text](https://leetcode.com/problems/find-in-mountain-array/)

%

**Pattern:** Binary Search on Unimodal Array

**Approach:** First, find the peak index of the mountain array using binary search. Then, perform two separate binary searches: one on the increasing part of the array (from the start to the peak) and another on the decreasing part of the array (from the peak to the end). If the target is found in either part, return its index; otherwise, return -1.

**Key Insight:** The key insight is that a mountain array has a unique peak, and the elements on either side of the peak are sorted in opposite orders (increasing on the left and decreasing on the right). By first finding the peak index, you can effectively split the problem into two binary search problems, each of which can be solved efficiently due to the sorted nature of the respective subarrays.

**Gotchas:** Be careful to handle edge cases where the target is equal to the peak element or where the target is not present in either subarray. Additionally, ensure that you are correctly implementing the binary search for both the increasing and decreasing parts of the array, and that you are correctly updating the pointers during the search to avoid infinite loops or incorrect results.

**Complexity:** Time: O(log n) for finding the peak and O(log n) for each of the two binary searches, resulting in O(log n) overall | Space: O(1) for the variables used to store indices and target value

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Peak Index in a Mountain Array — LC #852 | Only find the peak index, no target search → stop after the first phase of LC #1095 without running subsequent side searches | Yes — identical foundational phase |
| Find in Mountain Array — LC #1095 | Find the *minimum index* matching a target inside a mountain structure → requires finding the peak first, then running two separate binary searches on opposite slopes | Yes — the complete multi-phase template |
| Search in Rotated Sorted Array — LC #33 | Single-phase search where the sorted property drops off sharply at a single rotation point → evaluate localized sorted properties at `mid` directly | Partial — both handle non-monotonically sorted arrays, but LC #33 does not require isolating a global peak first |
| Find Minimum in Rotated Sorted Array — LC #153 | Find the absolute lowest point in an inflected array → find the sharp single-drop boundary rather than an increasing-then-decreasing peak | Partial — localized boundary convergence without secondary target tracking |

**How this pattern scales:**
- **Multi-Phase Binary Search O(log n)** is the optimal strategy for structural arrays that exhibit multiple distinct, predictable, monotonic zones. When a collection is non-monotonic as a whole but can be cleanly split into independently monotonic sub-regions (like a mountain array with an ascending slope and a descending slope), you solve it by isolating the exact boundaries of those zones before searching for specific values.
- **Peak isolation via directional tracking**. The first phase utilizes a modified binary search to locate the mountain peak (the transition point where the array switches from increasing to decreasing). By comparing `mountainArr.get(mid)` with `mountainArr.get(mid + 1)`, the algorithm calculates a localized slope direction. If it slopes upward, the peak lies strictly to the right (`left = mid + 1`). If it slopes downward, `mid` could be the peak or the peak lies to the left (`right = mid`). This isolates the maximum element index in $O(\log n)$ time.
- **Direction-Aware Binary Search Subroutines**. Once the peak index is found, the array is partitioned into two distinct search spaces: a standard ascending array (index `0` to `peak`) and a reversed descending array (index `peak` to `length - 1`). The pattern scales by reusing a binary search template but adjusting the comparison logic:
  1. *Ascending Side:* Standard logic applies (if `target > mid_val`, move right).
  2. *Descending Side:* Inverted logic applies (if `target > mid_val`, move left, because values shrink as indices grow).
- **Short-Circuiting for Minimum Index Constraints**. Because the problem explicitly requires returning the *minimum* index where the target appears, the order of operations matters. The algorithm runs its search on the ascending left slope first. If the target is found there, it immediately returns that index, short-circuiting and completely skipping the more expensive search on the right descending slope.

```cpp
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0;
        int right = mountainArr.length() - 1;
        int peak = -1;
        int midHolder = -1;
        bool foundInLeft = false;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        peak = left;

        if(mountainArr.get(peak) == target){
            return peak;
        }
        //do binary search here

        int left1 = 0;
        int right1 = peak - 1;
        while (left1 <= right1){
            int mid = left1 + (right1 - left1) / 2;
            if(mountainArr.get(mid) == target){
                foundInLeft = true;
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                left1 = mid + 1;
            }
            else{
                right1 = mid - 1;
            }

        }

        if(!foundInLeft){
             int right2 = mountainArr.length() -1;
        int left2 = peak + 1;
        while (left2 <= right2){
            int mid = left2 + (right2 - left2) / 2;
            if(mountainArr.get(mid) == target){
                return mid;
            }
            else if(mountainArr.get(mid) < target){
                right2 = mid - 1;
            }
            else{
                left2 = mid + 1;
            }
        }
    }
    return -1;
    }
};
```
