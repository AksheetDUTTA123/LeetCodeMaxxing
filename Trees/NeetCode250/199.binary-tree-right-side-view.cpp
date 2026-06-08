#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
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
// @lc code=end

