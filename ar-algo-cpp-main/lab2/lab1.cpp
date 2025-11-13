#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <locale>

using namespace std;

// функция подсчитывает количество повторений каждой строки из файла
vector<int> count_values(const vector<string>& arr) {
    unordered_map<string, int> counts; // хранит количество вхождений
    vector<int> result;
    result.reserve(arr.size());

    // подсчёт количества повторений
    for (const auto& s : arr) {
        counts[s]++;
    }

    // заполняем результат — количество повторений для каждой строки
    for (const auto& s : arr) {
        result.push_back(counts[s]);
    }

    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // список тестовых файлов
    // test1.txt — содержит несколько повторяющихся строк (проверка корректности подсчёта повторений)
    // test2.txt — все строки уникальные (проверка случая без повторов)
    // test3.txt — все строки одинаковые (проверка работы при максимальном количестве повторов)
    vector<string> filenames = { "test1.txt", "test2.txt", "test3.txt" };

    // обработка каждого файла по очереди
    for (const auto& filename : filenames) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка: не удалось открыть файл " << filename << endl;
            continue;
        }

        vector<string> arr;
        string line;

        // читаем строки из файла
        while (getline(file, line)) {
            if (!line.empty()) {
                arr.push_back(line);
            }
        }
        file.close();

        cout << "Файл: " << filename << endl;
        cout << "Прочитано строк: " << arr.size() << endl;

        // получаем результат
        vector<int> result = count_values(arr);

        cout << "Количество повторений для каждой строки:" << endl;
        for (int x : result) {
            cout << x << " ";
        }
        cout << endl << endl;
    }

    // примерный подсчёт использования памяти:
    // N - количество строк, U - количество уникальных строк
    // vector<string> примерно 100 * N байт
    // unordered_map примерно 40 * U байт
    // vector<int> примерно 4 * N байт
    // при N = 10^4 общий объём около 1–1.2 МБ — в пределах нормы

    return 0;
}
