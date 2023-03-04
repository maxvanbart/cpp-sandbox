#ifdef _MSC_VER
#  define NOINLINE __declspec(noinline)
#else
#  define NOINLINE __attribute__((noinline))
#endif

#include <chrono>
#include <vector>
#include <iostream>
// #include <typeinfo>

template<typename... T>
auto add_elems(int i, const T&... elems) {
    return (elems[i] + ...);
}

// TODO: Replace the following function template. You may change the template
// arguments and function arguments if necessary.
template<typename V, typename... T>
std::vector<V> add_vectors_singleloop(const std::vector<V>& head, const T&... tail)
{
    std::vector<V> result(head.size());

    int j = head.size();
    for (int i = 0; i < j; i++) {
        result[i] = add_elems(i, head, tail...);
    }
    return result;
}


// TODO: Replace the following function template. You may change the template
// arguments and function arguments if necessary.
template<typename V>
std::vector<V> add_2_vectors(std::vector<V>* head, const std::vector<V>& tail) {
    std::vector<V> result((*head).size());

    // std::cout << "Hello I am adding vectors!\n";
    long unsigned int length = (*head).size();
    for (long unsigned int i = 0; i < length; i++) {
        result[i] = (*head)[i] + tail[i];
        // std::cout << result[i] << "\n";
    }
    *head = result;
    return result;
}

template<typename V, typename... T>
std::vector<V> add_vectors_simple(const std::vector<V>& head, const T&... tail)
{
    std::vector<V> result(head.size());
    result = add_2_vectors(&result, head);

    // for (long unsigned int i = 0; i < result.size(); i++) {
    //     std::cout << result[i] << "\n";
    // }

    result = (add_2_vectors(&result, tail), ...);

    return result;
}

// template<typename V, typename... T>
// int add_vectors_simple_test(const std::vector<V>& head, const T&... tail)
// {
//     // std::vector<V> result(head.size());

//     // std::cout << head.size() << "\n";



//     int result = (head[i] + ...[i] + tail[i]);

//     // iterate(tail_result);

//     return result;
// }





NOINLINE std::vector<double> test_add_vectors_singleloop(
        const std::vector<double>& a, const std::vector<double>& b,
        const std::vector<double>& c, const std::vector<double>& d)
{
    return add_vectors_singleloop(a, b, c, d);
}

NOINLINE std::vector<double> test_add_vectors_simple(
        const std::vector<double>& a, const std::vector<double>& b,
        const std::vector<double>& c, const std::vector<double>& d)
{
    return add_vectors_simple(a, b, c, d);
}

#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
    // Reduced from 10000 for testing purposes
    int n = 10;
    if (argc > 1) n = std::atoi(argv[1]);

    std::vector<double> v1(n);
    std::vector<double> v2(n);
    std::vector<double> v3(n);
    for (long unsigned int i = 0; i < v1.size(); i++) {
        v1[i] = 3;
        v2[i] = 5;
        v3[i] = 2;
    }

    // Test to see if add_vectors_simple gives the correct result: 10
    std::cout << "Testing add vectors simple\n";
    auto v4 = add_vectors_simple(v1, v2, v3);
    for (long unsigned int i = 0; i < v4.size(); i++) {
        std::cout << v4[i] << "\n";
    };

    std::cout << "Testing add vectors singleloop\n";
    auto v5 = add_vectors_singleloop(v1, v2, v3);
    for (long unsigned int i = 0; i < v4.size(); i++) {
        std::cout << v5[i] << "\n";
    };

    std::cout << "Testing add elems\n";
    std::cout << add_elems(4, v1, v2, v3) << "\n";

    n = 10000;
    std::vector<double> a(n);
    std::vector<double> b(n);
    std::vector<double> c(n);
    std::vector<double> d(n);

    {
        std::cout << "Testing simple version........\n";
        auto tic = std::chrono::system_clock::now();
        for (int i = 0; i < 100; i++) {
            test_add_vectors_simple(a, b, c, d);
            // std::cout << "==================================\n";
        };
        auto toc = std::chrono::system_clock::now();
        std::cout << std::chrono::duration<double>(toc-tic).count() << "s" << std::endl;
    }

    {
        std::cout << "Testing single-loop version...";
        auto tic = std::chrono::system_clock::now();
        for (int i = 0; i < 100; i++)
            test_add_vectors_singleloop(a, b, c, d);
        auto toc = std::chrono::system_clock::now();
        std::cout << std::chrono::duration<double>(toc-tic).count() << "s" << std::endl;
    }
    return 0;
}







// #ifdef _MSC_VER
// #  define NOINLINE __declspec(noinline)
// #else
// #  define NOINLINE __attribute__((noinline))
// #endif
//
// #include <chrono>
// #include <vector>
//
// TODO: Replace the following function template. You may change the template
// arguments and function arguments if necessary.
// template<typename V, typename... T>
// std::vector<V> add_vectors_singleloop(const std::vector<V>& head, const T&... tail)
// {
//     std::vector<V> result(head.size());
//
//     return result;
// }
//
//
//
//
//
// // TODO: Replace the following function template. You may change the template
// // arguments and function arguments if necessary.
// template<typename V, typename... T>
// std::vector<V> add_vectors_simple(const std::vector<V>& head, const T&... tail)
// {
//     std::vector<V> result(head.size());
//     return result;
// }
//
// NOINLINE std::vector<double> test_add_vectors_singleloop(
//     const std::vector<double>& a, const std::vector<double>& b,
//     const std::vector<double>& c, const std::vector<double>& d)
// {
//     return add_vectors_singleloop(a, b, c, d);
// }
//
// NOINLINE std::vector<double> test_add_vectors_simple(
//     const std::vector<double>& a, const std::vector<double>& b,
//     const std::vector<double>& c, const std::vector<double>& d)
// {
//     return add_vectors_simple(a, b, c, d);
// }
//
// // template<std::vector<i> a, std::vector<j> b>
// // add_vectors_simple
//
//
//
// #include <iostream>
// #include <cstring>
//
// int main(int argc, char* argv[])
// {
//     int n = 10000;
//     if (argc > 1) n = std::atoi(argv[1]);
//
//     std::vector<double> a(n);
//     std::vector<double> b(n);
//     std::vector<double> c(n);
//     std::vector<double> d(n);
//
//     {
//         std::cout << "Testing simple version........";
//         auto tic = std::chrono::system_clock::now();
//         for (int i = 0; i < 100; i++)
//             test_add_vectors_simple(a, b, c, d);
//         auto toc = std::chrono::system_clock::now();
//         std::cout << std::chrono::duration<double>(toc-tic).count() << "s" << std::endl;
//     }
//
//     {
//         std::cout << "Testing single-loop version...";
//         auto tic = std::chrono::system_clock::now();
//         for (int i = 0; i < 100; i++)
//             test_add_vectors_singleloop(a, b, c, d);
//         auto toc = std::chrono::system_clock::now();
//         std::cout << std::chrono::duration<double>(toc-tic).count() << "s" << std::endl;
//     }
//     return 0;
// }
