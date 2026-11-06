#pragma once

#include "Finder_min_dist.h"


class DP_finder : public Finder_min_dist
{
public:

    long long find_min_dist(const Graph& graph, int id_vertex_start, int id_vertex_end) const override;

};