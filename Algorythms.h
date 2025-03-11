#ifndef ALGORYTHMS_H
#define ALGORYTHMS_H
#include <chrono>

class Algorythms {
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
                j = j - 1;
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
};

#endif
