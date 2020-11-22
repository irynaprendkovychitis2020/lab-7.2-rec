// lab 7.2 rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);

    j++;
    if (j == colCount) {
        i++;
        j = 0;
    }

    if (i < rowCount)
        CreateRows(a, rowCount, colCount, Low, High, i, j);
}
void PrintRows(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];

    j++;
    if (j == colCount) {
        i++;
        j = 0;
        cout << endl;
    }

    if (i == rowCount)
        return;
    PrintRows(a, rowCount, colCount, i, j);
}

int SearchMin(int** a, const int icol, int i)
{
    if (i > 1) {
        int min = SearchMin(a, icol, i - 1);
        if (a[min][icol] > a[i - 1][icol])
            min = i - 1;
        return min;
    }
    return 0;
}

int SearchMax(int** a, const int icol, int i)
{
    if (i > 1) {
        int min = SearchMax(a, icol, i - 1);
        if (a[min][icol] < a[i - 1][icol])
            min = i - 1;
        return min;
    }
    return 0;
}

void Inverse(int** a, const int rowCount, int colCount_i) {
    if (colCount_i % 2 == 0)
        --colCount_i;
    else colCount_i -= 2;

    int min = SearchMin(a, colCount_i, rowCount),
        max = SearchMax(a, colCount_i, rowCount);

    swap(a[min][colCount_i], a[max][colCount_i]);

    if (colCount_i > 1)
        Inverse(a, rowCount, colCount_i);
}

int main()
{
    srand((unsigned)time(NULL));
    int rowCount;
    int colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];
    int Low = 7, High = 65;
    CreateRows(a, rowCount, colCount, Low, High, 0, 0);
    PrintRows(a, rowCount, colCount, 0, 0);
    Inverse(a, rowCount, colCount);
    cout << endl;
    PrintRows(a, rowCount, colCount, 0, 0);
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
