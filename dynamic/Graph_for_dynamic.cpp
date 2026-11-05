#include "Graph_for_dynamic.h"

#include <queue>

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




void Graph_for_dynamic::add_edge(int id, const Edge& edge) {
    ++count_edge;
    vertices[id].add_edge(edge);
}


const std::vector<Edge>& Graph_for_dynamic::get_edges(int id) const {
    return vertices[id].get_edges();
}


int Graph_for_dynamic::get_count_edge() const {
    return count_edge;
}



int Graph_for_dynamic::get_count_vertex() const {
    return count_vertex;
}


void Graph_for_dynamic::print_vertex(std::ostream& os) const {
    os << "||| Данные о графе |||" << std::endl;
    os << "Кол-во вершин в графе: " << count_vertex << std::endl;
    os << "Кол-во ребер в графе: " << count_edge << std::endl;

    os << std::endl;

    os << "    || Вершины графа ||" << std::endl;
    for (const Vertex& v : vertices) {
        v.to_stream(os);
    }
}






long long Graph_for_dynamic::dist(int id_vertex_to, int id_vertex_end) const {

    // очередь вершин которые не раскрыты
    std::queue<int> queue_id_vertices;
    queue_id_vertices.push(id_vertex_to);

    // массив флагов была ли раскрыта вершина
    std::vector<bool> expended_id_vertex(this->count_vertex + 1, false);


    // массив расстояний от начальной вершины
    std::vector<long long> dist_from_begin(this->count_vertex + 1, INT_MAX);
   
    // стартовая позиция дистанция 0
    dist_from_begin[id_vertex_to] = 0;



    while (queue_id_vertices.size() != 0)
    {
        // берем вершину из очереди
        const int current_id_vertex = queue_id_vertices.front();
        const Vertex& current_vertex = vertices[current_id_vertex];
        queue_id_vertices.pop();
        expended_id_vertex[current_id_vertex] = true;


        // перебираем все ребра текущей вершины
        for (const Edge& e : current_vertex.get_edges()) 
        {
            if ((dist_from_begin[current_id_vertex] + e.weight) < dist_from_begin[e.to]) 
            {
                dist_from_begin[e.to] = (dist_from_begin[current_id_vertex] + e.weight);
                
                // проверяем не раскрыли ли уже вершину и добавляем в очередь
                if (expended_id_vertex[e.to] == false) {
                    queue_id_vertices.push(e.to);
                }
            }
        }
    }


    if (dist_from_begin[id_vertex_end] != INT_MAX) {
        return dist_from_begin[id_vertex_end];
    }

    return -1;
}