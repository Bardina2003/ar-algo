// 1903. наибольшее нечётное число в строке
// задача: вернуть самую большую нечётную подстроку строки num

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // жадный подход: идём с конца и ищем первую нечётную цифру
        // если нашли — вся подстрока до неё уже максимальная возможная
        for (int i = num.size() - 1; i >= 0; i--) {
            // переводим символ в число и проверяем нечётность
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        // если нечётных нет — вернём пустую строку
        return "";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Solution sol;

    cout << sol.largestOddNumber("35420") << endl;
    cout << sol.largestOddNumber("4206") << endl;
    cout << sol.largestOddNumber("13579") << endl;

    return 0;
}
