// 1221. разбиение строки на сбалансированные строки
// задача: разбить строку на максимальное количество подстрок, где L = R

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        // жадная идея: считаем баланс между L и R
        // как только баланс стал 0 — это готовая сбалансированная подстрока
        int balance = 0;
        int count = 0;

        for (char c : s) {
            if (c == 'R') balance++;
            else balance--;

            // если баланс 0 — нашли одну подстроку
            if (balance == 0) count++;
        }
        return count;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Solution sol;

    cout << sol.balancedStringSplit("RLRRLLRLRL") << endl;
    cout << sol.balancedStringSplit("RLRRRLLRLL") << endl;
    cout << sol.balancedStringSplit("LLLLRRRR") << endl;

    return 0;
}
