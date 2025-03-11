#ifndef GUI_H
#define GUI_H
#include <process.h>
#include <conio.h>
using namespace std;


class GUI {
public:
    static int consoleStart() {
        int choice = 1;
        while (true) {
            system("cls");
            cout << "Wybierz typ danych:" << endl;
            cout << (choice == 1 ? "--> " : "    ") << "1. Generuj losowe tablice int" << endl;
            cout << (choice == 2 ? "--> " : "    ") << "2. Generuj losowe tablice float" << endl;
            cout << (choice == 3 ? "--> " : "    ") << "3. Testowanie algorytmow" << endl;
            cout << (choice == 4 ? "--> " : "    ") << "4. Wyjscie" << endl;

            char key = _getch();
            if (key == 72) {
                if (choice > 1) choice--;
            } else if (key == 80) {
                if (choice < 4) choice++;
            } else if (key == 13) {
                return choice;
            }
        }
    }

    static int chooseAlgorythm() {
        int choice = 1;
        while (true) {
            system("cls");
            cout << "Wybierz typ danych:" << endl;
            cout << (choice == 1 ? "--> " : "    ") << "1. Insertion Sort(przez wstawianie)" << endl;
            cout << (choice == 2 ? "--> " : "    ") << "2. Heap Sort(przez kopcowanie)" << endl;
            cout << (choice == 3 ? "--> " : "    ") << "3. ###" << endl;
            cout << (choice == 4 ? "--> " : "    ") << "4. ###" << endl;
            cout << (choice == 5 ? "--> " : "    ") << "5. Wyjscie" << endl;

            char key = _getch();
            if (key == 72) {
                if (choice > 1) choice--;
            } else if (key == 80) {
                if (choice < 5) choice++;
            } else if (key == 13) {
                return choice;
            }
        }
    }

    static int testGUI() {
        int choice = 1;
        while (true) {
            system("cls");
            cout << "Wybierz typ danych:" << endl;
            cout << (choice == 1 ? "--> " : "    ") << "1. Wczytaj z pliku" << endl;
            cout << (choice == 2 ? "--> " : "    ") << "2. Wygeneruj losowa tablice int" << endl;
            cout << (choice == 3 ? "--> " : "    ") << "3. Wygeneruj losowa tablice float" << endl;
            cout << (choice == 4 ? "--> " : "    ") << "4. Wybierz algorytm" << endl;
            cout << (choice == 5 ? "--> " : "    ") << "5. Wyswietl nieposortowana tablice" << endl;
            cout << (choice == 6 ? "--> " : "    ") << "6. Wyswietl posortowana tablice" << endl;
            cout << (choice == 7 ? "--> " : "    ") << "7. Wyjscie" << endl;

            char key = _getch();
            if (key == 72) {
                if (choice > 1) choice--;
            } else if (key == 80) {
                if (choice < 7) choice++;
            } else if (key == 13) {
                return choice;
            }
        }
    }
};

#endif
