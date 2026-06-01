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

