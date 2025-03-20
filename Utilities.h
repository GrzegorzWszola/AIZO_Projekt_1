#ifndef UTILITIES_H
#define UTILITIES_H
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

class Utilities {
public:
    static int* generateRandomIntArray(int size) {
        auto arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = std::rand() % size;
        }
        return arr;
    }

    static float* generateRandomFloatArray(int size) {
        auto arr = new float[size];
        for (int i = 0; i < size; ++i) {
            float newFloat = std::round(static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)*100)/100;
            arr[i] = newFloat + std::rand() % size;
        }
        return arr;
    }

    static bool isInt(const std::string& str) {
        std::istringstream iss(str);
        int x;
        return (iss >> x) && iss.eof();
    }

    static bool isFloatCheck(std::string filename) {
        if (filename.empty()) {
            throw invalid_argument("filename is empty");
        }
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            if (line.find(',') != std::string::npos || line.find('.') != std::string::npos) {
                return true;
            }
        }
        return false;
    }

    static int* readAndGenerateIntTable(std::string& filePath, int& size) {
        if (!filePath.empty() && filePath.front() == '\"' && filePath.back() == '\"') {
            filePath = filePath.substr(1, filePath.length() - 2);
        }
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Nie udało się otworzyć pliku.");
        }
        file >> size;
        if (size <= 0) {
            throw std::invalid_argument("Niepoprawny rozmiar tablicy");
        }
        auto numbers = new int[size];
        std::string line;
        int index = 0;
        while (file >> line) {
            if (!isInt(line)) {
                throw std::invalid_argument("Invalid data encountered. Not an integer: " + line);
            }
            numbers[index++] = std::stoi(line);
            if (index == size) {
                break;
            }
        }
        if (index != size) {
            delete[] numbers;
            throw std::invalid_argument("File contains fewer numbers than expected.");
        }
        return numbers;
    }

    static float* readAndGenerateFloatTable(std::string &filePath, int &size) {
        if (!filePath.empty() && filePath.front() == '"' && filePath.back() == '"') {
            filePath = filePath.substr(1, filePath.length() - 2);
        }
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Nie udalo sie otworzyc pliku.");
        }
        file >> size;
        if (size <= 0) {
            throw std::invalid_argument("Niepoprawny rozmiar tablicy");
        }
        auto numbers = new float[size];
        std::string numberStr;
        int index = 0;
        while (file >> numberStr) {
            std::replace(numberStr.begin(), numberStr.end(), ',', '.');
            try {
                float number = std::stof(numberStr);
                if (index >= size) {
                    delete[] numbers;
                    throw std::invalid_argument("Plik zawiera więcej liczb niz oczekiwano.");
                }
                numbers[index++] = number;
            } catch (const std::invalid_argument& e) {
                delete[] numbers;
                throw std::invalid_argument("Nieprawidłowy format liczby.");
            }
        }
        if (index < size) {
            delete[] numbers;
            throw std::invalid_argument("Plik zawiera mniej liczb niż oczekiwano.");
        }
        return numbers;
    }

    static int** generateTableCopies(int size, int* intTable) {
        auto tableCopies = new int*[5];
        auto intTableCopy = new int[size];
        auto intTable33p = new int[size];
        auto intTable66p = new int[size];
        auto intTableSorted = new int[size];
        auto intTableReverseSorted = new int[size];
        memcpy(intTableCopy, intTable, sizeof(int)*size);
        memcpy(intTable33p, intTable, sizeof(int)*size);
        memcpy(intTable66p, intTable, sizeof(int)*size);
        memcpy(intTableSorted, intTable, sizeof(int)*size);
        memcpy(intTableReverseSorted, intTable, sizeof(int)*size);
        std::sort(intTable33p, intTable33p + size/3);
        std::sort(intTable66p, intTable66p + (2 * size / 3));
        std::sort(intTableSorted, intTableSorted + size);
        std::sort(intTableReverseSorted, intTableReverseSorted + size, std::greater<int>());
        tableCopies[0] = intTableCopy;
        tableCopies[1] = intTable33p;
        tableCopies[2] = intTable66p;
        tableCopies[3] = intTableSorted;
        tableCopies[4] = intTableReverseSorted;
        return tableCopies;
    }

    static void generateTableFloat(int size, float*& floatTable, float*& floatTableCopy, float*& floatTable33p, float*& floatTable66p, float*& floatTableSorted, float*& floatTableReverseSorted){
        floatTableCopy = new float[size];
        floatTable33p = new float[size];
        floatTable66p = new float[size];
        floatTableSorted = new float[size];
        floatTableReverseSorted = new float[size];
        memcpy(floatTableCopy, floatTable, sizeof(int)*size);
        memcpy(floatTable33p, floatTable, sizeof(int)*size);
        memcpy(floatTable66p, floatTable, sizeof(int)*size);
        memcpy(floatTableSorted, floatTable, sizeof(int)*size);
        memcpy(floatTableReverseSorted, floatTable, sizeof(int)*size);
        std::sort(floatTable33p, floatTable33p + size/3);
        std::sort(floatTable66p, floatTable66p + (2 * size / 3));
        std::sort(floatTableSorted, floatTableSorted + size);
        std::sort(floatTableReverseSorted, floatTableReverseSorted + size, std::greater<int>());
    }
};


#endif
