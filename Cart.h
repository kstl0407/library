#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include "Book.h"

class Cart {
private:
    std::vector<const Book*> items;

public:
    void addBook(const Book* book) {
        items.push_back(book);
        std::cout << "  \"" << book->getTitle() << "\" a kosarba kerult!\n";
    }

    bool   isEmpty() const { return items.empty(); }
    size_t size()    const { return items.size();  }

    void removeBook(size_t index) {
        if (index < items.size()) {
            std::cout << "  \"" << items[index]->getTitle() << "\" eltavolitva a kosarbol.\n";
            items.erase(items.begin() + index);
        }
    }

    double getTotal() const {
        double total = 0;
        for (const Book* b : items)
            total += b->getPrice();
        return total;
    }

    // Kosar tartalmanak kilistazasa + vegosszeg
    void printContents() const {
        if (items.empty()) {
            std::cout << "  A kosar ures.\n";
            return;
        }
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << "  " << i + 1 << ". ";
            items[i]->printSummary();
        }
        std::cout << "  ---------------------------\n"
                  << "  Osszesen: " << std::fixed << std::setprecision(0)
                  << getTotal() << " Ft\n";
    }

    void clear() { items.clear(); }
};
