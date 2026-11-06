#pragma once

#include "../Graph/Graph.h"


class Finder_min_tree {
public:
    virtual ~Finder_min_tree() = default;

    virtual long long find_min_tree(const Graph& graph, int id_vertex_start, int id_vertex_end) const = 0;
};