#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Alien Dictionary
 */

// @lc code=start
class Solution {
public:
    string alienOrder(vector<string>& words) {
        //we will use Kahns algo here, top sort
        //first thing, lets find the unique characters in the words, and create a graph with them
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        string resString;
        int result = 0;
        for(auto word : words){
            for (auto c: word){
                graph[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        //here, we will compare each pair of words, and find the first character that is different, and create a directed edge from the first character to the second character, and increment the indegree of the second character
        for(int i = 0; i < words.size() - 1; i++){
            string word1 = words[i];
            string word2 = words[i + 1];
            int minLength = min(word1.size(), word2.size());
            for(int j = 0; j < minLength; j++){
                char c1 = word1[j];
                char c2 = word2[j];
                if(c1 != c2){
                    if(graph[c1].find(c2) == graph[c1].end()){
                        graph[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break; //we only care about the first different character, because that is the order of the characters
                }
            }
            //check for invalid case, if word1 is longer than word2 and word1 starts with word2, then it is invalid
            //prefix trap
            if(word1.size() > word2.size() && word1.substr(0, minLength) == word2.substr(0, minLength)){
                return "";
            }
        }


//from here, textbook kahns algo topological sort like Course Schedule
        queue<char> q;
        for(auto pair : indegree){
            if(pair.second ==0){
                q.push(pair.first);
            }
        }

        while(!q.empty()){
            auto front = q.front();
            q.pop();
            result++;
            resString.push_back(front);
            for(auto neighbor : graph[front]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if(result != graph.size()) return "";
        return resString;
    }
};
// @lc code=end

