#include <stdio.h>
#include <Windows.h>

// ������ 1
void print1_10() {

	int a = 1;

	do {
		printf("%d ", a);
		a += 1;
	} while (a <= 10);

}

void print10_1() {

	int a = 10;

	do {
		printf("%d ", a);
		a -= 1;
	} while (a >= 1);

}

void print5Odds() {

	int a = 1;
	int i = 1;

	do {
		printf("%d ", a);
		a += 2;
		i += 1;
	} while (i <= 5);

}

// ������ 2
void print100_10_while() {
	int a = 100;

	while (a >= 10) {
		printf("%d ", a);
		a -= 10;
	}
}

// ������ 3
void print1000_100_while() {
	int a = 1000;

	while (a >= 100) {
		printf("%d ", a);
		a -= 100;
	}
}

// ������ 5
void print1000_0_while() {
	int a = 1000;
	int n = 29;
	
	while (a >= 0) {
		printf("%d ", a);
		a -= n;
	}
	printf("0");
}

// ������ 6*
void print1_n_factorial() {
	int n;
	int a = 1;
	int i = 2;

	printf("������� n ");
	scanf_s("%d", &n);
	
	while (n > 0) {
		printf("%d ", a);
		a *= i;
		i++;
		n -= 1;
	}
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	do {
		printf("\n");
		printf("\n");
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������� ����� �� 1 �� 10\n");
		printf("2: ������� ����� �� 10 �� 1\n");
		printf("3: ������� 5 ������ �������� ����� ������� � 1\n");
		printf("11: ������� ����� 100 90 80 ... 10\n");
		printf("12: ������� ����� 1000 900 800 ... 100\n");
		printf("20: ������� ����� 1000 971 942 ... 0\n");
		printf("21: ������� n ������ ����������� (1 2 6 24 120 ... n!\n");
		printf("\n");
		printf("0: ����� �� ���������\n");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			print1_10();
			break;
		case 2:
			print10_1();
			break;
		case 3:
			print5Odds();
			break;
		case 11:
			print100_10_while();
			break;
		case 12:
			print1000_100_while();
			break;
		case 20:
			print1000_0_while();
			break;
		case 21:
			print1_n_factorial();
			break;
		}
	} while (n != 0);
}