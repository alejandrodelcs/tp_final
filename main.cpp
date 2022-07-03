#include "List.h"
#include "Mst.h"
#include "Graph.h"
#include "Reading.h"
#include "AuthorsFileParser.h"
#include "Menu.h"
#include "Hash.h"

int main() {
    Menu m;
    int input;
    bool exit = false;
    m.buildLists();
    while (!exit) {
        m.displayMenu();
        std::cout << "> ";
        std::cin >> input;
        std::cin.ignore();
        std::cout << std::endl;        
        exit = m.processInput(input);
    }
    return 0;
}