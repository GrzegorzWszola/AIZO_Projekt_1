#include <iostream>
#include <limits>

#include "Algorythms.h"
#include "GUI.h"
#include "RaportGeneration.h"
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

        //GENEROWANIE CSV
        if (choice == 1 || choice == 2) {
            cout << "Podaj rozmiar: ";
            while (!(cin >> size)) {
                cout << "Blad! Wprowadz liczbe calkowita: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (choice == 1) {
                Utilities::resetOutputFile();
                Utilities::writeSortType("Insertion Sort;");
                RaportGeneration::generateDataForSort<int>(size, 1);
                Utilities::writeSortType("Heap Sort;");
                RaportGeneration::generateDataForSort<int>(size, 2);
                Utilities::writeSortType("Shell Sort n/2;");
                RaportGeneration::generateDataForSort<int>(size, 3);
                Utilities::writeSortType("Shell Sort optymalne;");
                RaportGeneration::generateDataForSort<int>(size, 4);
                Utilities::writeSortType("Quick Sort prawy;");
                RaportGeneration::generateDataForSort<int>(size, 5);
                Utilities::writeSortType("Quick Sort lewy;");
                RaportGeneration::generateDataForSort<int>(size, 6);
                Utilities::writeSortType("Quick Sort srodkowy;");
                RaportGeneration::generateDataForSort<int>(size, 7);
                Utilities::writeSortType("Quick Sort losowy;");
                RaportGeneration::generateDataForSort<int>(size, 8);
            }
            if (choice == 2) {
                Utilities::resetOutputFile();
                Utilities::writeSortType("Insertion Sort;");
                RaportGeneration::generateDataForSort<float>(size, 1);
                Utilities::writeSortType("Heap Sort;");
                RaportGeneration::generateDataForSort<float>(size, 2);
                Utilities::writeSortType("Shell Sort n/2;");
                RaportGeneration::generateDataForSort<float>(size, 3);
                Utilities::writeSortType("Shell Sort optymalne;");
                RaportGeneration::generateDataForSort<float>(size, 4);
                Utilities::writeSortType("Quick Sort prawy;");
                RaportGeneration::generateDataForSort<float>(size, 5);
                Utilities::writeSortType("Quick Sort lewy;");
                RaportGeneration::generateDataForSort<float>(size, 6);
                Utilities::writeSortType("Quick Sort srodkowy;");
                RaportGeneration::generateDataForSort<float>(size, 7);
                Utilities::writeSortType("Quick Sort losowy;");
                RaportGeneration::generateDataForSort<float>(size, 8);
            }
        }

        //TESTOWANIE ALGO
        if (choice == 3) {
            while (true) {
                int testChoice = GUI::testGUI();
                if (testChoice == 1) {
                    floatTable = nullptr;
                    intTable = nullptr;
                    std::string input;
                    cout << "Podaj nazwe pliku: ";
                    try {
                        cin >> input;
                        bool isFloat = Utilities::isFloatCheck(input);
                        if (isFloat) {
                            floatTable = Utilities::readAndGenerateFloatTable(input, size);
                        } else {
                            intTable = Utilities::readAndGenerateIntTable(input, size);
                        }

                    }
                    catch (invalid_argument &e) {cout << e.what();}
                    catch (runtime_error &e) {cout << e.what();}
                }

                if (testChoice == 2) {
                    floatTable = nullptr;
                    sortedFloatTable = nullptr;
                    cout << "Podaj rozmiar: "; cin >> size;
                    intTable = Utilities::generateRandomArray<int>(size);
                }

                if (testChoice == 3) {
                    intTable = nullptr;
                    sortedIntTable = nullptr;
                    cout << "Podaj rozmiar: "; cin >> size;
                    floatTable = Utilities::generateRandomArray<float>(size);
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
                    if (algChoice == 3) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::ShellSort(sortedIntTable, size, time, true);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 4) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::ShellSort(sortedIntTable, size, time, false);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 5) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::QuickSort(sortedIntTable, size, time, 1);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 6) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::QuickSort(sortedIntTable, size, time, 2);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 7) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::QuickSort(sortedIntTable, size, time, 3);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 8) {
                        sortedIntTable = new int[size];
                        memcpy(sortedIntTable, intTable, size*sizeof(int));
                        Algorythms::QuickSort(sortedIntTable, size, time, 4);
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
                    if (algChoice == 3) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::ShellSort(sortedFloatTable, size, time, true);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 4) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::ShellSort(sortedFloatTable, size, time, false);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 5) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::QuickSort(sortedFloatTable, size, time, 1);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 6) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::QuickSort(sortedFloatTable, size, time, 2);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 7) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::QuickSort(sortedFloatTable, size, time, 3);
                        cout << "Czas potrzebny do sortowania: " << time << " ms" << endl;
                        system("pause");
                    }
                    if (algChoice == 8) {
                        sortedFloatTable = new float[size];
                        memcpy(sortedFloatTable, floatTable, size*sizeof(float));
                        Algorythms::QuickSort(sortedFloatTable, size, time, 4);
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
                if (testChoice == 7 && sortedIntTable != nullptr) {
                    if (Utilities::isSorted<int>(sortedIntTable, size)) {
                        cout << "Tablica posortowana" << endl;
                    } else {
                        cout << "Tablica nie posortowana" << endl;
                    }
                    system("pause");
                }
                if (testChoice == 7 && sortedFloatTable != nullptr) {
                    if (Utilities::isSorted<float>(sortedFloatTable, size)) {
                        cout << "Tablica posortowana" << endl;
                    } else {
                        cout << "Tablica nie posortowana" << endl;
                    }
                    system("pause");
                }
                if (testChoice == 8) {break;}
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
