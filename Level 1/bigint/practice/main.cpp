#include "bigint.hpp"

int main()
{
    const bigint a(42);
    bigint b(21), c, d(1337), e(d);

    std::cout << "a = " << a << std::endl; //42
    std::cout << "b = " << b << std::endl; //21
    std::cout << "c = " << c << std::endl; //0
    std::cout << "d = " << d << std::endl; //1337
    std::cout << "e = " << e << std::endl; //1337
    std::cout << "a + b = " << a + b << std::endl; //63
    std::cout << "(c += a) = " << (c += a) << std::endl; //42
    std::cout << "b = " << b << std::endl; //21
    std::cout << "++b = " << ++b << std::endl; //22
    std::cout << "b++ = " << b++ << std::endl; //22 (but it's now 23)
    std::cout << "(b << 10) + 42 = " << (b << 10) + 42 << std::endl; //230000000042
    std::cout << "(d <<= 4) = " << (d <<= 4) << std::endl; //13370000
    std::cout << "(d >>= 2) = " << (d >>= (const bigint)2) << std::endl; //133700
    std::cout << "a = " << a << std::endl; //42
    std::cout << "d = " << d << std::endl; //133700
    std::cout << "(d < a) = " << (d < a) << std::endl; //0
    std::cout << "(d > a) = " << (d > a) << std::endl; //1
    std::cout << "(d == a) = " << (d == a) << std::endl; //0
    std::cout << "(d != a) = " << (d != a) << std::endl; //1
    std::cout << "(d <= a) = " << (d <= a) << std::endl; //0
    std::cout << "(d >= a) = " << (d >= a) << std::endl; //1

    return (0);
}

/*
output should be:
a = 42
b = 21
c = 0
d = 1337
e = 1337
a + b = 63
(c += a) = 42
b = 21
++b = 22
b++ = 22
(b << 10) + 42 = 230000000042
(d <<= 4) = 13370000
(d >>= 2) = 133700
a = 42
d = 133700
(d < a) = 0
(d > a) = 1
(d == a) = 0
(d != a) = 1
(d <= a) = 0
(d >= a) = 1
*/