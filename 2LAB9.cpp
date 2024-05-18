#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Функція для вставки рядка S0 після кожного входження символу C у рядок S
std::string insertAfterEachOccurrence(char C, const std::string &S, const std::string &S0) {
    std::string result;
    for (char ch : S) {
        result += ch;
        if (ch == C) {
            result += S0;
        }
    }
    return result;
}

// Функція для перевірки, чи містить рядок символ C
bool containsCharacter(char C, const std::string &S) {
    return S.find(C) != std::string::npos;
}

// Основна функція для обробки файлу
void processFile(const std::string &inputFile, const std::string &outputFile, char C, const std::string &S0) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);
    std::string line;
    while (std::getline(inFile, line)) {
        if (containsCharacter(C, line)) {
            line = insertAfterEachOccurrence(C, line, S0);
        }
        outFile << line << std::endl;
    }
    inFile.close();
    outFile.close();
}

int main() {
    char C;
    std::string S0;

    // Введення додаткових даних з консолі
    std::cout << "Enter the character C: ";
    std::cin >> C;
    std::cout << "Enter the string S0: ";
    std::cin.ignore(); // Ігнорувати залишковий новий рядок від попереднього вводу
    std::getline(std::cin, S0);

    std::string inputFile = "input.txt";
    std::string outputFile = "output.txt";

    // Створення вхідного файлу з 10 різними рядками
    std::vector<std::string> lines = {
        "Hello world",
        "This is no test",
        "Python programming",
        "Mykhailo character",
        "Data processing",
        "Formula1",
        "Morty Rose",
        "Text Slime",
        "String functions",
        "End of examples"
    };

    std::ofstream outFile(inputFile);
    for (const std::string &line : lines) {
        outFile << line << std::endl;
    }
    outFile.close();

    // Обробка файлу
    processFile(inputFile, outputFile, C, S0);

    std::cout << "Processed lines have been written to " << outputFile << std::endl;

    return 0;
}
