#include "bigint.hpp"

bigint::bigint() : _digits('0')
{

}

bigint::bigint(unsigned long long n)
{   
    this->_digits = std::to_string(n);
}

bigint::bigint(std::string src) : _digits(src)
{
    
}

bigint::~bigint()
{

}

bigint::bigint(const bigint& other)
{
    *this = other;
}

bigint& bigint::operator=(const bigint& other)
{
    if(this != &other)
    {
        this->_digits = other._digits;
    }
    return *this;
}

bool bigint::operator>(const bigint& other) const
{
    if(this->_digits > other._digits)
        return true;
    else
        return false;
}

std::string bigint::getDigits()const
{
    return this->_digits;
}

bool bigint::operator<(const bigint& other)const
{
    if(this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() < other.getDigits().size());
    else
        return this->_digits < other.getDigits();

}

bool bigint::operator>(const bigint& other)const
{
    if(this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() > other.getDigits().size());
    else
        return (this->_digits > other.getDigits());

}

bool bigint::operator==(const bigint& other)const
{
    if(this->_digits == other.getDigits())
        return true;
    else
        return false;
}

bool bigint::operator!=(const bigint& other)const
{
    if(this->_digits != other.getDigits())
        return true;
    else
        return false;
}

bool bigint::operator>=(const bigint& other)const
{
    if(this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() >= other.getDigits().size());
    else
        return (this->_digits >= other.getDigits());
}

bool bigint::operator<=(const bigint& other)const
{
    if(this->_digits.size() != other.getDigits().size())
        return (this->_digits.size() <= other.getDigits().size());
    else
        return (this->_digits <= other.getDigits());
}





//for printing

std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
    output << obj.getDigits();
    return output;
}