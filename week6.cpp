#include<iostream>
#include<cmath>
#include<cassert>

// struct Function {
//     static double eval(double x) { return x; };
//     // typedef ... derivative;
//     using derivative = Function;
// };

template<int value>
struct ConstInt {
    static double eval(double x) {return value;};
    using derivative = ConstInt<0>;
};

template<typename a, typename b>
struct Add {
    static double eval(double x) {return a::eval(x) + b::eval(x);};
    using derivative = Add<typename a::derivative, typename b::derivative>;
};

template<typename a, typename b>
struct Mul {
    static double eval(double x) {return a::eval(x) * b::eval(x);};
    // using derivative = Add<typename a::derivative, typename b::derivative>;
    using derivative = Add<Mul<typename b::derivative, a>,
            Mul<typename a::derivative, b>>;
};

template<int exponent, int numer = 1>
struct Monomial {
    static double eval(double x) {return numer * pow(x, exponent);};
    using derivative = Monomial<exponent - 1, exponent * numer>;
};

template<typename f>
struct Neg {
    static double eval(double x) {return -f::eval(x);};
    using derivative = Neg<typename f::derivative>;
};

struct Sin;
struct Cos;

struct Sin {
    static double eval(double x) {return sin(x);};
    using derivative = Cos;
};

struct Cos {
    static double eval(double x) {return cos(x);};
    using derivative = Neg<Sin>;
};



int main() {

    std::cout << "Hello world!\n";

    // Test the ConstInt struct
    std::cout << "ConstInt Tests\n";
    typedef ConstInt<4> a;
    std::cout << "let a(x) = 4\n";
    std::cout << "a(3) = " << a::eval(3) << "\n";
    assert(a::eval(3) == 4);
    std::cout << "a'(3) = " << a::derivative::eval(3) << "\n";
    assert(a::derivative::eval(3) == 0);

    // Test the Add and Mul structs
    std::cout << "Add and Mul Tests\n";
    typedef ConstInt<2> b;
    std::cout << "let b(x) = 2\n";
    typedef Add<a, b> c;
    std::cout << "let c(x) = a(x) + b(x)\n";
    std::cout << "c(5) = " << c::eval(5) << "\n";
    assert(c::eval(5) == 6);
    std::cout << "c'(5) = " << c::derivative::eval(5) << "\n";
    assert(c::derivative::eval(5) == 0);
    typedef Mul<a, b> d;
    std::cout << "let d(x) = a(x) * b(x)\n";
    std::cout << "d(5) = " << d::eval(5) << "\n";
    assert(d::eval(5) == 8);

    // Test Monomial
    typedef Monomial<3> e;
    std::cout << "Monomial Tests\n";
    std::cout << "let e(x) = x^3\n";
    std::cout << "e(3) = " << e::eval(3) << "\n";
    assert(e::eval(3) == 27);
    std::cout << "e'(2) = " << e::derivative::eval(2) << "\n";
    assert(e::derivative::eval(12));
    std::cout << "e''(4) = " << e::derivative::derivative::eval(4) << "\n";
    assert(e::derivative::derivative::eval(4) == 24);

    // Test Neg
    std::cout << "Neg Tests\n";
    typedef Neg<e> f;
    std::cout << "let f(x) = -e(x)\n";
    std::cout << "f(3) = " << f::eval(3) << "\n";
    assert(f::eval(3) == -27);
    std::cout << "f'(2) = " << f::derivative::eval(2) << "\n";
    assert(f::derivative::eval(2) == -12);

    // Test Sin and Cos
    // Asserts for the non interger returning functions have been left out and instead
    // checked using the cout and a hand calculator.
    std::cout << "Sin and Cos Tests\n";
    typedef Sin g;
    std::cout << "let g(x) = sin(x)\n";
    std::cout << "g(0) = " << g::eval(0) << "\n";
    assert(g::eval(0) == 0);
    std::cout << "g(3.14*0.5) = " << g::eval(3.14*0.5) << "\n";
    // assert(g::eval(3.14*0.5) == 1);
    std::cout << "g(1) = " << g::eval(1) << "\n";
    std::cout << "g'(0) = " << g::derivative::eval(0) << "\n";
    assert(g::derivative::eval(0) == 1);
    std::cout << "g'(1) = " << g::derivative::eval(1) << "\n";
    std::cout << "g''(1) = " << g::derivative::derivative::eval(1) << "\n";

    // Test Mul with more complex functions
    std::cout << "Complicated Mul Tests\n";
    typedef Mul<a, e> h;
    std::cout << "let h(x) = a(x) * e(x) = 4 * x^3\n";
    std::cout << "h(2) = " << h::eval(2) << "\n";
    assert(h::eval(2) == 32);
    std::cout << "h'(3) = " << h::derivative::eval(3) << "\n";
    assert(h::derivative::eval(3) == 108);
}