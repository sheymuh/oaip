#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>


int a[1000]; //������. 1000 - ����������� ���������� ���������� ���������
int n; // �������� ���������� ��������� � �������
int i;
int *pa;

void Load1() {
	// �������� �������� �����
	FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����19\\in1.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}

	// �������� ������� �� �������� �����
	fscanf(fin, "%d", &n);
	// ��������� ������ ��� ������������ ������
	pa = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	// �������� �������� �����
	fclose(fin);
}

void SaveResult1() {
	// ���������� �������� ���������������
	float sa = 0;
	int s = 0;
	for (i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	// ���������, ������� ��������� ������ �� ���������������
	int m = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] > sa) {
			m++;
		}
	}

	// �������� ��������� �����
	FILE* fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����19\\out1.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������\n");
		return;
	}

	// ���������� ��������� ������� �� ���������������
	fprintf(fout, "%d\n", m);
	for (i = 0; i < n; i++) {
		if (pa[i] > sa) {
			fprintf(fout, "%d ", pa[i]);
		}
	}

	// �������� �����
	fclose(fout);
}

void Load2() {
	// �������� �������� �����
	FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����19\\in3.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}

	// �������� ������� �� �������� �����
	fscanf(fin, "%d", &n);
	// ��������� ������ ��� ������������ ������
	pa = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	// ����������� �����
	printf("�����:\n%d\n", n);
	for (i = 0; i < n; i++) {
		printf("%d ", pa[i]);
	}

	// �������� �������� �����
	fclose(fin);
}

void SaveResult2() {
	// ���������� �������� ���������������
	float sa = 0;
	int s = 0;
	for (i = 0; i < n; i++) {
		s += pa[i];
	}
	sa = s / n;

	// ���������, ������� ��������� ������ 0, �� ������ �������� ���������������
	int m = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			m++;
		}
	}

	// �������� ��������� �����
	FILE* fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����19\\out3.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������\n");
		return;
	}

	// ���������� ��������� ������� 0, �� ������� �� ���������������
	fprintf(fout, "%d\n", m);
	printf("\n������:\n%d\n", m);
	for (i = 0; i < n; i++) {
		if (pa[i] > 0 && pa[i] < sa) {
			fprintf(fout, "%d ", pa[i]);
			printf("%d ", pa[i]);
		}
	}

	// �������� �����
	fclose(fout);
}

void Load3() {
	// �������� �������� �����
	FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����19\\in4.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������\n");
		return;
	}

	// �������� ������� �� �������� �����
	fscanf(fin, "%d", &n);
	// ��������� ������ ��� ������������ ������
	pa = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]);
	}

	// ����������� �����
	printf("�����:\n%d\n", n);
	for (i = 0; i < n; i++) {
		printf("%d ", pa[i]);
	}

	// �������� �������� �����
	fclose(fin);
}

void SaveResult3() {
	// ������������ �������
	int maxx = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] > maxx) {
			maxx = pa[i];
		}
	}

	// ������� �����
	int high_income = maxx * 2 / 3;
	printf("\n2/3 �� ������������� ������ = %d", high_income);

	// ���������, ������� ��������� �� ������, ��� 2/3 �� ������������� ������
	int m = 0;
	for (i = 0; i < n; i++) {
		if (pa[i] >= high_income) {
			m++;
		}
	}

	// �������� ��������� �����
	FILE* fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\����19\\out4.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ������\n");
		return;
	}

	// ���������� ��������� �� �������, ��� 2/3 �� ������������� ������
	fprintf(fout, "%d\n", m);
	printf("\n������:\n%d\n", m);
	for (i = 0; i < n; i++) {
		if (pa[i] >= high_income) {
			fprintf(fout, "%d ", pa[i]);
			printf("%d ", pa[i]);
		}
	}

	// �������� �����
	fclose(fout);
}


void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������ 1
	//printf("Hello! It is Task1!\n");
	//Load1();
	//SaveResult1();

	// ������ 2
	//printf("Hello! It is Task2!\n");
	//Load1();
	//SaveResult1();

	//free(pa);

	// ������ 3
	//printf("Hello! It is Task3!\n");
	//Load2();
	//SaveResult2();

	// ������ 4
	printf("Hello! It is Task4!\n");
	Load3();
	SaveResult3();
}