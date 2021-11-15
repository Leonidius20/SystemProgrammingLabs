#pragma once

#include <string>
#include <functional>

class Menu {
public:
    class Item {
        std::string title;
        std::function<void()> callback;
        bool terminal = false;
    public:
        Item() = default;
        Item(const std::string& title1, const std::function<void()>& callback, bool isTerminal);
        Item(const std::string& title1, const std::function<void()>& callback);
        [[nodiscard]] std::string getTitle() const { return title; };
        [[nodiscard]] std::function<void()> getCallback() const { return callback; };
        [[nodiscard]] bool isTerminal() const { return terminal; };
    };
    Menu(Item* items, int numberOfElements);
    void showItems();
    void askForSelection();
private:
    Item* items;
    int numberOfItems;
};