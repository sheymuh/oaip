#include "Tasks.h"


void Image1(HDC hdc, int cx, int cy, int size) {
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, cx, cy + size, NULL);
	LineTo(hdc, cx + size, cy - size);
	LineTo(hdc, cx - size, cy - size);
	LineTo(hdc, cx, cy + size);

	DeleteObject(hPen);
}

void RecursiveImage1_1(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
    if (size < 20) {
        return;
    }

	RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
	RecursiveImage1_1(hdc, cx + size, cy - size, size / 2);
}

void RecursiveImage1_2(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}

	RecursiveImage1_2(hdc, cx - size, cy - size, size / 2);
	RecursiveImage1_2(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_3(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}

	RecursiveImage1_3(hdc, cx - size, cy - size, size / 2);
	RecursiveImage1_3(hdc, cx + size, cy - size, size / 2);
	RecursiveImage1_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_4(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}

	RecursiveImage1_4(hdc, cx, cy - size, size / 2);
}

void RecursiveImage1_5(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}

	RecursiveImage1_5(hdc, cx + size, cy, size / 2);
}

void RecursiveImage1_6(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}

	RecursiveImage1_6(hdc, cx - size, cy, size / 2);
}

void RecursiveImage1_7(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20) {
		return;
	}

	RecursiveImage1_7(hdc, cx - size, cy, size / 2);
	RecursiveImage1_7(hdc, cx, cy - size, size / 2);
	RecursiveImage1_7(hdc, cx + size, cy, size / 2);
}