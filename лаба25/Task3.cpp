#include "Tasks.h"


void Image3(HDC hdc, int cx, int cy, int size) {
	int x1 = cx;
	int y1 = cy - size;

	int x2 = cx + size;
	int y2 = cy;

	int x3 = cx;
	int y3 = cy + size;

	int x4 = cx - size;
	int y4 = cy;

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x1, y1);

	DeleteObject(hPen);
}

void RecursiveImage3_1(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_1(hdc, cx + size, cy, size / 2);
	RecursiveImage3_1(hdc, cx - size, cy, size / 2);
}

void RecursiveImage3_2(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_2(hdc, cx + size, cy, size / 2);
	RecursiveImage3_2(hdc, cx - size, cy, size / 2);
	RecursiveImage3_2(hdc, cx, cy + size, size / 2);
}

void RecursiveImage3_3(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_3(hdc, cx + size, cy, size / 2);
	RecursiveImage3_3(hdc, cx - size, cy, size / 2);
	RecursiveImage3_3(hdc, cx, cy - size, size / 2);
}

void RecursiveImage3_4(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_4(hdc, cx + size, cy, size / 2);
	RecursiveImage3_4(hdc, cx - size, cy, size / 2);
	RecursiveImage3_4(hdc, cx, cy + size, size / 2);
	RecursiveImage3_4(hdc, cx, cy - size, size / 2);
}

void RecursiveImage3_5(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_5(hdc, cx + size, cy - size, size / 2);
	RecursiveImage3_5(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage3_6(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_6(hdc, cx, cy + size, size / 2);
	RecursiveImage3_6(hdc, cx, cy - size, size / 2);
}

void RecursiveImage3_7(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_7(hdc, cx + size, cy, size / 2);
	RecursiveImage3_7(hdc, cx + size, cy - size, size / 2);
	RecursiveImage3_7(hdc, cx + size, cy + size, size / 2);
	RecursiveImage3_7(hdc, cx - size, cy, size / 2);
	RecursiveImage3_7(hdc, cx - size, cy - size, size / 2);
	RecursiveImage3_7(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage3_8(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}
	RecursiveImage3_8(hdc, cx, cy + size, size / 2);
	RecursiveImage3_8(hdc, cx + size, cy + size, size / 2);
	RecursiveImage3_8(hdc, cx - size, cy + size, size / 2);
	RecursiveImage3_8(hdc, cx, cy - size, size / 2);
	RecursiveImage3_8(hdc, cx + size, cy - size, size / 2);
	RecursiveImage3_8(hdc, cx - size, cy - size, size / 2);
}