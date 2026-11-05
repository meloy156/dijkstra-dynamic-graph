#include "Graph_for_dynamic.h"

#include <iostream>
#include <string>
#include <windows.h>


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


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

    Graph_for_dynamic graph(count_vertex);

    for (const auto& e : edges) {
        graph.add_edge(e[0], {e[1], e[2]});
    }




    
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
        } else
        {
            id_to = std::stoi(string);
            std::cin >> id_end;
        }

        
        std::cout << "Итоговое расстояние: " << graph.dist(id_to, id_end) << std::endl;
        std::cout << std::endl;

    } while(true);
}