#pragma once

#include "Finder_min_dist.h"


class Dijkstra_finder : public Finder_min_dist
{

    long long find_min_dist(const Graph& graph, int id_vertex_start, int id_vertex_end) const override;
};