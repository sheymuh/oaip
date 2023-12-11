#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

//#define MAX_LEN 80

#define MAX_LEN 40

char s[MAX_LEN];
char filename[] = "C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\file1.txt";

char filenameIn[] = "C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\file2.txt";
char filenameHTML[] = "C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\file2_out.html";

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

int isalpha_my(unsigned char ch);

// ���������� 1 - ����  �� ����� �������� �����������.
// � ���� ������ � token ������������ ������, ���������� 
// ���� �����������.
// ���� � ����� ��� �� ����������� - ���������� 0.
// � ���� ������ ��������� token ������������.
int getNextDelim(FILE* fp, char token[])
{
	int ch = getc(fp);
	if (ch == EOF) {
		return 0;
	}
	if (isalpha_my((unsigned char)ch)) {
		ungetc(ch, fp);
		return 0;
	}
	token[0] = (unsigned char)ch;
	token[1] = '\0';
		return 1;
}

// ���������� 1 - ����  �� ����� ��������� �����.
// � ���� ������ � token ������������ ������, ���������� 
// ��� �����. ������������� ��� ����� �� ������ maxLen ��������.
// ���� � ����� �� ���� ����� - ���������� 0.
// � ���� ������ token �������� ������ ������.
int getNextWord(FILE* fp, char token[], int maxLen)
{
	int i = 0;
	int ch;
	while (((ch = getc(fp)) != EOF) && (i < maxLen - 1)) {
		if (!isalpha_my((unsigned char)(ch))) {
			break;
		}
		token[i++] = ch;
	}
	ungetc(ch, fp);
	token[i] = '\0';
		if (i == 0)
			return 0;
	return 1;
}

// ���������� 0 - ���� ch - �� �����.
// ���������� 1 - ���� ch - �����.
// ��������� �������� ��� ��������� ���� (� ������ < 128)
// � ��� ������� ���� �� ��������� ANSI
int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;

	// ANSI ���������!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	/*
		if (ch >= '�' && ch <= '�') return 1;
		if (ch >= '�' && ch <= '�') return 1;
		if (ch >= '�' && ch <= '�')return 1;
		if (ch == '�' ) return 1;
		if (ch == '�') return 1;*/

	return 0;
}

void main() {
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������ 1
	//printf("��23 ������ 1\n");
	//// ������� ����
	//FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\text1.txt", "rt");
	//if (fin == NULL) {
	//	printf("������� ���� �� ������");
	//	return;
	//}

	//// �������� ����
	//FILE* fout;
	//fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\out1.txt", "wt");
	//if (fout == NULL) {
	//	printf("�������� ���� �� ��������");
	//	return;
	//}
	//// � ����� ��� ���� �����
	//while (!feof(fin)) {
	//	// ��������� ������
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		// ���������� ����������� ������
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			if (s[i] == '\t') // ���� �������� ������
	//				s[i] = '%'; // �������� ��� �� '%'
	//		}
	//		// ��������� ������ � �������� ����
	//		fprintf(fout, "%s", s);
	//		printf(">>%s<<\n", s);
	//	}
	//}
	//// ������� �����
	//fclose(fin);
	//fclose(fout);

	//printf("��23 ������ 1 FINISH\n");

	// ������ 2
	//printf("��23 ������ 2\n");
	//// ������� ����
	//FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\text2.txt", "rt");
	//if (fin == NULL) {
	//	printf("������� ���� �� ������");
	//	return;
	//}

	//// �������� ����
	//FILE* fout;
	//fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\out2.txt", "wt");
	//if (fout == NULL) {
	//	printf("�������� ���� �� ��������");
	//	return;
	//}
	//// � ����� ��� ���� �����
	//while (!feof(fin)) {
	//	// ��������� ������
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		// ���������� ����������� ������
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			//s[i] = toUpperAll(s[i]); // �������� ����� �� ���������
	//			s[i] = toupper(s[i]); // �������� ����� �� ���������
	//		}
	//		// ��������� ������ � �������� ����
	//		fprintf(fout, "%s", s);
	//		printf(">>%s<<", s);
	//	}
	//}
	//// ������� �����
	//fclose(fin);
	//fclose(fout);

	//printf("��23 ������ 2 FINISH\n");

	// ������ 3
	//printf("��23 ������ 3\n");
	//// ������� ����
	//FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\text3.txt", "rt");
	//if (fin == NULL) {
	//	printf("������� ���� �� ������");
	//	return;
	//}

	//// �������� ����
	//FILE* fout;
	//fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\out3.txt", "wt");
	//if (fout == NULL) {
	//	printf("�������� ���� �� ��������");
	//	return;
	//}
	//// � ����� ��� ���� �����
	//int cnt;
	//while (!feof(fin)) {
	//	// ��������� ������
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		// ���������� ����������� ������
	//		cnt = 0;
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			if (isalpha(s[i])) {
	//				strcat(s, "#");
	//			}
	//			break;
	//		}
	//		// ��������� ������ � �������� ����
	//		fprintf(fout, "%s", s);
	//		printf(">>%s<<", s);
	//	}
	//}
	//// ������� �����
	//fclose(fin);
	//fclose(fout);

	//printf("��23 ������ 3 FINISH\n");

	// ������ 4
	// ��������� ���� � �������
	//FILE* fin = fopen(filename, "rt");
	//if (fin == NULL) {
	//	// ���� ���� �� ������ ������� - �������� �� ����
	//	printf("File %s doesn't opened!\n", filename);
	//	return;
	//}
	//char token[MAX_LEN];
	//
	//// ���� �� ����� �����
	//while (!feof(fin)) {
	//	// ���� ���� ����������� - ����� ���
	//	while (getNextDelim(fin, token)) {
	//		// ������� ����������� � �������
	//		printf("<DELIM>%s</DELIM>\n", token);
	//	}
	//	// ���� ���� ����� - ����� ���
	//	if (getNextWord(fin, token, MAX_LEN)) {
	//		// ������� ����� � �������
	//		printf("<WORD>%s</WORD>\n", token);
	//	}
	//}

	//// ��������� ���� � �������
	//fclose(fin);
	
	// ������ 5
	// ������� ���� ��������� (�������)
	//FILE* fin = fopen(filenameIn, "rt");
	//if (fin == NULL) {
	//	// ���� ���� �� ������ ������� - �������� �� ����
	//	printf("File %s doesn't opened!\n", filenameIn);
	//	return;
	//}

	//// ������� HTML ���� (�������� ����)  
	//FILE* fout = fopen(filenameHTML, "wt");
	//if (fout == NULL) {
	//	// ��������� ����� ������� �������� ������� ���� 
	//	fclose(fin);
	//	// ���� ���� �� ������ ������� - �������� �� ����
	//	printf("File %s doesn't opened!\n", filenameHTML);
	//	return;
	//}


	//// ������� � �������� ���� ��������� HTML ���������
	//fprintf(fout, "<!DOCTYPE html>");
	//fprintf(fout, "<html>");
	//fprintf(fout, "<head>");
	//fprintf(fout, "<meta http - equiv = \"Content-Type\" content = 	\"text/html; charset=utf-8\" />");
	//fprintf(fout, "<title>HTML Document</title>");
	//fprintf(fout, "</head>");
	//fprintf(fout, "<body>");

	//int ch;
	//while ((ch = getc(fin)) != EOF) {
	//	// � HTML ���� ��������� ������ ��� ����������� 
	//	// ������ "��� ����"
	//	fprintf(fout, "%c", ch);

	//	// ���� � ������ ��� ������ ����� ������ � 
	//	// � HTML ��������� ��� <BR> - ����� ������
	//	if (ch == '\n')
	//		fprintf(fout, "<br>");

	//}

	//// ������� � HTML ����������� ���� ��������� HTML
	//fprintf(fout, "</body>");
	//fprintf(fout, "</html>");

	//// ��������� ���� � �������
	//fclose(fin);

	//// ��������� HTML ���� 
	//fclose(fout);

	// ������ 6
	//FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\text6.txt", "rt");
	//if (fin == NULL) {
	//	printf("������� ���� �� ��������");
	//	return;
	//}

	//FILE* fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\out6.txt", "wt");
	//if (fin == NULL) {
	//	printf("�������� ���� �� ������");
	//	return;
	//}

	//int k;
	//while (!feof(fin)) {
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		k = 0;
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			if (s[i] == ';') k++;
	//		}
	//		fprintf(fout, "%s %d", s, k);
	//		printf(">>%s %d<<", s, k);
	//	}
	//}

	//fclose(fin);
	//fclose(fout);

	// ������ 7 ������� 9
	FILE* fin = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\text7.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ��������");
		return;
	}

	FILE* fout = fopen("C:\\Users\\������\\OneDrive\\������� ����\\����\\����\\���� 23\\out7.txt", "wt");
	if (fin == NULL) {
		printf("�������� ���� �� ������");
		return;
	}

	while (!feof(fin)) {
		if (fgets(s, MAX_LEN - 1, fin) != NULL) {
			for (int i = 0; s[i] != '\0'; i++) {
				if (ispunct(s[i])) {
					s[i] = '_';
				}
			}
			fprintf(fout, "%s", s);
			printf(">>%s<<", s);
		}
	}

	fclose(fin);
	fclose(fout);

	printf("END!!!\n");
}
