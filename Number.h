#pragma once

template <typename T1, typename T2>
class Number {
public:
    T1 Min(T1 num1, T2 num2);
};


template <typename T1, typename T2>
T1 Number<T1, T2>::Min(T1 num1, T2 num2) {
    return (num1 > num2) ? static_cast<T1>(num2) : num1;
}
