#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

class vect2{
    private:
        std::vector<int> vec;
    
    public:
        vect2();
        vect2(int x, int y);
        vect2(const vect2& src);
        vect2& operator= (const vect2& src);
        ~vect2();

        int operator[] (int index) const;
        int& operator[] (int index);

        vect2 operator++(int);
        vect2& operator++();
        vect2 operator--(int);
        vect2& operator--();

        vect2 operator+ (const vect2& other) const;
        vect2 operator- (const vect2& other) const;
        vect2 operator* (const vect2& other) const;
        vect2 operator* (int n) const;

        vect2& operator+= (const vect2& other);
        vect2& operator-= (const vect2& other);
        vect2& operator*= (const vect2& other);
        vect2& operator*= (int n);

        vect2& operator-();

        bool operator== (const vect2& other) const;
        bool operator!= (const vect2& other) const;
};

std::ostream& operator<< (std::ostream& output, const vect2& obj);
vect2 operator* (int n, const vect2& obj);