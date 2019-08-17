
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;

bool dfs (vector<vector<int>>& adj_graph, const int& start, const int& terminal=-1)
{
    if (adj_graph.size() <= 1)
        return false;

    vector<bool> is_visited(adj_graph.size());
    deque<int> q(1, start);
    int vertex;

    while (!q.empty())
    {
        vertex = q.front();
        q.pop_front();
        is_visited[vertex] = true;

        if (vertex == terminal)
            return true; 

        for (auto i: adj_graph[vertex])
            if (!is_visited[i])
                is_visited[i] = true, q.push_back(i);
    }

    return false;
}

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
    assert(false == dfs(adj_graph, start));
    
    //result: 0 1 2 4 7 6 3 
    assert(true == dfs(adj_graph, start, end));

    //result: 0 1 2 4 7 6 3 
    end = 7;
    assert(true == dfs(adj_graph, start, end));

    end = 5;
    assert(true == dfs(adj_graph, start, end));

    //result: 0 1 2 4 7 6 3 
    end = -1;
    assert(false == dfs(adj_graph, start, end));

    vector<vector<int>> g2(1);
    assert(false == dfs(g2, start, end));

    return 0;
}
