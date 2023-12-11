#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>

int isDigitMy(char c) {
	if (c >= '0' && c <= '9') {
		return 1;
	}
	return 0;
}

int toUpperAll(int c) {
	int new_c = c;
	if (c >= 'a' && c <= 'z')
		new_c = 'A' + (c - 'a');
	if (c >= 'а' && c <= 'п')
		new_c = 'А' + (c - 'а');
	if (c >= 'р' && c <= 'я')
		new_c = 'Р' + (c - 'р');
	if (c == 'ё')
		new_c = 'Ё';
	return new_c;
}

int strlenMy(char s[]) {
	int len = 0;
	while (s[len] != '\0') len++;
	return len;
}

int strcmpMy(char  s1[], char  s2[]) {
	int i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i]) i++;
	return s1[i] - s2[i];
}

void strcpyMy(char dest[], char src[]) {
	int i = 0;
	while (src[i] != 0) {
		dest[i] = src[i];
		i++;
	}
}

void strcatMy(char dest[], char src[]) {
	int i = strlen(dest);
	int j = 0;
	int i1 = i;
	for (i, j; i < i1 + strlen(src); i++, j++) {
		dest[i] = src[j];
	}
}

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ЗАДАЧА 1
	//char name[12];
	//printf("Введите ваше имя:");
	//fgets(name, 11, stdin);
	//printf("Приветствую тебя, %s\n", name);

	// ЗАДАЧА 2
	//printf("Введите символ: ");
	//int ch = getchar();

	//for (int c = ch; c <= ch + 19; c++) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");

	// ЗАДАЧА 3
	//printf("Введите символ: ");
	//int ch = getchar();
	//for (int c = ch; c >= ch - 29; c--) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");

	// ЗАДАЧА 4
	//char s[80];
	//printf("Введите строку: ");
	//fgets(s, 79, stdin);

	//printf("\nВы ввели строку s = \"%s\"", s);
	//int cnt = 0;
	//for (int i = 0; i < strlen(s); i++) {
	//	if (s[i] == ' ') cnt++;
	//}
	//printf("\nВ ней %d пробелов", cnt);

	// ЗАДАЧА 5
	//char s[80];
	//printf("Введите строку: ");
	//fgets(s, 79, stdin);

	//printf("\nВы ввели строку s = \"%s\"", s);
	//
	//for (int i = 0; i < strlen(s); i++) {
	//	if (isspace(s[i])) {
	//		s[i] = '#';
	//	}
	//}
	//printf("\nСтрока после обработки s = \"%s\"", s);
	//printf("\n\n\n");

	// ЗАДАЧА 6
	//char s[80];
	//printf("Введите строку: ");
	//fgets(s, 79, stdin);

	//printf("\nВы ввели строку s = \"%s\"", s);
	//for (int i = 0; i < strlen(s); i++) {
	//	//if (isdigit(s[i])) 
	//	if (isDigitMy(s[i]))
	//		s[i] = '$';
	//}
	//printf("\nСтрока после обработки s = \"%s\"", s);
	//printf("\n\n\n");

	// ЗАДАЧА 7
	//char s[80];
	//printf("Введите строку: ");
	//fgets(s, 79, stdin);

	//printf("\nВы ввели строку s = \"%s\"", s);
	//for (int i = 0; i < strlen(s); i++) {
	//	//s[i] = toupper(s[i]);
	//	s[i] = toUpperAll(s[i]);
	//}
	//printf("\nСтрока после обработки s = \"%s\"", s);
	//printf("\n\n\n");

	// ЗАДАЧА 9*
	//char s[80] = "Hi! Laba 22\n";
	//printf("Длина строки s = %d", strlenMy(s));
	
	// ЗАДАЧА 10*
	//char s1[] = "We";
	//char s2[] = "Apple";
	//printf("max = %s", strcmpMy(s1, s2) > 0 ? s1: s2);

	// ЗАДАЧА 11*
	//char s1[] = "Button";
	//char s2[20] = "This ";
	//printf("s1 = %s, s2 = %s\n", s1, s2);
	//strcpyMy(s2, s1);
	//printf("s1 = %s, s2 = %s\n", s1, s2);

	// ЗАДАЧА 12*
	//char s1[] = "Button";
	//char s2[20] = "This ";
	//printf("s1 = %s, s2 = %s\n", s1, s2);
	//strcatMy(s2, s1);
	//printf("s1 = %s, s2 = %s\n", s1, s2);


	//// ИНД. ЗАДАЧА ВАРИАНТ 9
	char s[80];
	printf("Введите строку: ");
	fgets(s, 79, stdin);

	printf("\nВы ввели строку s = \"%s\"", s);
	for (int i = 0; i < strlen(s); i++) {
		if (ispunct(s[i]))
			s[i] = '_';
	}
	printf("\nСтрока после обработки s = \"%s\"", s);
	printf("\n\n\n");
}
