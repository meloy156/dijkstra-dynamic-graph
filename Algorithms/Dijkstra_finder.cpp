#include "Dijkstra_finder.h"

#include <climits>

long long Dijkstra_finder::find_min_dist(const Graph& grap, int id_vertex_start, int id_vertex_end) const
{
    
    //массив расстояний от начальной вершины
    std::vector<long long> dist_from_start_vertex(grap.get_count_vertex() + 1, INT_MAX);
    
    // массив флагов расскрыли ли вершину
    std::vector<bool> is_expended_vertex(grap.get_count_vertex() + 1, false);

    // стартовая точка
    dist_from_start_vertex[id_vertex_start] = 0;



    
    for (int i = 0; i < grap.get_count_vertex(); ++i) {
        

        // поиск мин вершины
        int id_current_vertex = -1;
        long long current_min_dist = INT_MAX;
        for (int v = 1; v <= grap.get_count_vertex(); ++v)
        {
            if (!is_expended_vertex[v]
                && dist_from_start_vertex[v] < current_min_dist)
            {
                id_current_vertex = v;
                current_min_dist  = dist_from_start_vertex[v]; 
            }
        }

        // если нет вершины, то выходим
        if (id_current_vertex == -1)
            break;


        is_expended_vertex[id_current_vertex] = true;


        // расскрываем эту вершину
        for(const Edge& e : grap.get_edges(id_current_vertex))
        {
            if (!is_expended_vertex[e.to]
                && (dist_from_start_vertex[id_current_vertex] + e.weight) < dist_from_start_vertex[e.to])
            {
                dist_from_start_vertex[e.to] = (dist_from_start_vertex[id_current_vertex] + e.weight);
            }
        }
    }

    return dist_from_start_vertex[id_vertex_end] == INT_MAX ? -1 : dist_from_start_vertex[id_vertex_end];
}