#pragma once

#include "../Graph/Graph.h"


class Finder_min_dist {
public:
    virtual ~Finder_min_dist() = default;

    virtual long long find_min_dist(const Graph& graph, int id_vertex_start, int id_vertex_end) const = 0;
};