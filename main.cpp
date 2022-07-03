#include "List.h"
#include "Mst.h"
#include "Graph.h"
#include "Reading.h"
#include "AuthorsFileParser.h"
#include "Menu.h"
#include "Hash.h"
#include "Validation.h"

int main() {
    Validation validation;
    Menu m;
    int input;
    bool exit = false;
    m.buildLists();
    while (!exit) {
        m.displayMenu();
        input = validation.requestNumber("");
        std::cin >> input;
        std::cin.ignore();
        std::cout << std::endl;        
        exit = m.processInput(input);
    }
    return 0;
}