#include <stdio.h>
#include <Windows.h>

// ������� 1
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int a, b;
//
//	printf("������� ������ ����� = ");
//	scanf_s("%d", &a);
//	printf("������� ������ ����� = ");
//	scanf_s("%d", &b);
//
//	if (a > b)
//	{
//		printf("������� ����� = %d\n", a);
//		printf("������� ����� = %d\n", b);
//	}
//	else
//	{
//		printf("������� ����� = %d\n", b);
//		printf("������� ����� = %d\n", a);
//	}
//}

//������� 2
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int v1, v2, v3, v4, v5, max;
//	printf("������� 5 �����:");
//	scanf_s("%d%d%d%d%d", &v1, &v2, &v3, &v4, &v5);
//
//	max = v1;
//	if (v2 > max)
//	{
//		max = v2;
//	}
//	if (v3 > max)
//	{
//		max = v3;
//	}
//	if (v4 > max)
//	{
//		max = v4;
//	}
//	if (v5 > max)
//	{
//		max = v5;
//	}
//	printf("����� ������� �� ��������� ����� = %d", max);
//}

//������ 3
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int t;
//	printf("������� ����������� � ��������� ");
//	scanf_s("%d", &t);
//
//	if (t < 18)
//	{
//		printf("�������");
//	}
//	if (t >= 18 && t < 22)
//	{
//		printf("���������");
//	}
//	if (t >= 22 && t < 26)
//	{
//		printf("�����");
//	}
//	if (t >= 26)
//	{
//		printf("�����");
//	}
//}

//������ 4
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int t;
//	printf("������ ��������. �� � ����������, ������� ������. ������� ����������� �� ����� ");
//	scanf_s("%d", &t);
//	
//	if (t < -69)
//	{
//		printf("�� ����� �������� ������� �� �����");
//	}
//	if (t >= -69 && t < -59)
//	{
//		printf("�������, �� ��������� ����� �����");
//	}
//	if (t >= -59 && t < -48)
//	{
//		printf("���������, ����� ��������");
//	}
//	if (t >= -48)
//	{
//		printf("����� ��������, ����� ��������");
//	}
//}

//������ 5
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	int shava;
//	printf("�� �������� �������. ���� ������ ������. ������� ��������� � �����, ��� �� ������ � ������ ");
//	scanf_s("%d", &shava);
//
//	if (shava < 120)
//	{
//		printf("������, ��������� �� ���� �� ����� �������");
//	}
//	if (shava >= 120 && shava <= 140)
//	{
//		printf("���������, � � �����");
//	}
//	if (shava > 140 && shava <= 180)
//	{
//		printf("����������, �� ������ ���� �������");
//	}
//	if (shava > 180)
//	{
//		printf("���� ������, ���� ��� ��������, ���� �� ������");
//	}
//}

//������ 6
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int v;
	printf("�� ����� �� ���������� � ������ �����������. ������� ���� ��������(��/�) ");
	scanf_s("%d", &v);

	if (v < 5)
	{
		printf("����� ��������. ����� ��� ���������, ���� ��� �������� ��������?");
	}
	if (v >= 5 && v < 10)
	{
		printf("��������. ������������, ����������� ��");
	}
	if (v >= 10 && v < 15)
	{
		printf("���������. �������� �������, �� ������ �� �������");
	}
	if (v >= 15 && v < 20)
	{
		printf("������. ����� ��������� � �������� �������");
	}
	if (v >= 20)
	{
		printf("����� ������. �� �� ���������� � ����������� � ������� � ������. ��� ��...");
	}
}