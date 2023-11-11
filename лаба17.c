#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() { // Вывод элементов массива
	printf("< ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");
}

void keyboardInput() { // Ввод массива с клавиатуры
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values:\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() { // Все нечётные элементы увеличить в 10 раз
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}

int findMin() { // Найти минимальный элемент
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int ElementsAbove10() { // Сколько элементов больше 10
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			count++;
		}
	}
	return count;
}

int findFirstEven() { // Найти первый чётный элемент
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			return i;
		}
	}
	return -1;
}

int findLastEven() { // Найти последний чётный элемент
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] % 2 == 0) {
			return i;
		}
	}
	return -1;
}

int FindIndexMin() { // Найти индекс минимального элемента
	int min = arr[0];
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			index = i;
		}
	}
	return index;
}

void EvensXMinus1() { // Все чётные элементы массива умножить на -1
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] *= -1;
		}
	}
}

void Replace0321On4() { // Все элементы массива имеющие значения меньше 4 заменить на 4
	for (int i = 0; i < n; i++) {
		if (arr[i] < 4) {
			arr[i] = 4;
		}
	}
}

void deleteElement(int delIndex) { // Удалить выбранный элемент
	for (int i = delIndex; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}

void insertElement(int insIndex, int value) { // Вставить новый элемент в выбранное место массива
	for (int i = n; i > insIndex; i--) {
		arr[i] = arr[i - 1];
	}
	n++;
	arr[insIndex] = value;
}

void EvensEvens() { // Продублировать все чётные элементы
	for (int index = 0; index < n; index++) {
		if (arr[index] % 2 == 0) {
			insertElement(index + 1, arr[index]);
			index++;
		}
	}
}

void SaveArrayInFile() { // Сохранить в файл(out1) состояние массива
	FILE* fout = fopen("C:\\Users\\Андрей\\source\\repos\\лаба17\\out1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d\n", n);
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", arr[i]);
	}
	printf("Сохранение завершено");
	fclose(fout);
}

void UploadArrayFromFile() { // Загрузить состояние массива из файла(in1)
	FILE* fin = fopen("C:\\Users\\Андрей\\source\\repos\\лаба17\\in1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &arr[i]);
	}
	printf("Загрузка завершена");
	fclose(fin);
}

void main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int item;
	do {
		printf("\n");
		printf("------------------------------\n");
		printf("Содержимое массива:");
		printElements();
		printf("Выберите нужную вам операцию:\n");
		printf("1: Ввести с клавиатуры массив\n");
		printf("2: x10 для всех нечетных элементов\n");
		printf("3: Найти минимальный элемент\n");
		printf("4: Сколько элементов > 10\n");
		printf("5: x2 для последнего чётного элемента\n");
		printf("6: Сколько чётных левее минимального элемента\n");
		printf("7: Все чётные элементы умножить на -1\n");
		printf("8: Все элементы массива имеющие значения меньше 4 заменить на 4\n");
		printf("9: Все элементы между первым и последним чётным увеличить в 100 раз\n");
		printf("10: Удалить заданный элемент\n");
		printf("11: Вставить новый элемент в заданное место\n");
		printf("12: Удалить минимальный элемент\n");
		printf("13: Перед минимальным элементом вставить 0\n");
		printf("14: Продублировать все чётные элементы\n");
		printf("15: Сохранить в файл(out1) состояние массива\n");
		printf("16: Загрузить состояние массива из файла(in1)\n");
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		case 1:
			keyboardInput();
			break;

		case 2:
			oddsX10();
			break;

		case 3:
		{
			int min = findMin();
			printf("min = %d\n", min);
		}
		break;

		case 4:
			printf("%d элементов больше чем 10", ElementsAbove10());
			break;

		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;

		case 6:
		{
			int index = FindIndexMin();
			printf("Индекс минимального элемента = %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("Левее минимального %d чётных элементов\n", cnt);
		}
		break;

		case 7:
			EvensXMinus1();
			break;

		case 8:
			Replace0321On4();
			break;

		case 9:
			for (int i = findFirstEven() + 1; i < findLastEven(); i++) {
				arr[i] *= 100;
			}
			break;

		// ЗАДАЧА 1
		case 10:
		{
			printf("Индекс удаляемого элемента = ");
			int index;
			scanf_s("%d", &index);
			deleteElement(index);
		}
		break;

		// ЗАДАЧА 2
		case 11:
		{
			printf("Перед каким элементом нужно вставить новый? Индекс = ");
			int index;
			scanf_s("%d", &index);

			printf("Значение, которое нужно вставить = ");
			int value;
			scanf_s	("%d", &value);

			insertElement(index, value);
		}
		break;

		// ЗАДАЧА 3
		case 12:
		{
			int index = FindIndexMin();
			deleteElement(index);
			
		}
		break;

		// ЗАДАЧА 4
		case 13:
		{
			int index = FindIndexMin();
			insertElement(index, 0);
		}
		break;

		// ЗАДАЧА 6*
		case 14:
			EvensEvens();
			break;

		// лаба18 ЗАДАЧА 7
		case 15:
			SaveArrayInFile();
			break;

		// лаба18 ЗАДАЧА 8
		case 16:
			UploadArrayFromFile();
			break;
	
		}

	} while (item != 0);
}
