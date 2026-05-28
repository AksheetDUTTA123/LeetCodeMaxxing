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

