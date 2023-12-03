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
	printf("������� n (1-8) ");
	scanf_s("%d", &n);
	printf("������� m (1-10) ");
	scanf_s("%d", &m);
	printf("������� �������� �������:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("arr[%d][%d] = ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}
}

// ���������� ���������
void save() {
	// �������� ����
	FILE* fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����20\\arr1.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������");
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

// �������� ���������
void load() {

	FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����20\\arr1.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
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

void A9() { // �������� �������� ��� �����, � ������� ����������� ����� ���� ������� ���������
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

void B3() { // ������� �� ������, � ������� ����������� ������� ��������
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
		// ������ 1
		printf("=============================\n");
		printf("�������� ������ ��� ��������:\n");
		printf("1: ��������� ���������� i * 10 + j\n");
		printf("2: ��������� ������\n");
		printf("3: ��������� ���������� ����������\n");
		printf("4: ��� �������� ��������� � 10 ���\n");
		printf("5: ��� ������� 10 ��������� � 10 ���\n");
		printf("6: ������ ������ � ����������\n");
		printf("7: ��������� ������ � ����\n");
		printf("8: ��������� ������ �� �����\n");
		printf("9: ������� �������� ������  �� �������\n");
		printf("10: �������������� �������� ������� �������\n");
		printf("11: �������� �������� ��� �����, � ������� ����������� ����� ���� ������� ���������\n");
		printf("12: ������� �� ������, � ������� ����������� ������� ��������\n");
		printf("\n");
		printf("-1: ����� �� ���������\n");
		printf("��������� �������� >>>>>>\n");

		scanf_s("%d", &item);

		switch (item) {
		// ������ 2
		case 1:
			fillIx10();
			break;
		case 2:
			fillZero();
			break;
		case 3:
			randFill0_9();
		case 4: // ������ 3
			evensX10();
			break;
		case 5: // ������ 4
			multiples10divide10();
			break;
		case 6: // ������ 5
			arrKeyboard();
			break;
		// ������ 6
		case 7:
			save();
			break;
		case 8:
			load();
			break;
		case 9: // ������ 7
			printf("����� ������, ������� ����� �������: ");
			scanf_s("%d", &num);
			deleteRow(num);
			break;
		case 10: // ������ 8
			printf("����� ������, ������� ����� ��������������: ");
			scanf_s("%d", &num);
			doubleColumn(num);
			break;
		case 11: // ������ 9
			A9();
			break;
		case 12: // ������ 10*
			B3();
			break;
		}
	} while (item != -1);
}