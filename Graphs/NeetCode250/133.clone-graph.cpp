#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        visited[node] = new Node(node -> val);
        q.push(node); //need to push to start BFS traversal
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(Node* neighbors : top->neighbors){ //this goes through all of the neighbors of the top element in the queue
                if(visited.find(neighbors) == visited.end()){ //if neighbor not in visited, we need to make a new node for it
                    visited[neighbors] = new Node(neighbors->val); //make a new node for the neighbor in the map
                    q.push(neighbors); //push to queue, we will explore the neighbors neighbors later
                }
            visited[top]->neighbors.push_back(visited[neighbors]); //for the current node, push back the neighbor into the vector of neighbors for the current node we are at
            }
        }
        return visited[node];
    }
};
// @lc code=end

