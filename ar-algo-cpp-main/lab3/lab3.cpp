#include <iostream>
#include <string>
#include <locale>
using namespace std;

// функция проверяет корректность скобочной последовательности
// возвращает:
//   true  — если есть ошибка (неправильный порядок или незакрытые скобки) 
//   false — если последовательность корректна
// сложность: O(N) по времени, O(1) по памяти
bool checkBrackets(const string& s) {
    int balance = 0;

    for (char c : s) {
        if (c == '(') {
            balance++;
        }
        else if (c == ')') {
            balance--;
            if (balance < 0) {
                // лишняя закрывающая скобка
                return true;
            }
        }
    }

    // если остались незакрытые скобки — ошибка - возвращаем true
    return balance != 0;
}

// тесты для проверки корректности работы функции
void tests() {
    {
        string s = "a(b)(((a)b)"; // лишняя открывающая скобка
        cout << "Тест 1 (лишняя открывающая): "
            << (checkBrackets(s) ? "TRUE" : "FALSE") << endl;
    }
    {
        string s = "(a(b)c)"; // правильная последовательность
        cout << "Тест 2 (правильная последовательность): "
            << (checkBrackets(s) ? "TRUE" : "FALSE") << endl;
    }
    {
        string s = "))(("; // неверный порядок
        cout << "Тест 3 (неправильный порядок): "
            << (checkBrackets(s) ? "TRUE" : "FALSE") << endl;
    }
    {
        string s = ""; // пустая строка — корректная
        cout << "Тест 4 (пустая строка): "
            << (checkBrackets(s) ? "TRUE" : "FALSE") << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // поддержка русского языка в консоли

    string str = "a(b)(((a)b)"; // пример из задания

    cout << "Исходная строка: " << str << endl;

    bool result = checkBrackets(str);

    cout << "Результат проверки: ";
    cout << (result ? "TRUE" : "FALSE") << endl;

    cout << endl << "Проверка на тестах:" << endl;
    tests();

    return 0;
}

/*
Сложность:
- O(N) — один проход по строке
Память:
- O(1) — используется только счётчик balance (4 байта) и несколько служебных переменных
Максимальный объём памяти при N = 1e4 символов примерно 10 кб
*/
