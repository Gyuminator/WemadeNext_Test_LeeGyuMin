#include<iostream>

#define Make_Observed_Setter(name) \
void Set##name(const decltype(name)& _##name) \
{ \
	if(name != _##name)\
	{\
		name = _##name;\
		ProcObservers(#name, name); \
	}\
}

void ProcObservers(const char* propName, int value)
{
	// 일련의 작업들...
	// propName을 키값으로 등록된 함수(노티파이) 리스트를 순회 호출
	// +노티파이에 갱신된 value값 전달
}

class Test3
{
private:
	int m_HP;

public:
	Make_Observed_Setter(m_HP);
	const int Getm_HP() { return m_HP; }
};

int main(void)
{
	Test3 t3;
	t3.Setm_HP(100);
	std::cout << t3.Getm_HP();

	return 0;
}