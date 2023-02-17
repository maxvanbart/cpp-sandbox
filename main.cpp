#include <iostream>

int fibonacci(int n) {
    if (n == 1) {
        return 1;
    } else if (n < 1) {
        return 0;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}


int main() {
    std::cout << "Hello world!\n";
    int i = 8;

    std::cout << i << "th fibonacci number: " << fibonacci(i) << "\n";


    return 0;
}
// comment line