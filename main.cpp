#include <stdio.h>

template <typename T>

T Min(T a, T b) {
	if (a > b) {
		return static_cast<T>(b);
	}
	else {
		return static_cast<T>(a);
	}
}

template <>
char  Min<char>(char a, char b) {
	printf("数字以外は入力出来ません\n");
	return 'E';
}

template <typename T1, typename T2>
T1  Min(T1 a, T2 b) {

	if (a > b) {
		return static_cast<T1>(b);
	}
	else {
		return static_cast<T1>(a);
	}
}

int main() {
	int intA = 5;
	int intB = 7;
	float floatA = 5.5f;
	float floatB = 7.5f;
	double doubleA = 6.5f;
	double doubleB = 8.5f;
	char charA = 'a';
	char charB = 'b';

	//int
	int intMin = Min<int>(intA, intB);
	printf("int:%d\n", intMin);
	//float
	float floatMin = Min<float>(floatA, floatB);
	printf("float:%f\n", floatMin);
	//double
	double doubleMin = Min<double>(doubleA, doubleB);
	printf("double:%lf\n", doubleMin);
	//char
	char minChar = Min<char>(charA, charB);
	printf("char:%c", minChar);

	return 0;
}
