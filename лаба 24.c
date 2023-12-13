#include <stdio.h>
#include <Windows.h>

int fact(int n) {
	if (n == 0)
		return 1;
	long res = fact(n - 1) * n;
	return res;
}

void f1(int n) {
	printf("%d ", n);
	if (n > 1)
		f1(n - 2);
}

void f2(int n) {
	if (n > 1)
		f2(n - 2);
	printf("%d ", n);
}

void f3(int n) {
	printf("%d ", n);
	if (n > 1)
		f3(n - 2);
	printf("%d ", n);
}

void recEGE1(int n) {
	if (n >= 1) {
		printf(" %d", n);
		recEGE1(n - 1);
		recEGE1(n - 1);
	}
}

void F1(int n) {
	if (n > 2) {
		printf("%d\n", n);
		F1(n - 3);
		F1(n - 4);
	}
}

void F2(int n) {
	printf("%d\n", n);
	if (n < 5) {
		F2(n + 1);
		F2(n + 3);
	}
}

void G3(int n);

void F3(int n) {
	if (n > 0)
		G3(n - 1);
}

void G3(int n) {
	printf("*");
	if (n > 1)
		F3(n - 3);
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ÇÀÄÀ×À 1
	//int n = 5;
	//printf("%d! = %ld", n, fact(n));

	// ÇÀÄÀ×À 2
	//int n = 11;
	//printf("f1(n) = ");
	//f1(n);
	//
	//printf("\nf2(n) = ");
	//f2(n);
	//
	//printf("\nf3(n) = ");
	//f3(n);

	// ÇÀÄÀ×È 4, 5, 6, 7
	//recEGE1(3);

	//F1(10);

	//F2(1);

	//F3(11);
}