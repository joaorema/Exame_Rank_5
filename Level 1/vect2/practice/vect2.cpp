#include "vect2.hpp"

vect2::vect2(){
    this->vec.push_back(0);
    this->vec.push_back(0);
}

vect2::vect2(int x, int y){
    this->vec.push_back(x);
    this->vec.push_back(y);
}

vect2::vect2(const vect2& src) : vec(src.vec) {}

vect2& vect2::operator= (const vect2& src){
    if (this != &src)
        this->vec = src.vec;
    return *this;
}

vect2::~vect2(){}

int vect2::operator[] (int index) const{
    if (index != 0 && index != 1)
        throw std::runtime_error("index out of bounds");
    return this->vec[index];
}

int& vect2::operator[] (int index){
    if (index != 0 && index != 1)
        throw std::runtime_error("index out of bounds");
    return this->vec[index];
}

vect2 vect2::operator++(int){
    vect2 tmp = *this;
    this->vec[0] = this->vec[0] + 1;
    this->vec[1] = this->vec[1] + 1;
    return tmp;
}

vect2& vect2::operator++(){
    this->vec[0] = this->vec[0] + 1;
    this->vec[1] = this->vec[1] + 1;
    return *this;
}

vect2 vect2::operator--(int){
    vect2 tmp = *this;
    this->vec[0] = this->vec[0] - 1;
    this->vec[1] = this->vec[1] - 1;
    return tmp;
}

vect2& vect2::operator--(){
    this->vec[0] = this->vec[0] - 1;
    this->vec[1] = this->vec[1] - 1;
    return *this;
}

vect2 vect2::operator+ (const vect2& other) const{
    vect2 tmp = *this;
    tmp.vec[0] = tmp.vec[0] + other.vec[0];
    tmp.vec[1] = tmp.vec[1] + other.vec[1];
    return tmp;
}

vect2 vect2::operator- (const vect2& other) const{
    vect2 tmp = *this;
    tmp.vec[0] = tmp.vec[0] - other.vec[0];
    tmp.vec[1] = tmp.vec[1] - other.vec[1];
    return tmp;
}

vect2 vect2::operator* (const vect2& other) const{
    vect2 tmp = *this;
    tmp.vec[0] = tmp.vec[0] * other.vec[0];
    tmp.vec[1] = tmp.vec[1] * other.vec[1];
    return tmp;
}

vect2 vect2::operator* (int n) const{
    vect2 tmp = *this;
    tmp.vec[0] = tmp.vec[0] * n;
    tmp.vec[1] = tmp.vec[1] * n;
    return tmp;
}

vect2& vect2::operator+= (const vect2& other){
    *this = *this + other;
    return *this;
}

vect2& vect2::operator-= (const vect2& other){
    *this = *this - other;
    return *this;
}

vect2& vect2::operator*= (const vect2& other){
    *this = *this * other;
    return *this;
}

vect2& vect2::operator*= (int n){
    *this = *this * n;
    return *this;
}

vect2& vect2::operator-(){
    this->vec[0] = -(this->vec[0]);
    this->vec[1] = -(this->vec[1]);
    return *this;
}

bool vect2::operator== (const vect2& other) const{
    if ((this->vec[0] == other.vec[0]) && (this->vec[1] == other.vec[1]))
        return true;
    return false;
}

bool vect2::operator!= (const vect2& other) const{
    if ((this->vec[0] == other.vec[0]) && (this->vec[1] == other.vec[1]))
        return false;
    return true;
}

std::ostream& operator<< (std::ostream& output, const vect2& obj){
    output << "{" << obj[0] << ", " << obj[1] << "}" << std::endl;
    return output;
}

vect2 operator* (int n, const vect2& obj){
    vect2 tmp(obj[0] * n, obj[1] * n);
    return tmp;
}