// 2864. максимальное нечётное двоичное число
// задача: переставить биты так, чтобы число стало максимальным, но оставалось нечётным

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // считаем количество единиц
        int ones = 0;
        for (char c : s) if (c == '1') ones++;

        // нулей просто будет длина - количество единиц
        int zeros = s.size() - ones;

        // жадная идея:
        // - чтобы число было нечётным — последняя позиция должна быть '1'
        // - все оставшиеся единицы лучше поставить в начало (так число больше)
        // - между ними идут все нули
        return string(ones - 1, '1') + string(zeros, '0') + "1";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Solution sol;

    cout << sol.maximumOddBinaryNumber("010") << endl;
    cout << sol.maximumOddBinaryNumber("0101") << endl;
    cout << sol.maximumOddBinaryNumber("1110") << endl;
    cout << sol.maximumOddBinaryNumber("100") << endl;

    return 0;
}
