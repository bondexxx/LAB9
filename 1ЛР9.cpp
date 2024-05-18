#include <iostream>
#include <cstring> // Додано для використання функції strlen

size_t my_rfind(const char* str, const char* search, size_t pos = SIZE_MAX) {
    // Якщо pos більше довжини str, просто повертаємо npos
    size_t str_length = strlen(str);
    if (pos >= str_length)
        return SIZE_MAX;

    // Якщо pos дорівнює SIZE_MAX, змінюємо його на останній індекс str
    if (pos == SIZE_MAX)
        pos = str_length - 1;

    // Довжина підрядка для пошуку
    size_t search_length = strlen(search);

    // Починаємо пошук з останнього символу в str
    for (size_t i = pos; i != SIZE_MAX; --i) {
        bool found = true;
        // Перевіряємо, чи можливо знайти search з поточної позиції в str
        for (size_t j = 0; j < search_length; ++j) {
            if (i - j < 0 || str[i - j] != search[search_length - j - 1]) {
                found = false;
                break;
            }
        }
        if (found) {
            // Якщо search знайдено, повертаємо позицію першого символу входження
            return i - search_length + 1;
        }
    }
    // Якщо search не знайдено, повертаємо SIZE_MAX
    return SIZE_MAX;
}

int main() {
    // Введення рядка
    std::cout << "Enter a string: ";
    std::string str;
    std::getline(std::cin, str);

    // Введення рядка для пошуку
    std::cout << "Enter a substring to search for: ";
    std::string search;
    std::getline(std::cin, search);

    // Виклик власної функції
    size_t pos = my_rfind(str.c_str(), search.c_str(), str.size() - 1);

    // Виведення результату
    if (pos != SIZE_MAX) {
        std::cout << "Substring found at position: " << pos << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}
