#include <stdio.h>
#include <Windows.h>

#define NUM_ELEMENTS 10

int arr[NUM_ELEMENTS];
int n = 0;

void printElements() { // ����� ��������� �������
	printf("< ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf(">\n");
}

void keyboardInput() { // ���� ������� � ����������
	printf("n = ");
	scanf_s("%d", &n);

	printf("input %d values:\n", n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}
}

void oddsX10() { // ��� �������� �������� ��������� � 10 ���
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 1) {
			arr[i] = arr[i] * 10;
		}
	}
}

int findMin() { // ����� ����������� �������
	int min = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	return min;
}

int ElementsAbove10() { // ������� ��������� ������ 10
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 10) {
			count++;
		}
	}
	return count;
}

int findFirstEven() { // ����� ������ ������ �������
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			return i;
		}
	}
	return -1;
}

int findLastEven() { // ����� ��������� ������ �������
	for (int i = n - 1 ; i >= 0; i--) {
		if (arr[i] % 2 == 0) {
			return i;
		}
	}
	return -1;
}

int FindIndexMin() { // ����� ������ ������������ ��������
	int min = arr[0];
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min) {
			index = i;
		}
	}
	return index;
}

void EvensXMinus1() { // ��� ������ �������� ������� �������� �� -1
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0) {
			arr[i] *= -1;
		}
	}
}

void Replace0321On4() { // ��� �������� ������� ������� �������� ������ 4 �������� �� 4
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
		printf("���������� �������:");
		printElements();
		printf("�������� ������ ��� ��������:\n");
		printf("1: ������ � ���������� ������\n");
		printf("2: x10 ��� ���� �������� ���������\n");
		printf("3: ����� ����������� �������\n");
		printf("4: ������� ��������� > 10\n");
		printf("5: x2 ��� ���������� ������� ��������\n");
		printf("6: ������� ������ ����� ������������ ��������\n");
		printf("7: ��� ������ �������� �������� �� -1\n");
		printf("8: ��� �������� ������� ������� �������� ������ 4 �������� �� 4\n");
		printf("9: ��� �������� ����� ������ � ��������� ������ ��������� � 100 ���\n");
		printf("\n");
		printf("0: ����� �� ���������\n");
		printf("��������� �������� >>>>>> ");

		scanf_s("%d", &item);

		switch (item) {
		// ������ 1
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

		// ������ 2
		case 4:
			printf("%d ��������� ������ ��� 10", ElementsAbove10());
			break;

		// ������ 3
		case 5:
		{
			int index = findLastEven();
			if (index >= 0) {
				arr[index] *= 2;
			}
		}
		break;

		// ������ 4
		case 6:
		{
			int index = FindIndexMin();
			printf("������ ������������ �������� = %d\n", index);

			int cnt = 0;
			for (int i = 0; i < index; i++) {
				if (arr[i] % 2 == 0) {
					cnt++;
				}
			}
			printf("����� ������������ %d ������ ���������\n", cnt);
		}
		break;

		// ������ 7
		case 7:
			EvensXMinus1();
			break;
		
		// ������ 8
		case 8:
			Replace0321On4();
			break;

		// ������ 10**
		case 9:
			for (int i = findFirstEven() + 1; i < findLastEven(); i++) {
				arr[i] *= 100;
			}
		}

	} while (item != 0);
}
