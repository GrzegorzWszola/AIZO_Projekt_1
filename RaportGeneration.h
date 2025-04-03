#ifndef RAPORTGENERATION_H
#define RAPORTGENERATION_H
#include <iostream>

#include "Algorythms.h"
#include "Utilities.h"

static void loopGeneration(double &averageTime, int tableIndex, int size);

class RaportGeneration {
    template<typename T>
    static void loopGeneration(double &averageTime, int tableIndex, int size, int sortType) {
        double time = 0;
        for (int i = 0; i < 2; i++) {
            T* tab = Utilities::generateRandomArray<T>(size);
            T** tableCopies = Utilities::generateTableCopies<T>(size, tab);
            switch (sortType) {
                case 1:
                    Algorythms::InsertionSort(tableCopies[tableIndex], size, time);
                    break;
                case 2:
                    Algorythms::HeapSort(tableCopies[tableIndex], size, time);
                    break;
                case 3:
                    Algorythms::ShellSort(tableCopies[tableIndex], size, time, true);
                    break;
                case 4:
                    Algorythms::ShellSort(tableCopies[tableIndex], size, time, false);
                    break;
                case 5:
                    Algorythms::QuickSort(tableCopies[tableIndex], size, time, 1);
                    break;
                case 6:
                    Algorythms::QuickSort(tableCopies[tableIndex], size, time, 2);
                    break;
                case 7:
                    Algorythms::QuickSort(tableCopies[tableIndex], size, time, 3);
                    break;
                case 8:
                    Algorythms::QuickSort(tableCopies[tableIndex], size, time, 4);
                    break;
                default:
                    break;
            }
            averageTime += time;
        }
    }

public:
    template<typename T>
    static void generateDataForSort(int size, int sortType) {
        double averageTime = 0;
        //normal random
        loopGeneration<T>(averageTime, 0, size, sortType);
        averageTime = averageTime / 2;
        Utilities::writeToFile("Losowa kolejność", averageTime);

        averageTime = 0;
        //33% posortowana
        loopGeneration<T>(averageTime, 1, size, sortType);
        averageTime = averageTime / 2;
        Utilities::writeToFile("33% posortowana", averageTime);

        averageTime = 0;
        //66% posortowana
        loopGeneration<T>(averageTime, 2, size, sortType);
        averageTime = averageTime / 2;
        Utilities::writeToFile("66% posortowana", averageTime);\

        averageTime = 0;
        //posortowana
        loopGeneration<T>(averageTime, 3, size, sortType);
        averageTime = averageTime / 2;
        Utilities::writeToFile("posortowana", averageTime);

        averageTime = 0;
        //posortowana odwrotnie
        loopGeneration<T>(averageTime, 4, size, sortType);
        averageTime = averageTime / 2;
        Utilities::writeToFile("posortowana odwrotnie", averageTime);
    }
};



#endif
