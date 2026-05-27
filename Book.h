#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Book {
private:
    std::string title;
    std::string author;
    std::string genre;
    int year;
    double price;

public:
    Book(std::string title, std::string author, std::string genre, int year, double price)
        : title(title), author(author), genre(genre), year(year), price(price) {}

    std::string getTitle() const { return title; }
    double getPrice()      const { return price; }

    // Rovid osszefoglalo egy sorban
    void printSummary() const {
        std::cout << title << "  [" << author << ", " << year << "]\n";
    }

    // Reszletes adatlap
    void printDetails() const {
        std::cout << "  Cim      : " << title  << "\n"
                  << "  Szerzo   : " << author << "\n"
                  << "  Mufaj    : " << genre  << "\n"
                  << "  Kiadas   : " << year   << "\n"
                  << "  Ar       : " << std::fixed << std::setprecision(0)
                  << price << " Ft\n";
    }
};
