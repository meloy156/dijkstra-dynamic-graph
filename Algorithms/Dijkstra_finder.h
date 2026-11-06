#include "Finder_min_tree.h"


class Dijkstra_finder : public Finder_min_tree
{

    long long find_min_tree(const Graph& graph, int id_vertex_start, int id_vertex_end);
};