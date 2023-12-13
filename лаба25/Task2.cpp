#include "Tasks.h"


void Image2(HDC hdc, int cx, int cy, int size) {
	int x1 = cx - size / 2;
	int y1 = cy - size;

	int x2 = cx + size / 2;
	int y2 = cy - size;

	int x3 = cx - size;
	int y3 = cy + size;

	int x4 = cx + size;
	int y4 = cy + size;

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, hPen);

	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	LineTo(hdc, x3, y3);
	LineTo(hdc, x4, y4);
	LineTo(hdc, x1, y1);

	DeleteObject(hPen);
}

void RecursiveImage2_1(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_1(hdc, cx - size / 2, cy - size, size / 2);
}

void RecursiveImage2_2(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_2(hdc, cx - size / 2, cy - size, size / 2);
	RecursiveImage2_2(hdc, cx + size / 2, cy - size, size / 2);
}

void RecursiveImage2_3(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_3(hdc, cx - size, cy + size, size / 2);
	RecursiveImage2_3(hdc, cx + size, cy + size, size / 2);
}

void RecursiveImage2_4(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_4(hdc, cx - size / 2, cy - size, size / 2);
	RecursiveImage2_4(hdc, cx - size, cy + size, size / 2);
	RecursiveImage2_4(hdc, cx + size / 2, cy - size, size / 2);
	RecursiveImage2_4(hdc, cx + size, cy + size, size / 2);

}

void RecursiveImage2_5(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_5(hdc, cx - size, cy, size / 2);
}

void RecursiveImage2_6(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_6(hdc, cx + size, cy, size / 2);
}

void RecursiveImage2_7(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 10) {
		return;
	}
	RecursiveImage2_7(hdc, cx - size, cy, size / 2);
	RecursiveImage2_7(hdc, cx + size, cy, size / 2);
}