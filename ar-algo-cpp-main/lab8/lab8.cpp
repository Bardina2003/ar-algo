#include <iostream>
using namespace std;

class Vector {
    double* data; // динамический массив
    int size;     // размер вектора

public:
    // конструктор — создаёт вектор и заполняет нулями
    Vector(int n) {
        size = n;
        data = new double[size];
        for (int i = 0; i < size; i++)
            data[i] = 0.0;
    }

    // деструктор — освобождает память
    ~Vector() {
        delete[] data;
    }

    // ввод элементов вектора
    void input() {
        cout << "введите " << size << " элементов через пробел: ";
        for (int i = 0; i < size; i++)
            cin >> data[i];
    }

    // вывод вектора на экран
    void print() const {
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    // проверка совпадения размерности
    bool sameSize(const Vector& other) const {
        return size == other.size;
    }

    // сложение векторов
    Vector add(const Vector& other) const {
        Vector res(size);
        if (!sameSize(other)) {
            cout << "размерности не совпадают!" << endl;
            return res;
        }
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] + other.data[i];
        return res;
    }

    // вычитание векторов
    Vector sub(const Vector& other) const {
        Vector res(size);
        if (!sameSize(other)) {
            cout << "размерности не совпадают!" << endl;
            return res;
        }
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] - other.data[i];
        return res;
    }

    // поэлементное умножение векторов
    Vector mul(const Vector& other) const {
        Vector res(size);
        if (!sameSize(other)) {
            cout << "размерности не совпадают!" << endl;
            return res;
        }
        for (int i = 0; i < size; i++)
            res.data[i] = data[i] * other.data[i];
        return res;
    }

    // поэлементное деление векторов
    Vector div(const Vector& other) const {
        Vector res(size);
        if (!sameSize(other)) {
            cout << "размерности не совпадают!" << endl;
            return res;
        }
        for (int i = 0; i < size; i++) {
            if (other.data[i] != 0.0)
                res.data[i] = data[i] / other.data[i];
            else
                res.data[i] = 0.0; // деление на ноль — ставим 0
        }
        return res;
    }
};

// тестирование работы класса
int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "введите размер векторов: ";
    cin >> n;

    Vector v1(n), v2(n);

    cout << "первый вектор:\n";
    v1.input();
    cout << "второй вектор:\n";
    v2.input();

    cout << "\nрезультаты операций:\n";
    cout << "сложение:   "; v1.add(v2).print();
    cout << "вычитание:  "; v1.sub(v2).print();
    cout << "умножение:  "; v1.mul(v2).print();
    cout << "деление:    "; v1.div(v2).print();

    return 0;
}

/*
итог:
- базовая структура данных — динамический массив (double*)
- память выделяется вручную через new / delete[]
- при несовпадении размерностей выводится сообщение об ошибке
- операции выполняются поэлементно
- сложность: O(n) для всех операций
*/
