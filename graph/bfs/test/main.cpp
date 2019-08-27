
#include "bfs.hpp"

#include <cassert>

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

    int start (0), end(3);

    //result: 0 1 2 4 7 6 3 5 
    assert(false == bfs(adj_graph, start));
    
    //result: 0 1 2 4 7 6 3 
    assert(true == bfs(adj_graph, start, end));

    //result: 0 1 2 4 7 6 3 
    end = 7;
    assert(true == bfs(adj_graph, start, end));

    end = 5;
    assert(true == bfs(adj_graph, start, end));

    //result: 0 1 2 4 7 6 3 
    end = -1;
    assert(false == bfs(adj_graph, start, end));

    vector<vector<int>> g2(1);
    assert(false == bfs(g2, start, end));

    return 0;
}
