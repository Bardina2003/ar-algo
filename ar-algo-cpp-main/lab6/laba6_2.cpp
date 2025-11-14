#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <clocale>
using namespace std;

/*
задача 139. Перенос слова
почему здесь используется ДП:
- нам нужно понять, можно ли строку собрать из слов словаря
- если пробовать перебирать все разбиения строки — вариантов слишком много (их становится очень много при длинной строке)
- у строки постоянно повторяются одинаковые куски, например, слово "apple" может встречаться несколько раз
- поэтому мы делаем массив dp:
  dp[i] = можно ли корректно разбить строку до позиции i
- таким образом мы не пересчитываем одно и то же, а просто запоминаем и программа работает намного быстрее
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // превращаем словарь в множество (быстрее проверка)
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // создаём массив dp, в котором сначала все false
        vector<bool> dp(s.size() + 1, false);

        // dp[0] = true, потому что пустую строку разбить можно
        dp[0] = true;

        // перебираем все позиции строки
        for (int i = 1; i <= s.size(); i++) {

            // пробуем все возможные предыдущие позиции
            for (int j = 0; j < i; j++) {

                // если строка до j разбивается нормально
                if (dp[j]) {

                    // берём слово от j до i
                    string word = s.substr(j, i - j);

                    // если это слово есть в словаре — то и i тоже подходит
                    if (dict.count(word)) {
                        dp[i] = true;
                        break; // дальше проверять не надо
                    }
                }
            }
        }

        // результат: можно ли разбить всю строку
        return dp[s.size()];
    }
};

// тесты
void runTests() {
    Solution sol;

    string s1 = "leetcode";
    vector<string> d1 = { "leet", "code" };
    cout << "тест 1: " << sol.wordBreak(s1, d1) << " (должно быть 1)\n";

    string s2 = "applepenapple";
    vector<string> d2 = { "apple", "pen" };
    cout << "тест 2: " << sol.wordBreak(s2, d2) << " (должно быть 1)\n";

    string s3 = "catsandog";
    vector<string> d3 = { "cats", "dog", "sand", "and", "cat" };
    cout << "тест 3: " << sol.wordBreak(s3, d3) << " (должно быть 0)\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    runTests();
    return 0;
}
