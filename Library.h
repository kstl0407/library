#pragma once
#include <vector>
#include <limits>
#include "Book.h"
#include "Cart.h"

class Library {
private:
    std::vector<Book> books;
    Cart cart;

    // ---- segitsegfuggvenyek ----

    static void separator() {
        std::cout << "\n=============================\n";
    }

    // Biztonsagos egeszbeolvasas
    static int readInt() {
        int n;
        while (!(std::cin >> n)) {
            std::cin.clear();
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
            std::cout << "  Kerlek szamot irj: ";
        }
        return n;
    }

    // ---- almenuk ----

    // Reszletes nezet + kosarba tetes
    void bookDetailMenu(const Book& book) {
        while (true) {
            separator();
            book.printDetails();
            std::cout << "\n  1. Kosarba tesz\n"
                         "  0. Vissza\n"
                         "Valasszon: ";
            int ch = readInt();
            if (ch == 0) break;
            if (ch == 1) { cart.addBook(&book); break; }
            std::cout << "  Ervenytelen valasztas.\n";
        }
    }

    // Konyvek listajanak bongeszese
    void bookListMenu() {
        while (true) {
            separator();
            std::cout << "Konyvek listaja:\n\n";
            for (size_t i = 0; i < books.size(); ++i) {
                std::cout << "  " << i + 1 << ". ";
                books[i].printSummary();
            }
            std::cout << "\n  0. Vissza\n"
                         "Valasszon (reszletek): ";
            int ch = readInt();
            if (ch == 0) break;
            if (ch >= 1 && ch <= (int)books.size())
                bookDetailMenu(books[ch - 1]);
            else
                std::cout << "  Ervenytelen valasztas.\n";
        }
    }

    // Kosar megtekintese, fizetes, eltavolitas
    void cartMenu() {
        while (true) {
            separator();
            std::cout << "Kosar tartalma:\n\n";
            cart.printContents();

            std::cout << "\n";
            if (!cart.isEmpty()) {
                std::cout << "  1. Fizetes\n"
                             "  2. Konyv eltavolitasa a kosarbol\n";
            }
            std::cout << "  0. Vissza\n"
                         "Valasszon: ";
            int ch = readInt();

            if (ch == 0) break;

            if (ch == 1 && !cart.isEmpty()) {
                separator();
                std::cout << "  Fizetes sikeres!\n"
                          << "  Fizetett osszeg: " << std::fixed << std::setprecision(0)
                          << cart.getTotal() << " Ft\n"
                          << "  Koszonjuk a vasarlast!\n";
                cart.clear();
                break;
            }

            if (ch == 2 && !cart.isEmpty()) {
                std::cout << "  Melyik konyvet tavolitsa el? (1-" << cart.size() << "): ";
                int idx = readInt();
                if (idx >= 1 && idx <= (int)cart.size())
                    cart.removeBook(idx - 1);
                else
                    std::cout << "  Ervenytelen szam.\n";
                continue;
            }

            std::cout << "  Ervenytelen valasztas.\n";
        }
    }

public:
    Library() {
        books.push_back(Book("A gyuruk ura",                  "J.R.R. Tolkien",  "Fantasy",      1954, 4990));
        books.push_back(Book("Harry Potter es a bolcsek kove","J.K. Rowling",    "Fantasy",      1997, 3490));
        books.push_back(Book("1984",                          "George Orwell",   "Disztopia",    1949, 2990));
        books.push_back(Book("Egri csillagok",                "Gardonyi Geza",   "Tortenelmi",   1901, 1990));
        books.push_back(Book("Az ember tragediaja",           "Madach Imre",     "Drama",        1862, 1490));
        books.push_back(Book("A kis herceg",                  "Antoine de Saint-Exupery","Mese", 1943, 1290));
        books.push_back(Book("Crime and Punishment",          "Fjodor Dosztojevszkij","Regeny",  1866, 2490));
    }

    // Foprogram hurka
    void run() {
        std::cout << "Udvozoljuk a Konyvtarban!\n";

        while (true) {
            separator();
            std::cout << "Fomenu:\n\n"
                         "  1. Konyvek bongeszese\n"
                         "  2. Kosar megtekintese\n"
                         "  0. Tavozas\n"
                         "Valasszon: ";
            int ch = readInt();

            if (ch == 0) {
                if (!cart.isEmpty()) {
                    std::cout << "\n  FIGYELEM: A kosar nem ures!\n"
                                 "  Biztosan tavozni szeretne a kosar elhagyasaval? (1 = igen, 0 = nem): ";
                    int confirm = readInt();
                    if (confirm != 1) continue;
                }
                std::cout << "\n  Viszontlatasra!\n\n";
                break;
            }
            else if (ch == 1) bookListMenu();
            else if (ch == 2) cartMenu();
            else              std::cout << "  Ervenytelen valasztas.\n";
        }
    }
};
