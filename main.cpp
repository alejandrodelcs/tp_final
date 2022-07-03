#include "Menu.h"
#include "Validation.h"

int main() {
    Validation validation;
    Menu *menu = new Menu();
    int input;
    bool exit = false;
    menu->buildLists();
    while (!exit) {
        menu->displayMenu();
        input = validation.requestNumber("");
        exit = menu->processInput(input);
    }
    delete menu;
    return 0;
}