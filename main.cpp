#include <iostream>
#include <limits>

#include "Algorythms.h"
#include "GUI.h"
#include "Utilities.h"
using namespace std;
int main() {
    int size;
    double time;
    int** tableCopies;
    int* intTable;
    float* floatTable;
    int* sortedIntTable;
    float* sortedFloatTable;
    while (true) {
        size = 0;
        time = 0;
        tableCopies = nullptr;
        intTable = nullptr;
        floatTable = nullptr;
        sortedIntTable = nullptr;
        sortedFloatTable = nullptr;
        auto choice = GUI::consoleStart();
        if (choice == 4) {break;}
        if (choice == 1 || choice == 2) {
            cout << "Podaj rozmiar: ";
            while (!(cin >> size)) {
                cout << "Blad! Wprowadz liczbe calkowita: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            int algChoice = GUI::chooseAlgorythm();
            if (choice == 1 && algChoice == 1) {
                auto intTable = Utilities::generateRandomIntArray(size);
                tableCopies = Utilities::generateTableCopies(size, intTable);
                Algorythms::InsertionSort(tableCopies[0], size, time);
                cout << "Time needed to sort random array: " << time << " ms" << endl;
                Algorythms::InsertionSort(tableCopies[1], size, time);
                cout << "Time needed to sort random array: " << time << " ms" << endl;
                if (size <= 100) {
                    for (int i = 0; i < size; i++) {
                        cout << tableCopies[0][i] << " ";
                    }
                }
                system("pause");
            }
        }

        //TESTOWANIE ALGO
        if (choice == 3) {
            while (true) {
                int testChoice = GUI::testGUI();
                if (testChoice == 1) {

                }

                if (testChoice == 2) {
                    floatTable = nullptr;
                    sortedFloatTable = nullptr;
                    cout << "Podaj rozmiar: "; cin >> size;
                    intTable = Utilities::generateRandomIntArray(size);
                }

                if (testChoice == 3) {
                    intTable = nullptr;
                    sortedIntTable = nullptr;
                    cout << "Podaj rozmiar: "; cin >> size;
                    floatTable = Utilities::generateRandomFloatArray(size);
                }

                if (testChoice == 4 && intTable != nullptr) {
                    int algChoice = GUI::chooseAlgorythm();
                    if (algChoice == 1) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::InsertionSort(sortedIntTable, size, time);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 2) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::HeapSort(sortedIntTable, size, time);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                }else if (testChoice == 4 && floatTable != nullptr) {
                    int algChoice = GUI::chooseAlgorythm();
                    if (algChoice == 1) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::InsertionSort(sortedFloatTable, size, time);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 2) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::HeapSort(sortedFloatTable, size, time);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                }

                if (testChoice == 5 && intTable != nullptr) {
                    for (int i = 0; i < size; i++) {
                        cout << intTable[i] << " ";
                    }
                    system("pause");
                } else if (testChoice == 5 && floatTable != nullptr) {
                    for (int i = 0; i < size; i++) {
                        cout << floatTable[i] << " ";
                    }
                    system("pause");
                }
                if (testChoice == 6 && sortedIntTable != nullptr) {
                    for (int i = 0; i < size; i++) {
                        cout << sortedIntTable[i] << " ";
                    }
                    system("pause");
                }
                if (testChoice == 6 && sortedFloatTable != nullptr) {
                    for (int i = 0; i < size; i++) {
                        cout << sortedFloatTable[i] << " ";
                    }
                    system("pause");
                }
                if (testChoice == 7) {break;}
            }
        }

    }
    delete[] intTable;
    delete[] floatTable;
    delete[] sortedIntTable;
    delete[] sortedFloatTable;
    delete[] tableCopies;
    return 0;
}
