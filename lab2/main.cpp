#include <iostream>
#include "menu/menu.h"

using namespace std;

int main() {
	Menu::Item items[] = {
            Menu::Item("Add a hotel", []() {
                printBfs(graph, askForVertex(graph), cout);
            }),
            Menu::Item("Raise a hotel's rating", []() {
                printDfs(graph, askForVertex(graph), cout);
            }),
	    Menu::Item("Lower a hotel's rating", []() {
                printDfs(graph, askForVertex(graph), cout);
            }),
	    Menu::Item("Remove a hotel", []() {
                printDfs(graph, askForVertex(graph), cout);
            }),
	    Menu::Item("Get hotel info", []() {
                printDfs(graph, askForVertex(graph), cout);
            }),
            Menu::Item("Exit", []() {}, true)
    };
    Menu menu(items, 3);
    menu.showItems();
    menu.askForSelection();
}
