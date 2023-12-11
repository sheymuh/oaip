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
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c >= '�' && c <= '�')
		new_c = '�' + (c - '�');
	if (c == '�')
		new_c = '�';
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

	// ������ 1
	//char name[12];
	//printf("������� ���� ���:");
	//fgets(name, 11, stdin);
	//printf("����������� ����, %s\n", name);

	// ������ 2
	//printf("������� ������: ");
	//int ch = getchar();

	//for (int c = ch; c <= ch + 19; c++) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");

	// ������ 3
	//printf("������� ������: ");
	//int ch = getchar();
	//for (int c = ch; c >= ch - 29; c--) {
	//	printf("'%c' (%d)\n", c, c);
	//}
	//printf("\n\n\n");

	// ������ 4
	//char s[80];
	//printf("������� ������: ");
	//fgets(s, 79, stdin);

	//printf("\n�� ����� ������ s = \"%s\"", s);
	//int cnt = 0;
	//for (int i = 0; i < strlen(s); i++) {
	//	if (s[i] == ' ') cnt++;
	//}
	//printf("\n� ��� %d ��������", cnt);

	// ������ 5
	//char s[80];
	//printf("������� ������: ");
	//fgets(s, 79, stdin);

	//printf("\n�� ����� ������ s = \"%s\"", s);
	//
	//for (int i = 0; i < strlen(s); i++) {
	//	if (isspace(s[i])) {
	//		s[i] = '#';
	//	}
	//}
	//printf("\n������ ����� ��������� s = \"%s\"", s);
	//printf("\n\n\n");

	// ������ 6
	//char s[80];
	//printf("������� ������: ");
	//fgets(s, 79, stdin);

	//printf("\n�� ����� ������ s = \"%s\"", s);
	//for (int i = 0; i < strlen(s); i++) {
	//	//if (isdigit(s[i])) 
	//	if (isDigitMy(s[i]))
	//		s[i] = '$';
	//}
	//printf("\n������ ����� ��������� s = \"%s\"", s);
	//printf("\n\n\n");

	// ������ 7
	//char s[80];
	//printf("������� ������: ");
	//fgets(s, 79, stdin);

	//printf("\n�� ����� ������ s = \"%s\"", s);
	//for (int i = 0; i < strlen(s); i++) {
	//	//s[i] = toupper(s[i]);
	//	s[i] = toUpperAll(s[i]);
	//}
	//printf("\n������ ����� ��������� s = \"%s\"", s);
	//printf("\n\n\n");

	// ������ 9*
	//char s[80] = "Hi! Laba 22\n";
	//printf("����� ������ s = %d", strlenMy(s));
	
	// ������ 10*
	//char s1[] = "We";
	//char s2[] = "Apple";
	//printf("max = %s", strcmpMy(s1, s2) > 0 ? s1: s2);

	// ������ 11*
	//char s1[] = "Button";
	//char s2[20] = "This ";
	//printf("s1 = %s, s2 = %s\n", s1, s2);
	//strcpyMy(s2, s1);
	//printf("s1 = %s, s2 = %s\n", s1, s2);

	// ������ 12*
	//char s1[] = "Button";
	//char s2[20] = "This ";
	//printf("s1 = %s, s2 = %s\n", s1, s2);
	//strcatMy(s2, s1);
	//printf("s1 = %s, s2 = %s\n", s1, s2);


	//// ���. ������ ������� 9
	char s[80];
	printf("������� ������: ");
	fgets(s, 79, stdin);

	printf("\n�� ����� ������ s = \"%s\"", s);
	for (int i = 0; i < strlen(s); i++) {
		if (ispunct(s[i]))
			s[i] = '_';
	}
	printf("\n������ ����� ��������� s = \"%s\"", s);
	printf("\n\n\n");
}
