class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> hashTable;
       for (int i = 0; i < nums.size(); i++){
        hashTable[nums[i]] = i;
       } 

       for (int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];
        if(hashTable.find(complement) != hashTable.end() && hashTable[complement] != i){
            return {i, hashTable[complement]};
        }
       }
       return {};
    }
};
