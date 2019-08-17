
#include <iostream>
#include <deque>

#include "bfs.hpp"

void dfs (vector<vector<int>>& adj_graph, const int& start, const int& terminal=-1)
{
    vector<bool> is_visited(adj_graph.size());
    deque<int> q(1, start);
    int vertex;

    while (!q.empty())
    {
        vertex = q.front();
        q.pop_front();
        is_visited[vertex] = true;

        cout << vertex << ' ';

        if (vertex == terminal)
            break;

        for (auto i: adj_graph[vertex])
            if (!is_visited[i])
                is_visited[i] = true, q.push_back(i);
    }

    cout << endl;
}
