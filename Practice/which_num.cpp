//  Сортировка массива.


//Сгенерировать неупорядоченный массив целых чисел от 1 до N.


// Определить недостающее число в неупорядоченной последовательности целых чисел.
// Описание.
// Написать функцию, принимающую в качестве параметра массив неупорядоченных целых 
// чисел(сгенерированный с помощью функции из задачи 2) и определяющую значение последнего 
// элемента в массиве без доступа к нему.


#include <iostream>
#include <ctime>
#include <algorithm>
void GenerateRandomArray(int * _result, unsigned int _maxValue);
void Sort(int * arr, int size);
int BackNum(int * arr, int size);
int main()
{
    std::srand(time(0));
    int MAX = rand() % 4 + 5;
    int * result = new int[MAX];
    GenerateRandomArray(result, MAX);
    for (int i = 0; i < MAX; i++)
    {
        std::cout << result[i] << ' ';
    }
    std::cout << std::endl;
    // Sort(result, MAX);
    std::cout << BackNum(result, MAX);
    std::cout << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        std::cout << result[i] << ' ';
    }
    delete [] result;
    return 0;
}

void GenerateRandomArray(int * _result, unsigned int _maxValue)
{
    for (int i = 0; i < _maxValue; i++)
    {
        _result[i] = i + 1;
    }
    std::random_shuffle(_result, _result + _maxValue);
}

void Sort(int * arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}

int BackNum(int * arr, int size)
{
    int count1 = 0, count2 = 0;
    for (int i = 0; i < size; i++)
    {
        count1 += arr[i];
    }
    for (int i = 0; i < size - 1; i++)
    {
        count2 += arr[i];
    }
    int result = count1 - count2;
    return result;
}