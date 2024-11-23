#include <iostream>

constexpr float Pi = 3.141592f;
constexpr float AngleOfPi = 180.f;
constexpr float Gravity = 9.8f;
constexpr float R2 = 1.414f;

inline const float GetTheta(const float angle) { return angle * Pi / AngleOfPi; }
inline const float GetMaxHeight(const float startH, const float angle, const float startV, const float gravity);
inline const float GetTimeOnGround(const float startH, const float angle, const float startV, const float gravity);
inline const float GetDistanceMovedX(const float startH, const float angle, const float startV, const float gravity);

int main(void)
{
	const float startH = 100.f;
	const float angle = 45.f;
	const float startV = 100.f;
	const float gravity = Gravity;

	std::cout << GetMaxHeight(startH, angle, startV, gravity);
	std::cout << '\n';
	std::cout << GetTimeOnGround(startH, angle, startV, gravity);
	std::cout << '\n';
	std::cout << GetDistanceMovedX(startH, angle, startV, gravity);
	std::cout << '\n';

	return 0;
}

inline const float GetMaxHeight(const float startH, const float angle, const float startV, const float gravity)
{
	const float startVY = startV * sin(GetTheta(angle));
	const float TimeAtMaxHeight = startVY / gravity;

	return startVY * TimeAtMaxHeight / 2.f + startH;
}

inline const float GetTimeOnGround(const float startH, const float angle, const float startV, const float gravity)
{
	const float a = -gravity / 2.f;
	const float b = startV * sin(GetTheta(angle));
	const float c = startH;

	return (-b - sqrt(b * b - 4.f * a * c)) / (2.f * a);
}

inline const float GetDistanceMovedX(const float startH, const float angle, const float startV, const float gravity)
{
	return GetTimeOnGround(startH, angle, startV, gravity) * startV * cos(GetTheta(angle));
}
