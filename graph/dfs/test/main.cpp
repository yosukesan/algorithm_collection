
#include "dfs.hpp"

int main()
{
    vector<vector<int>> adj_graph ({{0, 1, 2, 4, 7, 6},
                                    {0, 6, 2},
                                    {1, 0, 3, 5},
                                    {4, 7},
                                    {0, 3, 6},
                                    {2, 6},
                                    {0, 1, 4, 5, 7},
                                    {3, 6, 0}});

    dfs(adj_graph, 0);
}
