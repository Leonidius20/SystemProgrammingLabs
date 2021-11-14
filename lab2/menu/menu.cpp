#include <iostream>
#include "menu.h"

using namespace std;

Menu::Item::Item(const std::string &title, const std::function<void()> &callback, bool isTerminal) {
    this->title = title;
    this->callback = callback;
    this->terminal = isTerminal;
}

Menu::Item::Item(const std::string &title1, const std::function<void()> &callback) {
    this->title = title1;
    this->callback = callback;
}

Menu::Menu(Menu::Item *items, int numberOfElements) {
    this->items = items;
    this->numberOfItems = numberOfElements;
}

void Menu::showItems() {
    for (int i = 1; i <= numberOfItems; i++) {
        cout << i << " - " << items[i - 1].getTitle() << endl;
    }
}

void Menu::askForSelection() {
    cout << "Choose an action: ";
    int action;
    cin >> action;
    if (action > numberOfItems || action < 1) {
        cout << "Invalid selection" << endl;
        askForSelection();
    }
    Item item = items[action - 1];
    item.getCallback()();
    if (!item.isTerminal()) {
        showItems();
        askForSelection();
    }
}
