#include <stdio.h>
#include <Windows.h>


// ������ 1
void Task1() {
	printf("Task1() START\n\n");
	int n, m;
	label_do:
		printf("������� N - ���������� ����� � M - ���������� ��������. N <= 9, M <= 9\n");
		printf("N = ");
		scanf_s("%d", &n);
		printf("M = ");
		scanf_s("%d", &m);

	if (n > 9 || m > 9) {
		printf("N ��� M ������ 9. ���������� ��� ���\n");
		goto label_do;
	}

	else {
		int i = 1;
		while (i <= n) {
			int j = 1;
			while (j <= m) {
				printf("%d%d ", i, j);
				j++;
			}
			printf("\n");
			i++;
		}
	}

	printf("\nTask1() FINISH\n");
}

// ������ 2
void Task2() {
	printf("Task2() START\n\n");

	int i = 1;
	do {
		int j = 1;
		do {
			printf("%3d ", j % 2 == 0 ? i * j: i - 1);
			j++;
		} while (j <= 10);
		printf("\n");
		i++;
	} while (i <= 10);

	printf("\nTask2() FINISH\n");
}

// ������ 3
void Task3() {
	printf("Task3() START\n\n");

	int i = 5;
	while (i > 0) {
		int j = i;
		while (j > 0) {
			printf("%d ", j);
			j--;
		}
		printf("\n");
		i--;
	}

	printf("\nTask3() FINISH\n");
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = -1;
	do {

		printf("\n");
		printf("\n");
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������ 1 (i * 10 + j) \n");
		printf("2: ������ 2 (������� ��������) \n");
		printf("3: ������ 3 (������� �� �������� 9) \n");
		printf("\n");
		printf("0: ����� �� ��������� \n\n");

		scanf_s("%d", &n);

		switch (n) {
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 3:
			Task3();
			break;
		}

	} while (n != 0);
}