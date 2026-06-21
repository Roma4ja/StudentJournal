#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include "jurnal.h"



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int choice;
    while (1)
    {
        printf("==== Меню =====\n");
        printf("1. Добавить студента\n");
        printf("2. Показать список\n");
        printf("3. Сохранить\n");
        printf("4. Загрузить\n");
        printf("5. Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: add_student(); break;
        case 2: show_all(); break;
        case 3: save_file(); break;
        case 4: load_file(); break;
        case 5:
            printf("До свидания! Нажмите любую клавишу...\n");
            getchar();
            getchar();
            return 0;
        default:
            printf("Неверный выбор!\n");
            break;
        }
    }
}