#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Ответы на вопросы:
// int, float, double, char
// Формат данных — способ представления значения; используется в printf/scanf через спецификаторы (%d, %f, %s)
// % — остаток от деления
// Прототип функции — объявление её имени, типа возвращаемого значения и параметров до определения
// Входные параметры — значения, передаваемые функции при вызове
// Тип функции — указывает тип возвращаемого значения
// Результат логической операции — 0  или 1

// Задачи на ввод и вывод данных:
// Задание 1
void task1InputOutput()
{
    int x;
    scanf("%d", &x);
    printf("%d\n", x);
}

// Задание 2
void task2InputOutput()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d %d %d %d\n", a + b, a - b, a * b, a / b);
}

// Задание 3
void task3InputOutput()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%f\n", (a + b + c) / 3.0);
}

// Задание 4
void task4InputOutput()
{
    char name[100];
    scanf("%s", name);
    printf("Привет, %s!\n", name);
}

// Задание 5
void task5InputOutput()
{
    int year;
    scanf("%d", &year);
    printf("%d\n", 2025 - year);
}

// Задачи на условные операторы:
// Задание 6.7
void task6_7()
{
    int x;
    scanf("%d", &x);
    printf("%s\n", x % 2 == 0 ? "Четное" : "Нечетное");
}

// Задание 6.8
void task6_8()
{
    int x;
    scanf("%d", &x);
    printf("%s\n", x >= 0 ? "Положительное" : "Отрицательное");
}

// Задание 6.9
void task6_9()
{
    int x;
    scanf("%d", &x);
    printf("%s\n", x % 3 == 0 ? "Кратно 3" : "Не кратно 3");
}

// Задание 6.10
void task6_10()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a > b ? a : b);
}

// Задание 6.11
void task6_11()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%s\n", a == b ? "Равны" : "Не равны");
}

// Задачи на циклы:
// Задание 1
void task1Cycles()
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

// Задание 2
void task2Cycles()
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", 5 * i);
    }
    printf("\n");
}

// Задание 3
void task3Cycles()
{
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
    }
    printf("%d\n", sum);
}

// Задание 4
void task4Cycles()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Задание 5
void task5Cycles()
{
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Задачи на массивы:
// Задание 1
void task1Arrays()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Задание 2
void task2Arrays()
{
    int arr[10];
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Задание 3
void task3Arrays()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Задание 4
void task4Arrays()
{
    int arr[10];
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        sum += arr[i];
    }
    printf("%d\n", sum);
}

// Задание 5
void task5Arrays()
{
    int a[10], b[10], c[10];
    for (int i = 0; i < 10; i++)
    {
        a[i] = i;
        b[i] = i * 2;
        c[i] = a[i] + b[i];
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
}

// Задачи на функции:
// Задание 1
long factorial(int n)
{
    long res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
void task1Functions()
{
    int x;
    scanf("%d", &x);
    printf("%ld\n", factorial(x));
}

// Задание 2
int is_prime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}
void task2Functions()
{
    int x;
    scanf("%d", &x);
    printf("%s\n", is_prime(x) ? "Простое" : "Составное");
}

// Задание 3
void task3Functions()
{
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Задание 4
void task4Functions()
{
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
}

// Задание 5
int sum_divisors(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
void task5Functions()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (sum_divisors(a) == b && sum_divisors(b) == a)
    {
        printf("Дружественные\n");
    }
    else
    {
        printf("Не дружественные\n");
    }
}

int main()
{
    printf("Задачи на ввод и вывод данных:\n");
    printf("Задание 1\n");
    task1InputOutput();
    printf("\n");

    printf("Задание 2\n");
    task2InputOutput();
    printf("\n");

    printf("Задание 3\n");
    task3InputOutput();
    printf("\n");

    printf("Задание 4\n");
    task4InputOutput();
    printf("\n");

    printf("Задание 5\n");
    task5InputOutput();
    printf("\n");

    printf("Задачи на условные операторы:\n");
    printf("Задание 6.7\n");
    task6_7();
    printf("\n");

    printf("Задание 6.8\n");
    task6_8();
    printf("\n");

    printf("Задание 6.9\n");
    task6_9();
    printf("\n");

    printf("Задание 6.10\n");
    task6_10();
    printf("\n");

    printf("Задание 6.11\n");
    task6_11();
    printf("\n");

    printf("Задачи на циклы:\n");
    printf("Задание 1\n");
    task1Cycles();
    printf("\n");

    printf("Задание 2\n");
    task2Cycles();
    printf("\n");

    printf("Задание 3\n");
    task3Cycles();
    printf("\n");

    printf("Задание 4\n");
    task4Cycles();
    printf("\n");

    printf("Задание 5\n");
    task5Cycles();
    printf("\n");

    printf("Задачи на массивы:\n");
    printf("Задание 1\n");
    task1Arrays();
    printf("\n");

    printf("Задание 2\n");
    task2Arrays();
    printf("\n");

    printf("Задание 3\n");
    task3Arrays();
    printf("\n");

    printf("Задание 4\n");
    task4Arrays();
    printf("\n");

    printf("Задание 5\n");
    task5Arrays();
    printf("\n");

    printf("Задачи на функции:\n");
    printf("Задание 1\n");
    task1Functions();
    printf("\n");

    printf("Задание 2\n");
    task2Functions();
    printf("\n");

    printf("Задание 3\n");
    task3Functions();
    printf("\n");

    printf("Задание 4\n");
    task4Functions();
    printf("\n");

    printf("Задание 5\n");
    task5Functions();
    printf("\n");

    return 0;
}
