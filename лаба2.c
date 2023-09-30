#include <stdio.h>
#include <math.h>

#include <Windows.h>

// ЗАДАЧА 1
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float h = 10.0;
//	float g = 9.8;
//	float t = sqrt(2 * h / g);
//
//	printf("Предмет падает с высоты %f метров\n", h);
//	printf("Он коснётся земли через %f секунд", t);
//}

//ЗАДАЧА 2
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float h;
//	printf("Введите высоту в метрах = ");
//	scanf_s("%f", &h);
//
//	float g = 9.8;
//	float t = sqrt(2 * h / g);
//
//	printf("Предмет падает с высоты %f метров\n", h);
//	printf("Он коснётся земли через %f секунд", t);
//}

// ЗАДАЧА 3
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float m;
//	int rub_m;
//
//	printf("Введите площадь квартиры m*m = ");
//	scanf_s("%f", &m);
//
//	printf("Введите стоимость одного квадратного метра в квартире RUB = ");
//	scanf_s("%d", &rub_m);
//
//	float price = m * rub_m;
//
//	printf("Квартира площадью %f m*m по цене %d RUB (m*m) стоит <%10.1f> RUB", m, rub_m, price);
//}

//ЗАДАЧА 4
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	float m;
//	int rub_m;
//	int z;
//
//	printf("Введите площадь квартиры m*m = ");
//	scanf_s("%f", &m);
//
//	printf("Введите стоимость одного квадратного метра в квартире RUB = ");
//	scanf_s("%d", &rub_m);
//
//	printf("Введите размер зарплаты RUB = ");
//	scanf_s("%d", &z);
//
//	float price = m * rub_m;
//
//	printf("Квартира площадью %f m*m по цене %d RUB (m*m) стоит <%10.1f> RUB\n", m, rub_m, price);
//
//	int mnths = price / (z * 0.5);
//
//	printf("При зарплате %d RUB на эту квартиру нужно копить %d месяцев", z, mnths);
//}

//ЗАДАЧА 5
//void main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	printf("В прямоугольном треугольнике ABC угол C прямой, угол A равен 23 градуса. Найдите угол B.\n");
//	printf("Вычисляем...\n\n\n");
//	
//	int A = 23;
//	int B = 90 - A;
//	
//	printf("Угол B равен %d", B);
//}

//ЗАДАЧА 6
//void main()
//	{
//		SetConsoleCP(1251);
//		SetConsoleOutputCP(1251);
//
//		printf("Расчитайте давление, производимое бетонной плитой, масса которой 780 кг, площадь опоры 2 квадратных метра.\n");
//		printf("Вычисляем...\n\n\n");
//		int m = 780;
//		int S = 2;
//		int g = 10;
//		int F = m * g;
//		int p = F / S;
//
//		printf("Давление равно %d Паскаль", p);
//	}

//ЗАДАЧА 7
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	printf("По вкладу банка \"А\" в конце каждого года сумма, имеющаяся на вкладе в начале года, будет увеличиваться на 9 процентов, а по вкладу банка \"Б\" - на 11 процентов. Андрей планирует вложить 300000 рублей в один из банков. На сколько больше рублей он получит через 3 года, если вложится в банк \"Б\"?\n");

	int money = 300000;

	float sumA = money * 1.09 * 1.09 * 1.09;
	float sumB = money * 1.11 * 1.11 * 1.11;
	
	float itog = sumB - sumA;

	printf("Андрей получит на %f рублей больше, если вложится в банк Б", itog);
}