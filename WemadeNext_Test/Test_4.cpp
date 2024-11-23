#include<iostream>
#include<Windows.h>

constexpr float Pi = 3.141592f;

void DrawCircle(HDC hdc, int centerX, int centerY, int r, COLORREF color);
void DrawCircleByTheta(HDC hdc, int centerX, int centerY, int r, COLORREF color);
inline int GetUpperSemiCircleY(int x, int r) { return static_cast<int>(sqrt(float(r * r - x * x))); }

int main(void)
{
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	Sleep(1000);

	int centerX = 200;
	int centerY = 200;
	int r = 100;
	COLORREF color = RGB(0, 255, 0);

	DrawCircle(hdc, centerX, centerY, r, color);
	centerX += 250;
	DrawCircleByTheta(hdc, centerX, centerY, r, color);

	std::cin.get();

	ReleaseDC(hwnd, hdc);

	return 0;
}

void DrawCircle(HDC hdc, int centerX, int centerY, int r, COLORREF color)
{
	int beginX = -r;
	int endX = r + 1;
	int y;
	for (int x = beginX; x < endX; ++x)
	{
		y = GetUpperSemiCircleY(x, r);
		SetPixel(hdc, x + centerX, y + centerY, color);
		SetPixel(hdc, x + centerX, -y + centerY, color);
	}
}

void DrawCircleByTheta(HDC hdc, int centerX, int centerY, int r, COLORREF color)
{
	float deltaTheta = 1.f / (2.f * Pi * float(r));
	float beginTheta = 0.f;
	float endTheta = 2.f * Pi;
	int x, y;
	for (float theta = beginTheta; theta < endTheta; theta += deltaTheta)
	{
		x = int((float)r * cos(theta));
		y = int((float)r * sin(theta));
		SetPixel(hdc, x + centerX, y + centerY, color);
	}
}
