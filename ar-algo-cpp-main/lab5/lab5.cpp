#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm> 
#include <ctime>
using namespace std;

// пузырьковая сортировка
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
}

// сортировка вставками
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < (int)arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// сортировка выбором
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[i], arr[min_idx]);
    }
}

// тесты:

// лучший случай
void testBestCase() {
    vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> expected = arr;
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr == expected);
}

// средний случай
void testAverageCase() {
    vector<int> arr = { 5,3,8,4,2,7,1,6 };
    vector<int> expected = { 1,2,3,4,5,6,7,8 };
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr == expected);
}

// худший случай
void testWorstCase() {
    vector<int> arr = { 10,9,8,7,6,5,4,3,2,1 };
    vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr == expected);
}

// пустой массив
void testEmptyArray() {
    vector<int> arr = {};
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr.empty());
}

// один элемент
void testSingleElement() {
    vector<int> arr = { 42 };
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr[0] == 42);
}

// все элементы одинаковые
void testAllElementsSame() {
    vector<int> arr = { 5,5,5,5,5 };
    vector<int> expected = arr;
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr == expected);
}

// отрицательные числа
void testNegativeNumbers() {
    vector<int> arr = { -3,-1,-7,-4,-5,-2 };
    vector<int> expected = { -7,-5,-4,-3,-2,-1 };
    bubbleSort(arr);
    insertionSort(arr);
    selectionSort(arr);
    assert(arr == expected);
}

// замер времени 
void measureTime() {
    for (int size = 1000; size <= 10000; size += 1000) {
        vector<int> arr(size);
        for (int i = 0; i < size; i++) arr[i] = rand() % 10000;

        vector<int> arr1 = arr;
        clock_t start1 = clock();
        bubbleSort(arr1);
        clock_t end1 = clock();

        vector<int> arr2 = arr;
        clock_t start2 = clock();
        insertionSort(arr2);
        clock_t end2 = clock();

        vector<int> arr3 = arr;
        clock_t start3 = clock();
        selectionSort(arr3);
        clock_t end3 = clock();

        double duration1 = double(end1 - start1) / CLOCKS_PER_SEC;
        double duration2 = double(end2 - start2) / CLOCKS_PER_SEC;
        double duration3 = double(end3 - start3) / CLOCKS_PER_SEC;

        cout << "размер " << size
            << " пузырьком: " << duration1
            << " вставками: " << duration2
            << " выбором: " << duration3 << " сек" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    testBestCase();
    testAverageCase();
    testWorstCase();
    testEmptyArray();
    testSingleElement();
    testAllElementsSame();
    testNegativeNumbers();

    cout << "все тесты успешно пройдены\n\n";

    cout << "замер времени сортировок:\n";
    measureTime();

    return 0;
}
