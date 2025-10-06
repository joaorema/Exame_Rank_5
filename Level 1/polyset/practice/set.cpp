#include "set.hpp"

set::set(searchable_bag& _bag) : bag(_bag) {}

set::set(const set& src) : bag(src.bag) {}

set& set::operator= (const set& src){
    if (this != &src)
        this->bag = src.bag;
    return *this;
}

set::~set(){}

void set::insert(int value){
    if (!this->bag.has(value))
        this->bag.insert(value);
}

void set::insert(int* array, int size){
    for (int i = 0; i < size; i++)
        insert(array[i]);
}

void set::print() const{
    return this->bag.print();
}

void set::clear(){
    return this->bag.clear();
}

bool set::has(int value) const{
    return this->bag.has(value);
}

searchable_bag& set::get_bag(){
    return this->bag;
}