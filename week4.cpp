#include <iostream>
#include <typeinfo>


template<typename T>
class Number {
public:
    const T value;
    Number(T val) : value(val) {}

    // template<typename U, typename R = typename std::result_of<T&(U)>::type>
    template<typename U>
    auto operator+(const Number<U>& other) const {
        auto result = value + other.value;
        return Number<decltype(result)>(result);
    }

    template<typename U>
    auto operator-(const Number<U>& other) const {
        auto result = value - other.value;
        return Number<decltype(result)>(result);
    }

    template<typename U>
    auto operator*(const Number<U>& other) const {
        auto result = value * other.value;
        return Number<decltype(result)>(result);
    }

    template<typename U>
    auto operator/(const Number<U>& other) const {
        auto result = value / other.value;
        return Number<decltype(result)>(result);
    }
};

template<typename T>
T add_simple(T a, T b) {
    return a + b;
}

template<typename A, typename B>
auto add(A a, B b) {
    return a + b;
}

template<typename T>
bool is_int(T a) {
    if (typeid(a) == typeid(int)) {
        return true;
    }
    return false;
}

template<int n>
struct fibonacci
{
    static const int value = fibonacci<n-1>::value + fibonacci<n-2>::value;
};


template<>
struct fibonacci<0>
{
    static const int value = 0;
};
template<>
struct fibonacci<1>
{
    static const int value = 1;
};





// template<int 0>
// struct fibonacci
// {
//     static const int value = 0;
// };
// template<int 1>
// struct fibonacci
// {
//     static const int value = 1;
// };

int main () {
    std::cout << "Hello world!\n";

    // Q1
    std::cout << add_simple<int>(1, 2) << "\n";
    std::cout << add_simple<double>(1.5, 2.2) << "\n";

    // Q2
    std::cout << add<int, double>(2, 1.5) << "\n";

    // Q3
    std::cout << is_int<int>(5) << "\n";
    std::cout << is_int<float>(5.35) << "\n";
    std::cout << is_int<float>(5) << "\n";

    // Q4
    Number<int> a(5);
    Number<float> b(2.5);
    std::cout << a.value << "\n";
    std::cout << b.value << "\n";

    std::cout << (a + b).value << " (a + b)\n";
    std::cout << (a - b).value << " (a - b)\n";
    std::cout << (a * b).value << " (a * b)\n";
    std::cout << (a / b).value << " (a / b)\n";

    // Q5
    // Fibonacci 13 should give 233
    std::cout << fibonacci<13>::value;

    return 0;
}