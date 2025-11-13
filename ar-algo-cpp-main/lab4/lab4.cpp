#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>
#include <clocale>
using namespace std;
using namespace std::chrono;

vector<int> arr;                // сам массив
vector<vector<int>> result;     // сюда складываем найденные комбинации
int K;                          // сколько индексов нужно выбрать

// рекурсивный перебор всех комбинаций
void generate(int start, vector<int>& current) {

    // если уже набрали K элементов - проверяем сумму
    if (current.size() == K) {
        int sum = 0;

        // считаем сумму выбранных элементов
        for (int idx : current)
            sum += arr[idx];

        // если сумма 0 — добавляем в ответы
        if (sum == 0)
            result.push_back(current);

        return;
    }

    // перебираем дальше все возможные индексы
    for (int i = start; i < arr.size(); i++) {

        // берём этот индекс
        current.push_back(i);

        // идём глубже (следующий индекс должен быть больше текущего)
        generate(i + 1, current);

        // убираем индекс, чтобы попробовать следующий вариант
        current.pop_back();
    }
}

// функция запускает рекурсивный перебор
vector<vector<int>> findZeroSumComb(const vector<int>& input, int k) {
    arr = input;   // сохраняем массив
    K = k;         // сохраняем размер подмассива
    result.clear();

    vector<int> cur;  // временный вектор для сборки комбинации
    generate(0, cur);

    return result;
}

// делаем случайный массив
vector<int> randomArray(int n) {
    vector<int> a(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> d(-10, 10);

    // заполняем случайными числами
    for (int i = 0; i < n; i++)
        a[i] = d(gen);

    return a;
}

// маленькие тесты, чтобы убедиться, что алгоритм работает
void runSmallTests() {
    cout << "\nТесты для маленьких массивов:\n";

    // тест 1: проверка уникальных индексов
    vector<int> t1 = { 1, -1, -1 };
    auto r1 = findZeroSumComb(t1, 2);
    cout << "Массив: [1, -1, -1], K=2 -> найденные индексы:\n";
    for (auto& v : r1) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    // тест 2: массив из нулей, должны найти все комбинации
    vector<int> t2 = { 0, 0, 0, 0 };
    auto r2 = findZeroSumComb(t2, 3);
    cout << "\nМассив: [0 0 0 0], K=3 -> должны быть все C(4,3)=4 комбинации:\n";
    for (auto& v : r2) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    const int K = 7;  // по условию
    vector<int> sizes = { 10,12,14,16,18,20,22,24,25 };

    cout << "Перебор всех комбинаций размера K=" << K << "\n\n";

    cout << "N     | Время (мс)\n";

    // запускаем тесты на разных размерах массива
    for (int N : sizes) {

        vector<int> a = randomArray(N);

        auto start = high_resolution_clock::now();

        // перебираем все комбинации
        findZeroSumComb(a, K);

        auto end = high_resolution_clock::now();

        // считаем время
        double time_ms = duration<double>(end - start).count() * 1000;

        // выводим таблицу
        cout << setw(5) << N << " | " << fixed << setprecision(3) << time_ms << "\n";
    }

    runSmallTests();

    return 0;
}
