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

## Add Two Numbers LC 2

<!-- notecardId: 1780698669318 -->

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

**Link**: [text](https://leetcode.com/problems/add-two-numbers/)

&

**Pattern:** Linked List Addition with Carry

**Approach:** Use two pointers to traverse both linked lists simultaneously, adding corresponding digits along with any carry from the previous addition. Create a new linked list to store the result. If one linked list is shorter than the other, treat missing nodes as 0. Continue this process until both linked lists are fully traversed and there is no carry left.

**Key Insight:** The key insight is that you can treat the linked lists as representations of numbers in reverse order, allowing you to add them digit by digit while managing carries. By using a dummy head for the result linked list, you can simplify the logic for appending new nodes and avoid edge cases when initializing the result list.

**Gotchas:** Be careful to handle edge cases where the linked lists have different lengths, and ensure that you correctly manage the carry when the sum of two digits exceeds 9. Additionally, make sure to check for any remaining carry after the main loop and append it to the result linked list if necessary.

**Complexity:** Time: O(max(m, n)) where m and n are the lengths of the two linked lists | Space: O(max(m, n)) for the new linked list that stores the result

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Add Binary — LC #67 | Add binary strings not linked lists → same carry propagation string instead of nodes | Partial — same carry idea |
| Multiply Strings — LC #43 | Multiply not add → digit by digit carry propagation more complex | Partial — same carry family |
| Sum of Two Integers — LC #371 | Add without arithmetic operators → bit manipulation XOR and AND carry | No — different pattern |
| Merge Two Sorted Lists — LC #21 | Merge not add → same two pointer linked list traversal different operation | Partial — same linked list structure |
| Add Two Numbers II — LC #445 | Digits stored most significant first → reverse lists or use stacks first | Yes — direct upgrade |
| Plus One — LC #66 | Add one to number stored as array → same carry propagation single pass | Partial — same carry idea |
| Linked List Cycle — LC #141 | Detect cycle not add → Floyd's fast slow pointer | No — different pattern |
| Reverse Linked List — LC #206 | Reverse not add → prev curr pointer swap | No — different pattern |

**How this pattern scales:**
- **Carry propagation** is the core trick — traverse both lists simultaneously maintaining a carry variable. At each step compute `sum = l1.val + l2.val + carry`, set `carry = sum / 10`, create new node with `sum % 10`. Continue until both lists exhausted and carry is zero. O(max(m,n)) time O(max(m,n)) space
- **Three termination conditions** — loop must continue while `l1 != null OR l2 != null OR carry != 0`. Missing the carry condition causes the last digit to be dropped when a final carry propagates beyond both list lengths — the single most common bug on this problem
- **Dummy head node pattern** — create a dummy head node and build the result list from it. Return `dummy.next` at the end. Eliminates special casing the first node and is the standard pattern for any linked list construction problem
- **Most significant first upgrade** → LC #445 stores digits most significant first making direct carry propagation impossible since carry flows from least to most significant. Two approaches: reverse both lists and apply LC #2 directly, or push all digits onto stacks and pop to simulate reverse traversal
- **Carry propagation generalizes** → Plus One (LC #66), Add Binary (LC #67), and Multiply Strings (LC #43) all use the same carry variable pattern on different data structures. The core arithmetic is identical — only the container (linked list, array, string) changes

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //start by making a new linked list
        ListNode* newLL = new ListNode(0); //this is now to create a new linked list, make a new node and this is the start
        ListNode * curr = newLL;
        int carry = 0;

        while((l1 || l2) || carry != 0){ //if carry not 0 and l1 and l2 done, need to make a new node and add the carry over
            int val1 = 0;
            int val2 = 0;
            if(l1 != nullptr){ //have to check if nullptr, if not then use val
                val1 = l1->val;
            }
            else{
                val1 = 0; //it is possible that list alr ended, so just set val1 as 0 so l2 numbers can be added
            }
            if(l2 != nullptr){
                val2 = l2->val;
            }
            else{
                val2 = 0;
            }
            curr -> next = new ListNode((val1+ val2 + carry) % 10); // 9 + 9 = 18, node will have 8 and carry will be 1
            carry = (val1+ val2 + carry) / 10; 
            curr = curr -> next; //move to next node of answer linked list
            if(l1) l1 = l1->next;  //advnace linked list if not nullptr
            if(l2) l2 = l2->next; //advnace linked list if not nullptr
        }
        return newLL->next; //return the linked list 
    }
};
```
## Remove nth Node From End of List LC 19

<!-- notecardId: 1780699036518 -->

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?

**Link**: [text](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

%

**Pattern:** Two Pointer Technique (Fast and Slow Pointers)

**Approach:** Use two pointers, `fast` and `slow`, to traverse the linked list. Move the `fast` pointer `n` steps ahead of the `slow` pointer. Then, move both pointers simultaneously until the `fast` pointer reaches the end of the list. At this point, the `slow` pointer will be at the node just before the one that needs to be removed. Adjust the `next` pointer of the `slow` node to skip the target node and return the head of the modified list.

**Key Insight:** The key insight is that by maintaining a fixed distance of `n` between the `fast` and `slow` pointers, you can effectively identify the node that needs to be removed in a single pass through the list. When the `fast` pointer reaches the end, the `slow` pointer will be positioned just before the target node, allowing for easy removal.

**Gotchas:** Be careful to handle edge cases where the node to be removed is the head of the list (when `n` is equal to the length of the list). In this case, you need to update the head pointer to point to the second node. Additionally, ensure that you are correctly updating the `next` pointers to avoid breaking the linked list structure.

**Complexity:** Time: O(sz) where sz is the number of nodes in the linked list | Space: O(1) for the pointers used to traverse the list

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Remove Linked List Elements — LC #203 | Remove all nodes with given value not nth from end → same dummy head single pointer | Partial — same removal idea |
| Delete Node in a Linked List — LC #237 | Delete node with only access to that node → copy next value no prev pointer needed | No — different pattern |
| Middle of the Linked List — LC #876 | Find middle not nth from end → same fast slow pointer different gap | Yes — direct variant |
| Linked List Cycle — LC #141 | Detect cycle → same fast slow pointer different speed | Partial — same two pointer family |
| Reorder List — LC #143 | Find middle reverse second half merge → same fast slow pointer as subroutine | Partial — same pointer idea |
| Swapping Nodes in a Linked List — LC #1721 | Swap kth from start and kth from end → same two pointer gap technique | Yes — direct variant |
| Add Two Numbers — LC #2 | Traverse two lists simultaneously → same dummy head construction pattern | Partial — same dummy head idea |
| Reverse Linked List II — LC #92 | Reverse sublist between positions → same gap pointer positioning idea | Partial — same positioning idea |

**How this pattern scales:**
- **Two pointer gap technique** is the core trick — advance fast pointer n+1 steps ahead of slow pointer. Move both at the same speed until fast reaches null. Slow now points to the node before the target. Set `slow.next = slow.next.next` to remove. O(n) time O(1) space single pass
- **n+1 gap not n** — fast must be n+1 steps ahead not n so that slow lands on the node BEFORE the target enabling the removal. Landing on the target itself means you have no reference to the previous node making deletion impossible in a singly linked list
- **Dummy head eliminates edge cases** — attach a dummy node before head and start slow at dummy. Handles removing the head node without special casing since slow always has a valid previous node to work from
- **Fast slow pointer family** → Middle of Linked List (LC #876) uses gap of `n/2`. Linked List Cycle (LC #141) uses speed ratio 2:1. LC #19 uses fixed gap of n+1. All three are variations of the same two pointer separation idea applied to different goals
- **Swapping upgrade** → LC #1721 uses the same gap technique twice — one pointer finds kth from start, another finds kth from end using the n+1 gap, then values are swapped. Direct application of LC #19's positioning logic

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * first = head;
        ListNode * second = head;
        for(int i = 0; i < n; i++){
            second = second -> next;
        }
        //this moves second to n past first ptr
        if(second == nullptr){ //if nullptr, we need to remove the head 
            return head -> next;
        }
        while(second->next != nullptr){
            second = second -> next; //moving both pointers together until we reach the end
            first = first -> next;
        }
        first-> next = first -> next -> next; //this is how to delete the node, next gets mapped to the one after the deleted node
        return head;

    }
};
```

## Merge Two Sorted Lists LC 21

<!-- notecardId: 1780699948865 -->

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

**Link**: [text](https://leetcode.com/problems/merge-two-sorted-lists/)

%

**Pattern:** Linked List Merge

**Approach:** Use two pointers to traverse both linked lists simultaneously. Compare the current nodes of both lists and append the smaller one to the merged list. Move the pointer of the list from which you took the node forward. Continue this process until you reach the end of one of the lists, then append the remaining nodes of the other list to the merged list.

**Key Insight:** The key insight is that since both linked lists are already sorted, you can efficiently merge them by always choosing the smaller current node from either list. This allows you to maintain the sorted order of the merged list without needing additional sorting steps.

**Gotchas:** Be careful to handle edge cases where one or both linked lists are empty. In such cases, you should return the non-empty list or null if both are empty. Additionally, ensure that you are correctly updating the `next` pointers to maintain the structure of the merged linked list.

**Complexity:** Time: O(m + n) where m and n are the lengths of the two linked lists | Space: O(1) for the pointers used to traverse and merge the lists (excluding the space for the new merged list)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Merge k Sorted Lists — LC #23 | Merge k lists not two → min heap or divide and conquer | Partial — direct upgrade |
| Sort List — LC #148 | Sort unsorted linked list → merge sort using LC #21 as merge step | Yes — direct application |
| Merge Sorted Array — LC #88 | Merge two sorted arrays not lists → same two pointer from back | Partial — same merge idea |
| Add Two Numbers — LC #2 | Traverse two lists with carry → same dummy head two pointer traversal | Partial — same structure |
| Remove Duplicates from Sorted List — LC #83 | Remove duplicates from single sorted list → same single pointer traversal | Partial — same sorted list idea |
| Intersection of Two Linked Lists — LC #160 | Find common node not merge → same two pointer different goal | Partial — same two pointer family |
| Palindrome Linked List — LC #234 | Find middle reverse half compare → same linked list traversal different goal | No — different pattern |
| Reorder List — LC #143 | Find middle reverse second half merge → LC #21 merge as final subroutine | Yes — direct application |

**How this pattern scales:**
- **Dummy head + two pointer merge** is the core trick — create a dummy head, maintain a current pointer, compare l1 and l2 values at each step appending the smaller node and advancing that list's pointer. After either list exhausts append the remaining list directly. O(m+n) time O(1) space
- **Append remaining directly** — when one list is exhausted do not loop through the remaining nodes one by one. Simply set `curr.next = l1 or l2` whichever is non null. The remaining list is already sorted so the entire tail can be attached in O(1)
- **Recursive alternative** — base case returns the non null list when one is null. Recursive case sets the smaller node's next to the result of merging the rest. Elegant but uses O(m+n) stack space — always prefer iterative in interviews unless recursion is explicitly requested
- **Merge sort application** → Sort List (LC #148) splits the list in half using fast/slow pointers then recursively sorts each half then merges using LC #21 as the merge step. This is the exact merge step of merge sort — mastering LC #21 means the hardest part of LC #148 is already solved
- **k list upgrade** → LC #23 generalizes to k lists using a min heap of size k. Extract minimum node from heap append to result insert that node's next into heap. Same merge logic but heap replaces the two pointer comparison — O(n log k) time

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        if(list1-> val <= list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```

## Merge k Sorted Lists LC 23

<!-- notecardId: 1780700213568 -->

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

**Link**: [text](https://leetcode.com/problems/merge-k-sorted-lists/)

%

**Pattern:** Linked List, Min Heap

**Approach:** Use a min heap (priority queue) to keep track of the smallest current node among the k linked lists. Initially, insert the head of each non-empty linked list into the min heap. Then, repeatedly extract the minimum node from the heap, add it to the merged linked list, and if the extracted node has a next node, insert that next node into the min heap. Continue this process until the min heap is empty.

**Key Insight:** The key insight is that by using a min heap, you can efficiently retrieve the smallest current node among the k linked lists at each step. This allows you to maintain the sorted order of the merged linked list without needing to compare all nodes at each step, which would be inefficient.

**Gotchas:** Be careful to handle edge cases where the input array of linked lists is empty or contains only empty linked lists. In such cases, you should return null. Additionally, ensure that you are correctly managing the pointers for the merged linked list and that you are properly inserting nodes into the min heap.

**Complexity:** Time: O(N log k) where N is the total number of nodes across all linked lists and k is the number of linked lists | Space: O(k) for the min heap that stores the current nodes of each linked list

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Merge Two Sorted Lists — LC #21 | Merge two lists not k → dummy head two pointer no heap needed | Yes — foundation |
| Sort List — LC #148 | Sort unsorted list → merge sort using LC #21 as merge step | Partial — same merge idea |
| Kth Smallest Element in Sorted Matrix — LC #378 | Kth smallest across sorted rows → same min heap extraction pattern | Yes — same pattern |
| Find K Pairs with Smallest Sums — LC #373 | K smallest pair sums → same min heap lazy expansion | Yes — same pattern |
| Ugly Number II — LC #264 | Next ugly number from k=3 sequences → same min heap k way merge | Yes — direct variant |
| Task Scheduler — LC #621 | Schedule tasks with cooldown → max heap frequency not k way merge | No — different pattern |
| Smallest Range Covering Elements from K Lists — LC #632 | Find smallest range containing one element from each list → same min heap k pointer | Yes — direct generalization |
| Top K Frequent Elements — LC #347 | K most frequent elements → heap on frequency not k way merge | Partial — same heap family |

**How this pattern scales:**
- **Min heap k way merge** is the optimal O(n log k) approach — initialize heap with the head of each non null list. Extract minimum node append to result insert that node's next into heap if non null. Repeat until heap empty. O(n log k) time O(k) space where n is total nodes
- **Divide and conquer alternative** is O(n log k) same complexity — pair up lists and merge repeatedly halving the number of lists each round. Uses LC #21 as the merge step. O(1) extra space ignoring recursion stack — cleaner to implement if you already have LC #21 memorized
- **Heap initialization matters** — only insert non null list heads. Inserting null pointers causes null pointer exceptions that are hard to debug under pressure. Always check `if (node != null)` before heap insertion
- **Custom comparator** — min heap needs a custom comparator sorting by node value not memory address. In C++ use a lambda or struct with `operator()`. In Java use `(a, b) -> a.val - b.val`. Forgetting the comparator compiles but produces garbage output
- **k way merge generalizes** → Smallest Range Covering Elements from K Lists (LC #632) extends this exact heap structure by also tracking the current maximum across all heap entries to maintain the range. Same heap with one additional running max variable

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a -> val > b -> val; //min heap
    }
};
    priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
    for(ListNode * list : lists){
        if(list != nullptr){
            minHeap.push(list); //we only want to add the head of each list to the heap, since we will be adding the next nodes as we pop from the heap
        }
    }
    ListNode * dummyHead = new ListNode(-1);
    ListNode * tail = dummyHead;
    while(!minHeap.empty()){
        ListNode * minNode = minHeap.top();
        minHeap.pop();
        tail->next = minNode;
        tail = tail-> next;
        if(minNode->next != nullptr){
            minHeap.push(minNode->next); //if the minNode has a next node, we need to add it to the heap for consideration in the next iteration
        }
    }
    return dummyHead->next;
    }

};
```

## Reverse Nodes in k-Group LC 25

<!-- notecardId: 1780701530317 -->

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?

**Link**: [text](https://leetcode.com/problems/reverse-nodes-in-k-group/)

%

**Pattern:** Linked List Reversal

**Approach:** Use a dummy head to simplify edge cases. Iterate through the linked list in groups of k nodes. For each group, reverse the nodes in place and connect the reversed group back to the main list. If the number of remaining nodes is less than k, leave them as is.

**Key Insight:** The key insight is that you can reverse a portion of the linked list in place by manipulating the `next` pointers. By using a dummy head, you can easily handle cases where the head of the list changes due to reversal. The process involves identifying the start and end of each group of k nodes, reversing that group, and then connecting it back to the main list.

**Gotchas:** Be careful to handle edge cases where the number of nodes is not a multiple of k, ensuring that the remaining nodes are left unchanged. Additionally, ensure that you are correctly updating the `next` pointers during the reversal process to maintain the integrity of the linked list.

**Complexity:** Time: O(n) where n is the number of nodes in the linked list | Space: O(1) for the pointers used to reverse the list in place

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Reverse Linked List — LC #206 | Reverse entire list not k groups → same reversal subroutine no grouping | Yes — foundation |
| Reverse Linked List II — LC #92 | Reverse sublist between two positions → same reversal subroutine fixed window | Yes — direct variant |
| Swap Nodes in Pairs — LC #24 | Reverse groups of exactly 2 → special case of LC #25 with k=2 | Yes — direct simplification |
| Rotate List — LC #61 | Rotate list by k positions → find tail connect to head different from reversal | Partial — same linked list idea |
| Reorder List — LC #143 | Find middle reverse second half merge → same reversal as subroutine | Partial — same reversal idea |
| Split Linked List in Parts — LC #725 | Split list into k parts evenly → same group counting idea different operation | Partial — same grouping idea |
| Palindrome Linked List — LC #234 | Reverse second half to compare → same reversal as subroutine | Partial — same reversal idea |
| Merge k Sorted Lists — LC #23 | Merge k lists → heap or divide and conquer no reversal | No — different pattern |

**How this pattern scales:**
- **Check k nodes exist before reversing** is the core trick — before reversing each group walk k steps to verify k nodes remain. If fewer than k nodes remain leave them as is. This check prevents partial group reversal and is the key difference from LC #92
- **Four pointer reversal** — maintain `prevGroupTail`, `groupHead`, `groupTail`, and `nextGroupHead`. After reversing k nodes reconnect `prevGroupTail.next` to new group head and `groupTail.next` to `nextGroupHead`. Getting all four connections right is the hardest implementation detail
- **Reversal subroutine** — isolate the k node reversal into a helper function that reverses a sublist and returns the new head. Keeping reversal logic separate from group management makes the code cleaner and easier to debug under pressure
- **Dummy head eliminates edge cases** — attach dummy before head so `prevGroupTail` always has a valid node to connect from. Without dummy the first group reversal requires special casing the head pointer
- **Recursive alternative** — reverse first k nodes, recursively call on remaining list, connect results. Elegant but uses O(n/k) stack space. Iterative is always preferred in interviews for O(1) space
- **k=2 simplification** → Swap Nodes in Pairs (LC #24) is LC #25 with k hardcoded to 2 — same four pointer logic but the check and reversal loop are trivially unrolled into a direct swap making the code much simpler

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = 0;
        ListNode * curr = head;
        while(curr && length < k){
            curr = curr -> next;
            length++;
        }
        if(length < k){ //increment the length to see if there are k nodes, if not then just return head
            return head;
        }
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        curr = head; //return back to the start of the linked list
        while(length > 0){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            length--;
        }
        head -> next = reverseKGroup(curr, k); //after reversing the first k nodes, head is now the last node of the reversed linked list, so we need to connect it to the next reversed linked list, which is the result of reverseKGroup(curr, k)
        head = prev;
        return head;
    }
};
```

## Reverse Linked List II LC 92

<!-- notecardId: 1780702364864 -->

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?

**Link**: [text](https://leetcode.com/problems/reverse-linked-list-ii/)

%

**Pattern:** Linked List Reversal

**Approach:** Use a dummy head to simplify edge cases. Traverse the linked list to find the node at position `left` and keep track of the node just before it. Then, reverse the nodes from position `left` to `right` in place by manipulating the `next` pointers. Finally, connect the reversed portion back to the main list and return the head of the modified list.

**Key Insight:** The key insight is that you can reverse a portion of the linked list in place by manipulating the `next` pointers. By using a dummy head, you can easily handle cases where the head of the list changes due to reversal. The process involves identifying the start and end of the sublist to be reversed, performing the reversal, and then reconnecting it back to the main list.

**Gotchas:** Be careful to handle edge cases where `left` is equal to `right`, which means no reversal is needed. Additionally, ensure that you are correctly updating the `next` pointers during the reversal process to maintain the integrity of the linked list. The challenge is connecting the rest of the list with the reversed portion correctly, especially when the reversal includes the head of the list. 

**Complexity:** Time: O(n) where n is the number of nodes in the linked list | Space: O(1) for the pointers used to reverse the list in place

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Reverse Linked List — LC #206 | Reverse entire list not sublist → same reversal no boundary tracking needed | Yes — foundation |
| Reverse Nodes in k-Group — LC #25 | Reverse in groups of k not fixed positions → same reversal subroutine repeated | Yes — direct upgrade |
| Swap Nodes in Pairs — LC #24 | Swap adjacent pairs → same reversal with k=2 fixed window | Yes — same family |
| Rotate List — LC #61 | Rotate by k positions → find tail reconnect to head different from sublist reversal | Partial — same linked list idea |
| Palindrome Linked List — LC #234 | Reverse second half to compare → same reversal as subroutine different goal | Partial — same reversal idea |
| Reorder List — LC #143 | Find middle reverse second half merge → same reversal as subroutine | Yes — direct application |
| Remove Nth Node From End — LC #19 | Remove node at position → same position finding different operation | Partial — same positioning idea |
| Reverse Words in a String — LC #151 | Reverse words not linked list nodes → same reversal idea different data structure | Partial — same reversal family |

**How this pattern scales:**
- **Four pointer setup** is the core trick — before reversing identify `prevLeft` (node before position left), `curr` (node at left), track `prev` and `next` during reversal. After reversing reconnect `prevLeft.next` to new sublist head and original `curr.next` to node after position right. O(n) time O(1) space
- **Single pass reversal** — advance to position left tracking prevLeft, then reverse exactly `right - left + 1` nodes using standard three pointer reversal (prev curr next). No need to find right boundary first since you count steps during reversal
- **Dummy head eliminates left=1 edge case** — without dummy when left=1 there is no prevLeft node making the head reconnection a special case. Dummy node gives prevLeft a valid node to work from regardless of left value
- **Reconnection order matters** — connect `curr.next` to `node after right` BEFORE connecting `prevLeft.next` to new head. Reversing the order loses the reference to the remaining list. Always set the tail connection before the head connection
- **Four step mental model**:
  1. Advance prevLeft to node before left
  2. Reverse right - left + 1 nodes
  3. Connect original left node (now tail) to node after right
  4. Connect prevLeft to original right node (now head)
- **LC #25 generalization** → Reverse Nodes in k-Group repeats this exact sublist reversal for every k group across the entire list. LC #92 is the single group case — mastering the four pointer reconnection here makes LC #25 a straightforward extension

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * dummy = new ListNode(0);
        dummy -> next = head;
        ListNode * pre = dummy;
        for(int i = 0; i < left - 1; i++){
            pre = pre -> next;
        }
        ListNode * start = pre -> next;
        ListNode * tail = start;
        for(int i = 0; i < (right - left); i++){
            tail = tail -> next;
        }
        ListNode * after = tail -> next; //after is the node after the tail, we want to reverse from start to tail, and then connect pre to tail and start to after

        ListNode * curr = start;
        ListNode * prev = nullptr;
        ListNode * next = nullptr;
        //now we got to reverse the linked list

        while(curr != after){
            next = curr-> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        //now have to set pre and after next ptr

        pre-> next = prev; //pre is the node before the start, so we want to connect it to the tail, which is now the head of the reversed linked list. at this point, prev is the tail, and curr is the node after the tail.
        //prev is at the end of the reversed linked list. Prev will move up near the beginning of the linked list, and we connect it with pre, which is the node before the start.
        start -> next = after; //start is the node at the beginning before the reverse, so after the reverse, this is the end. We then have to connect it to the node after the tail, which is after
        return dummy -> next;
    }
};
```

## Copy List with random pointer LC 138

<!-- notecardId: 1780703603717 -->

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

**Link**: [text](https://leetcode.com/problems/copy-list-with-random-pointer/)

%

**Pattern:** Linked List, Hash Map

**Approach:** Use a hash map to store the mapping between original nodes and their corresponding copied nodes. First, iterate through the original linked list and create a copy of each node, storing the mapping in the hash map. Then, iterate through the original linked list again and set the `next` and `random` pointers for each copied node using the hash map to find the corresponding copied nodes.

**Key Insight:** The key insight is that by using a hash map, you can easily keep track of the relationship between original nodes and their copies. This allows you to set the `next` and `random` pointers for the copied nodes correctly without needing to modify the original linked list or use additional data structures.

**Gotchas:** Be careful to handle edge cases where the input linked list is empty (i.e., head is null). In such cases, you should return null. Additionally, ensure that you are correctly populating the hash map and that you are using it to set both the `next` and `random` pointers for the copied nodes.

**Complexity:** Time: O(n) where n is the number of nodes in the linked list | Space: O(n) for the hash map that stores the mapping between original and copied nodes

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Clone Graph — LC #133 | Deep copy graph not linked list → same hash map node mapping DFS/BFS traversal | Yes — direct generalization |
| Copy Binary Tree with Random Pointer | Deep copy tree with random pointers → same hash map old to new node mapping | Yes — same pattern |
| Reverse Linked List — LC #206 | Reverse not copy → same linked list traversal different operation | No — different pattern |
| Flatten a Multilevel Doubly Linked List — LC #430 | Flatten nested list not copy → same pointer manipulation different goal | Partial — same linked list idea |
| Deep Copy of Directed Graph | Deep copy with arbitrary edges → same hash map mapping DFS traversal | Yes — same pattern |
| LRU Cache — LC #146 | Doubly linked list with hash map → same combined data structure idea | Partial — same hash map + list |
| Serialize and Deserialize Binary Tree — LC #297 | Encode decode tree structure → same node recreation idea different structure | Partial — same reconstruction idea |
| Find the Duplicate Number — LC #287 | Detect cycle in implicit graph → Floyd's algorithm no copying | No — different pattern |

**How this pattern scales:**
- **Hash map old to new node** is the core O(n) space approach — first pass creates all new nodes storing `original → copy` mapping in hash map. Second pass wires `next` and `random` pointers using the map to look up corresponding copy nodes. O(n) time O(n) space
- **O(1) space interleaving trick** — three pass approach without hash map: (1) interleave copy nodes between originals `1 → 1' → 2 → 2'`. (2) set random pointers `node.next.random = node.random.next`. (3) separate the two lists restoring originals and extracting copies. O(n) time O(1) space — worth mentioning as follow-up
- **Two pass is mandatory for hash map approach** — you cannot wire random pointers in a single pass because a random pointer may reference a node not yet created. The first pass ensures all copy nodes exist before any pointer wiring begins
- **Clone graph generalization** → LC #133 applies the exact same hash map old to new node mapping but uses DFS/BFS to traverse edges instead of next pointers. The hash map serves the same dual purpose — memo to avoid revisiting nodes AND lookup table for wiring edges
- **Interleaving insight** → `node.next.random = node.random.next` works because after interleaving every original node's copy sits immediately after it. So `node.random.next` is exactly the copy of `node.random` — eliminating the need for a hash map lookup entirely

```cpp
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap; //this is a mapping of old nodes to new nodes, so we can easily assign the next and random pointers in the second pass
        Node* curr = head;
        while(curr){
            Node * newNode = new Node(curr->val); //make a new node with the same value as the current node
            nodeMap[curr] = newNode;// map the current node to the new node that we just made
            curr = curr -> next; //move to the next node in the LL
        }
        curr = head; //reset current back to the beginning of the LL
        while(curr){
            nodeMap[curr]-> next = nodeMap[curr->next]; //assign the next pointer of the new node to the new node that corresponds to the next node of the current node
            nodeMap[curr]->random = nodeMap[curr->random]; //assign the random pointer of the new node to the new node that corresponds to the random node of the current node
            curr = curr -> next;
        }
        return nodeMap[head];
    }
};
```

## Linked List Cycle LC 141

<!-- notecardId: 1780704267192 -->

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

**Link**: [text](https://leetcode.com/problems/linked-list-cycle/)

%

**Pattern:** Linked List, Two Pointers

**Approach:** Use the Floyd’s Tortoise and Hare algorithm, which employs two pointers (slow and fast) to traverse the linked list. The slow pointer moves one step at a time, while the fast pointer moves two steps at a time. If there is a cycle in the linked list, the fast pointer will eventually meet the slow pointer. If there is no cycle, the fast pointer will reach the end of the list.

**Key Insight:** The key insight is that if there is a cycle, the fast pointer will eventually lap the slow pointer, causing them to meet. If there is no cycle, the fast pointer will reach the end of the list (null) without ever meeting the slow pointer. This allows you to determine the presence of a cycle in O(n) time and O(1) space.

**Gotchas:** Be careful to check for null pointers when advancing the fast pointer, as it moves two steps at a time. If the fast pointer reaches null, it means there is no cycle. Additionally, ensure that you are correctly initializing the slow and fast pointers to the head of the linked list.

**Complexity:** Time: O(n) where n is the number of nodes in the linked list | Space: O(1) for the two pointers used to traverse the list

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Linked List Cycle II — LC #142 | Find cycle entry point not just detect → same fast slow then reset slow to head | Yes — direct upgrade |
| Find the Duplicate Number — LC #287 | Duplicate in array implicit linked list → same Floyd's algorithm different structure | Yes — direct application |
| Happy Number — LC #202 | Detect cycle in number sequence → same fast slow pointer on implicit sequence | Yes — direct variant |
| Middle of the Linked List — LC #876 | Find middle not cycle → same fast slow pointer different termination | Yes — same pointer family |
| Remove Nth Node From End — LC #19 | Find nth from end not cycle → same two pointer gap technique | Partial — same two pointer family |
| Palindrome Linked List — LC #234 | Find middle reverse second half → same fast slow as subroutine | Partial — same pointer idea |
| Reorder List — LC #143 | Find middle reverse merge → same fast slow as subroutine | Partial — same pointer idea |
| Detect Cycle in Directed Graph — LC #207 | Cycle in graph not linked list → DFS with visited and recursion stack | No — different pattern |

**How this pattern scales:**
- **Floyd's cycle detection** is the core trick — fast pointer moves two steps slow pointer moves one step. If they meet a cycle exists. If fast reaches null no cycle. O(n) time O(1) space
- **Why they must meet** — if a cycle exists fast enters it and laps slow. The relative speed difference is one step per iteration so fast catches slow within at most cycle length iterations. Meeting is guaranteed because fast never skips over slow in a cycle — the gap closes by exactly one each step
- **Hash set alternative** is O(n) space — store visited nodes, return true when a node is seen twice. Easier to derive but misses the O(1) space insight interviewers look for. Always mention Floyd's as the optimal approach
- **Cycle entry point upgrade** → LC #142 adds a second phase after detection — reset slow to head keep fast at meeting point move both one step at a time. They meet at the cycle entry. Mathematical proof: distance from head to entry equals distance from meeting point to entry around the cycle
- **Implicit linked list pattern** → Find Duplicate Number (LC #287) and Happy Number (LC #202) model their problem as an implicit linked list where each value points to the next. Floyd's algorithm applies identically even though there is no actual linked list structure — the key insight is recognizing the implicit cycle

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){
            return false;
        }

        ListNode* slowPtr = head; //both start at the beginning
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next){ //while fastPtr has something after it and is valid, not a nullptr
            slowPtr = slowPtr -> next; //slow moves one at a time
            fastPtr = fastPtr -> next -> next; //fast moves two at a time
            if(slowPtr == fastPtr){
                return true; //if slow and fast ever become equal, that means pastPtr must have entered a cycle to loop back to where slowPtr is
            }
        }
        return false;

    }
};
```
## Reorder List LC 143

<!-- notecardId: 1780705095810 -->

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

**Link**: [text](https://leetcode.com/problems/reorder-list/)

%

**Pattern:** Linked List, Two Pointers

**Approach:** Use the fast and slow pointer technique to find the middle of the linked list. Then, reverse the second half of the linked list. Finally, merge the two halves together by alternating nodes from each half.

**Key Insight:** The key insight is that by using the fast and slow pointer technique, you can efficiently find the middle of the linked list in O(n) time. Reversing the second half of the list allows you to easily merge the two halves together in the required order. This approach ensures that you are only traversing the list a few times, resulting in an overall efficient solution.

**Gotchas:** Be careful to handle edge cases where the linked list has an odd number of nodes, ensuring that the middle node is correctly identified and handled during the merge process. Additionally, ensure that you are correctly reversing the second half of the linked list and that you are properly merging the two halves together without losing any nodes.

**Complexity:** Time: O(n) where n is the number of nodes in the linked list | Space: O(1) for the pointers used to manipulate the list in place

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Reverse Linked List — LC #206 | Reverse entire list not second half → same reversal subroutine simpler | Yes — foundation |
| Middle of the Linked List — LC #876 | Find middle only no reversal or merge → same fast slow pointer first step only | Yes — direct subroutine |
| Palindrome Linked List — LC #234 | Find middle reverse second half compare → same three step structure different final operation | Yes — same pattern |
| Merge Two Sorted Lists — LC #21 | Merge two sorted lists not interleave → same two pointer merge different condition | Partial — same merge idea |
| Reverse Linked List II — LC #92 | Reverse sublist between positions → same reversal subroutine different scope | Partial — same reversal idea |
| Reverse Nodes in k-Group — LC #25 | Reverse in k groups → same reversal subroutine repeated | Partial — same reversal family |
| Split Linked List in Parts — LC #725 | Split into k parts evenly → same midpoint finding idea different operation | Partial — same splitting idea |
| Flatten a Multilevel Doubly Linked List — LC #430 | Flatten nested list → same pointer rewiring different structure | No — different pattern |

**How this pattern scales:**
- **Three step decomposition** is the core trick — (1) find middle using fast/slow pointers (2) reverse second half in place (3) interleave first and second halves. Each step is a standalone problem making this one of the best examples of combining multiple linked list primitives. O(n) time O(1) space
- **Fast slow middle finding** — advance fast two steps and slow one step until fast reaches null or fast.next reaches null. Slow lands at the middle. For even length lists slow lands at the first middle node — sever the list at `slow.next = null` before reversing to avoid cycles
- **Sever before reversing** — set `slow.next = null` after finding the middle to disconnect the two halves. Failing to sever creates a cycle in the second half during reversal causing infinite loops that are extremely hard to debug
- **Interleave not merge** — the final merge alternates nodes from first and second halves regardless of value. This is different from LC #21 which merges by value comparison. The interleave condition is always `take one from first then one from second` with no comparison needed
- **Palindrome connection** → LC #234 uses the exact same three steps but replaces the interleave with a value comparison. If you can implement LC #143 you have already solved the hard part of LC #234 — both problems reduce to find middle + reverse second half with different final operations

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
      //key insight for this question 
      //find the midpoint of the linked list, use slow/fast ptrs for this
      //then, you need to reverse the second half of the linked list
      //then merge the two lists together.
      //lot of pointers  
      ListNode* slow = head;
      ListNode* fast = head;
      
      

      while (fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
      }

      //now need to reverse everything from slow to the end
      ListNode* next = nullptr;
      ListNode* prev = nullptr;
      ListNode * second = slow -> next; //this is the start of the second half of the linked list, we want to reverse this part
    slow -> next = nullptr; //this is to break the linked list into two halves, now we have two separate linked lists, one from head to slow and one from second to the end
      while(second){
        next = second -> next; //standard reverse linked list steps
        second -> next = prev;
        prev = second;
        second = next;
      }
      ListNode* left = head; //this is the start of the first half of the linked list, we want to merge this with the reversed second half which starts at prev
      ListNode * right = prev; //this is the start of the reversed second half of the linked list, we want to merge this with the first half which starts at left 
      while(right){ //while right is not null, we need to merge the two linked lists together, if right is shorter than left, then we know we are done merging because we are merging in the order of left, right, left, right, so if right is shorter than left, then we know we have merged all of right into left and we are done
      ListNode* nextLeft = left -> next; 
      ListNode* nextRight = right -> next; 
        left -> next = right; //merge the two linked lists together, left points to right, then right points to left
        right -> next = nextLeft; //right points to the next node in the left linked list
        left = nextLeft;
        right = nextRight;
      }
    }
};
```

## LRU Cache LC 146

<!-- notecardId: 1780705597567 -->

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.

**Link**: [text](https://leetcode.com/problems/lru-cache/)

%

**Pattern:** Hash Map, Doubly Linked List

**Approach:** Use a hash map to store the key-value pairs for O(1) access, and a doubly linked list to keep track of the order of usage. The most recently used items will be moved to the front of the list, while the least recently used items will be at the back. When adding a new item, if the cache exceeds its capacity, remove the item at the back of the list (the least recently used item) and delete its entry from the hash map.

**Key Insight:** The key insight is that a hash map provides O(1) access to the values based on keys, while a doubly linked list allows for efficient insertion and deletion of nodes to maintain the order of usage. By combining these two data structures, you can achieve the required O(1) time complexity for both `get` and `put` operations while also keeping track of the least recently used items.

**Gotchas:** Be careful to handle edge cases where the cache is empty or when trying to access a key that does not exist. Additionally, ensure that you are correctly updating the order of usage in the doubly linked list whenever a key is accessed or updated. When evicting the least recently used item, make sure to remove it from both the linked list and the hash map to avoid memory leaks.

**Complexity:** Time: O(1) for both `get` and `put` operations | Space: O(capacity) for the hash map and linked list storing the cache items

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| LFU Cache — LC #460 | Evict least frequently used not least recently used → hash map + frequency buckets + doubly linked list per frequency | Partial — harder upgrade |
| Design HashMap — LC #706 | Hash map without eviction policy → same hash map foundation no linked list needed | Partial — same hash map idea |
| Design Linked List — LC #707 | Implement doubly linked list operations → same doubly linked list foundation | Partial — same list structure |
| Insert Delete GetRandom O(1) — LC #380 | O(1) random access with delete → hash map + array no linked list | Partial — same O(1) design goal |
| All O(1) Data Structure — LC #432 | O(1) increment decrement get max min → doubly linked list + hash map same combined structure | Yes — direct generalization |
| Time Based Key Value Store — LC #981 | Versioned values with timestamp → hash map + binary search no eviction | Partial — same key value design |
| Design Twitter — LC #355 | Recent tweets per user → same recency tracking idea heap for feed | Partial — same recency idea |
| Snake Game — LC #353 | Track snake body with eviction from tail → same deque as sliding window | Partial — same eviction idea |

**How this pattern scales:**
- **Hash map + doubly linked list** is the core trick — hash map gives O(1) key lookup, doubly linked list maintains recency order with O(1) insertion and deletion. Most recently used at head least recently used at tail. On get move accessed node to head. On put insert at head evict tail if over capacity. O(1) all operations
- **Dummy head and tail sentinels** eliminate all edge cases — never check if head or tail is null. Insert always goes between dummy head and its current next. Remove always has valid prev and next pointers. This is non negotiable for clean implementation under pressure
- **Four pointer remove then insert** — every access (get or put) removes the node from its current position then reinserts at head. Isolate `removeNode(node)` and `insertAtHead(node)` as helper functions. Trying to do both inline leads to pointer errors under pressure
- **LFU upgrade** → LC #460 adds frequency tracking on top of the same structure. Each frequency bucket is its own doubly linked list of nodes with that frequency. A min frequency variable tracks which bucket to evict from. Same O(1) operations but three hash maps instead of one
- **The combination is the insight** — neither hash map alone nor linked list alone achieves O(1) for all operations. Hash map gives O(1) lookup but cannot track order. Linked list tracks order but gives O(n) lookup. Combining them is what makes LRU Cache one of the most instructive design problems in all of LeetCode

```cpp
struct Node{
    int key; //here we define a doubly linked list, needed for this problem
    int val;
    Node * prev;
    Node * next;
    Node(int _key, int _val){
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1); //make a dummy head and tail node that point to each other, add real nodes in between them
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        //first use the map to access from cache
        if(cache.find(key) == cache.end()){
            return -1;
        }
        //need to now update that cache and move it to most recently used
        cache[key] -> prev -> next = cache[key] -> next; //first we have to remove the node from its current position in the linked list, so we have to connect the prev and next node together
        cache[key] -> next -> prev = cache[key] -> prev;

        //move it to end of the linked list
        cache[key] -> prev = head;
        cache[key] -> next = head-> next;
        head -> next -> prev = cache[key];
        head -> next = cache[key];
        return cache[key] -> val;
    }
    
    void put(int key, int value) {
    if(cache.find(key) != cache.end()){ //if the key already exists, we just need to update the value and move it to the most recently used position
    //similar to the get function and just update the value
            cache[key]-> val = value;
        cache[key] -> prev -> next = cache[key] -> next;  //first we have to remove the node from its current position in the linked list, so we have to connect the prev and next node together
        cache[key] -> next -> prev = cache[key] -> prev;

        cache[key] -> prev = head;
        cache[key] -> next = head-> next;
        head -> next -> prev = cache[key];
        head -> next = cache[key];
        }
    else{
        Node* newNode = new Node(key, value); //need to make a new node with that key and value
        cache[key] = newNode; //map the key to the node
        newNode -> prev = head; //place node right after the head dummy node, which is the most recently used position
        newNode -> next = head -> next;
        head -> next -> prev = newNode; //update the next nodes prev and head next ptr
        head -> next = newNode;        
        if(cache.size() > capacity){ //if the cache.size() is more than capacity, we need to evict the LRU node, which is the node right before the tail dummy node
            Node * tailPrev = tail -> prev; //tailPrev is what is getting evicted, so have to set tail prev to the prev of TailPrev
            tail -> prev = tailPrev -> prev;
            tailPrev -> prev -> next = tail; //and the next of the prev of tailPrev should point to tail, hence deleting tailPrev
            cache.erase(tailPrev -> key);
        }
    }

    }
private:
    int capacity;
    unordered_map<int, Node*> cache; //unordered map that points the key to the Node in the linked list, so we can access in O(1)
    Node* head; //head and tail of the linked list, head is most recently used, tail is least recently used
    Node* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

## Reversed Linked List LC 206

<!-- notecardId: 1780706758295 -->

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

**Link**: [text](https://leetcode.com/problems/reverse-linked-list/)

%

**Pattern:** Linked List, Two Pointers

**Approach:** Use three pointers (prev, curr, next) to iteratively reverse the linked list. Initialize `prev` to null and `curr` to the head of the list. In each iteration, store the next node (`next = curr->next`), reverse the current node's pointer (`curr->next = prev`), then move `prev` and `curr` one step forward (`prev = curr`, `curr = next`). Continue this process until `curr` becomes null, at which point `prev` will be the new head of the reversed linked list.

**Key Insight:** The key insight is that by maintaining three pointers, you can reverse the linked list in place without needing additional data structures. The `prev` pointer keeps track of the reversed portion of the list, while `curr` traverses the original list. By updating the pointers in the correct order, you can effectively reverse the direction of the linked list as you iterate through it.

**Gotchas:** Be careful to handle edge cases where the linked list is empty (i.e., head is null) or has only one node. In such cases, the reversed linked list will be the same as the original linked list. Additionally, ensure that you are correctly updating the `next` pointer of each node to point to the previous node, and that you are moving the `prev` and `curr` pointers in the correct order to avoid losing access to the remaining nodes in the original list.

**Complexity:** Time: O(n) where n is the number of nodes in the linked list | Space: O(1) for the three pointers used to reverse the list in place

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Reverse Linked List II — LC #92 | Reverse sublist between positions → same three pointer reversal bounded by positions | Yes — direct upgrade |
| Reverse Nodes in k-Group — LC #25 | Reverse in groups of k → same reversal subroutine repeated with group management | Yes — direct upgrade |
| Swap Nodes in Pairs — LC #24 | Swap adjacent pairs → same reversal with k=2 | Yes — direct simplification |
| Palindrome Linked List — LC #234 | Reverse second half then compare → same reversal as subroutine | Yes — direct application |
| Reorder List — LC #143 | Find middle reverse second half interleave → same reversal as subroutine | Yes — direct application |
| Rotate List — LC #61 | Rotate by k positions → find tail reconnect no reversal needed | Partial — same linked list family |
| Reverse String — LC #344 | Reverse array not linked list → same two pointer swap different data structure | Partial — same reversal idea |
| Flatten a Multilevel Doubly Linked List — LC #430 | Flatten nested list → same pointer rewiring different structure | No — different pattern |

**How this pattern scales:**
- **Three pointer iterative reversal** is the core trick — maintain `prev` (null initially) `curr` (head initially) `next` (temp storage). At each step save `curr.next` to `next`, point `curr.next` to `prev`, advance `prev` to `curr`, advance `curr` to `next`. Return `prev` when `curr` is null. O(n) time O(1) space
- **Recursive alternative** — base case returns head when `head` or `head.next` is null. Recursive case reverses the rest then sets `head.next.next = head` and `head.next = null`. Elegant but O(n) stack space — always prefer iterative in interviews
- **Return prev not curr** — when the loop terminates `curr` is null and `prev` is the new head. Returning `curr` is the single most common bug on this problem — always return `prev`
- **Universal linked list subroutine** → LC #206 appears as a subroutine inside LC #92, LC #25, LC #143, LC #234, and LC #148. It is the single most reused linked list primitive in all of LeetCode. Implementing it from muscle memory in under 60 seconds is a baseline expectation in any linked list interview
- **Three pointer visualization** — draw three adjacent nodes with arrows before coding. Label prev curr next and trace one iteration manually. This 30 second exercise eliminates all pointer confusion and is faster than debugging a wrong implementation

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(!head || !head->next){
        return head;
       }
       ListNode* curr = head;
       ListNode* next = nullptr;
       ListNode* prev = nullptr;

       while(curr){
        next = curr->next; //have a pointer point to the node after current
        curr -> next = prev; //reverse the currents next, now it points to prev
        prev = curr; //move prev up to current
        curr = next; //move current up to the next one, keep going
       }
       head = prev;
       return head; //this is the new head
    }
};
```

## Find the Duplicate Number LC 287

<!-- notecardId: 1780707283602 -->

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?

**Link**: [text](https://leetcode.com/problems/find-the-duplicate-number/)

%

**Pattern:** Linked List Cycle Detection (Floyd's Tortoise and Hare)

**Approach:** Treat the array as a linked list where the value at each index points to the next index. Use Floyd's Tortoise and Hare algorithm to detect the cycle formed by the duplicate number. The duplicate number will be the entry point of the cycle.

**Key Insight:** The key insight is that since there are n + 1 integers and each integer is in the range [1, n], there must be at least one duplicate. By treating the array as a linked list, we can use the cycle detection algorithm to find the duplicate without modifying the array and using only constant extra space.

**Gotchas:** Be careful to handle edge cases where the duplicate number appears more than twice. The algorithm will still work as it relies on the presence of a cycle, but it's important to ensure that the implementation correctly identifies the entry point of the cycle. Additionally, make sure to initialize the slow and fast pointers correctly to avoid infinite loops.

**Complexity:** Time: O(n) where n is the number of integers in the array | Space: O(1) for the two pointers used to detect the cycle

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Linked List Cycle II — LC #142 | Find cycle entry in explicit linked list → same Floyd's two phase algorithm | Yes — direct foundation |
| Missing Number — LC #268 | Find missing not duplicate → XOR or math no cycle detection | Partial — same family |
| Find All Duplicates in Array — LC #442 | Find all duplicates not just one → same index negation marking | Partial — same index idea |
| First Missing Positive — LC #41 | Find missing positive → same index as hash map idea | Partial — same index family |
| Linked List Cycle — LC #141 | Detect cycle existence not entry → same fast slow first phase only | Yes — same foundation |
| Set Matrix Zeroes — LC #73 | Mark cells in place → same index marking idea different structure | Partial — same in place idea |
| Find the Duplicate File — LC #609 | Group files by content hash → hash map grouping no cycle detection | No — different pattern |
| Number of Subarrays with Bounded Maximum — LC #795 | Count subarrays within range → two pointer no cycle detection | No — different pattern |

**How this pattern scales:**
- **Floyd's cycle detection on implicit linked list** is the optimal O(n) time O(1) space trick — treat each value `nums[i]` as a pointer to index `nums[i]`. Since one value is duplicated two indices point to the same next node creating a cycle. Phase 1 finds meeting point with fast/slow. Phase 2 resets slow to index 0 advances both one step until they meet at the cycle entry which is the duplicate
- **Why the implicit linked list works** — array indices 0 to n map to values 1 to n with one duplicate. Each element points to another valid index creating a functional linked list structure. The duplicate value creates two pointers into the same node — exactly the condition that produces a cycle entry point
- **Three alternative approaches** worth knowing:
  - **Binary search on value** O(n log n) — for each mid count elements ≤ mid, if count > mid the duplicate is in [lo, mid]
  - **Index negation marking** O(n) time O(1) space — negate value at index nums[abs(v)], duplicate found when already negative. Modifies input
  - **Hash set** O(n) time O(n) space — simplest to derive, return on first repeated element
- **Cannot use sorting** — problem requires O(1) space and O(n) time, sorting is O(n log n). Cannot modify array makes index negation non compliant with strict constraints
- **Constraint sensitivity** — the optimal solution changes dramatically based on constraints. O(1) space + cannot modify → Floyd's. O(1) space + can modify → index negation. O(n) space allowed → hash set. Always clarify constraints before choosing approach

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //not a linked list problem, almost a two pointer problem, remember Floyd cycle dection algo tho
        int slow = nums[0]; //start at the beginning
        int fast = nums[0]; //start at the beginning
        while(true){
            slow = nums[slow]; //slow moves one step at a time, so we just follow the value of the current index to the next index
            fast = nums[nums[fast]]; //fast moves two steps at a time, so we follow the value of the current index to the next index, and then follow that value to the next index again
            if(slow == fast){
                break; //if equal, we found a point in the cycle 
            }
        }
        fast = nums[0]; //move fast back to the beginning, now we will move both slow and fast one step at a time until they meet, that is the start of the cycle, which is the duplicate number
        while(slow != fast){
            slow = nums[slow]; //move slow up by one, slow is alr at a point in the cycle
            fast = nums[fast]; //fast is at the beginning, so we follow the value to move it up by one, if it is not the duplicate, it will eventually meet up with slow at the cycle at the start of the cycle
        }
        return slow; //this is the start of the cycle
    }
    /*
    ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;          // Move 1 step
            fast = fast->next->next;    // Move 2 steps
            if (slow == fast) {
                break;                  // Intersection point found
            }
        }
        
        // Edge case: If there is no cycle in the linked list
        if (!fast || !fast->next) {
            return nullptr; 
        }

        // Phase 2: Find the entrance of the cycle (the duplicate)
        fast = head;                    // Reset fast to the beginning
        while (slow != fast) {
            slow = slow->next;          // Move both 1 step at a time
            fast = fast->next;
        }
        
        return slow;                    // This is the node where the duplicate occurs
    }
    */
};
```

## LFU Cache LC 460

<!-- notecardId: 1780708764510 -->

Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

Explanation
// cnt(x) = the use counter for key x
// cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
LFUCache lfu = new LFUCache(2);
lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lfu.get(1);      // return 1
                 // cache=[1,2], cnt(2)=1, cnt(1)=2
lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                 // cache=[3,1], cnt(3)=1, cnt(1)=2
lfu.get(2);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,1], cnt(3)=2, cnt(1)=2
lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                 // cache=[4,3], cnt(4)=1, cnt(3)=2
lfu.get(1);      // return -1 (not found)
lfu.get(3);      // return 3
                 // cache=[3,4], cnt(4)=1, cnt(3)=3
lfu.get(4);      // return 4
                 // cache=[4,3], cnt(4)=2, cnt(3)=3
 

Constraints:

1 <= capacity <= 104
0 <= key <= 105
0 <= value <= 109
At most 2 * 105 calls will be made to get and put.
 
**Link**: [text](https://leetcode.com/problems/lfu-cache/)

%

**Pattern:** Hash Map, Doubly Linked List

**Approach:** Use a hash map to store the key-value pairs and their corresponding frequencies. Use a doubly linked list to maintain the order of keys based on their frequencies. Each frequency will have its own linked list of keys. When a key is accessed or updated, move it to the appropriate frequency list. When evicting, remove the least frequently used key from the lowest frequency list.

**Key Insight:** The key insight is that by maintaining a hash map for O(1) access to key-value pairs and a doubly linked list for each frequency, you can efficiently track the least frequently used keys. When a key's frequency changes, you can move it to the appropriate list in O(1) time. This structure allows you to meet the requirement of O(1) time complexity for both `get` and `put` operations while also keeping track of the least frequently used keys.

**Gotchas:** Be careful to handle edge cases where multiple keys have the same frequency. In such cases, you need to ensure that you are evicting the least recently used key among those with the same frequency. Additionally, make sure to correctly update the frequency lists when a key's frequency changes, and to remove empty frequency lists when necessary. You also need a hash map storing the iterators for each key to its position in the frequency list to allow O(1) updates.

**Complexity:** Time: O(1) for both `get` and `put` operations | Space: O(capacity) for the hash map and linked lists storing the cache items

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| LRU Cache — LC #146 | Evict least recently used not least frequently → hash map + single doubly linked list | Yes — foundation |
| All O(1) Data Structure — LC #432 | O(1) increment decrement get max min → same doubly linked list + hash map structure | Yes — direct generalization |
| Design HashMap — LC #706 | Hash map without eviction → same hash map foundation no frequency tracking | Partial — same hash map idea |
| First Unique Character in a String — LC #387 | Find least frequent character → frequency map no eviction needed | Partial — same frequency idea |
| Top K Frequent Elements — LC #347 | Find k most frequent → heap or bucket sort no eviction | Partial — same frequency tracking |
| Design Twitter — LC #355 | Recent tweets per user → recency not frequency tracking | Partial — same design family |
| Insert Delete GetRandom O(1) — LC #380 | O(1) random access with delete → hash map + array no frequency | Partial — same O(1) design goal |
| Snake Game — LC #353 | Track body with tail eviction → deque not frequency map | No — different pattern |

**How this pattern scales:**
- **Three hash maps + doubly linked list per frequency** is the core structure — `keyToVal` maps key to value, `keyToFreq` maps key to its current frequency, `freqToList` maps each frequency to a doubly linked list of keys at that frequency (ordered by recency within frequency). `minFreq` tracks the current minimum frequency for O(1) eviction. All operations O(1)
- **minFreq update rules** — on get: increment key's frequency update freqToList remove from old freq add to new freq update minFreq only if old freq list becomes empty AND old freq == minFreq. On put new key: always set minFreq = 1 since new keys start at frequency 1
- **LRU within each frequency bucket** — within each frequency's doubly linked list nodes are ordered by recency most recent at head least recent at tail. When two keys have the same frequency the least recently used one is evicted — same LRU logic as LC #146 but scoped per frequency bucket
- **LRU → LFU upgrade path** — LC #146 uses one doubly linked list for all keys ordered by recency. LC #460 replaces that with one doubly linked list PER frequency level. Everything else (dummy sentinels, removeNode, insertAtHead helpers, hash map lookup) is identical — the only structural addition is the frequency layer
- **minFreq is the critical invariant** — always know the current minimum frequency so eviction is O(1). The only time minFreq increases is when a get or put increments the only key at minFreq — detected by checking if `freqToList[minFreq]` is empty after removal. On put of a new key minFreq always resets to 1

```cpp
struct Node {
    int key;
    int val;
    int freq;
    Node * prev;
    Node * next;
    Node(int _key, int _val){
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
        freq = 1;
    }
};


class LFUCache {
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        int oldFreq = cache[key]-> freq;
        freqMap[oldFreq].erase(iterMap[key]);
        if(freqMap[oldFreq].empty()){
            freqMap.erase(oldFreq);
            if(minFreq == oldFreq){
                minFreq++;
            }
        }
        //need to update the frequency of the node and move it to the correct position in the linked list
        cache[key] -> freq++;

        //move it to the correct position in the linked list based on its frequency
        freqMap[cache[key]->freq].push_back(cache[key]);
        iterMap[key] = prev(freqMap[cache[key]->freq].end());
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0){
            return;
        }
        if(cache.find(key) != cache.end()){
        cache[key]->val = value; 
        int oldFreq = cache[key] -> freq;
        freqMap[oldFreq].erase(iterMap[key]);
        if(freqMap[oldFreq].empty()){
            freqMap.erase(oldFreq);
            if(minFreq == oldFreq){
                minFreq++;
            }
        }
        cache[key] -> freq++;

        //move it to the correct position in the linked list based on its frequency
        freqMap[cache[key]->freq].push_back(cache[key]);
        iterMap[key] = prev(freqMap[cache[key]->freq].end());
    }
    else{
        if(cache.size() == capacity){
            //evict the least frequently used node, which is the node with the lowest frequency in the linked list
            Node * nodeToEvict = freqMap[minFreq].front();
            freqMap[minFreq].pop_front();
            cache.erase(nodeToEvict->key);
            iterMap.erase(nodeToEvict->key);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        freqMap[1].push_back(cache[key]);
        iterMap[key] = prev(freqMap[1].end());
        minFreq = 1;
    }
    }
private:
 unordered_map<int, Node*> cache;
  unordered_map<int, list<Node*>> freqMap;
  unordered_map<int, list<Node*>::iterator> iterMap;
  int minFreq = 0;
  int capacity;
  Node* head;
  Node *tail;

};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

## Design Circular Queue LC 622

<!-- notecardId: 1780709617332 -->

Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.
You must solve the problem without using the built-in queue data structure in your programming language. 

 

Example 1:

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]

Explanation
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 3000 calls will be made to enQueue, deQueue, Front, Rear, isEmpty, and isFull.

**Link**: [text](https://leetcode.com/problems/design-circular-queue/)

%

**Pattern:** Array, Two Pointers

**Approach:** Use a fixed-size array to store the elements of the circular queue. Maintain two pointers, `front` and `rear`, to track the positions of the front and rear elements in the queue. The `enQueue` operation adds an element at the rear pointer and moves it forward, while the `deQueue` operation removes an element from the front pointer and moves it forward. Use modulo arithmetic to wrap around the pointers when they reach the end of the array.

**Key Insight:** The key insight is that by using a fixed-size array and two pointers, you can efficiently implement a circular queue without needing to shift elements as in a normal queue. The modulo operator allows the pointers to wrap around to the beginning of the array when they reach the end, creating a circular structure. This approach allows you to achieve O(1) time complexity for both `enQueue` and `deQueue` operations while maintaining a fixed capacity.

**Gotchas:** Be careful to handle edge cases where the queue is empty or full. When the queue is full, the `enQueue` operation should return false and not add the new element. When the queue is empty, the `deQueue` operation should return false and not remove any element. Additionally, make sure to correctly update the `front` and `rear` pointers after each operation, and to use modulo arithmetic to wrap around the pointers when necessary.

**Complexity:** Time: O(1) for both `enQueue` and `deQueue` operations | Space: O(k) for the fixed-size array used to store the elements of the circular queue

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Design Circular Deque — LC #641 | Double ended circular queue → same circular array add front/back remove front/back | Yes — direct upgrade |
| Implement Queue Using Stacks — LC #232 | Simulate queue with stacks → amortized O(1) no circular array | Partial — same queue design |
| Implement Stack Using Queues — LC #225 | Simulate stack with queues → rotation trick no circular array | Partial — same design family |
| Moving Average from Data Stream — LC #346 | Sliding window average → same circular buffer fixed size | Yes — direct application |
| Design Hit Counter — LC #362 | Count hits in last 300 seconds → same circular buffer time window | Yes — direct application |
| Number of Recent Calls — LC #933 | Count calls in last 3000ms → queue as sliding window | Partial — same window idea |
| Snake Game — LC #353 | Track snake body with head/tail → same circular queue eviction idea | Partial — same circular idea |
| LRU Cache — LC #146 | Evict least recently used → doubly linked list not circular array | No — different pattern |

**How this pattern scales:**
- **Fixed size array + head/tail pointers + size counter** is the core trick — `head` points to front element `tail` points to next empty slot. Enqueue writes to `tail` then advances `tail = (tail + 1) % capacity`. Dequeue reads from `head` then advances `head = (head + 1) % capacity`. Size counter tracks current elements for isEmpty and isFull checks. O(1) all operations
- **Modulo wrapping** is the key insight — `(index + 1) % capacity` wraps any index back to 0 when it reaches capacity. This is what makes the array circular without physically moving elements. All circular buffer problems reduce to this single modulo formula
- **Size counter vs head == tail ambiguity** — without a size counter an empty queue and a full queue both have `head == tail` making them indistinguishable. Always maintain a separate size counter or use `capacity - 1` usable slots reserving one slot as a sentinel to distinguish the two states
- **Circular buffer generalizes** → Moving Average (LC #346) and Design Hit Counter (LC #362) use the exact same fixed size circular array — new values overwrite the oldest at the tail position. Same modulo wrapping, same head/tail advancement, different semantic meaning of the stored values
- **Deque upgrade** → LC #641 adds `enqueueFront` and `dequeueBack` operations. Front insertion uses `head = (head - 1 + capacity) % capacity` to wrap backwards — the `+ capacity` prevents negative modulo which behaves differently across languages

```cpp
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        arr.resize(k);
        start = 0;
        end = 0;
        count = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if(count == capacity){
            return false;
        }
        arr[end] = value;
        end = (end + 1) % capacity;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (count == 0) return false;
        start = (start + 1) % capacity; //move the start pointer up, and if it goes past the end of the array, it wraps around to the beginning
        //we modify start because queue is fifo, so beginning of the queue is what is popped out.
        count --;
        return true;
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }
        return arr[start];
    }
    
    int Rear() {
    if(isEmpty()){
            return -1;
        }
        return arr[(end - 1 + capacity) % capacity]; //why this works, if end is at the beginning of the array, end - 1 will be -1, but we can add capacity to it, and then mod by capacity, it will wrap around to the end of the array, which is the rear of the queue.
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == capacity);
    }
    private:
    vector<int> arr;
    int start;
    int end;
    int count;
    int capacity;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
```

## Binary Tree inorder traversal LC 94

<!-- notecardId: 1780851444188 -->

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

**Link**: [text](https://leetcode.com/problems/binary-tree-inorder-traversal/)

%

**Pattern:** Tree Traversal, Stack

**Approach:** Use a stack to iteratively traverse the binary tree in inorder (left, root, right). Start from the root and keep pushing left children onto the stack until you reach a null. Then pop from the stack, add the node's value to the result, and move to the right child. Repeat this process until both the stack is empty and the current node is null.

**Key Insight:** The key insight is that the inorder traversal can be simulated using a stack to keep track of the nodes. By pushing all left children onto the stack, you can ensure that you visit the leftmost node first. When you pop from the stack, you are visiting the root of the current subtree, and then you can move to the right child to continue the traversal. This iterative approach allows you to achieve O(n) time complexity without using recursion.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the result should be an empty list. Additionally, make sure to correctly manage the stack and the current node pointer to avoid infinite loops or null pointer exceptions. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Preorder Traversal — LC #144 | Visit root before children → same iterative stack different push order | Yes — direct variant |
| Binary Tree Postorder Traversal — LC #145 | Visit root after children → same iterative stack reversed preorder trick | Yes — direct variant |
| Validate Binary Search Tree — LC #98 | Inorder must be strictly increasing → same inorder traversal with value check | Yes — direct application |
| Kth Smallest Element in BST — LC #230 | Kth element in inorder sequence → same inorder traversal stop at kth | Yes — direct application |
| Binary Search Tree Iterator — LC #173 | Inorder traversal on demand → same iterative inorder stack held between calls | Yes — direct application |
| Flatten Binary Tree to Linked List — LC #114 | Preorder traversal rewiring nodes → same traversal different operation | Partial — same traversal family |
| Recover Binary Search Tree — LC #99 | Find swapped nodes in inorder sequence → same inorder traversal track prev node | Yes — direct application |
| Morris Traversal | Inorder with O(1) space no stack → thread right pointers to inorder successor | Yes — space optimized upgrade |

**How this pattern scales:**
- **Iterative stack inorder** is the core pattern — push all left children onto stack, pop and visit, move to right child, repeat. O(n) time O(h) space where h is tree height
- **Three traversal order comparison**:
  - **Preorder** (root left right) → push right then left so left is processed first
  - **Inorder** (left root right) → push all lefts first pop visit move right
  - **Postorder** (left right root) → reverse of modified preorder (root right left) → push left then right reverse result
- **BST inorder is sorted** — inorder traversal of a BST always produces a strictly increasing sequence. This property unlocks LC #98, LC #230, LC #173, and LC #99 — all four reduce to inorder traversal with an additional condition check
- **BST Iterator connection** → LC #173 is the most important application — it holds the iterative inorder stack as instance state between `next()` calls, producing one element at a time on demand. This is the exact stack from iterative inorder traversal paused mid-execution between calls
- **Morris traversal** is the O(1) space upgrade — thread each node's rightmost left subtree node back to the node itself as an inorder successor pointer. Eliminates the stack entirely. Worth mentioning as a follow-up when interviewer asks for O(1) space solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     if (root == nullptr) return result; //base case for recursion, if the node is null, return empty vector
    //    vector<int> leftSide = inorderTraversal(root->left); //recursively call the left side of the tree, this will return a vector of the left side of the tree in order
    //    result.insert(result.end(), leftSide.begin(), leftSide.end()); //add the result of the left side to the result vector, remember inorder is left, root, right
    // result.push_back(root->val); //push back the root value to the result vector
    //     vector<int> rightSide = inorderTraversal(root->right); //recursively call the right side of the tree, this will return a vector of the right side of the tree in order
    //     result.insert(result.end(), rightSide.begin(), rightSide.end());
    //     return result;
    //above was recursive solution

    //below is iterative solution

    vector<int> result;
    stack<TreeNode*> treeNodes; //for the iterative design, you need a stack to keep track of the nodes you have visited, 
    //this is because you need to go back up the tree after you have visited the left side, and then go to the right side, so you need to keep track of the nodes you have visited in order to go back up the tree
    TreeNode* curr = root; //start at the root node

    while(curr != NULL || !treeNodes.empty()){
        while(curr != NULL){ //while not at the end of the left side, keep going left and pushing the nodes into the stack
            treeNodes.push(curr);
            curr = curr -> left;
        }
        curr = treeNodes.top(); //get the top of the stack, this is the node you need to visit, because you have already visited the left side, so now you need to visit the root node
        treeNodes.pop();
        result.push_back(curr->val);
        curr = curr -> right; //after visiting the root node, you need to go to the right side, so you need to set the current node to the right child of the current node, 
        //this will allow you to go to the right side of the tree and repeat the process of going left and visiting the nodes until you reach the end of the tree
    }
    return result;
    }

    //Morris Algorithm for O(1) space inorder traversal
        vector<int> morrisInorderTraversal(TreeNode* root) {
            vector<int> result;
            TreeNode* curr = root;
    
            while (curr != nullptr) {
                if (curr->left == nullptr) {
                    result.push_back(curr->val); // Visit the node
                    curr = curr->right; // Move to the right child
                } else {
                    // Find the inorder predecessor of curr
                    TreeNode* pred = curr->left;
                    while (pred->right != nullptr && pred->right != curr) {
                        pred = pred->right;
                    }
    
                    if (pred->right == nullptr) {
                        // Make curr the right child of its inorder predecessor
                        pred->right = curr;
                        curr = curr->left; // Move to the left child
                    } else {
                        // Revert the changes made in the 'if' part to restore the original tree
                        pred->right = nullptr;
                        result.push_back(curr->val); // Visit the node
                        curr = curr->right; // Move to the right child
                    }
                }
            }
    
            return result;
        }
};
```
## Binary Tree Preorder Traversal LC 144

<!-- notecardId: 1780853227032 -->

Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

**Link**: [text](https://leetcode.com/problems/binary-tree-preorder-traversal/)

%

**Pattern:** Tree Traversal, Stack

**Approach:** Use a stack to iteratively traverse the binary tree in preorder (root, left, right). Start from the root and push it onto the stack. Then, while the stack is not empty, pop the top node, add its value to the result, and push its right child followed by its left child onto the stack (if they exist). This ensures that the left child is processed before the right child.

**Key Insight:** The key insight is that the preorder traversal can be simulated using a stack to keep track of the nodes. By pushing the right child before the left child, you ensure that the left child is processed first when popping from the stack. This iterative approach allows you to achieve O(n) time complexity without using recursion.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the result should be an empty list. Additionally, make sure to correctly manage the stack and the current node pointer to avoid infinite loops or null pointer exceptions. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Inorder Traversal — LC #94 | Visit root between children → same stack different push order | Yes — direct variant |
| Binary Tree Postorder Traversal — LC #145 | Visit root after children → reversed modified preorder trick | Yes — direct variant |
| Binary Tree Level Order Traversal — LC #102 | Visit level by level → BFS queue not DFS stack | Partial — same traversal family |
| Flatten Binary Tree to Linked List — LC #114 | Rewire nodes in preorder → same preorder traversal different operation | Yes — direct application |
| Serialize and Deserialize Binary Tree — LC #297 | Encode decode tree structure → preorder traversal as encoding order | Yes — direct application |
| Path Sum — LC #112 | Check if root to leaf sum equals target → same preorder DFS different operation | Yes — same DFS family |
| Construct Binary Tree from Preorder and Inorder — LC #105 | Rebuild tree from traversal orders → preorder gives root inorder gives split | Yes — direct application |
| N-ary Tree Preorder Traversal — LC #589 | Preorder on tree with multiple children → same stack push children right to left | Yes — direct generalization |

**How this pattern scales:**
- **Iterative stack preorder** is the core pattern — push root visit it push right child then left child (so left is processed first). Pop visit push children repeat until stack empty. O(n) time O(h) space where h is tree height
- **Push right before left** — stack is LIFO so push right child first so left child sits on top and is processed first. Reversing this order produces a right-first preorder — a common bug that produces wrong results on asymmetric trees
- **Three traversal comparison**:
  - **Preorder** (root left right) → push right then left visit on push
  - **Inorder** (left root right) → push all lefts first pop visit move right
  - **Postorder** (left right root) → modified preorder (root right left) then reverse result
- **Serialize connection** → LC #297 uses preorder as the natural serialization order because the root always appears first making deserialization trivial — the first element is always the root, recurse left then right. Preorder is the only traversal where this root-first property holds
- **Flatten connection** → LC #114 rewires nodes to follow preorder sequence in place. The preorder stack gives you nodes in exactly the order they should appear in the flattened list — same traversal, pointer rewiring instead of value collection
- **N-ary generalization** → LC #589 pushes all children right to left instead of just two. Same LIFO logic — push rightmost child first so leftmost sits on top and is processed first. One line change from binary to n-ary

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // if(root == nullptr){
        //     return ans;
        // }
        // ans.push_back(root->val);
        // vector<int> leftside = preorderTraversal(root->left);
        // ans.insert(ans.end(), leftside.begin(), leftside.end());
        // vector<int> rightside = preorderTraversal(root->right);
        // ans.insert(ans.end(), rightside.begin(), rightside.end());
        // return ans;
         stack<TreeNode*> treeNodes; //for the iterative design, you need a stack to keep track of the nodes you have visited, 
        //this is because you need to go back up the tree after you have visited the left side, and then go to the right side, so you need to keep track of the nodes you have visited in order to go back up the tree
        TreeNode* curr = root; //start at the root node

     while(curr != NULL || !treeNodes.empty()){
        while(curr != NULL){ //while not at the end of the left side, keep going left and pushing the nodes into the stack
            ans.push_back(curr->val);
            treeNodes.push(curr);
            curr = curr -> left;
        }
        curr = treeNodes.top(); //get the top of the stack, this is the node you need to visit, because you have already visited the left side, so now you need to visit the root node
        treeNodes.pop();
        curr = curr -> right; //after visiting the root node, you need to go to the right side, so you need to set the current node to the right child of the current node, 
        //this will allow you to go to the right side of the tree and repeat the process of going left and visiting the nodes until you reach the end of the tree
    }
    return ans;

    }
};
```

## Binary Tree Postorder Traversal LC 145

<!-- notecardId: 1780859781543 -->

Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [3,2,1]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,6,7,5,2,9,8,3,1]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

**Link**: [text](https://leetcode.com/problems/binary-tree-postorder-traversal/)

%

**Pattern:** Tree Traversal, Stack

**Approach:** Use a stack to iteratively traverse the binary tree in postorder (left, right, root). Start from the root and push it onto the stack. Then, while the stack is not empty, pop the top node, add its value to the result, and push its left child followed by its right child onto the stack (if they exist). This ensures that the right child is processed before the left child. Finally, reverse the result list to get the correct postorder sequence. If doing it without reversing, you can modify the order of pushing children to achieve postorder directly.

**Key Insight:** The key insight is that the postorder traversal can be simulated using a stack to keep track of the nodes. By pushing the left child before the right child, you ensure that the right child is processed first when popping from the stack. This iterative approach allows you to achieve O(n) time complexity without using recursion. The reversal at the end is necessary because we are effectively doing a modified preorder (root, right, left) which gives us the nodes in reverse postorder.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the result should be an empty list. Additionally, make sure to correctly manage the stack and the current node pointer to avoid infinite loops or null pointer exceptions. Always check if the current node is null before trying to access its value or children. If you choose to do it without reversing at the end, be careful with the order of pushing children onto the stack.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Preorder Traversal — LC #144 | Visit root before children → same stack push right then left visit on push | Yes — direct variant |
| Binary Tree Inorder Traversal — LC #94 | Visit root between children → push all lefts pop visit move right | Yes — direct variant |
| Binary Tree Level Order Traversal — LC #102 | Visit level by level → BFS queue not DFS stack | Partial — same traversal family |
| Delete Nodes and Return Forest — LC #1110 | Postorder to process children before parent → same bottom up traversal | Yes — direct application |
| Binary Tree Maximum Path Sum — LC #124 | Compute max path bottom up → same postorder children before parent | Yes — direct application |
| Lowest Common Ancestor — LC #236 | Find LCA bottom up → same postorder return values up the tree | Yes — direct application |
| Serialize and Deserialize Binary Tree — LC #297 | Preorder encoding easier than postorder → same traversal family different encoding order | Partial — same traversal family |
| Construct Binary Tree from Inorder and Postorder — LC #106 | Rebuild tree using postorder and inorder → postorder gives root from right end | Yes — direct application |

**How this pattern scales:**
- **Reverse modified preorder** is the cleanest iterative trick — run modified preorder visiting root then RIGHT then left, collect results, reverse at end. Produces left right root which is postorder. O(n) time O(n) space for result storage
- **Three traversal comparison**:
  - **Preorder** (root left right) → push right then left visit on pop
  - **Inorder** (left root right) → push all lefts pop visit move right
  - **Postorder** (left right root) → modified preorder (root right left) reversed
- **Bottom up property** is the key insight — postorder processes children before parents making it the natural traversal for problems where a node's answer depends on its children's answers. Any problem asking "compute something at each node using its subtree" uses postorder
- **Delete Nodes connection** → LC #1110 must process children before deciding whether to delete a parent — postorder guarantees children are handled first. Same bottom up dependency pattern
- **Construct from postorder** → LC #106 uses the fact that the last element of postorder is always the root — mirror of preorder where the first element is the root. Postorder gives root from the right end, inorder gives the left/right split

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // if(root == nullptr){
        //     return ans;
        // }
        // vector<int> leftside = postorderTraversal(root->left);
        // ans.insert(ans.end(), leftside.begin(), leftside.end());
        // vector<int> rightside = postorderTraversal(root->right);
        // ans.insert(ans.end(), rightside.begin(), rightside.end());
        // ans.push_back(root->val);
        // return ans;
         stack<TreeNode*> treeNodes; //for the iterative design, you need a stack to keep track of the nodes you have visited, 
        //this is because you need to go back up the tree after you have visited the left side, and then go to the right side, so you need to keep track of the nodes you have visited in order to go back up the tree
        TreeNode* curr = root; //start at the root node
        TreeNode* lastVisited = nullptr; //keep track of the last visited node, this is important because you need to know when you have visited the right side of the tree, so you can visit the root node after you have visited the right side, you can visit the root node,
        // but if you have not visited the right side, you cannot visit the root node, because you need to visit the right side before you can visit the root node in postorder traversal

     while(curr != NULL || !treeNodes.empty()){
        while(curr != NULL){ //while not at the end of the left side, keep going left and pushing the nodes into the stack
            treeNodes.push(curr);
            curr = curr -> left;
        }
        
        curr = treeNodes.top(); //get the top of the stack, this is the node you need to visit, because you have already visited the left side, so now you need to visit the root node
        if(curr -> right == NULL || curr -> right == lastVisited) {
            //if the right child is null or the right child is the last visited node, then you can visit the root node
        ans.push_back(curr->val);
        lastVisited = curr; //update the last visited node to the current node, because you have just visited the current node, so you need to update the last visited node to the current node, this will allow you to keep track of the last visited node, so you can know when you have visited the right side of the tree
        treeNodes.pop();
        curr = nullptr; //after visiting the root node, you need to set the current node to null, because you have already visited the current node, so you need to set the current node to null, this will allow you to go back up the tree and visit the next node in the stack, which is the parent node of the current node, this will allow you to visit the parent node after you have visited the left and right side of the tree
    }
    else{
        curr = curr -> right; //if the right child is not null and the right child is not the last visited node, then you need to go to the right side of the tree, so you need to set the current node to the right child of the current node,
    }
    }
    
        return ans;
            }

};
```

## Binary Tree Level Order Traversal LC 102

<!-- notecardId: 1780980394512 -->

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

**Link**: [text](https://leetcode.com/problems/binary-tree-level-order-traversal/)

%

**Pattern:** Tree Traversal, Breadth-First Search (BFS), Queue

**Approach:** Use a queue to perform a breadth-first search (BFS) on the binary tree. Start by enqueueing the root node. Then, while the queue is not empty, process each level of the tree by dequeuing all nodes at the current level, adding their values to a list, and enqueueing their non-null left and right children. Repeat this process until all levels have been processed.

**Key Insight:** The key insight is that level order traversal can be efficiently achieved using a queue to keep track of the nodes at each level. By processing all nodes at the current level before moving on to the next level, you can easily group the values by level. This approach allows you to achieve O(n) time complexity, where n is the number of nodes in the tree.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the result should be an empty list. Additionally, make sure to correctly manage the queue and the current level's node count to avoid infinite loops or null pointer exceptions. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(m) where m is the maximum number of nodes at any level (worst case O(n/2) for a complete binary tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Zigzag Level Order — LC #103 | Alternate direction each level → same BFS flip insert direction per level | Yes — direct variant |
| Binary Tree Level Order Traversal II — LC #107 | Bottom up level order → same BFS reverse result at end | Yes — direct variant |
| Average of Levels in Binary Tree — LC #637 | Average not collect nodes per level → same BFS sum divide by level size | Yes — direct variant |
| Minimum Depth of Binary Tree — LC #111 | First leaf level → same BFS return level count on first leaf | Yes — direct application |
| Maximum Depth of Binary Tree — LC #104 | Deepest level → same BFS count total levels | Yes — direct variant |
| Populating Next Right Pointers — LC #116 | Wire next pointers within each level → same BFS process level by level | Yes — direct application |
| Word Ladder — LC #127 | Shortest path in word graph → same BFS level by level different structure | Partial — same BFS family |
| Binary Tree Right Side View — LC #199 | Last node of each level → same BFS collect last node per level | Yes — direct variant |

**How this pattern scales:**
- **BFS with level size snapshot** is the core trick — use a queue initialized with root. At the start of each level snapshot `levelSize = queue.size()`. Process exactly `levelSize` nodes collecting their values and enqueuing their children. Append level to result. O(n) time O(w) space where w is maximum width
- **Level size snapshot is critical** — snapshotting queue size at the start of each level is what separates nodes by level. Without the snapshot all nodes blur into one continuous BFS stream with no level boundaries
- **Queue vs deque for zigzag** → LC #103 alternates insertion direction each level. Use a deque and append to front or back depending on current level parity. Same BFS skeleton, deque replaces queue, one direction flag added
- **BFS is the natural level tool** — DFS can compute level order but requires carrying depth as a parameter and sorting by depth at the end. BFS processes nodes level by level naturally making it always preferable for level based problems
- **Right side view** → LC #199 is the most elegant BFS variant — collect only the last node of each level. Same level size snapshot loop, replace level collection with single last node capture. One line change from full level order
- **Word Ladder connection** → LC #127 applies BFS level counting to a graph instead of a tree. Level number equals shortest path length. Same queue initialization snapshot processing structure — the data structure changes but the BFS skeleton is identical

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result; //empty tree, return empty result, needed
        std::queue<TreeNode*> q1; //make a queue that stores for each level, we need first in first out.
        q1.push(root); //start with root
        while(!q1.empty()){
            int nodesInLevel = q1.size(); //at this moment, we know what nodes are in this level, needed for loop
            vector<int> levelNodes; //vector container that holds every node in this level
            for(int i = 0; i < nodesInLevel; i++){
                TreeNode* top = q1.front(); //pop the top and add to nodes in this level
                q1.pop();
                levelNodes.push_back(top -> val);
                if (top->left != nullptr) q1.push(top->left); //add the next levels nodes to the end of the queue, these will then get added for the next level once this level
                //has been added
                if (top->right != nullptr) q1.push(top->right);
            }
            result.push_back(levelNodes); //at the end of the loop, all nodes in that level has been add it, add vector to the ans vector 
            //that holds a vector for each level
        }
        return result;

    }
};
```

## Maximum Depth of Binary Tree LC 104

<!-- notecardId: 1780981329229 -->

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

**Link**: [text](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS)

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree. Start from the root and recursively compute the maximum depth of the left and right subtrees. The maximum depth of the current node is 1 (for itself) plus the maximum of the depths of its left and right children. If the node is null, return 0.

**Key Insight:** The key insight is that the maximum depth of a binary tree can be computed by recursively determining the depth of its left and right subtrees. The depth of a node is defined as 1 plus the maximum depth of its children. This recursive approach allows you to explore all paths from the root to the leaf nodes and find the longest one.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the maximum depth should be 0. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Minimum Depth of Binary Tree — LC #111 | Depth of first leaf not deepest leaf → same DFS but return on first leaf reached | Yes — direct variant |
| Diameter of Binary Tree — LC #543 | Longest path between any two nodes → same postorder DFS return height combine at each node | Yes — direct application |
| Balanced Binary Tree — LC #110 | Check if height difference ≤ 1 at every node → same postorder height computation with validity check | Yes — direct application |
| Maximum Depth of N-ary Tree — LC #559 | Multiple children not just two → same DFS max over all children instead of two | Yes — direct generalization |
| Binary Tree Level Order Traversal — LC #102 | Level by level BFS → count total levels instead of max recursive depth | Partial — same answer different approach |
| Binary Tree Maximum Path Sum — LC #124 | Maximum sum path not maximum depth → same postorder DFS different value tracked | Partial — same DFS structure |
| Longest Univalue Path — LC #687 | Longest path with same value → same postorder height idea with value constraint | Partial — same DFS family |
| Count Good Nodes in Binary Tree — LC #1448 | Count nodes where value ≥ all ancestors → same preorder DFS carry max down | Partial — same DFS family |

**How this pattern scales:**
- **Recursive postorder DFS** is the core trick — `return 1 + max(maxDepth(left), maxDepth(right))`. Base case returns 0 for null node. O(n) time O(h) space where h is tree height
- **BFS alternative** — count levels using level order traversal. Increment depth counter after processing each level. Returns same answer in O(n) time O(w) space where w is max width. Prefer BFS when asked for minimum depth since it short circuits on first leaf
- **Minimum depth gotcha** → LC #111 is NOT simply swapping max for min. A node with one null child is not a leaf — minimum depth must reach an actual leaf node with both children null. Using `min` naively returns 0 for any node with a null child producing wrong answers on skewed trees
- **Postorder height pattern** → LC #543 (Diameter) and LC #110 (Balanced) both compute subtree heights in postorder then combine results at each node. LC #104 is the simplest form — diameter adds left height + right height, balanced checks their difference. All three use identical DFS structure with different combination logic
- **Carry value down vs return value up** → maximum depth returns height up the tree (postorder). Count Good Nodes (LC #1448) carries the running maximum down the tree (preorder). These are the two fundamental DFS information flow directions — knowing which direction a problem needs determines the traversal order immediately

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int max = 0;
        if (root == nullptr){
            return 0;
        }
        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);
        return std::max(left, right) + 1;
    }
};
```

## Balanced Binary Tree LC 110

<!-- notecardId: 1780981581479 -->

Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104

**Link**: [text](https://leetcode.com/problems/balanced-binary-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS)

**Approach:** Use a depth-first search (DFS) approach to determine if the binary tree is height-balanced. Define a recursive function that returns the height of the subtree if it is balanced, and -1 if it is not. For each node, recursively check the left and right subtrees. If either subtree is unbalanced (returns -1), propagate that value up. If both subtrees are balanced, return the maximum of their heights plus one for the current node.

**Key Insight:** The key insight is that a binary tree is height-balanced if for every node, the difference in height between its left and right subtrees is at most 1. By using a recursive function that returns the height of the subtree or -1 if it is unbalanced, you can efficiently determine if the entire tree is balanced in a single pass.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the tree is considered balanced, so return true. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Maximum Depth of Binary Tree — LC #104 | Compute height only no balance check → same postorder DFS simpler return | Yes — foundation |
| Diameter of Binary Tree — LC #543 | Longest path between nodes → same postorder height combination different metric | Yes — same pattern |
| Binary Tree Maximum Path Sum — LC #124 | Maximum sum path → same postorder return value up combine at node | Yes — same DFS structure |
| Count Complete Tree Nodes — LC #222 | Count nodes in complete tree → same height computation per subtree | Partial — same height idea |
| Find Leaves of Binary Tree — LC #366 | Group nodes by height from bottom → same postorder height return | Yes — direct application |
| Symmetric Tree — LC #101 | Check mirror symmetry not balance → same recursive pair comparison | Partial — same tree validation |
| Minimum Depth of Binary Tree — LC #111 | Depth of first leaf → same DFS different termination condition | Partial — same DFS family |
| N-ary Tree Level Order Traversal — LC #429 | Level order on multiple children tree → BFS not postorder DFS | No — different pattern |

**How this pattern scales:**
- **Early termination postorder** is the core trick — compute height in postorder but return -1 as a sentinel value the moment any subtree is unbalanced. Propagate -1 up the tree skipping all further computation. If final result is not -1 tree is balanced. O(n) time O(h) space
- **Naive two pass is O(n²)** — calling `height()` and `isBalanced()` separately recomputes heights redundantly. Every node recomputes the height of its entire subtree. The single pass sentinel trick fuses both computations eliminating all redundant work
- **Sentinel value pattern** — returning -1 to signal invalid state through recursion is a general technique. Whenever a recursive computation can fail early encode failure as a special return value that propagates up automatically. Same pattern appears in LC #543 and LC #124
- **Postorder height family** → LC #104 returns raw height. LC #110 returns height or -1. LC #543 uses height to compute diameter at each node. LC #124 uses gain to compute max path at each node. All four share identical DFS skeleton — only the combination logic and return value differ
- **Balance condition** — `abs(leftHeight - rightHeight) <= 1` must hold at EVERY node not just the root. A common wrong answer checks only the root or only one level deep. The postorder approach naturally checks every node since it builds from leaves up

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int getHeight(TreeNode* root){
        //this is where postorder traversal comes in, because you need to calculate the height of the left and right child of the root node before you can calculate the height of the root node, because the height of the root node is the maximum height of the left and right child of the root node plus one,
        // so you need to calculate the height of the left and right child of the root node before you can calculate the height of the root node

        if (root == nullptr){
            return 0;
        }
        int left = getHeight(root -> left); //recursively call the left side of the tree, this will return the height of the left child of the root node
        if (left == -1) return -1; //call this like an early exit, if the left child of the root node is not balanced, then whole tree is not balanced, just return -1 and this will go through the entire recursive stack and return -1 for all the nodes, this will allow you to easily check if the tree is balanced or not, because if the getHeight function returns -1, 
        //then it means that the tree is not balanced, so you can return false in the isBalanced function, otherwise you can return true in the isBalanced function
        int right = getHeight(root -> right);
        if (right == -1) return -1;
        if(abs(left - right) > 1){
            return -1; //at this moment, this is the detection of the first unbalanced node, if the height difference between the left and right child of the root node is greater than one, then it means that the tree is not balanced, so you can return -1 to indicate that the tree is not balanced.
        }
        return 1 + max(left,right);
    }

public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int height = getHeight(root); //call it on the root node, and if -1 returned, not balanced, if any other number returned, then it is balanced and we get the height of the tree
        if(height == -1){
            return false;
        }
        return true;
    }
};
```

## Binary Tree Right Side View LC 199

<!-- notecardId: 1781469255895 -->

<!-- notecardId: 1780981968600 -->

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

**Link**: [text](https://leetcode.com/problems/binary-tree-right-side-view/)

%

**Pattern:** Tree Traversal, Breadth-First Search (BFS)

**Approach:** Use a breadth-first search (BFS) approach to traverse the binary tree level by level. For each level, capture the last node's value, which represents the rightmost node visible from that level. Enqueue the left and right children of each node as you process them to ensure you are traversing the tree in the correct order.

**Key Insight:** The key insight is that the right side view of a binary tree can be obtained by performing a level order traversal (BFS) and recording the last node's value at each level. This approach allows you to efficiently capture the visible nodes from the right side without needing to perform a more complex depth-first search.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the result should be an empty list. Additionally, make sure to correctly manage the queue and the current level's node count to avoid infinite loops or null pointer exceptions. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(m) where m is the maximum number of nodes at any level (worst case O(n/2) for a complete binary tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Level Order Traversal — LC #102 | Collect all nodes per level → same BFS collect last node only | Yes — foundation |
| Binary Tree Zigzag Level Order — LC #103 | Alternate direction each level → same BFS flip collection direction | Yes — same pattern |
| Binary Tree Left Side View — variant | Collect first node per level → same BFS collect first not last | Yes — direct variant |
| Average of Levels in Binary Tree — LC #637 | Average per level not rightmost → same BFS different aggregation | Yes — same pattern |
| Maximum Width of Binary Tree — LC #662 | Width between leftmost and rightmost → same BFS track indices per level | Partial — same level idea |
| Populating Next Right Pointers — LC #116 | Wire next pointers within level → same BFS process level by level | Partial — same level structure |
| Find Bottom Left Tree Value — LC #513 | Leftmost value of last level → same BFS collect first node of last level | Yes — direct variant |
| Vertical Order Traversal — LC #987 | Group nodes by column not level → same BFS with column index tracking | Partial — same BFS family |

**How this pattern scales:**
- **BFS collect last node per level** is the core trick — same level size snapshot as LC #102 but only append `node.val` when `i == levelSize - 1` inside the inner loop. O(n) time O(w) space where w is maximum width
- **DFS alternative** — preorder DFS carrying depth as parameter. Maintain result list, when `depth == result.size()` append current node (first visit at this depth is rightmost in right-first preorder). Visit right child before left. O(n) time O(h) space — better space than BFS for skewed trees
- **Right first preorder DFS** — visiting right before left in DFS means the first node encountered at each depth is always the rightmost visible node. Append to result only on first visit at each depth using `depth == result.size()` as the condition
- **Left side view** is a one line change — BFS collect first node instead of last (`i == 0`). DFS visit left before right and same first visit condition. Knowing both variants cold shows complete understanding of the pattern
- **Find Bottom Left (LC #513)** is the most elegant variant — BFS naturally processes left before right so the first node of the last level is automatically the bottom left. Collect first node of last level instead of last node of every level

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        vector<vector<int>> BFS;
        std::queue<TreeNode*> q1;
        if (root == nullptr) return ans;
        q1.push(root);
        while(!q1.empty()){
            vector<int> currNodes;
            int currLevel = q1.size();
            for(int i = 0; i < currLevel; i++){
                TreeNode* currNode = q1.front();
                q1.pop();
                currNodes.push_back(currNode->val);
                if(currNode ->left) q1.push(currNode->left);
                if(currNode ->right) q1.push(currNode->right);
            }
            BFS.push_back(currNodes);
        } //up till here, literally just BFS
        for(auto vec : BFS){
            ans.push_back(vec[vec.size()- 1]); //take the last element, this will be the rightmost element at each level and hence what we can see from the right side
        }
        return ans; //return answer vector
    }
};
```

## Invert Binary Tree LC 226

<!-- notecardId: 1780982463073 -->

Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:


Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
Example 2:


Input: root = [2,1,3]
Output: [2,3,1]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

**Link**: [text](https://leetcode.com/problems/invert-binary-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS)

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree and swap the left and right children of each node. This can be done recursively by first inverting the left and right subtrees and then swapping them at the current node.

**Key Insight:** The key insight is that inverting a binary tree can be achieved by recursively swapping the left and right children of each node. By performing a postorder traversal (processing children before the parent), you can ensure that the entire subtree is inverted before swapping at the current node.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, simply return null. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Level Order Traversal — LC #102 | Collect all nodes per level → same BFS collect last node only | Yes — foundation |
| Binary Tree Zigzag Level Order — LC #103 | Alternate direction each level → same BFS flip collection direction | Yes — same pattern |
| Binary Tree Left Side View — variant | Collect first node per level → same BFS collect first not last | Yes — direct variant |
| Average of Levels in Binary Tree — LC #637 | Average per level not rightmost → same BFS different aggregation | Yes — same pattern |
| Maximum Width of Binary Tree — LC #662 | Width between leftmost and rightmost → same BFS track indices per level | Partial — same level idea |
| Populating Next Right Pointers — LC #116 | Wire next pointers within level → same BFS process level by level | Partial — same level structure |
| Find Bottom Left Tree Value — LC #513 | Leftmost value of last level → same BFS collect first node of last level | Yes — direct variant |
| Vertical Order Traversal — LC #987 | Group nodes by column not level → same BFS with column index tracking | Partial — same BFS family |

**How this pattern scales:**
- **BFS collect last node per level** is the core trick — same level size snapshot as LC #102 but only append `node.val` when `i == levelSize - 1` inside the inner loop. O(n) time O(w) space where w is maximum width
- **DFS alternative** — preorder DFS carrying depth as parameter. Maintain result list, when `depth == result.size()` append current node (first visit at this depth is rightmost in right-first preorder). Visit right child before left. O(n) time O(h) space — better space than BFS for skewed trees
- **Right first preorder DFS** — visiting right before left in DFS means the first node encountered at each depth is always the rightmost visible node. Append to result only on first visit at each depth using `depth == result.size()` as the condition
- **Left side view** is a one line change — BFS collect first node instead of last (`i == 0`). DFS visit left before right and same first visit condition. Knowing both variants cold shows complete understanding of the pattern
- **Find Bottom Left (LC #513)** is the most elegant variant — BFS naturally processes left before right so the first node of the last level is automatically the bottom left. Collect first node of last level instead of last node of every level

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }
        TreeNode* temp = root -> right; //need to store temporary variable to store the right child of the root node,
        // because you need to swap the left and right child of the root node, so you need to store the right child in a temporary variable, so you can assign it to the left child after you have assigned the left child to the right child
        root -> right = root -> left;
        root -> left = temp;
        invertTree(root->left); //after you have swapped the left and right child of the root node, 
        //you need to recursively call the function on the left and right child of the root node, because you need to 
        //invert the left and right child of the root node, so you need to recursively call the function on the left and right child of the root node, 
        //this will allow you to invert the left and right child of the root node, 
        //and then return the root node after you have inverted the left and right child of the root node
        invertTree(root->right);
        return root;
    }
};
```

## Validate Binary Search Tree LC 98

<!-- notecardId: 1781466524393 -->

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1

**Link**: [text](https://leetcode.com/problems/validate-binary-search-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Inorder Traversal

**Approach:** Use an inorder traversal to check if the values of the nodes are in strictly increasing order. During the traversal, keep track of the previously visited node's value. If at any point the current node's value is not greater than the previous node's value, then the tree is not a valid binary search tree (BST).

**Key Insight:** The key insight is that an inorder traversal of a binary search tree (BST) will yield the node values in sorted order. Therefore, by performing an inorder traversal and comparing each node's value to the previously visited node's value, you can determine if the tree satisfies the BST properties.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., root is null). In such cases, the tree is considered a valid BST, so return true. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children. A bit dumb but keep note of the constraints, use long long for previous value to avoid overflow issues when comparing with node values at the extreme ends of the integer range.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Inorder Traversal — LC #94 | Inorder traversal without validation → same inorder DFS without range check | Yes — foundation |
| Kth Smallest Element in BST — LC #230 | Kth element in inorder sequence → same inorder traversal stop at kth | Yes — direct application |
| Binary Search Tree Iterator — LC #173 | Inorder on demand → same iterative inorder stack held between calls | Yes — direct application |
| Recover Binary Search Tree — LC #99 | Find and fix swapped nodes → same inorder traversal track prev node detect violation | Yes — direct upgrade |
| Insert into BST — LC #701 | Insert node maintaining BST property → same range based navigation | Partial — same BST property |
| Delete Node in BST — LC #450 | Delete node maintaining BST property → same range navigation plus restructuring | Partial — same BST property |
| Lowest Common Ancestor of BST — LC #235 | LCA using BST ordering property → same range comparison different goal | Partial — same BST property |
| Convert Sorted Array to BST — LC #108 | Build BST from sorted array → same BST property different direction | Partial — same BST family |

**How this pattern scales:**
- **Range propagation** is the core trick — pass valid range `(min, max)` down the tree. At each node check `min < node.val < max`. Recurse left with `(min, node.val)` and right with `(node.val, max)`. Initialize with `(-infinity, +infinity)`. O(n) time O(h) space
- **Inorder strictly increasing alternative** — inorder traversal tracking previous node value. Each new value must be strictly greater than previous. Elegant but same O(n) complexity — range propagation is more explicit and easier to explain under pressure
- **Common wrong answer** — checking only `left.val < root.val < right.val` at each node fails on cases like `[5, 4, 6, null, null, 3, 7]` where 3 is in the right subtree of 5 but left subtree of 6. The range must propagate from all ancestors not just the immediate parent
- **Strict inequality matters** — BST requires strictly less than not less than or equal. Duplicates make a tree invalid. Missing the strict inequality produces wrong answers on inputs with duplicate values
- **Recover BST upgrade** → LC #99 finds exactly two swapped nodes using the same inorder traversal. First violation `prev.val > curr.val` marks the first swapped node. Second violation marks the second. Swap their values to fix. Same inorder traversal with two additional tracking variables

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    long long prev = LLONG_MIN;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        if(!isValidBST(root->left)) return false;

        if(root->val <= prev)   return false;
        prev = root -> val;

        if(!isValidBST(root->right)) return false;

        return true;
    }
     
};
```

## Same Tree LC 100

<!-- notecardId: 1781466999788 -->

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

**Link**: [text](https://leetcode.com/problems/same-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS),  Preorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse both trees simultaneously. At each step, compare the current nodes of both trees. If the values are different or if one node is null while the other is not, then the trees are not the same. If both nodes are null, continue checking the next nodes. If all corresponding nodes are identical, then the trees are the same. This is a classic example of preorder traversal as you check the node and then you check the corresponding children.

**Key Insight:** The key insight is that two binary trees are the same if they have the same structure and the same node values. By performing a simultaneous traversal of both trees, you can directly compare corresponding nodes to determine if the trees are identical.

**Gotchas:** Be careful to handle edge cases where one or both trees are empty (i.e., root is null). In such cases, if both are null, they are the same, so return true. If one is null and the other is not, they are not the same, so return false. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current nodes are null before trying to access their values or children.

**Complexity:** Time: O(n) where n is the number of nodes in the smaller tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Symmetric Tree — LC #101 | Check if tree mirrors itself → same recursive pair comparison different pairing | Yes — direct variant |
| Subtree of Another Tree — LC #572 | Check if one tree is subtree of another → same LC #100 as subroutine at every node | Yes — direct application |
| Invert Binary Tree — LC #226 | Mirror tree not compare → same recursive traversal different operation | Partial — same recursive structure |
| Merge Two Binary Trees — LC #617 | Merge not compare → same simultaneous two tree traversal different operation | Yes — same traversal pattern |
| Leaf Similar Trees — LC #872 | Compare leaf sequences not full structure → same DFS collect leaves compare | Partial — same comparison idea |
| Find Duplicate Subtrees — LC #652 | Find all duplicate subtrees → same structure comparison serialize subtrees | Partial — same equality idea |
| Flip Equivalent Binary Trees — LC #951 | Trees equivalent under flips → same recursive comparison allow swapped children | Yes — direct upgrade |
| Count Univalue Subtrees — LC #250 | Count subtrees where all nodes equal → same postorder validation different goal | Partial — same recursive structure |

**How this pattern scales:**
- **Simultaneous recursive traversal** is the core trick — recurse on both trees together checking three conditions at each node: both null (return true), one null (return false), values differ (return false). Otherwise recurse on both left and right pairs. O(n) time O(h) space
- **Three base cases before recursion** — null/null, null/non-null, value mismatch must all be handled before recursing. Missing any one produces null pointer exceptions or wrong answers on edge cases
- **Subtree connection** → LC #572 calls LC #100 as a subroutine at every node of the larger tree. O(m*n) time where m and n are tree sizes. KMP or tree hashing reduces to O(m+n) but the naive LC #100 subroutine approach is always acceptable in interviews
- **Symmetric tree variant** → LC #101 pairs `(left.left, right.right)` and `(left.right, right.left)` instead of `(left.left, right.left)` and `(left.right, right.right)`. Same three base cases same recursive structure — one line change in the pairing
- **Serialization alternative** → serialize both trees to strings using preorder with null markers, compare strings. O(n) time O(n) space. Less elegant but shows awareness of alternative approaches — worth mentioning as a follow-up

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//this is a preorder traversal question, the way you could tell here is that you need to check the value of the current node before you check the left and right child, because if the value of the current node is not the same,
// then you can return false immediately without checking the left and right child, so this is a preorder traversal question, because you need to check the value of the current node before you check the left and right child, if it was a postorder traversal question, 
//then you would need to check the left and right child before you check the value of the current node, and if it was an inorder traversal question, then you would need to check the left child before you check the value of the current node, and then check the right child after you check the value of the current node
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true; //empty tree

        if((p == nullptr || q == nullptr) || p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```

## Construct Binary Tree from Preorder and Inorder Traversal LC 105

<!-- notecardId: 1781467210698 -->

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

**Link**: [text](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

%

**Pattern:** Tree Construction, Depth-First Search (DFS)

**Approach:** Use the properties of preorder and inorder traversals to construct the binary tree. The first element of the preorder array is the root of the tree. Find this root value in the inorder array to determine the left and right subtrees. Recursively apply this process to construct the left and right subtrees.

**Key Insight:** The key insight is that the preorder traversal gives you the root node first, while the inorder traversal allows you to determine the boundary between the left and right subtrees. By recursively applying this logic, you can reconstruct the entire binary tree. You gave to go through and store all of the inorder elements in a hash map to get O(1) look up time for the index of the root in the inorder array, otherwise you would have to do a linear search for the root in the inorder array at each step which would lead to O(n^2) time complexity. 

**Gotchas:** Be careful to handle edge cases where the input arrays are empty. In such cases, return null. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current indices are within bounds before trying to access elements in the arrays.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(n) for the hash map and O(h) for the recursion stack (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Construct Binary Tree from Inorder and Postorder — LC #106 | Root is last element of postorder not first → same split logic mirror approach | Yes — direct variant |
| Construct Binary Tree from Preorder and Postorder — LC #889 | No inorder given → multiple valid trees possible same recursive split | Partial — same construction idea |
| Serialize and Deserialize Binary Tree — LC #297 | Encode decode with null markers → preorder traversal same root first property | Partial — same preorder idea |
| Verify Preorder Sequence in BST — LC #255 | Validate not construct → same preorder root identification different goal | Partial — same preorder property |
| Binary Tree Inorder Traversal — LC #94 | Traverse not construct → same inorder left root right property | Yes — foundation |
| Binary Tree Preorder Traversal — LC #144 | Traverse not construct → same preorder root left right property | Yes — foundation |
| Recover Binary Search Tree — LC #99 | Fix swapped nodes using inorder → same inorder property different goal | Partial — same inorder idea |
| Maximum Binary Tree — LC #654 | Build tree from array using maximum as root → same recursive split different root selection | Partial — same construction family |

**How this pattern scales:**
- **Root identification + inorder split** is the core trick — first element of preorder is always root. Find root in inorder array — everything left is left subtree everything right is right subtree. Recurse with corresponding preorder and inorder slices. O(n²) naive O(n) with hash map
- **Hash map optimization is mandatory** — naive linear search for root in inorder is O(n) per call producing O(n²) total. Precompute `inorderIndex = {val: index}` hash map before recursion. Root lookup becomes O(1) reducing total to O(n)
- **Left subtree size is the key** — `leftSize = inorderRootIndex - inorderLeft`. This single value determines exactly how many elements belong to the left subtree in both preorder and inorder arrays. Getting this calculation wrong produces incorrect splits
- **LC #106 mirror** → postorder gives root as LAST element not first. Everything else is identical — find root in inorder compute left size split both arrays recurse. The only code change is `root = postorder[postRight]` instead of `postorder[postLeft]`
- **Recursive index passing** — pass `preLeft preRight inorderLeft inorderRight` as indices instead of slicing arrays. Slicing creates O(n) copies at each level blowing space to O(n²). Index passing keeps space at O(n) for the hash map plus O(h) for the call stack

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int preorderIndex = 0;
    unordered_map<int, int> inorderIndexMap; //this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees

    TreeNode * buildTreeHelper(vector<int>& preorder, int left, int right){
        if(left > right) return nullptr; //base case for recursion, if the left index is greater than the right index, then it means that there are no nodes in this subtree, so we can return null

        int rootValue = preorder[preorderIndex++]; //get the value of the root node from the preorder traversal, this is important because the first value in the preorder traversal is always the root node, so we can get the value of the root node from the preorder traversal, and then we can use this value to find the index of the root node in the inorder traversal, this will allow us to split the inorder traversal into left and right subtrees

        TreeNode* root = new TreeNode(rootValue); //create a new tree node with the value of the root node

        int inorderIndex = inorderIndexMap[rootValue]; //get the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees

        root -> left = buildTreeHelper(preorder, left, inorderIndex - 1); //recursively build the left subtree, this will allow us to build the left subtree of the current root node, this will allow us to build the left subtree of the current root node
        root -> right = buildTreeHelper(preorder, inorderIndex + 1, right); //recursively build the right subtree, this will allow us to build the right subtree of the current root node, this will allow us to build the right subtree of the current root node

        return root; //return the current root node
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0; //reset the preorder index to 0, this is important because we need to start from the first value in the preorder traversal, this is important because the first value in the preorder traversal is always the root node, so we can get the value of the root node from the preorder traversal, and then we can use this value to find the index of the root node in the inorder traversal, this will allow us to split the inorder traversal into left and right subtrees
        for(int i = 0; i < inorder.size(); i++){
            inorderIndexMap[inorder[i]] = i; //build the index map for the inorder traversal, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees, this will allow us to quickly find the index of the root node in the inorder traversal, this is important because we need to know where to split the inorder traversal into left and right subtrees
        }
        
        return buildTreeHelper(preorder, 0, inorder.size() - 1); //call the helper function to build the tree, this will allow us to build the tree from the preorder and inorder traversals, this will allow us to build the tree from the preorder and inorder traversals
    }
};

```

## Binary Tree Maximum Path Sum LC 124

<!-- notecardId: 1781468879721 -->

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

Example 1:


Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.
Example 2:


Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 

Constraints:

The number of nodes in the tree is in the range [1, 3 * 104].
-1000 <= Node.val <= 1000

**Link**: [text](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Postorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree and calculate the maximum path sum. At each node, compute the maximum path sum that can be obtained by including the current node and possibly extending to one of its children. Update a global variable to keep track of the maximum path sum found so far. This is a postorder traversal because you need to compute the values from the children before you can compute the value for the current node.

**Key Insight:** The key insight is that the maximum path sum at any node can be calculated by considering the maximum path sums from its left and right children. The path can either include the current node alone, or it can extend to one of its children, or it can form a path that goes through the current node connecting both children. By keeping track of the maximum path sum at each node and updating a global maximum, you can find the overall maximum path sum in the tree.

**Gotchas:** Be careful to handle edge cases where the tree has only one node or where all node values are negative. In such cases, the maximum path sum would be the value of the single node or the least negative value, respectively. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Maximum Depth of Binary Tree — LC #104 | Return height not max path sum → same postorder DFS simpler return | Yes — foundation |
| Diameter of Binary Tree — LC #543 | Longest path in node count not sum → same postorder combine left right different metric | Yes — direct variant |
| Balanced Binary Tree — LC #110 | Check height difference not max sum → same postorder height return sentinel on fail | Partial — same DFS structure |
| Path Sum — LC #112 | Check if root to leaf sum equals target → same DFS different path constraint | Partial — same path idea |
| Path Sum II — LC #113 | Collect all root to leaf paths → same DFS carry running sum backtrack | Partial — same path family |
| Maximum Sum BST in Binary Tree — LC #1373 | Maximum sum BST subtree → same postorder return multiple values up tree | Yes — same pattern |
| Binary Tree Maximum Path Sum II | Max path from root to any node → simpler no left right combination needed | Partial — same path idea |
| Longest Univalue Path — LC #687 | Longest path with same value → same postorder extension logic value constraint | Partial — same DFS family |

**How this pattern scales:**
- **Global max + local return split** is the core trick — maintain a global `maxSum` variable. At each node compute `leftGain = max(0, dfs(left))` and `rightGain = max(0, dfs(right))`. Update `maxSum = max(maxSum, node.val + leftGain + rightGain)`. Return `node.val + max(leftGain, rightGain)` to parent — only one branch can extend upward. O(n) time O(h) space
- **Two separate computations at each node** — the path through the current node (used to update global max, can use both branches) vs the path extended to parent (can only use one branch since a path cannot fork). Conflating these two is the single most common conceptual mistake on this problem
- **Max with zero trick** — `max(0, dfs(child))` treats negative subtrees as dead weight by clamping their contribution to zero. Any path that would decrease the sum is simply not taken. This elegantly handles all negative value cases without special casing
- **Diameter connection** → LC #543 is structurally identical — `leftGain + rightGain` becomes `leftHeight + rightHeight` and the global max tracks longest path instead of maximum sum. Same global max + local return split, same two computation insight, different metric
- **Multiple return values pattern** → LC #1373 (Maximum Sum BST) needs to return sum, min, max, and validity up the tree simultaneously. Use a tuple or array return instead of a single int. Same postorder structure, richer return type

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

private: //this question is a postorder traversal question, we need to deal with the left and right subtrees 
//before dealing with the root node, because we need to calculate the maximum path sum of the left and right subtrees before we can calculate 
//the maximum path sum of the root node
int globalMax = INT_MIN;
    int pathFromSubTree(TreeNode* root){
        if(root == nullptr) return 0;

        int leftSum = max(0, pathFromSubTree(root->left)); //get the leftSum of the leftSubtree, ignore if negative
        int rightSum = max(0, pathFromSubTree(root->right));
        int bridgeSum = root->val + leftSum + rightSum; //calculate the path sum of the path that goes through the root node, which is the value of the root node plus the leftSum and rightSum
        //the bridge tells us the maximum path sum of the path that goes through the root node, which is the value of the root node plus the leftSum and rightSum, we need to compare this with the globalMax,
        // because this could be the maximum path sum of the entire tree

        //bridgeSum is if this is where we are allowing the path to split, we can only split once, we can only split at one node, which is the root node in this case, we cannot split at any other node in the left or right subtrees, 
        //because that would violate the definition of a path, which is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them, and a path can only split at one node, which is the root node in this case
        globalMax = max(globalMax, bridgeSum);
        return root->val + max(leftSum, rightSum); //we return this because this is the maximum path sum of the path that goes from the root node to any leaf node in the subtree, 
        //we return this to the node above, because we assume that the node above will have the option to split, if the node above decides to split, then it will use the leftSum and rightSum that we calculated here, if the node above decides not to split, then it will just use the maximum path sum of the path that goes from the root node to any leaf node in the subtree, which is what we are returning here

    }
public:
    int maxPathSum(TreeNode* root) {
        pathFromSubTree(root); //kick off recursion
        return globalMax; //this is the stored answer
    }
};
```

## Kth smallest element in a BST LC 230

<!-- notecardId: 1781469255895 -->

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?

**Link**: [text](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Inorder Traversal

**Approach:** Use an inorder traversal to visit the nodes of the binary search tree (BST) in sorted order. Keep a count of the nodes visited and return the value of the kth node visited. This is an inorder traversal because in a BST, the inorder traversal visits nodes in ascending order.

**Key Insight:** The key insight is that an inorder traversal of a binary search tree (BST) will yield the node values in sorted order. Therefore, by performing an inorder traversal and counting the nodes visited, you can directly access the kth smallest element when the count reaches k. You first have to keep traversing to the left most element, and then go inorder until you reach the kth element.

**Gotchas:** Be careful to handle edge cases where k is out of bounds (e.g., k is less than 1 or greater than the number of nodes in the tree). In such cases, you may want to return an error value or throw an exception. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(n) in the worst case where n is the number of nodes in the binary tree (if k is equal to n) | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Inorder Traversal — LC #94 | Full inorder traversal no early stop → same iterative stack different termination | Yes — foundation |
| Binary Search Tree Iterator — LC #173 | Inorder on demand → same iterative inorder stack held between next() calls | Yes — direct variant |
| Validate Binary Search Tree — LC #98 | Inorder must be strictly increasing → same inorder traversal different check | Yes — same pattern |
| Kth Largest Element in Array — LC #215 | Kth largest in unsorted array → QuickSelect or heap no BST property | No — different pattern |
| Kth Largest Element in BST — variant | Kth largest not smallest → same inorder but right first or reverse inorder | Yes — direct variant |
| Count of Smaller Numbers After Self — LC #315 | Count smaller elements → modified merge sort or BIT no BST traversal | No — different pattern |
| Find Mode in BST — LC #501 | Most frequent element → same inorder traversal track frequency | Yes — same pattern |
| Balance a BST — LC #1382 | Rebalance BST → same inorder collect nodes rebuild | Yes — same inorder application |

**How this pattern scales:**
- **Iterative inorder with early termination** is the core trick — same iterative inorder stack as LC #94 but decrement k on each pop and return immediately when k reaches zero. No need to traverse the entire tree. O(k + h) time O(h) space where h is tree height
- **BST inorder is sorted** — inorder traversal of BST always produces ascending sequence. Kth element popped from iterative inorder is exactly the kth smallest. This single property collapses the problem to a traversal with a counter
- **Augmented BST follow-up** — if the tree is frequently modified and kth smallest queried often augment each node with `leftSize` (count of nodes in left subtree). Binary search using leftSize to find kth in O(h) without full traversal. Worth mentioning as a system design follow-up
- **BST Iterator connection** → LC #173 is this exact iterative inorder stack exposed as an API. `next()` pops one element from the stack exactly as the early termination does here. If you implement LC #173 first LC #230 is just calling `next()` k times
- **Kth largest variant** — swap left and right in the traversal (right first preorder gives descending order) or collect full inorder and index from the end. Same stack logic, mirrored traversal direction

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //to optimize, store the size of the left subtree in each node, then you can just compare k with the size of the left subtree to know whether to go left, right, or return the current node, this will allow you to find the kth smallest element in O(log n) time, because you will only need to go down the tree once, and you will not need to do an inorder traversal of the entire tree, this is a very clever optimization that can be done if you are allowed to modify the tree structure, but since we are not allowed to modify the tree structure in this question, we will just do an inorder traversal of the tree and keep track of how many nodes we have visited until we reach the kth smallest node, this will allow us to find the kth smallest node in O(n) time, because we may need to visit all the nodes in the tree in the worst case
    //use of binary search tree properties, we know that the left side of the tree will have smaller values than the root node, and the right side of the tree will have larger values than the root node, so we can use this property to our advantage when doing the inorder traversal, because we want to start from the smallest element and work our way up by then traversing in increasing order, so we can do an inorder traversal of the tree and keep track of how many nodes we have visited until we reach the kth smallest node, this will allow us to find the kth smallest node in O(n) time, because we may need to visit all the nodes in the tree in the worst case
private:
    int result = -1;
    void inorder(TreeNode* root, int &k){
        if (root == nullptr || k == 0) return;

        if(root->left) inorder(root->left, k); //do inorder traversal, go to the leftmost first, we want to start from the smallest element and work our way up by then traversing in increasing order
        k--; //decrement k, because we have visited one more node, so we need to decrement k by 1, this will allow us to keep track of how many nodes we have visited, and when k reaches 0, it means that we have visited the kth smallest node, so we can set the result to the value of the current node and return

        if(k == 0){ //if k is 0, it means that we have visited the kth smallest node, so we can set the result to the value of the current node and return, this will allow us to return the value of the kth smallest node after we have visited it
            result = root -> val;
            return;
        }
        
        inorder(root->right, k); //after we have visited the current node, we need to go to the right side of the tree, because the right side of the tree will have the larger values, so we need to go to the right side of the tree and continue the inorder traversal until we have visited the kth smallest node
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
```

## Lowest Common Ancestor of a Binary Search Tree LC 235

<!-- notecardId: 1781471313427 -->

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the BST.

**Link**: [text](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Inorder Traversal

**Approach:** Use the properties of a binary search tree (BST) to find the lowest common ancestor (LCA) of two given nodes. Start from the root and compare the values of the current node with the values of the two target nodes. If both target nodes are smaller than the current node, move to the left child. If both are larger, move to the right child. If one is smaller and the other is larger, then the current node is the LCA.

**Key Insight:** The key insight is that in a binary search tree (BST), the values of the nodes are ordered such that for any given node, all values in the left subtree are smaller and all values in the right subtree are larger. This property allows you to efficiently navigate the tree to find the LCA by comparing the target node values with the current node value. When you find a node where one target is on one side and the other target is on the other side, that node must be the lowest common ancestor.

**Gotchas:** Be careful to handle edge cases where one of the target nodes is the ancestor of the other. In such cases, the LCA would be the ancestor node itself. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children.

**Complexity:** Time: O(h) where h is the height of the tree (worst case O(n) for skewed tree) | Space: O(h) for the recursion stack (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Lowest Common Ancestor of Binary Tree — LC #236 | General tree not BST → cannot use ordering must search both subtrees postorder | Partial — harder upgrade |
| Lowest Common Ancestor of BST II — LC #1644 | Nodes may not exist → same navigation add existence flags before returning | Partial — direct upgrade |
| Lowest Common Ancestor of Deepest Leaves — LC #1123 | LCA of deepest leaves not given nodes → same postorder depth tracking | Partial — same LCA idea |
| Insert into BST — LC #701 | Insert maintaining BST property → same left right navigation different goal | Yes — same BST navigation |
| Delete Node in BST — LC #450 | Delete maintaining BST property → same navigation plus restructuring | Partial — same BST property |
| Validate Binary Search Tree — LC #98 | Validate ordering not find LCA → same range propagation different goal | Partial — same BST property |
| Search in BST — LC #700 | Find single node not LCA → same left right navigation simpler termination | Yes — direct foundation |
| Kth Smallest Element in BST — LC #230 | Kth inorder element → inorder traversal not ordering navigation | No — different pattern |

**How this pattern scales:**
- **BST ordering navigation** is the core trick — if both p and q less than root go left. If both greater go right. Otherwise current node is LCA — it is the first node where p and q diverge. O(h) time O(1) iterative space
- **Iterative is preferred** — unlike LC #236 which requires recursion to check both subtrees LC #235 deterministically goes left or right at each step. O(h) time O(1) space no call stack overhead. Always use iterative here
- **Three cases to handle explicitly** — (1) both p and q less than root → go left (2) both greater → go right (3) they straddle root OR one equals root → root is LCA. The straddle/equal condition identifies the split point which is the LCA
- **Why BST LCA is O(h) not O(n)** — BST ordering eliminates the need to search both subtrees at every node. Each comparison deterministically discards one entire subtree. For balanced BST this is O(log n) — fundamentally more efficient than LC #236's mandatory O(n)
- **LC #236 upgrade** → general binary tree LCA must use postorder — search both subtrees, if left finds p and right finds q current node is LCA, otherwise bubble up whichever side found something. No ordering means both sides always searched making O(n) unavoidable

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr; //in terms of traversal, this is a inorder traversal question, because you need to check the left and right child of the current node before you check the value of the current node, because if the value of the current node 
        //is between the values of p and q, then you can return the current node as the ancestor, but if you check the value of the current node before you check the left and right child, then you might miss the ancestor if it is not between the values of p and q, so this is an inorder traversal question, because you need to check the left and right child of the current node before you check the value of the current node
        TreeNode* curr = root;
        while(curr != nullptr){ //keep traversing until condition met, this is the iterative solution, you can also do this recursively by checking the same conditions in the recursive calls
        if(p->val > curr->val && q->val > curr -> val){ //if both p and q are greater than what we are checking
        //we know that the ancestor will be on the right side of the tree, so we need to move to the right child of the current node, because the ancestor will be on the right side of the tree, 
        //so we need to move to the right child of the current node, this will allow us to keep traversing down the tree until we find the ancestor
            curr = curr -> right;
        }
        else if(p->val < curr -> val && q -> val < curr -> val){
            curr = curr -> left;
        }
        else{
            return curr; //if we reach here, it means that we have found the ancestor, because if p and q are on different sides of the current node, then the current node is the ancestor, because it is the lowest node that has both p and q as descendants,
            // so we can return the current node as the ancestor
        }
        }
        return curr;
    }
};
```

## Serialize and Deserialize Binary Tree LC 297

<!-- notecardId: 1781475094536 -->

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:


Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-1000 <= Node.val <= 1000

**Link**: [text](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Preorder Traversal, Breadth-First Search (BFS)

**Approach:** Use a breadth-first search (BFS) approach to serialize the binary tree level by level, using a queue to keep track of the nodes at each level. For deserialization, use the same BFS approach to reconstruct the tree from the serialized string. Alternatively, you can use a depth-first search (DFS) approach with preorder traversal for serialization and deserialization.

**Key Insight:** The key insight is that you can represent the structure of the binary tree in a string format by using a specific traversal method (BFS or DFS) and including markers for null nodes. This allows you to capture both the values of the nodes and the structure of the tree. During deserialization, you can use the same traversal method to read the string and reconstruct the original tree structure.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., the root is null). In such cases, you should return an appropriate representation for an empty tree during serialization and handle it correctly during deserialization. Additionally, make sure to correctly manage the queue or stack used for traversal to avoid memory leaks or infinite loops.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(n) for the serialized string and the queue/stack used during traversal

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Serialize and Deserialize BST — LC #449 | BST properties allow more compact encoding → preorder only no null markers needed | Partial — direct variant |
| Encode and Decode Strings — LC #271 | Encode decode flat string list not tree → length prefix no tree structure | Partial — same encoding idea |
| Construct Binary Tree from Preorder and Inorder — LC #105 | Rebuild from two traversals not serialized string → same root first preorder property | Partial — same preorder idea |
| Binary Tree Level Order Traversal — LC #102 | BFS traversal not serialization → same level by level structure different goal | Partial — same BFS idea |
| Find Duplicate Subtrees — LC #652 | Serialize subtrees to detect duplicates → same preorder serialization as subroutine | Yes — direct application |
| Flatten Binary Tree to Linked List — LC #114 | Flatten to linked list not string → same preorder traversal different output | Partial — same preorder family |
| Verify Preorder Serialization — LC #331 | Validate not reconstruct → same null marker counting different goal | Yes — same serialization idea |
| Clone Binary Tree with Random Pointer | Deep copy with extra pointers → same node recreation idea different structure | Partial — same reconstruction idea |

**How this pattern scales:**
- **Preorder with null markers** is the core trick — serialize by preorder DFS appending node values and `#` for null children separated by commas. Deserialize by consuming tokens from a queue reconstructing root then left then right recursively. O(n) time O(n) space both directions
- **Queue for deserialization** — convert serialized string to a queue of tokens. Each recursive call pops exactly one token. Queue naturally tracks position across recursive calls without index passing — cleaner and less error prone than maintaining a global index
- **Why preorder not inorder** — preorder places root first making deserialization trivial. The first token is always the root. Inorder serialization with null markers cannot be uniquely deserialized since the root position is ambiguous without additional information
- **BST compact encoding** → LC #449 exploits BST ordering to skip null markers entirely. Preorder of a BST can be uniquely deserialized using value ranges to reconstruct left and right subtrees. Saves space but only valid when BST property is guaranteed
- **BFS alternative** — serialize level by level using BFS appending null markers for missing children. Deserialize by reconstructing level by level using a queue of parent nodes. Same O(n) complexity but BFS encoding is wider and less cache friendly than DFS preorder
- **Find Duplicate Subtrees connection** → LC #652 serializes every subtree using the same preorder null marker approach storing results in a hash map. If any serialization appears twice that subtree is a duplicate — LC #297's serialization used as a structural fingerprint

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
//This was solved with BFS, also can be done with DFS, but BFS is more intuitive for this question, 
//we are basically doing a level order traversal of the tree and encoding the values of the nodes in a string, we also need to encode the null nodes, because we need to be able to reconstruct the tree from the string, if we don't encode the null nodes, then we won't be able to reconstruct the tree correctly
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "null,"; //represet null node
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0){
            TreeNode* node = q.front();
            q.pop(); //we are doing a level order traversal of the tree, we are processing the nodes in the order they were added to the queue, 
            //which is the order they were visited in the level order traversal
            if(node == nullptr){
                result += "null,"; //if the node is null, encode it as null
            }
            else{
                result += to_string(node->val) + ","; //if node not null, encode by value, and then add left and right child to queue, will be processed in BFS format
                q.push(node->left);
                q.push(node->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "null,") return nullptr;
        stringstream ss(data); //use stringstream to parse the string, we will use getline to get the values of the nodes,
        // we will use a queue to keep track of the nodes that we need to process, we will process the nodes in the order they were added to the queue, which is the order they were visited in the level order traversal
        string item;
        getline(ss, item, ','); //get the value of the root node, this will be the first value in the string, we can assume that the first value will always be the root node, because we are doing a level order traversal and we are encoding the values of the nodes in the order they were visited in the level order traversal
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root); //add the root node to the queue, we will process the root node first, then we will process the left and right child of the root node, then we will process the left and right child of the left child of the root node, and so on, we are basically doing a level order traversal of the tree, but in reverse, we are reconstructing the tree from the string in the order it was encoded, which is the order it was visited in the level order traversal
        while(q.size() > 0){
            TreeNode* node=q.front(); //get the next node to process, this will be the next node in the level order traversal, we will process the left and right child of this node, then we will process the left and right child of the left child of this node,
            // and so on, we are basically doing a level order traversal of the tree, but in reverse, we are reconstructing the tree from the string in the order it was encoded, which is the order it was visited in the level order traversal
            q.pop();
            getline(ss, item, ','); //get the left child value
            if(item == "null"){
                node->left = nullptr;
            }
            else{
                node->left = new TreeNode(stoi(item));
                q.push(node->left);
            }
            getline(ss, item, ','); //get the right child value
            if(item == "null"){
                node->right = nullptr;
            }
            else{
                node->right = new TreeNode(stoi(item));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```

## House Robber III LC 337

<!-- notecardId: 1781475765868 -->

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

 

Example 1:


Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:


Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 104

**Link**: [text](https://leetcode.com/problems/house-robber-iii/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Postorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree and calculate the maximum amount of money that can be robbed. At each node, compute two values: the maximum amount that can be robbed if the current node is robbed (which means its children cannot be robbed) and the maximum amount that can be robbed if the current node is not robbed (which means its children can be robbed). Use a postorder traversal to ensure that you compute the values for the children before computing the values for the current node.

**Key Insight:** The key insight is that at each node, you have two choices: either rob the current node and skip its children, or skip the current node and rob its children. By using a postorder traversal, you can compute the maximum amount for the children first, which allows you to make an informed decision for the current node. This approach effectively uses dynamic programming on trees, where you store the results of subproblems (the maximum amounts for the children) to solve larger problems (the maximum amount for the current node).

**Gotchas:** Be careful to handle edge cases where the tree has only one node or where all node values are zero. In such cases, the maximum amount would be the value of the single node or zero, respectively. Additionally, make sure to correctly manage the recursive calls to avoid stack overflow for very deep trees. Always check if the current node is null before trying to access its value or children. Always draw out this question if given this problem, because you have to realize the format of the pair being (robCurrent, notRobCurrent), and then you have to realize that the robCurrent is the value of the current node plus the notRobCurrent of the left and right child, and the notRobCurrent is the max of the robCurrent and notRobCurrent of the left child plus the max of the robCurrent and notRobCurrent of the right child. This is a very tricky question, so you have to draw it out to understand it.

**Complexity:** Time: O(n) where n is the number of nodes in the binary tree | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| House Robber — LC #198 | Linear array not tree → same rob or skip DP on 1D array | Partial — foundation |
| House Robber II — LC #213 | Circular array not tree → same DP run twice exclude first or last | Partial — same family |
| Maximum Independent Set on Tree | Select max weight nodes no two adjacent → exact restatement of LC #337 | Yes — direct application |
| Binary Tree Maximum Path Sum — LC #124 | Combine values from both subtrees → same postorder return multiple values up | Partial — same DFS structure |
| Diameter of Binary Tree — LC #543 | Return height combine at each node → same postorder tuple return pattern | Partial — same DFS structure |
| Maximum Sum BST in Binary Tree — LC #1373 | Find max sum BST subtree → same postorder return multiple values up tree | Yes — same pattern |
| Paint House — LC #256 | Color houses no adjacent same color → same DP state carry down | Partial — same constraint idea |
| Distribute Coins in Binary Tree — LC #979 | Move coins to balance tree → same postorder return value up different metric | Partial — same DFS family |

**How this pattern scales:**
- **Return pair (rob, skip) postorder** is the core trick — at each node return two values: `rob` = value gained by robbing this node (cannot rob children), `skip` = value gained by skipping this node (children can be robbed or skipped). Parent combines children's pairs optimally. O(n) time O(h) space
- **Combination at each node** — `rob = node.val + leftSkip + rightSkip`. `skip = max(leftRob, leftSkip) + max(rightRob, rightSkip)`. Parent takes the best of both child states independently for skip since left and right subtrees are independent
- **Naive memoization alternative** — recursive `rob(node)` returning max profit with hash map caching results per node. Cleaner to derive under pressure but requires two passes (rob root, skip root) and memo map. O(n) time O(n) space — worse than pair return approach
- **House Robber ladder** → LC #198 (linear) → LC #213 (circular) → LC #337 (tree). Each adds structural complexity. The core constraint "cannot rob adjacent nodes" is identical across all three — only the adjacency structure changes from linear to circular to parent-child
- **Tuple return pattern generalizes** → any tree DP where a node's optimal answer depends on its children's states uses this pair/tuple return. LC #124 returns single gain value but maintains global max separately. LC #337 returns two states letting the parent decide optimally — richer information flow up the tree

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//this question is a postorder traversal, because you need to calculate the maximum amount of money that can be robbed for the left and right child of the current node before you can calculate the maximum amount of money that can be robbed for the current node, because the maximum amount of money that can be robbed for the current node is the maximum of the two cases, if we rob the current node, then we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed, if we do not rob the current node, then we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for
// the left and right child of the current node
class Solution {
private:
    std::pair<int,int> robHelper(TreeNode* root){
        if (root == nullptr){
            return {0, 0};
        }
        //simple trick to remember, store {if robbed, if skipped}
        //and add .second if we rob the current node, because the second is if we skip the left and right children, which is needed when we rob the current node

        //the left number in the pair is the max amnt of money that can be robbed if the current node is not robbed,
        // and the right number in the pair is the max amnt of money that can be robbed if the current node is robbed, this will allow us to easily calculate the max amnt of money that can be robbed for the current node, because if the current node is not robbed, then we can rob both the left and right child of the current node, so we can add the max amnt of money that can be robbed for the left and right child of the current node, if the current node is robbed, then we cannot rob the left and right child of the current node, so we can only add the value of the current node to the max amnt of money that can be robbed for the left and right child of the current node when they are not robbed

        std::pair<int, int> left = robHelper(root->left); //this will return a pair of integers, the first integer is the maximum amount of money that can be robbed if the current node is not robbed, and the second integer is the maximum amount of money that can be robbed if the current node is robbed, 
        //this will allow us to easily calculate the maximum amount of money that can be robbed for the current node, because if the current node is not robbed, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and 
        //right child of the current node, if the current node is robbed, then we cannot rob the left and right child of the current node, so we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed
        std::pair<int, int> right = robHelper(root->right);
        int robCurrent = root->val + left.second + right.second; //if we rob the current node, then we cannot rob the left and right child of the current node, so we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child 
        //of the current node when they are not robbed

        //root->val is current node, and we add left.second and right.second because
        //left.first is the max amount of money if we rob that node, and left.second is the max amount of money if we skip that node
        //we add .second because root->val is the house we rob, and left.second and right.second is the max amount of money we can rob if we skip the left and right child of the current node, because we cannot rob the left and right child of the current node if we rob the current node, so we can only add the value 
        //of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed
        int notRobCurrent = max(left.second, left.first) + max(right.second, right.first);
        //left.first and right.first is the max amount of money that can be robbed if we rob the left and right child of the current node.
        //there is a case where we rob the left child and not rob the right child, and there is a case where we rob the right child and not rob the left child, so we need to take the maximum of the two cases, so we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and right child of the current node 
        return {robCurrent, notRobCurrent};
    }
public:
    int rob(TreeNode* root) {
        std::pair<int, int> result = robHelper(root);
        return std::max(result.first, result.second); //the maximum amount of money that can be robbed for the current node is the maximum of the two cases, if we rob the current node, then we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed, if we do not rob the current node, then we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and right child of the current node
        //this is for the root node, this is like the last step of the postorder traversal, because we need to calculate the maximum amount of money that can be robbed for the left and right child of the current node before we can calculate the maximum amount of money that can be robbed for the current node, because the maximum amount 
        //of money that can be robbed for the current node is the maximum of the two cases, if we rob the current node, then we can only add the value of the current node to the maximum amount of money that can be robbed for the left and right child of the current node when they are not robbed, if we do not rob the current node, then we can add the maximum amount of money that can be robbed for the left and right child of the current node, because if we do not rob the current node, then we can rob both the left and right child of the current node, so we can add the maximum amount of money that can be robbed for the left and right child of the current node
    }
};
```

## Construct Quad Tree LC 427

<!-- notecardId: 1781477175035 -->

Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

Return the root of the Quad-Tree representing grid.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
Explanation: The explanation of this example is shown below:
Notice that 0 represents False and 1 represents True in the photo representing the Quad-Tree.

Example 2:



Input: grid = [[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]
Output: [[0,1],[1,1],[0,1],[1,1],[1,0],null,null,null,null,[1,0],[1,0],[1,1],[1,1]]
Explanation: All values in the grid are not the same. We divide the grid into four sub-grids.
The topLeft, bottomLeft and bottomRight each has the same value.
The topRight have different values so we divide it into 4 sub-grids where each has the same value.
Explanation is shown in the photo below:

 

Constraints:

n == grid.length == grid[i].length
n == 2x where 0 <= x <= 6

**Link**: [text](https://leetcode.com/problems/construct-quad-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Postorder Traversal

**Approach:** Use a depth-first search (DFS) approach to construct the Quad-Tree from the given grid. Start from the entire grid and check if all values are the same. If they are, create a leaf node with the corresponding value. If not, divide the grid into four equal sub-grids and recursively construct the Quad-Tree for each sub-grid. Combine the results to create an internal node with four children.

**Key Insight:** The key insight is that you can determine whether a node is a leaf or an internal node by checking if all values in the corresponding grid are the same. If they are, you can create a leaf node. If not, you need to divide the grid and create internal nodes for each sub-grid. This approach naturally leads to a postorder traversal, where you compute the values for the children before computing the value for the current node.

**Gotchas:** Be careful to handle edge cases where the grid is empty or where all values are the same. In such cases, you should return a single leaf node with the appropriate value. Additionally, make sure to correctly manage the indices when dividing the grid into sub-grids to avoid out-of-bounds errors.

**Complexity:** Time: O(n^2) where n is the length of the grid (since you need to check all values in the grid) | Space: O(n^2) for the Quad-Tree in the worst case (when all values are different)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Construct Binary Tree from Preorder and Inorder — LC #105 | Build binary not quad tree → same recursive construction different split | Partial — same construction idea |
| Range Sum Query 2D — LC #304 | Prefix sum on 2D matrix → same 2D region sum as subroutine for uniform check | Yes — direct application |
| Serialize and Deserialize Binary Tree — LC #297 | Encode decode binary tree not quad tree → same recursive structure different branching | Partial — same serialization idea |
| N-ary Tree Preorder Traversal — LC #589 | Traverse not construct n-ary tree → same multiple children structure | Partial — same n-ary idea |
| Maximum Sum Rectangle — LC #363 | Find max sum submatrix → same 2D region decomposition idea | No — different pattern |
| Image Overlap — LC #835 | Compare 2D regions → same grid subdivision idea different operation | No — different pattern |
| Count Complete Tree Nodes — LC #222 | Count nodes using tree structure → same recursive subdivision | Partial — same recursive idea |
| Longest Univalue Path — LC #687 | Uniform value path in binary tree → same uniform check different structure | Partial — same uniformity idea |

**How this pattern scales:**
- **Recursive grid subdivision** is the core trick — check if current region is uniform (all 0s or all 1s). If uniform return a leaf node with that value. If not split into four equal quadrants (topLeft topRight bottomLeft bottomRight) recurse on each. O(n² log n) naive O(n²) with prefix sums
- **Uniformity check optimization** — naive uniformity check scans entire subgrid O(n²) per call producing O(n⁴) total. Build a 2D prefix sum array first then check any subgrid sum equals `0` or `rows * cols` in O(1). Reduces total to O(n²) — this optimization is mandatory for large grids
- **Four children always** — unlike binary trees where null children are common quad trees always split into exactly four children when not a leaf. Never have 1, 2, or 3 children — always 0 (leaf) or 4 (internal node)
- **Prefix sum integration** → LC #304 builds the exact same 2D prefix sum array. Subgrid sum formula `P[r2][c2] - P[r1-1][c2] - P[r2][c1-1] + P[r1-1][c1-1]` checks uniformity in O(1). Knowing LC #304 cold makes the optimization step of LC #427 trivially derived
- **Spatial indexing generalization** → quad trees are used in real systems for 2D spatial indexing (collision detection, map rendering, image compression). The recursive subdivision pattern appears in kd-trees for higher dimensions and R-trees for geographic data — worth mentioning as a system design connection

```cpp
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    //THIS QUESTION IS DIFFICULT, REVIEW THIS CLEARLY
    Node* constructTree(vector<vector<int>>& grid, int r1, int c1, int r2, int c2){
        bool same = true;
        //check the corners to find if the n by n grid is a subtree or not
        for(int i = r1; i <= r2; i++){
            for (int j = c1 ; j <= c2; j++){
                if (grid[i][j] != grid[r1][c1]){
                    same = false;
                    break;
                }
            }
            if (!same) break;
        }
        if(same){
            return new Node(grid[r1][c1] == 1, true); //val is 1, isLeaf is true, because if all the values in the grid are the same, then this is a leaf node, and the value of the node is the value of the grid, which is either 0 or 1,
            // so we can just check if it is equal to 1 to get the boolean value for the node
        }

        //what if not the same, this is where we need to divide the grid into 4 subgrids and recursively call the constructTree function on each subgrid,
        // and then create a new node with the value of the current grid, which is not a leaf node, and the children of the node are the nodes returned by the recursive calls on the subgrids

        int midRow = r1 + (r2 - r1) / 2;
        int midCol = c1 + (c2 - c1) / 2;

        Node* root = new Node(true, false); //given in the problem, we know that the value of the node is true, and the node is not a leaf node, because we are going to divide the grid into 4 subgrids, so we know that this node is not a leaf node, and the value of the node is true, because it does not matter what the value of the node is, 
        //because it is not a leaf node, so we can just set it to true

        root->topLeft = constructTree(grid, r1, c1, midRow, midCol);
        root->topRight = constructTree(grid, r1, midCol + 1, midRow, c2);
        root->bottomLeft = constructTree(grid, midRow + 1, c1, r2, midCol);
        root->bottomRight = constructTree(grid, midRow + 1, midCol + 1, r2, c2);

        return root;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        return constructTree(grid, 0, 0, grid.size() -1, grid[0].size() - 1);
    }
};
```

## Delete Node in a BST LC 450

<!-- notecardId: 1781479005108 -->

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105
 

Follow up: Could you solve it with time complexity O(height of tree)?

**Link**: [text](https://leetcode.com/problems/delete-node-in-a-bst/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Binary Search Tree (BST) Properties, inorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse the binary search tree (BST) and find the node with the given key. Once the node is found, there are three cases to consider: if the node has no children, simply remove it; if the node has one child, replace it with its child; if the node has two children, find the inorder successor (the smallest node in the right subtree), replace the value of the current node with the value of the inorder successor, and then delete the inorder successor.

**Key Insight:** The key insight is to leverage the properties of the binary search tree to efficiently find the node to delete. The inorder successor is used in the case where the node has two children because it maintains the BST property when replacing the value of the current node. By recursively calling the delete function on the right subtree after replacing the value, you can ensure that the duplicate value (the inorder successor) is removed from its original position.

**Gotchas:** Be careful to handle edge cases where the node to delete is the root node or where the node has only one child. In such cases, you need to ensure that the tree remains a valid BST after deletion. Additionally, make sure to correctly manage the pointers when replacing nodes to avoid memory leaks or dangling pointers.

**Complexity:** Time: O(h) where h is the height of the tree (O(log n) for balanced BST, O(n) for skewed BST) | Space: O(h) due to recursive call stack

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search in BST — LC #700 | Find node not delete → same left right navigation simpler termination | Yes — foundation |
| Insert into BST — LC #701 | Insert not delete → same navigation find position attach new node | Yes — direct variant |
| Validate Binary Search Tree — LC #98 | Validate ordering not modify → same BST property different goal | Partial — same BST property |
| Lowest Common Ancestor of BST — LC #235 | Find LCA not delete → same ordering navigation different goal | Partial — same BST navigation |
| Trim a BST — LC #669 | Remove all nodes outside range → same recursive deletion different condition | Yes — direct variant |
| Kth Smallest Element in BST — LC #230 | Find kth not delete → same inorder property different goal | No — different pattern |
| Balance a BST — LC #1382 | Rebalance after modifications → same inorder collect rebuild | Partial — same BST modification |
| Delete Nodes and Return Forest — LC #1110 | Delete multiple nodes return forest → same deletion logic repeated | Partial — same deletion idea |

**How this pattern scales:**
- **Three deletion cases** is the core trick — (1) node is a leaf → return null (2) node has one child → return that child (3) node has two children → find inorder successor (leftmost node in right subtree) copy its value to current node delete inorder successor from right subtree. O(h) time O(h) space
- **Inorder successor for two child case** — when deleting a node with two children you cannot simply remove it. Replace its value with the inorder successor (smallest value in right subtree) then delete the inorder successor which is guaranteed to have at most one child making it a simpler case
- **Inorder predecessor alternative** — instead of inorder successor use inorder predecessor (largest value in left subtree). Either maintains BST property — successor comes from right subtree predecessor from left. Choose whichever simplifies implementation
- **Recursive structure** — navigate left if target less than root, right if greater. When target found apply three cases. Return modified subtree root at each level to rewire parent pointers automatically. Same recursive rewiring as insert
- **Trim BST connection** → LC #669 applies deletion logic to all nodes outside a range in a single postorder pass. Instead of finding a specific node and handling three cases it recursively prunes entire subtrees. Same BST navigation same three case awareness different triggering condition

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        if(key > root -> val){
            root -> right = deleteNode(root->right, key);
        }
        else if(key < root -> val){
            root -> left = deleteNode(root->left, key);
        }
        else{
            //here we got to delete a node, how is this done?
            //what if a leaf node, this just becomes a nullptr because nothing below it
            if(root-> left == nullptr){
                TreeNode *temp = root -> right;
                delete root; 
                return temp; //return right child
                
            }
            else if (root -> right == nullptr){
                TreeNode *temp = root -> left;
                delete root;
                return temp; //return left child
            }

            //if node has two children, find the smallest in right subtree (inorder traversal)
            TreeNode* successor = root -> right;
            while(successor->left != nullptr){
                successor = successor->left;
            }

            //now, we have found the smallest in the right subtree;

            root ->val = successor->val; //update current nodes value with the value of the successor we want to update with (smallest in right subtree)

            root ->right = deleteNode(root->right, successor->val); //now we have to go in and delete that value in the right subtree, since we have already updated the root's value.
            //very clever!
        }
        return root;
    }
};
```

## Diameter of Binary Tree LC 543

<!-- notecardId: 1781482449579 -->

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100

**Link**: [text](https://leetcode.com/problems/diameter-of-binary-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Postorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree and calculate the diameter. At each node, compute the longest path through that node by summing the longest path from the left child and the longest path from the right child. Update a global variable to keep track of the maximum diameter found so far. The longest path from a node is defined as the maximum of the longest path from its left child and the longest path from its right child plus one (to account for the edge to the child).

**Key Insight:** The key insight is that the diameter of the tree can be found by considering the longest path that passes through each node. By using a postorder traversal, you can compute the longest path from the left and right children before computing the diameter at the current node. This allows you to efficiently update the maximum diameter as you traverse the tree.

**Gotchas:** Be careful to handle edge cases where the tree has only one node or where all nodes are in a straight line (skewed tree). In such cases, the diameter would be the number of edges between the nodes, which is one less than the number of nodes. Additionally, make sure to correctly manage the global variable that tracks the maximum diameter to avoid incorrect updates.

**Complexity:** Time: O(n) where n is the number of nodes in the tree (since you visit each node once) | Space: O(h) where h is the height of the tree (worst case O(n) for skewed tree)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Binary Tree Maximum Path Sum — LC #124 | Maximum sum path not longest path → same global max + local return split | Yes — direct variant |
| Longest Univalue Path — LC #687 | Longest path with same value constraint → same postorder extension logic value check | Yes — direct variant |
| Maximum Depth of Binary Tree — LC #104 | Return height only no diameter computation → same postorder DFS simpler return | Yes — foundation |
| Balanced Binary Tree — LC #110 | Check height difference not diameter → same postorder height return sentinel on fail | Partial — same DFS structure |
| Count Good Nodes — LC #1448 | Carry max value down preorder → same DFS different direction | No — different direction |
| Binary Tree Cameras — LC #968 | Place minimum cameras covering all nodes → same postorder state return up tree | Partial — same postorder family |
| Diameter of N-ary Tree — LC #1522 | Multiple children not just two → same global max sum all child heights | Yes — direct generalization |
| Longest Path With Different Adjacent Values — LC #2246 | Longest path no adjacent same value → same global max local return different constraint | Yes — same pattern |

**How this pattern scales:**
- **Global max + local height return** is the core trick — maintain global `diameter` variable. At each node compute `leftHeight = dfs(left)` and `rightHeight = dfs(right)`. Update `diameter = max(diameter, leftHeight + rightHeight)`. Return `1 + max(leftHeight, rightHeight)` to parent. O(n) time O(h) space
- **Two separate computations** — diameter through current node uses both branches (leftHeight + rightHeight). Height returned to parent uses only the taller branch (1 + max). Same split as LC #124 — confusing these two is the most common wrong answer
- **Edge count vs node count** — diameter is measured in edges not nodes by default. `leftHeight + rightHeight` gives edge count naturally since leaf returns 0. If node count is asked add 1 to the final answer
- **LC #124 structural twin** → replace height with gain (`max(0, dfs(child))`) replace `leftHeight + rightHeight` with `node.val + leftGain + rightGain` replace `max(leftHeight, rightHeight)` with `max(leftGain, rightGain)`. Same skeleton two different metrics
- **N-ary generalization** → LC #1522 sums all child heights instead of just two. Sort child heights descending take top two for diameter update. Return largest child height plus one. Same global max local return structure one loop replaces two recursive calls

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
int maxDiameter = 0;
int maxDepth(TreeNode* root){
        if (root == nullptr){
            return 0; 
        }

        int leftDepth = maxDepth(root->left); //recursively call the left side of the tree, this will return the maximum depth of the left side of the tree
        int rightDepth = maxDepth(root->right); //recursively call the right side of the tree, this will return the maximum depth of the right side of the tree

        int currentDiameter = leftDepth + rightDepth;
        maxDiameter = max(maxDiameter, currentDiameter);
        return std::max(leftDepth,rightDepth) + 1;

    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        //this is a postorder traversal question, because you need to calculate the maximum depth of the left and right child of the root node before you can calculate the diameter of the tree, 
        //because the diameter of the tree is the maximum depth of the left side of the tree plus the maximum depth of the right side of the tree, so you need to calculate the maximum depth of the left and right child of the root node before 
        //you can calculate the diameter of the tree, so this is a postorder traversal question, because you need to calculate the maximum depth of the left and right child of the root node before you can calculate the diameter of the tree
        maxDepth(root); //call the maxDepth function to calculate the maximum depth of the tree, this will also update the maxDiameter variable with the maximum diameter of the tree,
        // because the diameter of the tree is the maximum depth of the left side of the tree plus the maximum depth of the right side of the tree, so you need to call the maxDepth function to calculate the maximum depth of the tree, and then return the maxDiameter variable after you have calculated the maximum depth of the tree
        return maxDiameter;
    }
};
```

## Subtree of Another Tree LC 572

<!-- notecardId: 1781482807807 -->

Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

 

Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
 

Constraints:

The number of nodes in the root tree is in the range [1, 2000].
The number of nodes in the subRoot tree is in the range [1, 1000].
-104 <= root.val <= 104
-104 <= subRoot.val <= 104

**Link**: [text](https://leetcode.com/problems/subtree-of-another-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Preorder Traversal, Tree Comparison

**Approach:** Use a depth-first search (DFS) approach to traverse the main tree (root) and at each node, check if the subtree rooted at that node is identical to the subRoot tree. This can be done by implementing a helper function that compares two trees for structural and value equality. The main function will call this helper function at each node of the main tree until it finds a match or exhausts all nodes.

**Key Insight:** The key insight is that to determine if one tree is a subtree of another, you need to check for a match at every node of the main tree. By using a helper function to compare the two trees, you can efficiently determine if they are identical in structure and values. This approach ensures that you are checking all possible subtrees of the main tree for a match with the subRoot. It is preorder traversal, as you will check each node and then check its children.

**Gotchas:** Be careful to handle edge cases where the subRoot is null (which should return true since an empty tree is a subtree of any tree) or where the main tree is null (which should return false unless subRoot is also null). Additionally, make sure to correctly implement the tree comparison function to check both structure and values, as a mismatch in either should result in a false return.

**Complexity:** Time: O(m * n) where m is the number of nodes in the main tree and n is the number of nodes in the subRoot tree (in the worst case, you may compare every node of the main tree with every node of the subRoot) | Space: O(h) where h is the height of the main tree (due to recursive call stack)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Same Tree — LC #100 | Check two trees identical not subtree → same recursive pair comparison no search | Yes — direct foundation |
| Count Univalue Subtrees — LC #250 | Count subtrees where all nodes equal → same postorder validation different goal | Partial — same subtree idea |
| Find Duplicate Subtrees — LC #652 | Find all duplicate subtrees → same serialization fingerprint hash map | Partial — same subtree idea |
| Binary Tree Maximum Path Sum — LC #124 | Combine values bottom up → same postorder DFS different goal | No — different pattern |
| Most Frequent Subtree Sum — LC #508 | Find most frequent subtree sum → same postorder compute sum per subtree | Partial — same subtree computation |
| Serialize and Deserialize Binary Tree — LC #297 | Encode decode full tree → same preorder serialization as subtree fingerprint | Partial — same serialization idea |
| Construct Binary Tree from Preorder and Inorder — LC #105 | Build not compare → same tree structure idea different goal | No — different pattern |
| Check Subtree CTCI 4.10 | Classic interview variant → same LC #100 subroutine at every node | Yes — same pattern |

**How this pattern scales:**
- **LC #100 as subroutine at every node** is the core trick — for each node in the main tree call `isSameTree(node, subRoot)`. If any call returns true subRoot is a subtree. O(m*n) time O(h) space where m and n are tree sizes
- **Serialization optimization** — serialize both trees to strings using preorder with null markers. Check if subRoot's serialization is a substring of root's serialization. O(m+n) time O(m+n) space — reduces to string matching. Must use delimiters to avoid false matches like `12` matching `1` in `120`
- **Delimiter requirement** — when serializing add delimiters between values and null markers. Without delimiters `#12#` appears as substring of `#120#` causing false positives. Use comma separated format `1,2,#,` to avoid all ambiguity
- **Tree hashing alternative** — hash each subtree using a Merkle-style hash combining node value and children hashes. Compare subRoot hash against all subtree hashes in O(1) per node. O(m+n) time with high probability correct — collision risk makes it less reliable than serialization
- **Subtree vs path** — a subtree must include all descendants of the matching node. A path only requires connected nodes. LC #572 checks full structural equality from the matching node down — any missing leaf or extra node fails the check

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:

    bool isSame(TreeNode* node1, TreeNode* node2){
        if (node1 == nullptr && node2 == nullptr){
            return true;
        }
        if(node1 == nullptr || node2 == nullptr){
            return false;
        }
        if(node1-> val != node2 -> val){
            return false;
        }
        return isSame(node1->left, node2->left) && isSame(node1->right, node2->right);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        if(isSame(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot)|| isSubtree(root->right, subRoot); //have to call isSubtree, not isSame, dont make silly error

    }
};
```

## Insert into a Binary Search Tree LC 701

<!-- notecardId: 1781483363132 -->

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

Example 1:


Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]
Explanation: Another accepted tree is:

Example 2:

Input: root = [40,20,60,10,30,50,70], val = 25
Output: [40,20,60,10,30,50,70,null,null,25]
Example 3:

Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
Output: [4,2,7,1,3,5]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-108 <= Node.val <= 108
All the values Node.val are unique.
-108 <= val <= 108
It's guaranteed that val does not exist in the original BST.

**Link**: [text](https://leetcode.com/problems/insert-into-a-binary-search-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Binary Search Tree (BST) Properties

**Approach:** Use a depth-first search (DFS) approach to traverse the binary search tree (BST) and find the correct position to insert the new value. Start from the root and compare the new value with the current node's value. If the new value is less than the current node's value, move to the left child; if it is greater, move to the right child. Continue this process until you find a null position where you can insert the new node with the given value.

**Key Insight:** The key insight is to leverage the properties of the binary search tree to efficiently find the correct position for the new value. By comparing the new value with the current node's value at each step, you can determine whether to go left or right, which allows you to maintain the BST property after insertion. This approach ensures that you are only traversing down one path from the root to a leaf, making it efficient.

**Gotchas:** Be careful to handle edge cases where the tree is empty (i.e., the root is null), in which case you should simply create a new node with the given value and return it as the new root. Additionally, make sure to correctly manage the pointers when inserting the new node to avoid memory leaks or dangling pointers.

**Complexity:** Time: O(h) where h is the height of the tree (O(log n) for balanced BST, O(n) for skewed BST) | Space: O(h) due to recursive call stack

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Search in BST — LC #700 | Find node not insert → same left right navigation simpler termination | Yes — direct foundation |
| Delete Node in BST — LC #450 | Delete not insert → same navigation three deletion cases on find | Yes — direct variant |
| Validate Binary Search Tree — LC #98 | Validate ordering not modify → same BST property different goal | Partial — same BST property |
| Lowest Common Ancestor of BST — LC #235 | Find LCA not insert → same ordering navigation different goal | Partial — same BST navigation |
| Balance a BST — LC #1382 | Rebalance after modifications → inorder collect then rebuild | Partial — same BST modification |
| Convert Sorted Array to BST — LC #108 | Build BST from scratch not insert one node → same BST property different construction | Partial — same BST family |
| Trim a BST — LC #669 | Remove nodes outside range → same recursive navigation different operation | Partial — same BST navigation |
| Two Sum IV — LC #653 | Find two nodes summing to target in BST → same BST navigation with hash set | Partial — same BST property |

**How this pattern scales:**
- **Recursive navigation to null slot** is the core trick — if val less than root go left, if greater go right. When null is reached create and return a new node. Recursive return value automatically rewires parent pointer to new node. O(h) time O(h) space
- **Return value rewiring** — `root.left = insert(root.left, val)` and `root.right = insert(root.right, val)` rewires parent pointers automatically on the way back up the recursion. No explicit parent tracking needed — same clean recursive pattern as delete
- **Iterative alternative** — track parent pointer explicitly as you navigate. When null child found attach new node directly to parent. O(h) time O(1) space — preferred when stack space is a concern for deep trees
- **Always inserts at leaf** — BST insertion always finds a null slot at the leaf level. Unlike balanced BST operations (AVL, Red-Black) that may rotate after insertion plain BST insert never modifies existing structure above the insertion point
- **BST modification family** → Search (LC #700) → Insert (LC #701) → Delete (LC #450) is the core BST operation ladder. Each builds on the same left right navigation skeleton — search terminates on find, insert terminates on null, delete terminates on find then restructures. All three share identical navigation logic with different termination behavior

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr){
            return new TreeNode(val);
        }
        if(val > root->val) root->right = insertIntoBST(root->right, val);
        else root -> left = insertIntoBST(root -> left, val);
        return root;
    }
};
```

## Delete Leaves With a Given Value LC 1325

<!-- notecardId: 1781483592009 -->

Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

 

Example 1:



Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).
Example 2:



Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]
Example 3:



Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.
 

Constraints:

The number of nodes in the tree is in the range [1, 3000].
1 <= Node.val, target <= 1000

**Link**: [text](https://leetcode.com/problems/delete-leaves-with-a-given-value/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Postorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree in postorder (left, right, node) and check if each node is a leaf with the target value. If it is, delete it by returning null to the parent. After processing both children, check if the current node has become a leaf with the target value and delete it if necessary. This process continues recursively until all applicable nodes are deleted.

**Key Insight:** The key insight is that you need to use postorder traversal to ensure that you check the children of a node before checking the node itself. This way, if a child node is deleted and causes the parent to become a leaf with the target value, you can then delete the parent node in the same recursive call. This cascading deletion is essential to correctly handle cases where multiple nodes in a path need to be deleted.

**Gotchas:** Be careful to handle edge cases where the root node itself may need to be deleted if it is a leaf with the target value. Additionally, make sure to correctly manage the return values to ensure that parent nodes are updated with null when their children are deleted.

**Complexity:** Time: O(n) where n is the number of nodes in the tree (since you visit each node once) | Space: O(h) where h is the height of the tree (due to recursive call stack)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Delete Node in BST — LC #450 | Delete specific node not leaves with value → same recursive return rewiring | Partial — same deletion idea |
| Delete Nodes and Return Forest — LC #1110 | Delete specific nodes return forest → same postorder deletion different trigger | Yes — direct variant |
| Prune Binary Tree — LC #814 | Remove subtrees containing only zeros → same postorder prune different condition | Yes — direct variant |
| Count Univalue Subtrees — LC #250 | Count subtrees all same value → same postorder bottom up validation | Partial — same postorder idea |
| Lowest Common Ancestor — LC #236 | Find LCA not delete → same postorder return value up tree | No — different pattern |
| Binary Tree Pruning — LC #814 | Remove zero subtrees → same leaf check cascade upward | Yes — same pattern |
| Serialize and Deserialize Binary Tree — LC #297 | Encode decode not delete → same postorder traversal different goal | No — different pattern |
| Find Leaves of Binary Tree — LC #366 | Group leaves by height → same postorder leaf identification different goal | Partial — same leaf idea |

**How this pattern scales:**
- **Postorder deletion with cascade** is the core trick — process children before parent. After recursing on both children check if current node has become a leaf with the target value. If so return null to parent effectively deleting it. Cascade continues upward automatically. O(n) time O(h) space
- **Postorder is mandatory** — must process children first so that newly created leaves (nodes whose children were just deleted) are caught in the same pass. Preorder would miss nodes that become leaves after their children are deleted
- **Return null to delete** — same return value rewiring as LC #701 and LC #450. `root.left = delete(root.left)` automatically disconnects deleted nodes. Returning null from a node removes it from the tree without explicit parent pointer manipulation
- **Cascade effect** — deleting a leaf may expose its parent as a new leaf with the target value which must also be deleted. Postorder naturally handles this since the parent is evaluated after its children have already been processed and potentially deleted
- **Prune BST connection** → LC #814 applies the same postorder cascade logic — remove subtrees containing only zeros. A node is pruned if both its children are pruned and its own value is zero. Same bottom up cascade, different pruning condition

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//postorder traversal, need to deal with leaves first before dealing with the root
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return nullptr;

        if(root -> left) root -> left = removeLeafNodes(root->left, target);
        if(root -> right) root -> right = removeLeafNodes(root->right, target);
        if(root->left == nullptr && root->right == nullptr && root->val == target){
            return nullptr; //if leaf node and the value of the leaf node is equal to the target, then we can delete the leaf node by returning nullptr, this will allow us to easily delete the leaf node, because when we return nullptr,
            // it will be assigned to the left or right child of the parent node, which will effectively delete the leaf node from the tree
        }
        return root;
    }
};
```

## Count Good Nodes in Binary Tree LC 1448

<!-- notecardId: 1781484178258 -->

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

 

Example 1:



Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
Example 2:



Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
Example 3:

Input: root = [1]
Output: 1
Explanation: Root is considered as good.
 

Constraints:

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4].

**Link**: [text](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

%

**Pattern:** Tree Traversal, Depth-First Search (DFS), Preorder Traversal

**Approach:** Use a depth-first search (DFS) approach to traverse the binary tree in preorder (node, left, right) while keeping track of the maximum value encountered along the path from the root to the current node. At each node, compare its value with the maximum value seen so far. If the current node's value is greater than or equal to the maximum value, it is considered a good node, and you can increment a counter. Update the maximum value if the current node's value is greater than the existing maximum before recursively traversing the left and right children.

**Key Insight:** The key insight is that you need to maintain the maximum value along the path from the root to the current node in order to determine if the current node is a good node. By using a preorder traversal, you can check the current node before traversing its children, which allows you to correctly count good nodes as you go down the tree.

**Gotchas:** Be careful to handle edge cases where the tree has only one node (the root), which is always a good node. Additionally, make sure to correctly update the maximum value as you traverse down the tree, and ensure that you are comparing the current node's value against the correct maximum value for that path.

**Complexity:** Time: O(n) where n is the number of nodes in the tree (since you visit each node once) | Space: O(h) where h is the height of the tree (due to recursive call stack)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Path Sum — LC #112 | Check if root to leaf sum equals target → same preorder carry running sum down | Yes — same pattern |
| Path Sum II — LC #113 | Collect all root to leaf paths meeting target → same preorder carry path backtrack | Yes — same pattern |
| Maximum Depth of Binary Tree — LC #104 | Carry depth down preorder → same preorder parameter passing different value | Yes — same DFS family |
| Binary Tree Maximum Path Sum — LC #124 | Combine values bottom up postorder → opposite direction to LC #1448 | No — different direction |
| Count Nodes Equal to Average of Subtree — LC #2265 | Count nodes where value equals subtree average → same postorder return sum and count | Partial — same counting idea |
| Pseudo-Palindromic Paths — LC #1457 | Count root to leaf paths that are pseudo palindromes → same preorder carry bitmask down | Yes — same pattern |
| Sum Root to Leaf Numbers — LC #129 | Build numbers from root to leaf paths → same preorder carry running number down | Yes — same pattern |
| Path Sum III — LC #437 | Count paths summing to target not just root to leaf → prefix sum hash map DFS | Partial — same path family |

**How this pattern scales:**
- **Preorder carry max down** is the core trick — pass running maximum from root to current node as parameter. At each node if `node.val >= maxSoFar` it is a good node increment count and update max. Recurse on both children with updated max. O(n) time O(h) space
- **Preorder carry direction** — information flows TOP DOWN. Parent passes context (running max) to children. This is the opposite of postorder problems like LC #124 where information flows BOTTOM UP. Recognizing which direction information needs to flow determines traversal order immediately
- **Global counter vs return value** — maintain a global count variable or pass count as a return value accumulated up the tree. Global variable is cleaner for counting problems. Return value accumulation (`return 1 + left + right`) is equally valid and avoids global state
- **Carry value pattern family** → Path Sum (LC #112) carries running sum, LC #1448 carries running max, Pseudo-Palindromic Paths (LC #1457) carries a bitmask of seen digits. All three use identical preorder skeleton — only the carried value and the condition check differ
- **Top down vs bottom up decision** → if a node needs information from its ancestors use preorder carry down. If a node needs information from its descendants use postorder return up. LC #1448 needs the max of all ancestors so preorder is mandatory — postorder cannot provide ancestor context

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root-> val); //start with the root
    }

private:
    int countGoodNodes(TreeNode* root, int maxSoFar){
        if(root == nullptr) return 0;

        int good = 0;
        if(root ->val >= maxSoFar){
            good = 1; //if it is good, just increment counter by 1, so if a node is good, good always gets incremented by 1 in the recursive call
            maxSoFar = root->val;  //update the max value, future nodes downstream get checked with this
        }
         good += countGoodNodes(root->left, maxSoFar); //this is an idea of preorder traversal, check the root and then check the left and right child, 
         //because you need to check the value of the current node before you check the left and right child, because if the value of the current node is not good, 
         //then you can return 0 immediately without checking the left and right child, so this is a preorder traversal question, because you need to check the value of the current node before you 
         //check the left and right child
        good += countGoodNodes(root->right, maxSoFar);

    return good;



    }
};
```

## Implement Trie (Prefix Tree) LC 208

<!-- notecardId: 1781629631361 -->

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

**Link**: [text](https://leetcode.com/problems/implement-trie-prefix-tree/)

%

**Pattern:** Trie Data Structure, Tree Implementation

**Approach:** Implement a Trie (prefix tree) data structure using a class with methods for inserting words, searching for complete words, and checking for prefixes. The Trie can be implemented using a nested class for the TrieNode, which contains a map of child nodes and a boolean flag to indicate if a node represents the end of a word. The insert method will add characters of the word to the Trie, the search method will check if a complete word exists in the Trie, and the startsWith method will check if any word in the Trie starts with the given prefix.

**Key Insight:** The key insight is that a Trie is a tree-like data structure where each node represents a character of a string. By using a map to store child nodes, you can efficiently navigate through the Trie to insert and search for words. The boolean flag at each node allows you to distinguish between nodes that represent the end of a valid word and those that are just intermediate characters.

**Gotchas:** Be careful to handle edge cases such as inserting an empty string or searching for an empty string. Additionally, make sure to correctly manage the child nodes in the Trie to avoid memory leaks or incorrect insertions. When implementing the search and startsWith methods, ensure that you are correctly traversing the Trie and checking the appropriate conditions for word completion and prefix matching.

**Complexity:** Time: O(m) for insert, search, and startsWith where m is the length of the word or prefix (since you need to traverse the Trie for each character) | Space: O(n * m) in the worst case where n is the number of words and m is the average length of the words (if all words are unique and share no common prefixes)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Word Search II — LC #212 | Find multiple words in board using Trie → same Trie structure as lookup optimization | Yes — direct application |
| Add and Search Word — LC #211 | Search with wildcard support → same Trie structure DFS on wildcard nodes | Yes — direct upgrade |
| Longest Common Prefix — LC #14 | Find longest shared prefix → Trie generalizes the vertical scan approach | Yes — generalization |
| Replace Words — LC #648 | Replace words with shortest root → same Trie prefix matching different goal | Yes — direct application |
| Design Search Autocomplete System — LC #642 | Autocomplete suggestions → same Trie with frequency tracking at nodes | Yes — direct upgrade |
| Maximum XOR of Two Numbers — LC #421 | Binary Trie for bitwise prefix matching → same Trie structure different alphabet | Yes — same pattern different domain |
| Map Sum Pairs — LC #677 | Sum values of keys with given prefix → same Trie with value aggregation at nodes | Yes — direct upgrade |
| Word Break — LC #139 | Check if string can be segmented using dictionary → Trie optimizes dictionary lookup | Partial — Trie as optimization |

**How this pattern scales:**
- **Array or hash map of children + isEnd flag** is the core structure — each TrieNode contains either a fixed size array of 26 children (lowercase only) or a hash map for general alphabets, plus a boolean `isEnd` marking complete words. Insert traverses or creates nodes character by character setting `isEnd = true` at the final node. O(L) time per operation where L is word length
- **Search vs startsWith distinction** — search requires `isEnd == true` at the final node confirming a complete word exists. startsWith only requires the traversal to complete successfully regardless of `isEnd`. Conflating these two checks is the most common implementation bug
- **Array vs hash map children** — fixed array of 26 is faster (O(1) indexing via `c - 'a'`) but wastes space for sparse alphabets. Hash map is more flexible for Unicode or mixed case but has higher constant overhead. Default to array for lowercase English problems, hash map otherwise
- **Trie as the answer to "repeated prefix lookups"** — any problem requiring multiple prefix queries against a fixed dictionary benefits from Trie's O(L) lookup regardless of dictionary size, compared to scanning all words which is O(n*L). This is the single biggest signal for reaching for a Trie
- **Word Search II connection** → LC #212 builds a Trie from the word list then DFS explores the board pruning branches where no Trie path exists. Building the Trie first transforms an O(words * board) brute force into a single combined board traversal — Trie eliminates redundant prefix checks across multiple words simultaneously

```cpp
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
```

## Design Add and Search Words Data Structure LC 211

<!-- notecardId: 1781630922244 -->

Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.

**Link**: [text](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

%

**Pattern:** Trie Data Structure with Wildcard Support, Tree Implementation

**Approach:** Implement a Trie (prefix tree) data structure similar to LC #208, but with additional support for wildcard characters ('.') in the search method. The TrieNode will contain a map of child nodes and a boolean flag to indicate if a node represents the end of a word. The addWord method will insert words into the Trie as before, while the search method will need to handle both exact character matches and wildcard matches by recursively checking all possible child nodes when a '.' is encountered.

**Key Insight:** The key insight is that when searching for a word with potential wildcard characters, you need to explore all possible paths in the Trie when you encounter a '.', since it can match any letter. This requires a recursive search approach that checks each child node of the current TrieNode when a '.' is encountered, while still maintaining the standard Trie traversal for exact character matches.

**Gotchas:** Be careful to handle edge cases such as searching for an empty string or a string that consists entirely of wildcard characters. Additionally, ensure that the recursive search correctly backtracks when exploring wildcard matches, and that it properly checks the isEnd flag to confirm complete word matches.

**Complexity:** Time: O(m) for addWord where m is the length of the word, O(26^k) for search where k is the number of wildcards (since each wildcard can match any of the 26 letters) | Space: O(n * m) in the worst case for addWord where n is the number of words and m is the average length of the words (if all words are unique and share no common prefixes)

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Implement Trie — LC #208 | No wildcard support → same Trie structure simpler search no DFS branching | Yes — direct foundation |
| Word Search II — LC #212 | Search board for multiple words → same Trie structure DFS on 2D grid not wildcard | Partial — same Trie + DFS idea |
| Wildcard Matching — LC #44 | Match pattern with * and ? against string → DP not Trie, different wildcard semantics | No — different pattern |
| Regular Expression Matching — LC #10 | Match pattern with . and * → DP not Trie, different wildcard semantics | No — different pattern |
| Replace Words — LC #648 | Replace words with shortest root → same Trie structure no wildcard needed | Partial — same Trie foundation |
| Design Search Autocomplete System — LC #642 | Autocomplete with frequency ranking → same Trie structure additional metadata | Partial — same Trie upgrade |
| Stream of Characters — LC #1032 | Check if any dictionary word ends at current stream position → Trie built in reverse | Yes — same Trie idea reversed |
| Map Sum Pairs — LC #677 | Sum values with given prefix → same Trie with value aggregation | Partial — same Trie foundation |

**How this pattern scales:**
- **Trie + DFS on wildcard** is the core trick — insert words normally into a Trie. Search recursively: for a normal character follow the single corresponding child. For `.` try all 26 possible children recursively (branching DFS). Return true if any branch reaches a node with `isEnd == true` at the end of the pattern. O(L) for exact match O(26^d) worst case for d dots
- **Branching only on wildcard** — the search degrades to exponential only in the number of `.` characters not the total word length. A pattern with zero dots is O(L) identical to LC #208. Most practical inputs have few wildcards keeping this fast in expected cases
- **DFS with index parameter** — pass current Trie node and current index into the pattern string as DFS parameters. Base case: index equals pattern length, return `node.isEnd`. Recursive case: if character is `.` loop through all existing children recursively, otherwise follow single child if it exists
- **Early termination optimization** — when looping through all 26 children for a `.`, return true immediately on the first successful branch rather than checking all 26. This is a single line optimization but meaningfully reduces average case work
- **Stream of Characters connection** → LC #1032 inserts dictionary words in REVERSE into a Trie then checks backward from the current stream position. Different problem framing but the same insight — Trie lookup direction can be inverted depending on what the query needs to check

```cpp
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
```

## Extra Characters in a String LC 2707 

<!-- notecardId: 1781634215584 -->

You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 

Constraints:

1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words

**Link**: [text](https://leetcode.com/problems/extra-characters-in-a-string/)

%

**Pattern:** Dynamic Programming, String Segmentation, Trie

**Approach:** Use DP to solve by using a memo table. The idea is to iterate through the string and for each index, check if any of the words in the dictionary match a substring starting at that index. If a match is found, recursively call the function for the index immediately following the matched word. The base case is when the index reaches the end of the string, at which point we return 0 (no extra characters). For each index, we also consider the case where we skip the current character (counting it as an extra character) and move to the next index. The minimum of these two options will give us the optimal solution.

**Gotchas:** Be careful to handle the base case correctly when the index reaches the end of the string. Additionally, ensure that you are correctly checking for matches against the dictionary words and that you are properly updating the minimum count of extra characters. It’s also important to use memoization to avoid redundant calculations and improve performance. You can't just go letter by letter and checking the trie as you might think for a brute force case, because you might have a case where you have a word in the dictionary that is longer than one letter, so you need to be able to check for matches against the dictionary words, and this is where the recursive calls come in, because you need to be able to check for matches against the dictionary words starting at each index of the string, and if you find a match, then you can recursively call the function for the index immediately following the matched word, this will allow you to check for all possible segmentations of the string against the dictionary words, and find the optimal solution with the minimum number of extra characters.

**Complexity:** Time: O(n * m * k) where n is the length of the string, m is the number of words in the dictionary, and k is the average length of the words (since for each index we check all words and their lengths) | Space: O(n) for the memoization table

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Word Break — LC #139 | Check if string can be fully segmented → same DP foundation no extra char counting | Yes — direct foundation |
| Word Break II — LC #140 | Return all valid segmentations → same DP with backtracking to collect paths | Partial — same DP family |
| Implement Trie — LC #208 | Build Trie for dictionary lookup → same Trie optimization for substring matching | Partial — same Trie optimization |
| Concatenated Words — LC #472 | Find words formed by other dictionary words → same DP segmentation different goal | Partial — same DP family |
| Palindrome Partitioning II — LC #132 | Minimum cuts for palindrome partitioning → same DP partition minimize cost | Yes — same DP structure |
| Perfect Squares — LC #279 | Minimum squares summing to n → same DP partition minimize count | Yes — same DP structure |
| Word Break with Trie optimization | Optimize dictionary lookup with Trie → same Trie + DP combination | Yes — direct optimization |
| Coin Change — LC #322 | Minimum coins summing to amount → same DP partition minimize count | Yes — same DP structure |

**How this pattern scales:**
- **DP partition minimizing leftover** is the core trick — `dp[i]` represents minimum extra characters in `s[0:i]`. For each position i try every substring `s[j:i]` checking if it is a dictionary word. If yes `dp[i] = min(dp[i], dp[j])`. If no extension helps `dp[i] = dp[i-1] + 1` (treat character i-1 as extra). O(n² * m) time where m is average word check cost, O(n) space
- **Base case and transition** — `dp[0] = 0` (empty prefix has zero extra characters). For each i from 1 to n, default `dp[i] = dp[i-1] + 1` assuming the current character is extra, then try all valid dictionary word endings to potentially improve it
- **Hash set for O(1) word lookup** — store dictionary words in a hash set for O(1) membership checks during the substring scan. Without it each check against the dictionary list is O(d) where d is dictionary size, blowing up total complexity significantly
- **Trie optimization** — replace the hash set with a Trie and walk the Trie while scanning substrings ending at each position. Avoids generating every possible substring explicitly since the Trie naturally prunes paths that cannot match any dictionary word. Reduces practical runtime when dictionary words share many prefixes
- **DP partition family** → Word Break (LC #139) asks "can it be fully segmented" (boolean). LC #2707 asks "minimize what is left over" (optimization). Coin Change (LC #322) and Perfect Squares (LC #279) ask "minimize count of pieces." All four share the identical partition DP skeleton — only the recurrence's combination logic and target metric differ

```cpp
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
```

## Word Search II LC 212

<!-- notecardId: 1781634840691 -->

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

**Link**: [text](https://leetcode.com/problems/word-search-ii/)

%

**Pattern:** Trie + Backtracking, DFS on 2D Grid

**Approach:** Build a Trie from the list of words to allow for efficient prefix checking. Then, perform a DFS on the board starting from each cell. During the DFS, check if the current path matches any prefix in the Trie. If it does, continue exploring; if it matches a complete word, add it to the result set. Use a visited set to ensure that the same cell is not used more than once in a single word path.

**Key Insight:** The key insight is that by using a Trie, you can efficiently check if the current path in the DFS is a valid prefix of any word in the list. This allows you to prune the search space early, avoiding unnecessary exploration of paths that cannot lead to a valid word. Additionally, using a set to store found words ensures that duplicates are not added to the result.

**Gotchas:** Be careful to mark cells as visited during the DFS and unmark them when backtracking to ensure that the same cell is not reused in a single path. Also, make sure to handle edge cases such as an empty board or an empty list of words. When adding found words to the result set, ensure that you are checking for complete word matches in the Trie, not just prefixes.

**Complexity:** Time: O(m * n * 4^L) where m and n are the dimensions of the board and L is the maximum length of words (since in the worst case, you may explore all paths of length L from each cell) | Space: O(W * L) for the Trie where W is the number of words and L is the average length of the words, plus O(L) for the recursion stack during DFS

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Word Search — LC #79 | Search for one word not multiple → same DFS backtracking no Trie needed | Yes — foundation |
| Implement Trie — LC #208 | Build Trie standalone → same Trie structure used as optimization here | Yes — direct foundation |
| Add and Search Word — LC #211 | Wildcard search in Trie → same Trie structure different query type | Partial — same Trie idea |
| Number of Islands — LC #200 | Count connected components → same DFS grid traversal different goal | Partial — same grid DFS family |
| Longest Common Prefix — LC #14 | Find shared prefix → Trie generalizes this idea to multiple words | Partial — same Trie foundation |
| Boggle Solver — classic problem | Find all valid words on letter grid → exact restatement of LC #212 | Yes — same problem family |
| Concatenated Words — LC #472 | Find words formed by other words → same Trie based prefix pruning idea | Partial — same Trie optimization |
| Robot Room Cleaner — LC #489 | DFS backtracking on grid with constraints → same backtrack and unmark visited | Partial — same backtracking idea |

**How this pattern scales:**
- **Trie + DFS backtracking with pruning** is the core trick — build a Trie from all words first. DFS from every cell in the board following Trie paths rather than checking each word independently. If the current cell's character has no corresponding Trie child, prune immediately. When a Trie node has `isEnd == true`, record the complete word. O(rows * cols * 4^L) worst case but Trie pruning makes practical performance far better
- **Why Trie beats per-word DFS** — naive approach runs DFS once per word giving O(words * rows * cols * 4^L). Building one Trie and running DFS once per starting cell shares prefix exploration across all words simultaneously — words sharing a prefix like "cat" and "car" explore the shared "ca" path only once
- **Mark visited and backtrack** — use a temporary marker (e.g. set cell to `#`) before recursing into neighbors and restore the original character after returning. Same visited tracking as LC #79 — failing to restore breaks subsequent searches starting from different cells
- **Trie pruning optimization** — after fully exploring a Trie node's subtree with no further unfound words below it, remove that child reference from the parent. This prevents repeatedly re-exploring dead branches across multiple starting cells, meaningfully improving performance on large boards
- **Duplicate avoidance** — once a word is found set `isEnd = false` or remove it from a results set check to avoid adding the same word twice if multiple paths reach it. A naive implementation can report the same word multiple times since multiple cells might trace the same word

```cpp
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
```

## Kth largest element in an array LC 215

<!-- notecardId: 1781844369109 -->

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

**Link**: [text](https://leetcode.com/problems/kth-largest-element-in-an-array/)

%

**Pattern:** Quickselect Algorithm, Partitioning, Priority Queue (Heap), Min Heap

**Approach:** Use the Quickselect algorithm, which is a selection algorithm to find the k-th smallest/largest element in an unordered list. The algorithm is based on the partitioning method used in QuickSort. We can choose a pivot and partition the array into two parts: elements greater than the pivot and elements less than the pivot. Depending on the position of the pivot after partitioning, we can determine if we need to search in the left or right partition or if we have found the k-th largest element. Or, if using a priority queue, we can maintain a min-heap of size k to keep track of the k largest elements seen so far. As we iterate through the array, we add elements to the heap and if the heap exceeds size k, we remove the smallest element. At the end, the root of the min-heap will be the k-th largest element.

**Key Insight:** The key insight is that the Quickselect algorithm allows us to find the k-th largest element in average O(n) time without needing to sort the entire array, which would take O(n log n). By partitioning the array around a pivot, we can effectively narrow down our search space for the k-th largest element. Alternatively, using a min-heap of size k allows us to maintain the k largest elements efficiently, ensuring that we can retrieve the k-th largest element in O(1) time after processing all elements.

**Gotchas:** When implementing the Quickselect algorithm, be careful with the partitioning logic to ensure that you are correctly identifying the position of the pivot and adjusting your search space accordingly. Additionally, when using a min-heap, make sure to handle edge cases such as when k is equal to the length of the array or when there are duplicate elements in the array. Also, be mindful of the time complexity of your chosen approach, as using a sorting method would not meet the requirement of solving it without sorting. When doing this question, it is easy to think using a max Heap is optimal, but it is not, because we would have to add all the elements to the max Heap, which would take O(n log n) time, and then we would have to remove the top element k times, which would take O(k log n) time, so the total time complexity would be O(n log n + k log n) which is not optimal. Using a min Heap of size k allows us to maintain only the k largest elements seen so far, and we can add elements to the heap in O(log k) time and remove the smallest element in O(log k) time, so the total time complexity would be O(n log k) which is more efficient than using a max Heap.

**Complexity:** Time: O(n) average case for Quickselect, O(n log k) for min-heap approach | Space: O(1) for Quickselect (in-place), O(k) for min-heap approach

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Kth Smallest Element in Sorted Matrix — LC #378 | Kth smallest across sorted matrix → binary search on value or heap | Partial — same kth idea |
| Top K Frequent Elements — LC #347 | K most frequent not kth largest → heap or bucket sort on frequency | Partial — same heap family |
| K Closest Points to Origin — LC #973 | K closest by distance not kth largest → same min heap size k | Yes — same pattern |
| Find K Pairs with Smallest Sums — LC #373 | K smallest pair sums → min heap lazy expansion | Partial — same heap idea |
| Sort an Array — LC #912 | Full sort not kth element → QuickSort or MergeSort no early stop | Partial — same partition idea |
| Wiggle Sort II — LC #324 | Interleave smaller and larger halves → same median finding via QuickSelect | Partial — same partition idea |
| Median of Two Sorted Arrays — LC #4 | Median across two sorted arrays → binary search on partition | Partial — same kth element family |
| Kth Largest Element in Stream — LC #703 | Kth largest in streaming data → maintain min heap of size k | Yes — direct variant |

**How this pattern scales:**
- **QuickSelect** is the optimal O(n) average approach — partition array around a random pivot. If pivot lands at index `n-k` (kth largest position from left in sorted order) return it. If pivot index is too large recurse left. If too small recurse right. O(n) average O(n²) worst case with bad pivot choice
- **Min heap of size k** is the O(n log k) alternative — iterate through array maintaining a min heap of size k. If current element exceeds heap minimum pop minimum push current. After processing all elements heap top is kth largest. Cleaner to implement under pressure than QuickSelect
- **Randomized pivot is mandatory for QuickSelect** — deterministic pivot selection (always first or last element) degrades to O(n²) on sorted or reverse sorted input. Always shuffle or pick a random pivot index before partitioning to guarantee O(n) average
- **Partition around pivot** — swap random pivot to end, use two pointer partition placing all elements less than pivot to the left all greater to the right return final pivot position. Same partition logic as Sort Colors (LC #75) Dutch National Flag applied to two groups not three
- **QuickSelect vs heap tradeoff** — QuickSelect is O(n) average but O(n²) worst case and modifies the input array. Min heap is O(n log k) always and does not modify input. For interviews always clarify whether input can be modified and whether worst case guarantee matters before choosing

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

// QuickSelect implementation for reference
class Solution {
private:
    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        swap(nums[pivotIndex], nums[right]); // Move pivot to end
        int storeIndex = left;

        for (int i = left; i < right; i++) {
            if (nums[i] > pivotValue) { // For kth largest, use > for descending order
                swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        swap(nums[right], nums[storeIndex]); // Move pivot to its final place
        return storeIndex;
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left]; // Only one element

        int pivotIndex = left + rand() % (right - left + 1); // Random pivot
        pivotIndex = partition(nums, left, right, pivotIndex);

        if (k == pivotIndex) {
            return nums[k]; // Found the kth largest
        } else if (k < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, k); // Search left
        } else {
            return quickSelect(nums, pivotIndex + 1, right, k); // Search right
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k - 1); // k-1 for zero-based index
    }
};
```

## Find Median from Data Stream LC 295

<!-- notecardId: 1781845202397 -->

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-105 <= num <= 105
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

**Link**: [text](https://leetcode.com/problems/find-median-from-data-stream/)

%

**Pattern:** Two Heaps (Min Heap and Max Heap), Median Maintenance

**Approach:** Use two heaps to maintain the lower half and upper half of the numbers. The max heap will store the smaller half of the numbers, while the min heap will store the larger half. When adding a number, we first add it to one of the heaps based on its value compared to the current median. After adding, we balance the heaps so that their sizes differ by at most one. To find the median, if both heaps have the same size, we take the average of their top elements; if one heap has more elements than the other, the median is the top element of that heap.

**Key Insight:** The key insight is that by maintaining two heaps, we can efficiently keep track of the median as new numbers are added. The max heap allows us to quickly access the largest number in the lower half, while the min heap allows us to quickly access the smallest number in the upper half. By ensuring that the heaps are balanced in size, we can easily compute the median based on the top elements of the heaps.

**Gotchas:** Be careful to maintain the balance of the two heaps after each insertion. When adding a new number, you may need to move elements between the heaps to ensure that their sizes differ by at most one. Additionally, when calculating the median, make sure to handle both cases where the heaps are of equal size and where one heap has more elements than the other. Also, consider edge cases such as when the first few numbers are added and how the median is calculated in those scenarios. To answer the follow ups, if all numbers are in the range [0, 100], we can use a counting array of size 101 to keep track of the frequency of each number and calculate the median based on the counts. If 99% of the numbers are in the range [0, 100], we can still use the counting array for those numbers and maintain a separate structure (like a min heap) for the outliers to efficiently calculate the median.

**Complexity:** Time: O(log n) for adding a number and O(1) for finding the median | Space: O(n) for storing the numbers in the heaps

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Kth Largest Element in Stream — LC #703 | Kth largest not median → single min heap of size k | Partial — same heap family |
| Sliding Window Median — LC #480 | Median in sliding window not full stream → same two heap idea with eviction | Yes — direct upgrade |
| Kth Largest Element in Array — LC #215 | Kth largest in static array → QuickSelect or heap no streaming | Partial — same heap idea |
| Find Median from Data Stream II | Weighted median with frequencies → same two heap structure different balancing | Partial — same heap family |
| IPO — LC #502 | Maximize capital using two heaps → same max heap min heap combination | Partial — same two heap idea |
| Sort an Array — LC #912 | Full sort not median → MergeSort or QuickSort no heap needed | No — different pattern |
| Data Stream as Disjoint Intervals — LC #352 | Track intervals not median → sorted set insertion different goal | No — different pattern |
| Maximum Average Subarray — LC #643 | Fixed window average not streaming median → sliding window | No — different pattern |

**How this pattern scales:**
- **Two heap invariant** is the core trick — maintain a max heap `lo` for the lower half and a min heap `hi` for the upper half. Invariant: `lo.size() == hi.size()` or `lo.size() == hi.size() + 1`. Median is `lo.top()` when sizes differ or `(lo.top() + hi.top()) / 2.0` when equal. O(log n) add O(1) findMedian
- **Add element protocol** — always push to `lo` first then balance. Push new element to `lo`. If `lo.top() > hi.top()` pop from `lo` push to `hi` to fix ordering violation. Then rebalance sizes — if `hi.size() > lo.size()` pop from `hi` push to `lo`
- **Three step add protocol** — (1) push to lo (2) fix ordering if lo top exceeds hi top (3) rebalance sizes. Collapsing these into fewer steps produces subtle bugs where the size invariant breaks on edge cases
- **Sliding window upgrade** → LC #480 adds eviction of expired elements from the window. Same two heap structure but requires lazy deletion — mark expired elements as deleted and skip them when they reach heap tops. Significantly harder than LC #295 — worth knowing exists as the natural hard follow-up
- **Two heap pattern generalizes** → IPO (LC #502) uses the same max heap min heap pair for a different purpose — min heap of project costs to find affordable projects max heap of profits to pick the best available. Same two heap management different semantic meaning per heap

```cpp
class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
    }
    
/*
maxHeap = 3 2 
minHeap =  4 



*/


    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        while(minHeap.size() > maxHeap.size()){
             maxHeap.push(minHeap.top());
             minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()){
            return (double) maxHeap.top();
        }
        else return (double) (minHeap.top() + maxHeap.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

## Design Twitter LC 355

<!-- notecardId: 1781850268078 -->

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
 

Constraints:

1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
A user cannot follow himself.

**Link**: [text](https://leetcode.com/problems/design-twitter/)

%

**Pattern:** Design, Hash Map, Priority Queue (Heap), Linked List

**Approach:** Use a hash map to store the tweets for each user, where the key is the userId and the value is a list of tweets (each tweet can be represented as a pair of tweetId and timestamp). Use another hash map to store the followers for each user, where the key is the userId and the value is a set of followeeIds. When posting a tweet, add it to the user's list of tweets with a timestamp. When retrieving the news feed, use a priority queue (min heap) to merge the most recent tweets from the user and their followees, keeping only the 10 most recent tweets in the heap. When following or unfollowing, update the followers hash map accordingly.

**Key Insight:** The key insight is that by using a hash map to store the tweets and followers, we can efficiently manage the relationships between users and their tweets. The priority queue allows us to efficiently retrieve the most recent tweets from the user and their followees without needing to sort all tweets every time. By keeping only the 10 most recent tweets in the heap, we can ensure that retrieving the news feed is efficient even as the number of tweets grows.

**Gotchas:** Be careful to handle edge cases such as when a user has no tweets or when a user is not following anyone. When retrieving the news feed, make sure to include the user's own tweets in addition to the tweets from their followees. Also, ensure that the timestamps are correctly assigned to each tweet so that the priority queue can accurately determine the most recent tweets. When implementing the follow and unfollow functionality, make sure to prevent users from following themselves and to handle cases where a user tries to unfollow someone they are not following.

**Complexity:** Time: O(N log k) for retrieving the news feed where N is the total number of tweets from the user and their followees, and k is the number of followees (since we are merging tweets using a heap) | Space: O(U + T) where U is the number of users and T is the total number of tweets stored in the hash map

**Variations & Related Problems:**

| Problem | Key Difference | Same Pattern? |
|---|---|---|
| Merge k Sorted Lists — LC #23 | Merge k sorted lists not k user tweet feeds → same min heap k way merge | Yes — direct foundation |
| Find Median from Data Stream — LC #295 | Two heaps for median not feed ranking → same heap management different goal | Partial — same heap family |
| Top K Frequent Elements — LC #347 | K most frequent not k most recent → heap on frequency not timestamp | Partial — same heap idea |
| LRU Cache — LC #146 | Evict least recently used → same recency tracking different structure | Partial — same recency idea |
| Design HashMap — LC #706 | Hash map foundation → same hash map for user data storage | Partial — same design family |
| Kth Largest Element in Stream — LC #703 | Kth largest in stream → same min heap size k | Partial — same heap family |
| News Feed Design — system design | Design scalable news feed → same follow/unfollow tweet concepts at scale | Partial — same concept |
| Design File System — LC #1166 | Hash map for path storage → same hash map design pattern | No — different pattern |

**How this pattern scales:**
- **Hash map + timestamp + k way merge heap** is the core trick — maintain `userTweets` map of userId to list of (timestamp, tweetId) pairs and `following` map of userId to set of followeeIds. For getNewsFeed collect most recent tweets from all followees into a min heap of size 10 extracting the globally most recent across all feeds. O(n log k) for getNewsFeed where n is total followees and k is feed size
- **Global timestamp counter** — maintain a single incrementing integer timestamp for every tweet posted. Higher timestamp means more recent. Using system time introduces collision risk — a single global counter guarantees strict ordering across all users
- **K way merge for feed** — initialize heap with the most recent tweet from each followee. Extract max (most recent) append to feed insert that followee's next tweet into heap. Same exact pattern as LC #23 (Merge k Sorted Lists) — getNewsFeed IS a k way merge problem where each user's tweet history is one sorted list
- **Follow self edge case** — when calling getNewsFeed always include the user's own tweets alongside their followees. Either add the user to their own following set on creation or handle explicitly in getNewsFeed. Missing this produces wrong feeds for users who only follow others
- **Lazy deletion for unfollow** — when a user unfollows someone simply remove from the following set. No need to clean up cached feeds since getNewsFeed rebuilds from scratch each time. If feed caching were added unfollow would require cache invalidation — worth mentioning as a scale consideration

```cpp
class Twitter {
    private:
        int timeStamp; //track time each tweet sent at with global counter
        unordered_map<int, unordered_set<int>> followingMap; //check who is following who
        unordered_map<int, vector<pair<int, int>>> AllTweets; //all related tweets for a person is stored in a vector of pairs, we deal 
        //with the top 10 most recent wtihin getNewsFeed
public:
    Twitter() {
        timeStamp = 0;
       
    }
    
    void postTweet(int userId, int tweetId) {
        AllTweets[userId].push_back({timeStamp++, tweetId}); //push pair storing timestamp and tweetID into AllTweets
    }
    
    vector<int> getNewsFeed(int userId) {
    std::priority_queue<pair<int, int>> pq; //maxHeap, largest .first (most recent) will show up

    for(const auto twt : AllTweets[userId]){
        pq.push(twt); //push all usertTweets
    }

    for(auto followee : followingMap[userId]){
        for(const auto twt : AllTweets[followee])
        pq.push(twt); //push all tweets from followees into the pq
    }

    vector<int> res;
    while(!pq.empty() && res.size() < 10){
        int currID = pq.top().second; //until top 10 found, push currIDs onto the vector
        pq.pop();
        res.push_back(currID);
    }
    return res;

    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followingMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followingMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
```

## IPO LC 502

<!-- notecardId: 1781850428455 -->


