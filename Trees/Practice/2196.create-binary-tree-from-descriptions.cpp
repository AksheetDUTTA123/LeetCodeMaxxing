#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap; //this will be used to store the nodes of the tree, the key will be the value of the node,
        // and the value will be a pointer to the node, this will allow you to easily access the node when you need to assign the left and right child of the node, 
        //because you can easily access the node by its value, and then assign the left and right child of the node by using the pointer to the node
        unordered_set<int> childNodes; //we need this for the second pass, if we find a node that is never a child node, then that node must be the root node, 
        //because the root node is the only node that is never a child node, so we need to keep track of the child nodes in order to find the root node in the second pass
        for(const auto &des : descriptions){
            int parent = des[0];
            int child = des[1];
            int isLeft = des[2];

            if(nodeMap.find(parent) == nodeMap.end()){
                nodeMap[parent] = new TreeNode(parent); //if the parent node is not in the nodeMap, then we need to create a new node 
                //for the parent node and add it to the nodeMap, this will allow us to easily access the parent node when we need to assign the left and right child of the parent node
            }
            if(nodeMap.find(child) == nodeMap.end()){
                nodeMap[child] = new TreeNode(child); //do the same thing for a child node not in the nodeMap
            }
            if(nodeMap.find(parent) != nodeMap.end() && nodeMap.find(child) != nodeMap.end()){ //if both the parent and child node are in the nodeMap
                if(isLeft == 1){
                    nodeMap[parent]-> left = nodeMap[child];
                }
                else{
                    nodeMap[parent]-> right = nodeMap[child];
                }
                childNodes.insert(child); //insert childNode to the set, needed for second pass to return the root
            }
        }
        for(const auto& des : descriptions){
            int parent = des[0];
            if(childNodes.find(parent) == childNodes.end()){
                return nodeMap[parent];
            }
        }
        return nullptr; //return nullptr because if we have gone through the second pass and we have not found a node that is never a child node, then there is no root node, which means the tree is empty, so we return nullptr
    }
};
// @lc code=end

