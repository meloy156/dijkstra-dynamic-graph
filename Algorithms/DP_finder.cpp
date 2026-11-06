#include "DP_finder.h"

#include <vector>
#include <climits>

long long DP_finder::find_min_dist(const Graph& graph, int id_vertex_start, int id_vertex_end) const
{
    int count_vertex = graph.get_count_vertex();


    // массив расстояний от стартовой вершины
    std::vector<long long> dist_from_start_vertex(count_vertex + 1, INT_MAX);

    dist_from_start_vertex[id_vertex_start] = 0;


    // k - колво ребер от точки старта
    for(int k = 0; k < (count_vertex - 1); ++k)
    {
        bool flag_changes = false;
        
        // все вершины которые уже нашли
        for (int v = 1; v <= count_vertex; ++v)
        {
            if (dist_from_start_vertex[v] == INT_MAX)
                continue;


            // все ребра найденной вершины
            for (const Edge& e : graph.get_edges(v))
            {
                if ((dist_from_start_vertex[v] + e.weight) < dist_from_start_vertex[e.to])
                {
                    dist_from_start_vertex[e.to] = (dist_from_start_vertex[v] + e.weight);
                    flag_changes = true;
                }
            }
        }

        if (!flag_changes) break;
    }

    return dist_from_start_vertex[id_vertex_end] != INT_MAX ? dist_from_start_vertex[id_vertex_end] : -1;
}