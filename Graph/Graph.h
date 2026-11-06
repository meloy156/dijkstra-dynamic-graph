#pragma once

#include <iostream>
#include <vector>

struct Edge
{
    int to;
    int weight;

    Edge(int to, int weight): to(to), weight(weight) {}

    void to_stream(std::ostream& os) const;
};



struct Vertex
{
private:
    int id;
    std::vector<Edge> edges;
    
public:

    Vertex(): id(0), edges() {}
    Vertex(int id): id(id), edges() {}

    void add_edge(int to, int weight);
    void add_edge(const Edge& edge);

    int get_id() const;
    const std::vector<Edge>& get_edges() const;


    void to_stream(std::ostream& os) const;
};



class Graph
{
private:
    int count_vertex;
    int count_edge;
    std::vector<Vertex> vertices;

public:


    Graph()
        : count_vertex(0)
        , count_edge(0)
        , vertices()
    {}


    Graph(int count_vertex)
        : count_vertex(count_vertex)
        , count_edge(0)
        , vertices(count_vertex + 1)
    {}

    void add_edge(int id, const Edge& edge);

    const std::vector<Edge>& get_edges(int id) const;
    int get_count_vertex() const;
    int get_count_edge() const;

    void print_vertex(std::ostream& os) const;
};