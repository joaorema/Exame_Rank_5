#include "vect2.hpp"

/*** BASICS ***/
vect2::vect2() {
    _vec.push_back(0);
    _vec.push_back(0);
}

vect2::vect2(int x, int y){
    _vec.push_back(x);
    _vec.push_back(y);
}

vect2::vect2(const vect2& src) : _vec(src._vec) {}

vect2& vect2::operator= (const vect2& src){
    if (this != &src)
        this->_vec = src._vec;
    return *this;
}

vect2::~vect2(){}

/*** OPERATOR [] ***/
int& vect2::operator[] (int index){
    if (index == 0 || index == 1)
        return this->_vec[index];
    else
        throw std::runtime_error("index out of bounds\n");
}

int vect2::operator[] (int index) const{
    if (index == 0 || index == 1)
        return this->_vec[index];
    else
        throw std::runtime_error("index out of bounds\n");
}

/*** INCREMENT & DECREMENT OPERATORS ***/

vect2& vect2::operator++ (){ //pre
    this->_vec[0]++;
    this->_vec[1]++;
    return *this;
}

vect2 vect2::operator++ (int){
    vect2 tmp = *this;
    ++(*this);
    return tmp;
}

vect2& vect2::operator-- (){ //pre
    this->_vec[0]--;
    this->_vec[1]--;
    return *this;
}

vect2 vect2::operator-- (int){
    vect2 tmp = *this;
    --(*this);
    return tmp;
}

/*** OPERATORS +, -, *, +=, -=, *= ***/
vect2& vect2::operator+= (const vect2& other){
    this->_vec[0] += other._vec[0];
    this->_vec[1] += other._vec[1];
    return *this;
}

vect2& vect2::operator-= (const vect2& other){
    this->_vec[0] -= other._vec[0];
    this->_vec[1] -= other._vec[1];
    return *this;
}

vect2& vect2::operator*= (const vect2& other){
    this->_vec[0] *= other._vec[0];
    this->_vec[1] *= other._vec[1];
    return *this;
}

vect2& vect2::operator*= (int n){
    this->_vec[0] *= n;
    this->_vec[1] *= n;
    return *this;
} 

vect2 vect2::operator+ (const vect2& other) const{
    vect2 tmp = *this;

    tmp._vec[0] += other._vec[0];
    tmp._vec[1] += other._vec[1];
    
    return tmp;
}

vect2 vect2::operator- (const vect2& other) const{
    vect2 tmp = *this;

    tmp._vec[0] -= other._vec[0];
    tmp._vec[1] -= other._vec[1];
    
    return tmp;
}

vect2 vect2::operator* (const vect2& other) const{
    vect2 tmp = *this;

    tmp._vec[0] *= other._vec[0];
    tmp._vec[1] *= other._vec[1];
    
    return tmp;
}

vect2 vect2::operator* (int n) const{
    vect2 tmp = *this;

    tmp._vec[0] *= n;
    tmp._vec[1] *= n;
    
    return tmp;
}

vect2 vect2::operator- () const{
    vect2 tmp = *this;

    tmp._vec[0] = -(tmp._vec[0]);
    tmp._vec[1] = -(tmp._vec[1]);

    return tmp;
}

/*** COMPARISON ***/

bool vect2::operator== (const vect2& other){
    if ((this->_vec[0] == other._vec[0]) && this->_vec[1] == other._vec[1])
        return true;
    return false;
}

bool vect2::operator!= (const vect2& other){
    if ((this->_vec[0] != other._vec[0]) && this->_vec[1] != other._vec[1])
        return true;
    return false;
}

/*** OUTSIDE CLASS ***/

std::ostream& operator<< (std::ostream& output, const vect2& obj){
    output << "{" << obj[0] << ", " << obj[1] << "}" << std::endl;
    return output;
}

vect2 operator* (int n, const vect2& obj){
    vect2 newVec(obj[0] * n, obj[1] * n);
    return newVec;
}