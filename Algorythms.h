#ifndef ALGORYTHMS_H
#define ALGORYTHMS_H
#include <chrono>
#include <stack>

class Algorythms {
private:
    //Funkcja pomocnicza budująca maksymalny kopiec czyli taki który ma na najstarszej pozycji największą liczbę
    template<typename T>
    static void heapify(T a[], int n, int i){
        //Indeks rodzica posiadający dzieci
        int largest = i;
        //Indeks lewego i prawego dziecka rodzica
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        //Sprawdzamy czy któreś z dzieci jest większe od rodzica
        if (leftChild < n && a[leftChild] > a[largest]) {
            largest = leftChild;
        }
        if (rightChild < n && a[rightChild] > a[largest]) {
            largest = rightChild;
        }
        //Jeżeli któreś z dzieci okazało się większe zamieniamy je miejscem z rodzicem i używamy funkcji-
        //-heapify rekurencyjnie aby naprawić drzewo
        if (largest != i) {
            std::swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

    template<typename T>
    static void QuickSortRecursive(T a[], int low, int high, int type) {
        if (low < high) {
            int pi = Partition(a, low, high, type);
            QuickSortRecursive(a, low, pi - 1, type);
            QuickSortRecursive(a, pi + 1, high, type);
        }
    }

    template<typename T>
static void QuickSortIterative(T a[], int low, int high, int type) {
        std::stack<std::pair<int, int>> stack;
        stack.push({low, high});  // Zaczynamy od całego zakresu

        while (!stack.empty()) {
            auto [l, h] = stack.top();  // Pobieramy bieżący zakres
            stack.pop();  // Usuwamy z stosu

            if (l < h) {
                // Particjonowanie tablicy wokół pivota
                int pi = Partition(a, l, h, type);

                // Jeśli lewa część jest większa niż jeden element, dodajemy do stosu
                if (pi - 1 > l) {
                    stack.push({l, pi - 1});
                }

                // Jeśli prawa część jest większa niż jeden element, dodajemy do stosu
                if (pi + 1 < h) {
                    stack.push({pi + 1, h});
                }
            }
        }
    }

    template<typename T>
    static int Partition(T a[], int low, int high, int type) {
        int pivotIndex;

        // Wybór pivota
        switch (type) {
            case 1: pivotIndex = high; break;             // Skrajny prawy
            case 2: pivotIndex = low; break;              // Skrajny lewy
            case 3: pivotIndex = (low + high) / 2; break; // Środkowy element
            case 4: pivotIndex = low + std::rand() % (high - low + 1); break; // Losowy element
            default: pivotIndex = high; break;
        }

        // Przesunięcie pivota na koniec
        std::swap(a[pivotIndex], a[high]);
        T pivot = a[high];
        int i = low - 1; // Indeks mniejszych elementów

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                std::swap(a[i], a[j]);
            }
        }

        std::swap(a[i + 1], a[high]);  // Umieszczamy pivota w odpowiednim miejscu
        return i + 1;  // Zwracamy nową pozycję pivota
    }

public:
    template<typename T>
    static void InsertionSort(T tempArray[], int size, double &time) {
        auto start = std::chrono::high_resolution_clock::now();
        //Iterujemy przez tablice
        for (int i = 1; i < size; ++i) {
            //Klucz to zmienna w której przechowywany jest element, który będziemy wstawiać w odpowiednie miejsce w posortowanej części tablicy.
            T key = tempArray[i];
            //Tworzymy j to indeks w posortowanej części tablicy
            int j = i - 1;

            // Ta pętla sprawdza czy elementy w posortowanej części tablicy są większe niż klucz.
            // Jeśli tak przesuwamy je w prawo aby zrobić miejsce dla klucza.
            while (j >= 0 && tempArray[j] > key) {
                //Przestwiamy element o jeden w prawo
                tempArray[j + 1] = tempArray[j];
                j--;
            }
            //Przypisujemy klucz w odpowiednie miejsce tabeli
            tempArray[j + 1] = key;
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        time = elapsed.count();
    }

    template<typename T>
    static void HeapSort(T tempArray[], int size, double &time) {
        auto start = std::chrono::high_resolution_clock::now();
        // Budowanie kopca (Heapify dla wszystkich węzłów wewnętrznych od dołu do góry)
        for (int i = size/2 - 1; i >= 0; i--) {
            heapify(tempArray, size, i);
        }
        // Sortowanie przez usuwanie elementów z kopca
        for (int i = size - 1; i > 0; i--) {
            // Zamiana największego elementu z ostatnim elementem w tablicy
            std::swap(tempArray[0], tempArray[i]);
            // Naprawa kopca dla zmniejszonej części tablicy
            heapify(tempArray, i, 0);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        time = elapsed.count();
    }

    template<typename T>
    static void ShellSort(T* a, int size, double &time, bool type) {
        auto start = std::chrono::high_resolution_clock::now();
        if (type == true) {
            for (int gap = size / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < size; i++) {
                    T temporary = a[i];
                    int j;
                    for (j = i; j >= gap && a[j - gap] > temporary; j -= gap) {
                        a[j] = a[j - gap];
                    }
                    a[j] = temporary;
                }
            }
        } else {
            int gap = 1;
            //Sprawdzamy największą możliwą przerwe
            while (gap < size / 3) {
                gap = 3 * gap + 1;
            }
            while (gap >= 1) {
                for (int i = gap; i < size; i++) {
                    T temp = a[i];
                    int j = i;
                    while (j >= gap && a[j - gap] > temp) {
                        a[j] = a[j - gap];
                        j -= gap;
                    }
                    a[j] = temp;
                }
                gap /= 3;
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        time = elapsed.count();
    }

    template<typename T>
    static void QuickSort(T* a, int size, double &time, int type) {
        auto start = std::chrono::high_resolution_clock::now();

        QuickSortRecursive(a, 0, size - 1, type);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        time = elapsed.count();
    }


};

#endif
