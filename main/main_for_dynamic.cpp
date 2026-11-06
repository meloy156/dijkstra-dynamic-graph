#include "../Graph/Graph.h"
#include "../Algorithms/DP_finder.h"

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {

    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    #endif

    // Исходный граф
    const int count_vertex = 7;
    const int edges[11][3] = {
        {1, 2, 16}, {1, 3, 11},
        {2, 4, 4}, {2, 5, 2},
        {3, 2, 2}, {3, 5, 5},
        {4, 6, 9}, {4, 7, 1},
        {5, 4, 3}, {5, 7, 6},
        {6, 7, 10}
    };

    Graph graph(count_vertex);

    for (const auto& e : edges) {
        graph.add_edge(e[0], {e[1], e[2]});
    }


    DP_finder dp_finder;

    
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

        
        std::cout << "Итоговое расстояние: " << dp_finder.find_min_dist(graph, id_to, id_end) << std::endl;
        std::cout << std::endl;

    } while(true);
}