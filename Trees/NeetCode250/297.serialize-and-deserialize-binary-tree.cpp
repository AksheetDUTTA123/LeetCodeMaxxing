#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
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
// @lc code=end

