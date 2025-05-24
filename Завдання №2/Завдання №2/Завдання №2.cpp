#include <iostream>
#include <cstring> // Для strcmp
#include <algorithm> // Для sort
using namespace std;

// Шаблон функції для об'єднання та сортування двох масивів
template <typename T> // шаблон функції: дозволяє працювати з будь-яким типом T.
T* mergeAndSort(T arr1[], int size1, T arr2[], int size2) {
    T* result = new T[size1 + size2]; // Виділення пам'яті для нового масиву
    //Два цикли копіюють елементи з обох масивів в новий.
    for (int i = 0; i < size1; ++i)
        result[i] = arr1[i]; // Копіюємо перший масив
    for (int i = 0; i < size2; ++i)
        result[size1 + i] = arr2[i]; // Копіюємо другий масив

    sort(result, result + size1 + size2); // Сортуємо масив

    return result;
}

// Спеціалізація для char*
template <>
/*
Оскільки const char* — це вказівники на символи (тобто C-рядки), ми не можемо їх сортувати з використанням оператора <, бо він порівнює адреси, а не значення.
*/
const char** mergeAndSort<const char*>(const char* arr1[], int size1, const char* arr2[], int size2) {
    const char** result = new const char* [size1 + size2];
    // Копіюємо вміст обох масивів рядків у новий масив result.
    for (int i = 0; i < size1; ++i)
        result[i] = arr1[i];
    for (int i = 0; i < size2; ++i)
        result[size1 + i] = arr2[i];

    // Сортування з використанням strcmp
    sort(result, result + size1 + size2, [](const char* a, const char* b) {
        return strcmp(a, b) < 0; // рядок a розташований раніше за b в алфавіті
        });

    return result;
}

int main() {

    setlocale(LC_ALL, "ukr");

    // Цілі числа
    //Створюємо два масиви цілих чисел
    int arr1[] = { 3, 1, 7 };
    int arr2[] = { 4, 2 };
    int* mergedInts = mergeAndSort(arr1, 3, arr2, 2); // Викликаємо mergeAndSort() — C++ сам обирає шаблон для типу int.
    /*
    * Виводимо відсортований об'єднаний масив.

      Звільняємо пам’ять, виділену за допомогою new[].
    */
    cout << "Об'єднаний масив цілих чисел: ";
    for (int i = 0; i < 5; ++i)
        cout << mergedInts[i] << " ";
    cout << endl;
    delete[] mergedInts; // Звільнення пам'яті

    //  Об'єднання рядків (char*)
    const char* strArr1[] = { "banana", "apple" };
    const char* strArr2[] = { "orange", "grape" };
    const char** mergedStrs = mergeAndSort(strArr1, 2, strArr2, 2);
    cout << "Об'єднаний масив рядків: ";
    for (int i = 0; i < 4; ++i)
        cout << mergedStrs[i] << " ";
    cout << endl;
    delete[] mergedStrs; // Звільнення пам'яті

    return 0;
}
