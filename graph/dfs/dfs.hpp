
#include <vector>
#include <iostream>

using namespace std;

void dfs_helper(vector<vector<int>>& g, const int& node, vector<bool>* is_visited);
void dfs(vector<vector<int>>& g, const int& start);
