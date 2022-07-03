#include "Menu.h"

int main() {
    Menu menu;
    bool exit = false;
    menu.buildListReadings();
    menu.buildGraph();
    menu.buildHashTable();
    menu.setEndMenu(exit);
    while(!exit){
        menu.interaction();
        exit = menu.getEndMenu();
    }
    return 0;
}