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
            cout << (choice == 1 ? "--> " : "    ") << "1. Generuj dane do sprawozdania int" << endl;
            cout << (choice == 2 ? "--> " : "    ") << "2. Generuj dane do sprawozdania float" << endl;
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
            cout << (choice == 3 ? "--> " : "    ") << "3. ShellSort (standardowy)" << endl;
            cout << (choice == 4 ? "--> " : "    ") << "4. ShellSort (optymalny)" << endl;
            cout << (choice == 5 ? "--> " : "    ") << "5. QuickSort (prawy)" << endl;
            cout << (choice == 6 ? "--> " : "    ") << "6. QuickSort (lewy)" << endl;
            cout << (choice == 7 ? "--> " : "    ") << "7. QuickSort (srodkowy)" << endl;
            cout << (choice == 8 ? "--> " : "    ") << "8. QuickSort (losowy)" << endl;
            cout << (choice == 9 ? "--> " : "    ") << "9. Wyjscie" << endl;

            char key = _getch();
            if (key == 72) {
                if (choice > 1) choice--;
            } else if (key == 80) {
                if (choice < 9) choice++;
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
            cout << (choice == 7 ? "--> " : "    ") << "7. Sprawdz posortowanie" << endl;
            cout << (choice == 8 ? "--> " : "    ") << "8. Wyjscie" << endl;

            char key = _getch();
            if (key == 72) {
                if (choice > 1) choice--;
            } else if (key == 80) {
                if (choice < 8) choice++;
            } else if (key == 13) {
                return choice;
            }
        }
    }
};

#endif
