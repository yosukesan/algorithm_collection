
#include "dfs.hpp"

void dfs_helper(vector<vector<int>>& g, const int& node, vector<bool>* is_visited) 
{
    if (!is_visited->at(node))
    {

        cout << node << endl;

        is_visited->at(node) = true;
        for (auto i: g[node])
            dfs_helper(g, i, is_visited);
    }
}

void dfs(vector<vector<int>>& g, const int& start)
{
    vector<bool> is_visited(g.size());

    dfs_helper(g, start, &is_visited);
}
