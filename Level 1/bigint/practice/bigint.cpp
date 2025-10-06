#include "bigint.hpp"

bigint::bigint() : digits("0") {}

bigint::bigint(std::string str) : digits(str) {}

bigint::bigint(long long n) : digits(std::to_string(n)) {}

bigint::bigint(const bigint& src) : digits(src.getDigits()) {}

bigint& bigint::operator= (const bigint& src){
    if (this != &src)
        this->digits = src.getDigits();
    return *this;
}

bigint::~bigint(){}

std::string bigint::getDigits() const{
    return this->digits;
}

bigint bigint::operator+ (const bigint& other) const{
    std::string result;
    int i = this->digits.size() - 1;
    int j = other.getDigits().size() - 1;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry != 0){
        int sum = carry;
        if (i >= 0)
            sum += this->digits[i--] - '0';
        if (j >= 0)
            sum += other.getDigits()[j--] - '0';
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return bigint(result);
}

bigint& bigint::operator+= (const bigint& other){
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++(){
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int){
    bigint tmp = *this;
    *this += bigint(1);
    return tmp;
}

bigint bigint::operator<< (int n){
    if (*this == bigint(0))
        return *this;

    std::string result = this->digits;
    result.append(n, '0');
    return bigint(result);
}

bigint bigint::operator>> (int n){
    if (this->digits.size() <= n)
        return bigint(0);
    return bigint(this->digits.substr(0, (this->digits.size() - n)));
}

bigint& bigint::operator<<= (int n){
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>= (int n){
    *this = *this >> n;
    return *this;
}

bigint& bigint::operator>>= (const bigint& other){
    *this =  *this >> toInt(other);
    return *this;
}

bool bigint::operator== (const bigint& other) const{
    if (this->digits == other.getDigits())
        return true;
    return false;
}

bool bigint::operator!= (const bigint& other) const{
    if (this->digits != other.getDigits())
        return true;
    return false;
}

bool bigint::operator> (const bigint& other) const{
    if (this->digits.size() != other.getDigits().size())
        return this->digits.size() > other.getDigits().size();
    return this->digits > other.getDigits();
}

bool bigint::operator< (const bigint& other) const{
    if (this->digits.size() != other.getDigits().size())
        return this->digits.size() < other.getDigits().size();
    return this->digits < other.getDigits();
}

bool bigint::operator>= (const bigint& other) const{
    if (this->digits.size() != other.getDigits().size())
        return this->digits.size() >= other.getDigits().size();
    return this->digits >= other.getDigits();
}

bool bigint::operator<= (const bigint& other) const{
    if (this->digits.size() != other.getDigits().size())
        return this->digits.size() <= other.getDigits().size();
    return this->digits <= other.getDigits();
}

std::ostream& operator<< (std::ostream& output, const bigint& obj){
    output << obj.getDigits();
    return output;
}

int toInt(const bigint& obj){
    if (obj.getDigits().size() > 9)
        return INT_MAX;
    int res = std::stoi(obj.getDigits());
    return res;
}