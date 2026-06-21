#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "jurnal.h"
#include <stdlib.h>
char full_name[50][100];
int mark[50];
int students_count = 0;

void add_student()
{
	printf("Введите ФИО студента: ");
	scanf(" %[^\n]", full_name[students_count]);  
	
	printf("Введите оценку: ");
	scanf("%d", &mark[students_count]);
	if (mark[students_count] > 5)
	{
		mark[students_count] = 5;
		printf("Оценка не может быть выше 5, поставлена оценка 5\n");
	}
	if (mark[students_count] < 2)
	{
		mark[students_count] = 2;
		printf("Оценка не может быть ниже 2, поставлена оценка 2\n");
	}
	students_count = students_count + 1;
	printf("Студент добавлен!\n");
}

void show_all()
{
	if (students_count == 0)
	{
		printf("Список пуст!\n");
		return;
	}
	printf("===== Cписок студентов =====\n");
	int i;
	for (i = 0; i < students_count; i++)
	{
		
		printf("%d. %s - оценка: %d\n", i + 1, full_name[i], mark[i]);
	}

}
void save_file()
{
	
	FILE* f = fopen("jurnal.txt", "w");
	if (f == NULL)  
	{
		printf("Ошибка открытия файла!\n");
		return;
	}
	fprintf(f, "Всего студентов: %d\n", students_count);
	for (int i = 0; i < students_count; i++)
		fprintf(f, "%s - оценка: %d\n", full_name[i],mark[i]);	
	fclose(f);
	printf("Сохранено!\n");
}

void load_file()
{
	FILE* f = fopen("jurnal.txt", "r");
	if (f == NULL)
	{
		printf("Файл не найден!\n");
		return;
	}

	fscanf(f, "Всего студентов: %d\n", &students_count);

	for (int i = 0; i < students_count; i++)
	{
		
		char line[200];
		fgets(line, 200, f);

		
		int len = strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';

		
		char* pos = strstr(line, " - оценка: ");
		*pos = '\0';  
		strcpy(full_name[i], line);  
		mark[i] = atoi(pos + strlen(" - оценка: "));
	}

	fclose(f);
	printf("Загружено!\n");
}