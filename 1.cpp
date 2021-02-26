#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

void input1(int* m, int& n)
{
    cout << "Введите количество значений в массиве: " << endl;
    cin >> n;
    while (n < 1 || n > 20)
    {
        cout << "Введите количество значений в массиве: " << endl;
        cin >> n;
        if (n < 1 || n > 20) cout << "Количество значений не может быть меньше 1 и больше 20" << endl;
    }
    for (int i = 0; i < n; i++) cin >> m[i]; //вводим массив вручную
}
void inputf(int* m, int& n)
{
    string s;
    cout << "Введите название файла для считывания: "; cin >> s;
    ifstream f(s);
    if (!f.is_open()) { cout << "Файл не может быть открыт" << endl; exit(1); }

    n = 0;
    while (!f.eof())
    {
        f >> m[n]; ++n;
    }
    f.close();
}
void output(int const* m, int n)
{
    for (int i = 0; i < n; i++) cout << m[i] << " "; //вывод
}
void outputf(int const* m, int l)
{
    string s;
    cout << "Введите название файла для записи: "; cin >> s;
    ofstream f(s);
    if (!f.is_open()) { cout << "Файл не может быть открыт" << endl; exit(1); }
    if (l == 0) f << "Таких эелементов не существует." << endl; else
        for (int i = 0; i < l; i++) f << m[i] << " ";
    f.close();
    cout << "Массив находится в файле " << s << endl;
}
void rand(int* m, int& n)
{
    int c, b, k;
    cout << "Введите количество значений в массиве: " << endl;
    cin >> n;
    while ((n < 1) || (n > 20))
    {
        cout << "Введите количество значений в массиве^ " << endl;
        cin >> n;
        if ((n < 1) || (n > 20)) cout << "Количество значений не может быть меньше 1 и больше 20" << endl;
    }
    cout << "Введите границы значений массива " << endl;
    cin >> c >> b;
    if (c > b) { k = c; c = b; b = k; }
    srand(time(NULL));
    for (int i = 0; i < n; i++) m[i] = rand() % (b - c + 1) + c;
}
void odinak(int* m1, int n1, int* m2, int n2)
{
    int m[40], k, l = 0;
    for (int i = 0; i < n1; i++)
    {
        k = 0;
        for (int j = 0; j < n2; j++)
            if (m1[i] == m2[j])
            {
                k++; break;
            }
        if (k != 0) { m[l] = m1[i]; l++; }
    }
    for (int j = 0; j < n2; j++)
    {
        k = 0;
        for (int i = 0; i < n1; i++)
            if (m1[i] == m2[j])
            {
                k++; break;
            }
        if (k == 0) { m[l] = m2[j]; l++; }
    }

    for (int i = 0; i < l - 1; ++i)
    {
        for (int j = 0; j < l - 1; ++j)
        {
            if (m[j + 1] < m[j])
            {
                k = m[j + 1];
                m[j + 1] = m[j];
                m[j] = k;
            }
        }
    }
    k = 0;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (m[i] == m[j])
            {
                k = i;
                for (int i = k; i < l; i++)
                {
                    m[i] = m[i + 1];
                }
                l--; j--;
            }
        }
    }

    cout << "Куда вывести результат?\n1) На экран\n2) В файл" << endl; cin >> k;
    if (k == 1) {
        if (l == 0) cout << "Одинаковых элементов не существует." << endl; else
        {
            cout << "Одинаковые элементы массивов: ";   for (int i = 0; i < l; i++) cout << m[i] << " ";
        }
    }
    else if (k == 2) outputf(m, l);
}
void mass1(int* m1, int n1, int* m2, int n2)
{
    int m[20], k, l = 0;
    for (int i = 0; i < n1; i++)
    {
        k = 0;
        for (int j = 0; j < n2; j++)
            if (m1[i] == m2[j])
            {
                k++; break;
            }
        if (k == 0) { m[l] = m1[i]; l++; }
    }
    for (int i = 0; i < l - 1; ++i)
    {
        for (int j = 0; j < l - 1; ++j)
        {
            if (m[j + 1] < m[j])
            {
                k = m[j + 1];
                m[j + 1] = m[j];
                m[j] = k;
            }
        }
    }
    k = 0;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (m[i] == m[j])
            {
                k = i;
                for (int i = k; i < l; i++)
                {
                    m[i] = m[i + 1];
                }
                l--; j--;
            }
        }
    }

    cout << "Куда вывести результат?\n1) На экран\n2) В файл" << endl; cin >> k;
    if (k == 1) {
        if (l == 0) cout << "Одинаковых элементов не существует." << endl; else
        {
            cout << "Элементы только из 1 массива: ";   for (int i = 0; i < l; i++) cout << m[i] << " ";
        }
    }
    else if (k == 2) outputf(m, l);
}
void mass2(int* m1, int n1, int* m2, int n2)
{
    int m[20], k, l = 0;
    for (int j = 0; j < n2; j++)
    {
        k = 0;
        for (int i = 0; i < n1; i++)
            if (m1[i] == m2[j])
            {
                k++; break;
            }
        if (k == 0) { m[l] = m2[j]; l++; }
    }
    for (int i = 0; i < l - 1; ++i)
    {
        for (int j = 0; j < l - 1; ++j)
        {
            if (m[j + 1] < m[j])
            {
                k = m[j + 1];
                m[j + 1] = m[j];
                m[j] = k;
            }
        }
    }
    k = 0;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (m[i] == m[j])
            {
                k = i;
                for (int i = k; i < l; i++) 
                {
                    m[i] = m[i + 1];
                }
                l--; j--;
            }
        }
    }
    cout << "Куда вывести результат?\n1) На экран\n2) В файл" << endl; cin >> k;
    if (k == 1) {
        if (l == 0) cout << "Одинаковых элементов не существует." << endl; else
        {
            cout << "Эелемент только из 2 массива: ";   for (int i = 0; i < l; i++) cout << m[i] << " ";
        }
    }
    else if (k == 2) outputf(m, l);
}

int main()
{
    setlocale(0, "");
    int l1, l2, m1[20], m2[20], n1, n2;
    do {
        cout << "Ввод 1-го массива\3 \n1) Перечислить элементы самостоятельно. \n2) Задать эелементы случайно.\n3) Массив из файла \n0 - выхода" << endl;
        cin >> l1;
        switch (l1)
        {
        case 1: input1(m1, n1); break;
        case 2: rand(m1, n1); break;
        case 3: inputf(m1, n1); break;
        case 0: cout << "Exit..." << endl; break;
        default: cout << "Некорректное значение." << endl; break;
        }
        cout << "Ввод 2-го массива\3 \n1) Перечислить элементы самостоятельно. \n2) Задать эелементы случайно.\n3) Массив из файла \n0 - выход" << endl;
        cin >> l2;
        switch (l2)
        {
        case 1: input1(m2, n2); break;
        case 2: rand(m2, n2); break;
        case 3: inputf(m2, n2); break;
        case 0: cout << "Exit..." << endl; break;
        default: cout << "Некорректное значение." << endl; break;
        }
        cout << "Ваш 1-ый массив: " << endl; output(m1, n1); cout << endl;
        cout << "Ваш 2-ой массив: " << endl; output(m2, n2); cout << endl;

        cout << " Выберите действие \n1) Одинаковые элементы массивов \n2) Элементы только из 1 массива \n3) Эелемент только из 2 массива" << endl;
        cin >> l2;
        switch (l2)
        {
        case 1: odinak(m1, n1, m2, n2); cout << endl; break;
        case 2: mass1(m1, n1, m2, n2); cout << endl; break;
        case 3: mass2(m1, n1, m2, n2); cout << endl; break;
        default: cout << "Некорректное значение." << endl; break;
        }
    } while (l1 != 0);

    cin.get();
    return 0;
}
