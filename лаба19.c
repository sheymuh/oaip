#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int a[1000]; //массив. 1000 - максимально допустимое количество элементов
int n; // Реальное количество элементов в массиве
int i;
int *pa;

void Load1() {
	// Открытие входного файла
	FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	// Выделение памяти под динамический массив
	pa = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	// Закрытие входного файла
	fclose(fin);
}

void SaveResult1() {
	// Вычисление среднего арифметического
	float sa = 0;
	int s = 0;
	for (i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	// Выяснение, сколько элементов больше ср арифметического
	int m = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] > sa) {
			m++;
		}
	}

	// Открытие выходного файла
	FILE* fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов больших ср арифметического
	fprintf(fout, "%d\n", m);
	for (i = 0; i < n; i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	// Закрытие файла
	fclose(fout);
}

void Load2() {
	// Открытие входного файла
	FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба19\\in3.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	// Выделение памяти под динамический массив
	pa = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	// Логирование ввода
	printf("Ввели:\n%d\n", n);
	for (i = 0; i < n; i++) {
		printf("%d ", pa[i]);
	}

	// Закрытие входного файла
	fclose(fin);
}

void SaveResult2() {
	// Вычисление среднего арифметического
	float sa = 0;
	int s = 0;
	for (i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	// Выяснение, сколько элементов больше 0, но меньше среднего арифметического
	int m = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			m++;
		}
	}

	// Открытие выходного файла
	FILE* fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба19\\out3.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов больших 0, но меньших ср арифметического
	fprintf(fout, "%d\n", m);
	printf("\nВывели:\n%d\n", m);
	for (i = 0; i < n; i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			fprintf(fout, "%d ", pa[i]);
			printf("%d ", pa[i]);
		}
	}

	// Закрытие файла
	fclose(fout);
}

void Load3() {
	// Открытие входного файла
	FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба19\\in4.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден\n");
		return;
	}

	// Загрузка массива из входного файла
	fscanf(fin, "%d", &n);
	// Выделение памяти под динамический массив
	pa = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	// Логирование ввода
	printf("Ввели:\n%d\n", n);
	for (i = 0; i < n; i++) {
		printf("%d ", pa[i]);
	}

	// Закрытие входного файла
	fclose(fin);
}

void SaveResult3() {
	// Максимальный элемент
	int maxx = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] > maxx) {
			maxx = pa[i];
		}
	}

	// Высокий доход
	int high_income = maxx * 2 / 3;
	printf("\n2/3 от максимального дохода = %d", high_income);

	// Выяснение, сколько элементов не меньше, чем 2/3 от максимального дохода
	int m = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] >= high_income) {
			m++;
		}
	}

	// Открытие выходного файла
	FILE* fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба19\\out4.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не найден\n");
		return;
	}

	// Сохранение элементов не меньших, чем 2/3 от максимального дохода
	fprintf(fout, "%d\n", m);
	printf("\nВывели:\n%d\n", m);
	for (i = 0; i < n; i++) {
		if (pa[i] >= high_income) {
			fprintf(fout, "%d ", pa[i]);
			printf("%d ", pa[i]);
		}
	}

	// Закрытие файла
	fclose(fout);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ЗАДАЧА 1
	//printf("Hello! It is Task1!\n");
	//Load1();
	//SaveResult1();

	// ЗАДАЧА 2
	//printf("Hello! It is Task2!\n");
	//Load1();
	//SaveResult1();

	//free(pa);

	// ЗАДАЧА 3
	//printf("Hello! It is Task3!\n");
	//Load2();
	//SaveResult2();

	// ЗАДАЧА 4
	printf("Hello! It is Task4!\n");
	Load3();
	SaveResult3();
}