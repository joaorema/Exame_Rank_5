#pragma once

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <limits.h>

class bigint{
    private:
        std::string digits;
    public:
        bigint();
        bigint(std::string str);
        bigint(long long n);
        bigint(const bigint& src);
        bigint& operator= (const bigint& src);
        ~bigint();

        std::string getDigits() const;

        bigint operator+ (const bigint& other) const;
        bigint& operator+= (const bigint& other);

        bigint& operator++();
        bigint operator++(int);

        bigint operator<< (int n);
        bigint operator>> (int n);
        bigint& operator<<= (int n);
        bigint& operator>>= (int n);
        bigint& operator>>= (const bigint& other);

        bool operator== (const bigint& other) const;
        bool operator!= (const bigint& other) const;
        bool operator> (const bigint& other) const;
        bool operator< (const bigint& other) const;
        bool operator>= (const bigint& other) const;
        bool operator<= (const bigint& other) const;
};

std::ostream& operator<< (std::ostream& output, const bigint& obj);
int toInt(const bigint& obj);