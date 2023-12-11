#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

//#define MAX_LEN 80

#define MAX_LEN 40

char s[MAX_LEN];
char filename[] = "C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\file1.txt";

char filenameIn[] = "C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\file2.txt";
char filenameHTML[] = "C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\file2_out.html";

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

int isalpha_my(unsigned char ch);

// Возвращает 1 - если  из файла прочитан разделитель.
// В этом случае в token возвращается строка, содержащая 
// этот разделитель.
// Если в файле был не разделитель - возвращает 0.
// В этом случае состояние token неопределено.
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

// Возвращает 1 - если  из файла прочитано слово.
// В этом случае в token возвращается строка, содержащая 
// это слово. Гарантируется что слово не болеее maxLen символов.
// Если в файле не было буквы - возвращает 0.
// В этом случае token содержит пустую строку.
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

// Возвращает 0 - если ch - не буква.
// Возвращает 1 - если ch - буква.
// Корректно работает для латинских букв (с кодами < 128)
// И для русских букв из кодировки ANSI
int isalpha_my(unsigned char ch) {
	if (isalpha(ch))
		return 1;

	// ANSI кодировка!!!
	if (ch >= 192 && ch <= 223)
		return 1;
	if (ch >= 224 && ch <= 255)
		return 1;

	/*
		if (ch >= 'А' && ch <= 'Я') return 1;
		if (ch >= 'а' && ch <= 'п') return 1;
		if (ch >= 'р' && ch <= 'я')return 1;
		if (ch == 'ё' ) return 1;
		if (ch == 'Ё') return 1;*/

	return 0;
}

void main() {
	printf("BEGIN!!!\n");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ЗАДАЧА 1
	//printf("ЛР23 Задача 1\n");
	//// Входной файл
	//FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\text1.txt", "rt");
	//if (fin == NULL) {
	//	printf("Входной файл не найден");
	//	return;
	//}

	//// Выходной файл
	//FILE* fout;
	//fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\out1.txt", "wt");
	//if (fout == NULL) {
	//	printf("Выходной файл не создался");
	//	return;
	//}
	//// в цикле для всех строк
	//while (!feof(fin)) {
	//	// загрузить строку
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		// обработать загруженную строку
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			if (s[i] == '\t') // Если прочитан пробел
	//				s[i] = '%'; // Заменяем его на '%'
	//		}
	//		// сохранить строку в выходной файл
	//		fprintf(fout, "%s", s);
	//		printf(">>%s<<\n", s);
	//	}
	//}
	//// закрыли файлы
	//fclose(fin);
	//fclose(fout);

	//printf("ЛР23 Задача 1 FINISH\n");

	// ЗАДАЧА 2
	//printf("ЛР23 Задача 2\n");
	//// Входной файл
	//FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\text2.txt", "rt");
	//if (fin == NULL) {
	//	printf("Входной файл не найден");
	//	return;
	//}

	//// Выходной файл
	//FILE* fout;
	//fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\out2.txt", "wt");
	//if (fout == NULL) {
	//	printf("Выходной файл не создался");
	//	return;
	//}
	//// в цикле для всех строк
	//while (!feof(fin)) {
	//	// загрузить строку
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		// обработать загруженную строку
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			//s[i] = toUpperAll(s[i]); // Заменяем буквы на заглавные
	//			s[i] = toupper(s[i]); // Заменяем буквы на заглавные
	//		}
	//		// сохранить строку в выходной файл
	//		fprintf(fout, "%s", s);
	//		printf(">>%s<<", s);
	//	}
	//}
	//// закрыли файлы
	//fclose(fin);
	//fclose(fout);

	//printf("ЛР23 Задача 2 FINISH\n");

	// ЗАДАЧА 3
	//printf("ЛР23 Задача 3\n");
	//// Входной файл
	//FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\text3.txt", "rt");
	//if (fin == NULL) {
	//	printf("Входной файл не найден");
	//	return;
	//}

	//// Выходной файл
	//FILE* fout;
	//fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\out3.txt", "wt");
	//if (fout == NULL) {
	//	printf("Выходной файл не создался");
	//	return;
	//}
	//// в цикле для всех строк
	//int cnt;
	//while (!feof(fin)) {
	//	// загрузить строку
	//	if (fgets(s, MAX_LEN - 1, fin) != NULL) {
	//		// обработать загруженную строку
	//		cnt = 0;
	//		for (int i = 0; s[i] != '\0'; i++) {
	//			if (isalpha(s[i])) {
	//				strcat(s, "#");
	//			}
	//			break;
	//		}
	//		// сохранить строку в выходной файл
	//		fprintf(fout, "%s", s);
	//		printf(">>%s<<", s);
	//	}
	//}
	//// закрыли файлы
	//fclose(fin);
	//fclose(fout);

	//printf("ЛР23 Задача 3 FINISH\n");

	// ЗАДАЧА 4
	// открываем файл с текстом
	//FILE* fin = fopen(filename, "rt");
	//if (fin == NULL) {
	//	// если файл не смогли открыть - сообщаем об этом
	//	printf("File %s doesn't opened!\n", filename);
	//	return;
	//}
	//char token[MAX_LEN];
	//
	//// пока не конец файла
	//while (!feof(fin)) {
	//	// пока есть разделитель - берем его
	//	while (getNextDelim(fin, token)) {
	//		// выводим разделитель в консоль
	//		printf("<DELIM>%s</DELIM>\n", token);
	//	}
	//	// если есть слово - берем его
	//	if (getNextWord(fin, token, MAX_LEN)) {
	//		// выводим слово в консоль
	//		printf("<WORD>%s</WORD>\n", token);
	//	}
	//}

	//// Закрываем файл с текстом
	//fclose(fin);
	
	// ЗАДАЧА 5
	// открыть файл текстовый (ВХОДНОЙ)
	//FILE* fin = fopen(filenameIn, "rt");
	//if (fin == NULL) {
	//	// если файл не смогли открыть - сообщаем об этом
	//	printf("File %s doesn't opened!\n", filenameIn);
	//	return;
	//}

	//// открыть HTML файл (выходной файл)  
	//FILE* fout = fopen(filenameHTML, "wt");
	//if (fout == NULL) {
	//	// закрываем ранее успешно открытый входной файл 
	//	fclose(fin);
	//	// если файл не смогли открыть - сообщаем об этом
	//	printf("File %s doesn't opened!\n", filenameHTML);
	//	return;
	//}


	//// Выводим в выходной файл заголовок HTML документа
	//fprintf(fout, "<!DOCTYPE html>");
	//fprintf(fout, "<html>");
	//fprintf(fout, "<head>");
	//fprintf(fout, "<meta http - equiv = \"Content-Type\" content = 	\"text/html; charset=utf-8\" />");
	//fprintf(fout, "<title>HTML Document</title>");
	//fprintf(fout, "</head>");
	//fprintf(fout, "<body>");

	//int ch;
	//while ((ch = getc(fin)) != EOF) {
	//	// в HTML файл добавляем только что прочитанный 
	//	// символ "КАК ЕСТЬ"
	//	fprintf(fout, "%c", ch);

	//	// если в тексте был символ новой строки – 
	//	// в HTML добавляем тег <BR> - новая строка
	//	if (ch == '\n')
	//		fprintf(fout, "<br>");

	//}

	//// выводит в HTML завершающие теги документа HTML
	//fprintf(fout, "</body>");
	//fprintf(fout, "</html>");

	//// Закрываем файл с текстом
	//fclose(fin);

	//// Закрываем HTML файл 
	//fclose(fout);

	// ЗАДАЧА 6
	//FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\text6.txt", "rt");
	//if (fin == NULL) {
	//	printf("Входной файл не создался");
	//	return;
	//}

	//FILE* fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\out6.txt", "wt");
	//if (fin == NULL) {
	//	printf("Выходной файл не найден");
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

	// ЗАДАЧА 7 вариант 9
	FILE* fin = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\text7.txt", "rt");
	if (fin == NULL) {
		printf("Входной файл не создался");
		return;
	}

	FILE* fout = fopen("C:\\Users\\Андрей\\OneDrive\\Рабочий стол\\уник\\ОАиП\\лаба 23\\out7.txt", "wt");
	if (fin == NULL) {
		printf("Выходной файл не найден");
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
