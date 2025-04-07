#ifndef UTILITIES_H
#define UTILITIES_H
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <random>
#include <bits/fs_fwd.h>
#include <bits/fs_path.h>

class Utilities {
public:
    template<typename T>
    static T* generateRandomArray(int size, T minValue = 0, T maxValue = 0) {
        if (maxValue <= minValue) {
            maxValue = static_cast<T>(size - 1);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        if constexpr (std::is_integral<T>::value) {
            std::uniform_int_distribution<int> dist(static_cast<int>(minValue), static_cast<int>(maxValue));
            auto arr = new T[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = static_cast<T>(dist(gen));
            }
            return arr;
        }
        else if constexpr (std::is_floating_point<T>::value) {
            std::uniform_real_distribution<T> dist(minValue, maxValue);
            auto arr = new T[size];
            for (int i = 0; i < size; ++i) {
                arr[i] = dist(gen);
            }
            return arr;
        }
        return nullptr;
    }

    static bool isInt(const std::string& str) {
        std::istringstream iss(str);
        int x;
        return (iss >> x) && iss.eof();
    }

    static bool isFloatCheck(std::string filename) {
        if (!filename.empty() && filename.front() == '"' && filename.back() == '"') {
            filename = filename.substr(1, filename.length() - 2);
        }
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
        if (!filePath.empty() && filePath.front() == '"' && filePath.back() == '"') {
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
        for (int i = 0; i < size; ++i) {
            cout << numbers[i] << " ";
        }
        system("pause");
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
        for (int i = 0; i < size; ++i) {
            cout << numbers[i] << " ";
        }
        system("pause");
        return numbers;
    }

    template<typename T>
    static T** generateTableCopies(int size, T* intTable) {
        auto tableCopies = new T*[5];
        auto tableCopy = new T[size];
        auto table33p = new T[size];
        auto table66p = new T[size];
        auto tableSorted = new T[size];
        auto tableReverseSorted = new T[size];
        memcpy(tableCopy, intTable, sizeof(T)*size);
        memcpy(table33p, intTable, sizeof(T)*size);
        memcpy(table66p, intTable, sizeof(T)*size);
        memcpy(tableSorted, intTable, sizeof(T)*size);
        memcpy(tableReverseSorted, intTable, sizeof(T)*size);
        std::sort(table33p, table33p + size/3);
        std::sort(table66p, table66p + (2 * size / 3));
        std::sort(tableSorted, tableSorted + size);
        std::sort(tableReverseSorted, tableReverseSorted + size, std::greater<T>());
        tableCopies[0] = tableCopy;
        tableCopies[1] = table33p;
        tableCopies[2] = table66p;
        tableCopies[3] = tableSorted;
        tableCopies[4] = tableReverseSorted;
        return tableCopies;
    }

    static void resetOutputFile() {
        std::filesystem::path currentPath = std::filesystem::current_path();
        std::string fileName = currentPath.parent_path().string() + "\\output.txt";
        std::ofstream file(fileName, std::ios::trunc);
        file.close();
    }

    static void writeSortType(std::string sortType) {
        std::filesystem::path currentPath = std::filesystem::current_path();
        std::string fileName = currentPath.parent_path().string() + "\\output.txt";
        std::ofstream file(fileName, std::ios::app);
        file << sortType << endl;
        file.close();
    }

    static void writeToFile(std::string name, double time) {
        std::filesystem::path currentPath = std::filesystem::current_path();
        std::string fileName = currentPath.parent_path().string() + "\\output.txt";
        std::ofstream file(fileName, std::ios::app);
        file << name << ";" << time << std::endl;
        file.close();
    }

    template <typename T>
    static bool isSorted(T* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
};


#endif
