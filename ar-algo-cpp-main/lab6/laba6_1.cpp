#include <iostream>
#include <vector>
#include <string>
#include <clocale> 
using namespace std;

/*
задача (leetcode q3. generate parentheses):
дано n пар скобок. нужно сгенерировать все корректные скобочные последовательности
пример:
n = 3 → ["((()))","(()())","(())()","()(())","()()()"]
n = 1 → ["()"]
ограничения: 1 <= n <= 8
*/

// класс solution для генерации скобочных последовательностей
class Solution {
public:
    // функция возвращает все корректные последовательности для n пар
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1); // dp[i] = все последовательности с i парами
        dp[0] = { "" }; // база: 0 пар - пустая строка

        // строим dp снизу вверх
        for (int i = 1; i <= n; ++i) {
            vector<string> current;
            for (int j = 0; j < i; ++j) {
                // берем все последовательности из dp[j] и dp[i-1-j]
                for (const string& left : dp[j]) {
                    for (const string& right : dp[i - 1 - j]) {
                        // формируем новую последовательность: '(' + left + ')' + right
                        current.push_back("(" + left + ")" + right);
                    }
                }
            }
            dp[i] = current; // сохраняем результат для i пар
        }

        return dp[n];
    }
};

int main() {
    setlocale(LC_ALL, ""); 
    Solution sol;

    vector<int> tests = { 1, 2, 3 }; // тесты
    for (int n : tests) {
        cout << "n = " << n << " | количество комбинаций: ";
        vector<string> res = sol.generateParenthesis(n);
        cout << res.size() << "\n";

        for (const auto& s : res) cout << s << "\n";

        cout << "------------------------\n"; // разделение тестов
    }

    return 0;
}

/*
почему такой подход:
- используем динамическое программирование: сохраняем все последовательности для меньших n
- чтобы построить последовательность для n, комбинируем варианты из dp[j] и dp[i-1-j]
- рекурсия здесь не нужна, все вычисляется снизу вверх
- хранение промежуточных результатов экономит время, не пересчитываем одинаковые подзадачи
*/
