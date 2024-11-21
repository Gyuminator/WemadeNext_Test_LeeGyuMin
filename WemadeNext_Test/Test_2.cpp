#include<iostream>
#include<tuple>

using std::tuple;

constexpr size_t MaxSizeOfVariants = 5;

template<typename... Args>
struct Variants
{
	static_assert(sizeof...(Args) <= MaxSizeOfVariants, "num of Args > Max");

	Variants(Args... args) : values{ args... } {}

	tuple<Args...> values;

	/*template<size_t index>
	std::tuple_element_t<index, tuple<Args...>> Get() { return std::get<index>(variants.values); }*/
};

template<size_t Index = 0, typename... Args>
void PrintVariants(const Variants<Args...>& variants)
{
	if constexpr (Index < sizeof...(Args))
	{
		std::cout << std::get<Index>(variants.values) << ' ';
		PrintVariants<Index + 1>(variants);
	}
}

// 크기 1 인 Variants 를 만듭니다.
// @param type0 [0] 의 type.
// @param type1 [0] 의 value.
#define MAKE_VARIANTS_1(type0, value0) Variants<type0>((value0));

// 크기 2 인 Variants 를 만듭니다.
// @param type0 [0] 의 type.
// @param type1 [0] 의 value.
// @param type0 [1] 의 type.
// @param type1 [1] 의 value.
#define MAKE_VARIANTS_2(type0, value0, type1, value1) Variants<type0, type1>((value0), (value1));

#define MAKE_VARIANTS_3(type0, value0, type1, value1, type2, value2) \
Variants<type0, type1, type2>((value0), (value1), (value2));

#define MAKE_VARIANTS_4(type0, value0, type1, value1, type2, value2, type3, value3) \
Variants<type0, type1, type2, type3>((value0), (value1), (value2), (value3));

#define MAKE_VARIANTS_5(type0, value0, type1, value1, type2, value2, type3, value3, type4, value4) \
Variants<type0, type1, type2, type3, type4>((value0), (value1), (value2), (value3), (value4));

// Variants 의 index 요소를 획득합니다.
// @param variants Variants 개체.
// @param index 배열 인덱스.
// @param value 배열 요소에 대한 참조.
#define GET_VARIANT_ITEM(variants, index_or_type, value) \
(value) = std::get<index_or_type>(variants.values);

int main(void)
{
	int a = 123;
	Variants inst = MAKE_VARIANTS_5(int, -a, const char*, "abc", double, 8.f, char, 'T', bool, true);
	
	std::cout << std::boolalpha;

	int b;
	char c;
	
	GET_VARIANT_ITEM(inst, 0, b);
	std::cout << b << '\n';
	GET_VARIANT_ITEM(inst, char, c);
	std::cout << c << '\n';

	PrintVariants(inst);

	return 0;
}