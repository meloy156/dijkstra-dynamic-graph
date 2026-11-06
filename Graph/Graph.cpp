#include "Graph.h"

#include <queue>
#include <climits>

void Edge::to_stream(std::ostream& os) const {
    os << "{"
       << to << ", "
       << weight
       << "}, ";
}


void Vertex::add_edge(int to, int weight) {
    edges.emplace_back(to, weight);
}

void Vertex::add_edge(const Edge& edge) {
    edges.emplace_back(edge);
}

int Vertex::get_id() const {
    return id;
}

const std::vector<Edge>& Vertex::get_edges() const {
    return edges;
}


void Vertex::to_stream(std::ostream& os) const {
    os << "ID вершины: " << id << std::endl;
    os << "Ребра вершины" << std::endl;
    os << "{куда, вес}" << std::endl;

    for (const Edge& e : edges) {
        e.to_stream(os);
    }
    os << std::endl;
}




void Graph::add_edge(int id, const Edge& edge) {
    ++count_edge;
    vertices[id].add_edge(edge);
}


const std::vector<Edge>& Graph::get_edges(int id) const {
    return vertices[id].get_edges();
}


int Graph::get_count_edge() const {
    return count_edge;
}



int Graph::get_count_vertex() const {
    return count_vertex;
}


void Graph::print_vertex(std::ostream& os) const {
    os << "||| Данные о графе |||" << std::endl;
    os << "Кол-во вершин в графе: " << count_vertex << std::endl;
    os << "Кол-во ребер в графе: " << count_edge << std::endl;

    os << std::endl;

    os << "    || Вершины графа ||" << std::endl;
    for (const Vertex& v : vertices) {
        v.to_stream(os);
    }
}