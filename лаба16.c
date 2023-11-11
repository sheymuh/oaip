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
	for (int i = n - 1 ; i >= 0; i--) {
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
		printf("\n");
		printf("0: Выйти из программы\n");
		printf("Выбранная операция >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		// ЗАДАЧА 1
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

		// ЗАДАЧА 2
		case 4:
			printf("%d элементов больше чем 10", ElementsAbove10());
			break;

		// ЗАДАЧА 3
		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;

		// ЗАДАЧА 4
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

		// ЗАДАЧА 7
		case 7:
			EvensXMinus1();
			break;
		
		// ЗАДАЧА 8
		case 8:
			Replace0321On4();
			break;

		// ЗАДАЧА 10**
		case 9:
			for (int i = findFirstEven() + 1; i < findLastEven(); i++) {
				arr[i] *= 100;
			}
		}

	} while (item != 0);
}
