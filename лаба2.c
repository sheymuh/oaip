#include <stdio.h>
#include <math.h>

#include <Windows.h>

// ������ 1
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float h = 10.0;
//	float g = 9.8;
//	float t = sqrt(2 * h / g);
//
//	printf("������� ������ � ������ %f ������\n", h);
//	printf("�� ������� ����� ����� %f ������", t);
//}

//������ 2
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float h;
//	printf("������� ������ � ������ = ");
//	scanf_s("%f", &h);
//
//	float g = 9.8;
//	float t = sqrt(2 * h / g);
//
//	printf("������� ������ � ������ %f ������\n", h);
//	printf("�� ������� ����� ����� %f ������", t);
//}

// ������ 3
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float m;
//	int rub_m;
//
//	printf("������� ������� �������� m*m = ");
//	scanf_s("%f", &m);
//
//	printf("������� ��������� ������ ����������� ����� � �������� RUB = ");
//	scanf_s("%d", &rub_m);
//
//	float price = m * rub_m;
//
//	printf("�������� �������� %f m*m �� ���� %d RUB (m*m) ����� <%10.1f> RUB", m, rub_m, price);
//}

//������ 4
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float m;
//	int rub_m;
//	int z;
//
//	printf("������� ������� �������� m*m = ");
//	scanf_s("%f", &m);
//
//	printf("������� ��������� ������ ����������� ����� � �������� RUB = ");
//	scanf_s("%d", &rub_m);
//
//	printf("������� ������ �������� RUB = ");
//	scanf_s("%d", &z);
//
//	float price = m * rub_m;
//
//	printf("�������� �������� %f m*m �� ���� %d RUB (m*m) ����� <%10.1f> RUB\n", m, rub_m, price);
//
//	int mnths = price / (z * 0.5);
//
//	printf("��� �������� %d RUB �� ��� �������� ����� ������ %d �������", z, mnths);
//}

//������ 5
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	printf("� ������������� ������������ ABC ���� C ������, ���� A ����� 23 �������. ������� ���� B.\n");
//	printf("���������...\n\n\n");
//	
//	int A = 23;
//	int B = 90 - A;
//	
//	printf("���� B ����� %d", B);
//}

//������ 6
//void main()
//	{
//		SetConsoleCP(1251);
//		SetConsoleOutputCP(1251);
//
//		printf("���������� ��������, ������������ �������� ������, ����� ������� 780 ��, ������� ����� 2 ���������� �����.\n");
//		printf("���������...\n\n\n");
//		int m = 780;
//		int S = 2;
//		int g = 10;
//		int F = m * g;
//		int p = F / S;
//
//		printf("�������� ����� %d �������", p);
//	}

//������ 7
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("�� ������ ����� \"�\" � ����� ������� ���� �����, ��������� �� ������ � ������ ����, ����� ������������� �� 9 ���������, � �� ������ ����� \"�\" - �� 11 ���������. ������ ��������� ������� 300000 ������ � ���� �� ������. �� ������� ������ ������ �� ������� ����� 3 ����, ���� �������� � ���� \"�\"?\n");

	int money = 300000;

	float sumA = money * 1.09 * 1.09 * 1.09;
	float sumB = money * 1.11 * 1.11 * 1.11;
	
	float itog = sumB - sumA;

	printf("������ ������� �� %f ������ ������, ���� �������� � ���� �", itog);
}