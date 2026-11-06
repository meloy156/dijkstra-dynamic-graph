#include "../Graph/Graph.h"
#include "../Algorithms/Dijkstra_finder.h"

#include <iostream>
#include <string>
#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    // Исходный граф
    const int count_vertex = 8;
    const int edges[14][3] = {
        {1, 2, 4}, {1, 5, 9}, {1, 6, 10},
        {2, 3, 1}, {2, 5, 3}, {2, 7, 2},
        {3, 4, 1}, {3, 6, 1}, {3, 8, 7},
        {4, 7, 8}, {4, 8, 6},
        {5, 6, 4},
        {6, 7, 1},
        {7, 8, 5}
    };

    Graph graph(count_vertex);

    for (const auto& e : edges) {
        graph.add_edge(e[0], {e[1], e[2]});
        graph.add_edge(e[1], {e[0], e[2]});

    }


    Dijkstra_finder dj_finder;

    
    do {

        std::string string;
        int id_to;
        int id_end;
        std::cout << "Расстояние от до: {id_от, id_до}" << std::endl;
        std::cout << "Выход: q" << std::endl;
        
        std::cin >> string;
        if (string == "q") 
        {
            break;
        }
         
        id_to = std::stoi(string);
        std::cin >> id_end;

        
        std::cout << "Итоговое расстояние: " << dj_finder.find_min_dist(graph, id_to, id_end) << std::endl;
        std::cout << std::endl;

    } while(true);
}