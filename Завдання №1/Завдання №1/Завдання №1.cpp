#include <iostream>
#include <cstring> // Для функції strcmp
using namespace std;

// Шаблон функції для знаходження мінімального елемента масиву
template <typename T>
T findMin(T arr[], int size) { // повертає мінімальний елемент масиву T
    T min = arr[0]; // Припускаємо, що перший елемент — мінімальний
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min)
            min = arr[i]; // Оновлюємо мінімум, якщо знайдено менше значення
    }
    return min;
}

// Шаблон функції для знаходження максимального елемента масиву
template <typename T>
T findMax(T arr[], int size) {
    T max = arr[0]; // Припускаємо, що перший елемент — максимальний
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i]; // Оновлюємо максимум, якщо знайдено більше значення
    }
    return max;
}


/*
* Для char* (вказівників на C-рядки) не можна використовувати < або >, бо вони порівнюють адреси в пам’яті, а не самі рядки.

Тому використовуємо strcmp():

strcmp(a, b) < 0 — означає, що a менше b в алфавітному порядку.

strcmp(a, b) > 0 — a більше b.
*/

// Спеціалізація шаблону функції для масиву рядків (char*)
template <>
const char* findMin<const char*>(const char* arr[], int size) {
    const char* min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], min) < 0)
            min = arr[i]; // Порівнюємо рядки за допомогою strcmp
    }
    return min;
}

template <>
const char* findMax<const char*>(const char* arr[], int size) {
    const char* max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], max) > 0)
            max = arr[i]; // Порівнюємо рядки за допомогою strcmp
    }
    return max;
}

int main() {

    setlocale(LC_ALL, "ukr");

    // Масив цілих чисел
    int intArr[] = { 4, 1, 8, 3 };
    cout << "Мінімальне ціле число: " << findMin(intArr, 4) << endl;
    cout << "Максимальне ціле число: " << findMax(intArr, 4) << endl;

    // Масив рядків
    const char* strArr[] = { "banana", "ice", "orange" };
    cout << "Мінімальний рядок: " << findMin(strArr, 3) << endl;
    cout << "Максимальний рядок: " << findMax(strArr, 3) << endl;

    return 0;
}
