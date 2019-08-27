
#include <iostream>
#include <deque>

#include "bfs.hpp"

bool bfs(vector<vector<int>>& adj_graph, const int& start, const int& terminal)
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
            return true;

        for (auto i: adj_graph[vertex])
            if (!is_visited[i])
                is_visited[i] = true, q.push_back(i);
    }

    cout << endl;
}

