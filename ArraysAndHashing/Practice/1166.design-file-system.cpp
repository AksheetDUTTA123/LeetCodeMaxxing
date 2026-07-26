#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=1166 lang=cpp
 *
 * [1166] Design File System
 */

// @lc code=start
class FileSystem {
private:
unordered_map<string, int> fs; //store pathnames, we can derive the parent using rfind
public:
    FileSystem() {
        
    }
    
    bool createPath(string path, int value) {
        if(path == "/" || path.empty() || path[0] != '/') return false;
        string parent = "";
        if(fs.find(path) != fs.end()) return false; //if path exists, return false;
        int lastSlash = path.rfind('/'); //get idx for last / , use this to find parent
        parent = path.substr(0, lastSlash);
        if(fs.find(parent) == fs.end() && !parent.empty()) return false; //if we cant find parent return false
        fs[path] = value;
        return true;
    }
    
    int get(string path) {
        if(fs.find(path) == fs.end()) return -1;
        return fs[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
// @lc code=end

