#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// Модуль 1: Проверка входных данных
bool validateInput(const std::string& input) {
    if (input.length() < 1 || input.length() > 255) {
        return false;
    }
    for (char c : input) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Модуль 2: Дополнение строки до кратности 8
std::string padToMultipleOf8(const std::string& input) {
    std::string padded = input;
    int remainder = input.length() % 8;
    if (remainder != 0) {
        int padding = 8 - remainder;
        padded.append(padding, '0');
    }
    return padded;
}

// Модуль 3: Преобразование бинарных блоков в числа
std::vector<int> binaryToNumber(const std::string& padded) {
    std::vector<int> numbers;
    for (size_t i = 0; i < padded.length(); i += 8) {
        std::string block = padded.substr(i, 8);
        int number = 0;
        for (int j = 0; j < 8; j++) {
            if (block[j] == '1') {
                number += static_cast<int>(std::pow(2, 7 - j));
            }
        }
        numbers.push_back(number);
    }
    return numbers;
}

// Модуль 4: Преобразование чисел в буквы
std::string numberToLetter(const std::vector<int>& numbers) {
    std::string result;
    for (int number : numbers) {
        int remainder = number % 26;
        char letter = 'a' + remainder;
        result += letter;
    }
    return result;
}

// Модуль 5: Вывод результата
void printResult(const std::string& result) {
    std::cout << result << std::endl;
}

// Функция для сравнения векторов
bool vectorsEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

// Тесты для модулей
void runTests() {
    // Тесты для validateInput
    std::cout << "Testing validateInput:" << std::endl;
    std::cout << "Test 1: Empty string: " << (validateInput("") == false ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 2: Too long (256 chars): " << (validateInput(std::string(256, '1')) == false ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 3: Invalid chars (12a3): " << (validateInput("12a3") == false ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 4: Valid (101): " << (validateInput("101") == true ? "PASSED" : "FAILED") << std::endl;
    std::cout << std::endl;

    // Тесты для padToMultipleOf8
    std::cout << "Testing padToMultipleOf8:" << std::endl;
    std::cout << "Test 1: 10101 -> 10101000: " << (padToMultipleOf8("10101") == "10101000" ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 2: 11111111 -> 11111111: " << (padToMultipleOf8("11111111") == "11111111" ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 3: 1 -> 10000000: " << (padToMultipleOf8("1") == "10000000" ? "PASSED" : "FAILED") << std::endl;
    std::cout << std::endl;

    // Тесты для binaryToNumber
    std::cout << "Testing binaryToNumber:" << std::endl;
    std::cout << "Test 1: 00000000 -> [0]: " << (vectorsEqual(binaryToNumber("00000000"), { 0 }) ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 2: 11111111 -> [255]: " << (vectorsEqual(binaryToNumber("11111111"), { 255 }) ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 3: 1010101011110000 -> [170, 240]: " << (vectorsEqual(binaryToNumber("1010101011110000"), { 170, 240 }) ? "PASSED" : "FAILED") << std::endl;
    std::cout << std::endl;

    // Тесты для numberToLetter
    std::cout << "Testing numberToLetter:" << std::endl;
    std::cout << "Test 1: [0] -> a: " << (numberToLetter({ 0 }) == "a" ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 2: [255] -> f: " << (numberToLetter({ 255 }) == "f" ? "PASSED" : "FAILED") << std::endl;
    std::cout << "Test 3: [128, 128] -> yy: " << (numberToLetter({ 128, 128 }) == "yy" ? "PASSED" : "FAILED") << std::endl;
    std::cout << std::endl;

    // Тесты для printResult (просто проверяем, что вывод происходит)
    std::cout << "Testing printResult:" << std::endl;
    std::cout << "Test 1: Output 'abc': ";
    printResult("abc");
    std::cout << "PASSED (manual check)" << std::endl;
}

int main() {
    runTests();
    return 0;
}