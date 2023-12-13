#include "Tasks.h"


void Image4(HDC hdc, int cx, int cy, int size) {
	int x1 = cx;
	int y1 = cy - size;

	int x2 = cx + size / 4;
	int y2 = cy - size / 4;

	int x3 = cx + size;
	int y3 = cy;

	int x4 = cx + size / 4;
	int y4 = cy  + size / 4;

	int x5 = cx;
	int y5 = cy + size;

	int x6 = cx - size / 4;
	int y6 = cy + size / 4;

	int x7 = cx - size;
	int y7 = cy;

	int x8 = cx - size / 4;
	int y8 = cy - size / 4;

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 2555));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x5, y5);
	LineTo(hdc, x6, y6);
	LineTo(hdc, x7, y7);
	LineTo(hdc, x8, y8);
	LineTo(hdc, x1, y1);

	DeleteObject(hPen);
}

void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_1(hdc, cx + size, cy, size / 2);
	RecursiveImage4_1(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_2(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_2(hdc, cx, cy + size, size / 2);
	RecursiveImage4_2(hdc, cx, cy - size, size / 2);
}

void RecursiveImage4_3(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_3(hdc, cx, cy + size, size / 2);
	RecursiveImage4_3(hdc, cx, cy - size, size / 2);
	RecursiveImage4_3(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_4(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_4(hdc, cx - size, cy + size, size / 2);
	RecursiveImage4_4(hdc, cx - size, cy - size, size / 2);
	RecursiveImage4_4(hdc, cx + size, cy + size, size / 2);
	RecursiveImage4_4(hdc, cx + size, cy - size, size / 2);
}

void RecursiveImage4_5(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_5(hdc, cx - size, cy + size, size / 2);
	RecursiveImage4_5(hdc, cx, cy + size, size / 2);
	RecursiveImage4_5(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_6(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_6(hdc, cx, cy - size, size / 2);
	RecursiveImage4_6(hdc, cx - size, cy, size / 2);
	RecursiveImage4_6(hdc, cx - size, cy + size, size / 2);
	RecursiveImage4_6(hdc, cx, cy + size, size / 2);
	RecursiveImage4_6(hdc, cx + size, cy, size / 2);
	RecursiveImage4_6(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage4_7(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage4_1(hdc, cx, cy, size / 2);
	RecursiveImage4_2(hdc, cx, cy, size / 2);
}