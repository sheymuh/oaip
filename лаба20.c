#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define MAX_N 8
#define MAX_M 10

int arr[MAX_N][MAX_M] = {
	{0, 1, 222, 3},
	{10, 11, 12, 13},
	{20, 21, 22, 23}
};
int	n = 3;
int m = 4;

void print() {
	printf("!!!! print() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fillIx10() {
	printf("!!!! fillIx10() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = i * 10 + j;
		}
	}
}

void fillZero() {
	printf("!!!! fillZero() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}
}

void randFill0_9() {
	printf("!!!! randFill0_9() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}

void evensX10() {
	printf("!!!! EvensX10 !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 0) {
				arr[i][j] *= 10;
			}
		}
	}
}

void multiples10divide10() {
	printf("!!!! multiples10divide10() !!!!\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 10 == 0) {
				arr[i][j] /= 10;
			}
		}
	}
}

void arrKeyboard() {
	printf("!!!! arrKeyboard() !!!!\n");
	printf("Введите n (1-8) ");
	scanf_s("%d", &n);
	printf("Введите m (1-10) ");
	scanf_s("%d", &m);
	printf("Введите элементы массива:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("arr[%d][%d] = ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}
}

// Сохранение состояния
void save() {
	// Выходной файл
	FILE* fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба20\\arr1.txt", "wt");
	if (fout == NULL) {
		printf("Выходной файл не создался");
		return;
	}

	fprintf(fout, "%d ", n);
	fprintf(fout, "%d\n", m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fprintf(fout, "%d ", arr[i][j]);
		}
		fprintf(fout, "\n");
	}

	fclose(fout);
}

// Загрузка состояния
void load() {

	FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба20\\arr1.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не найден");
		return;
	}

	fscanf(fin, "%d", &n);
	fscanf(fin, "%d", &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fscanf(fin, "%d", &arr[i][j]);
		}
	}

	fclose(fin);
}

void deleteRow(int delRow) {
	printf("!!!! deleteRow(%d) !!!!\n", delRow);
	for (int i = delRow; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i + 1][j];
		}
	}
	n--;
}

void doubleColumn(int doubCol) {
	printf("!!!! doubleColumn(%d) !!!!\n", doubCol);
	for (int i = 0; i < n; i++) {
		for (int j = m; j > doubCol; j--) {
			arr[i][j] = arr[i][j - 1];
		}
	}
	m++;
}

void doubleRow(int doubRow) {
	printf("!!!! doubleColumn(%d) !!!!\n", doubRow);
	for (int i = n; i > doubRow; i--) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = arr[i-1][j];
		}
	}
	n++;
}

void A9() { // Обнулить элементы тех строк, в которых встречается более двух нулевых элементов
	printf("!!!! A9() !!!!\n");
	int count;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				count++;
			}
		}
		if (count > 2) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
	}
}

void B3() { // Удалить те строки, в которых встречаются нулевые элементы
	int count;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				count++;
			}
		}
		if (count > 0) {
			deleteRow(i);
			i = 0;
		}
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int num;
	int item;
	do {
		print();
		// ЗАДАЧА 1
		printf("=============================\n");
		printf("Выберите нужную вам операцию:\n");
		printf("1: Заполнить значениями i * 10 + j\n");
		printf("2: Заполнить нулями\n");
		printf("3: Заполнить случайными значениями\n");
		printf("4: Все нечетные увеличить в 10 раз\n");
		printf("5: Все кратные 10 уменьшить в 10 раз\n");
		printf("6: Ввести массив с клавиатуры\n");
		printf("7: Сохранить массив в файл\n");
		printf("8: Загрузить массив из файла\n");
		printf("9: Удалить заданную строку  из массива\n");
		printf("10: Продублировать заданный столбец массива\n");
		printf("11: Обнулить элементы тех строк, в которых встречается более двух нулевых элементов\n");
		printf("12: Удалить те строки, в которых встречаются нулевые элементы\n");
		printf("\n");
		printf("-1: Выйти из программы\n");
		printf("Выбранная операция >>>>>>\n");

		scanf_s("%d", &item);

		switch (item) {
		// ЗАДАЧА 2
		case 1:
			fillIx10();
			break;
		case 2:
			fillZero();
			break;
		case 3:
			randFill0_9();
		case 4: // ЗАДАЧА 3
			evensX10();
			break;
		case 5: // ЗАДАЧА 4
			multiples10divide10();
			break;
		case 6: // ЗАДАЧА 5
			arrKeyboard();
			break;
		// ЗАДАЧА 6
		case 7:
			save();
			break;
		case 8:
			load();
			break;
		case 9: // ЗАДАЧА 7
			printf("Номер строки, которую нужно удалить: ");
			scanf_s("%d", &num);
			deleteRow(num);
			break;
		case 10: // ЗАДАЧА 8
			printf("Номер стобца, который нужно продублировать: ");
			scanf_s("%d", &num);
			doubleColumn(num);
			break;
		case 11: // ЗАДАЧА 9
			A9();
			break;
		case 12: // ЗАДАЧА 10*
			B3();
			break;
		}
	} while (item != -1);
}