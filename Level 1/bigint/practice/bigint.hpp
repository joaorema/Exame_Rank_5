#pragma once 
#include <string>
#include <algorithm>
#include <limits.h>
#include <iostream>
#include <iomanip>

class bigint{

    private:
        std::string _digits;

    public:
        //constructor & destructor
        bigint();
        bigint(unsigned long long n);
        bigint(std::string str);
        ~bigint();

        //copy contructor
        bigint(const bigint& other);
        bigint& operator= (const bigint& other);

        //comparissons
        bool operator >(const bigint& other)const;
        bool operator <(const bigint& other)const;
        bool operator <=(const bigint& other)const;
        bool operator >=(const bigint& other)const;
        bool operator ==(const bigint& other)const;
        bool operator !=(const bigint& other)const;
        
        std::string getdigits()const;


        
        
        
    };
    
    //for printing
    std::ostream& operator<<(const std::ostream& output, const bigint& obj);