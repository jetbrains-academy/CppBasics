#include "int_array.hpp"

// implement dynarray here
dynarray::dynarray() : m_data(nullptr), m_size(0) {}

dynarray::dynarray(const std::size_t size) : m_data(new int[size]), m_size(size) {}

dynarray::dynarray(const dynarray &other) : m_data(new int[other.m_size]), m_size(other.m_size) {
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

dynarray::dynarray(dynarray &&other) : m_data(other.m_data), m_size(other.m_size) {
    other.m_data = nullptr;
    other.m_size = 0;
}

void dynarray::swap(dynarray &other) {
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
}

dynarray &dynarray::operator=(dynarray other) {
    swap(other);
    return *this;
}

dynarray::~dynarray() {
    delete[] m_data;
}

std::size_t dynarray::size() const {
    return m_size;
}

int &dynarray::operator[](const std::size_t i) {
    return m_data[i];
}

const int &dynarray::operator[](const std::size_t i) const {
    return m_data[i];
}

std::ostream &operator<<(std::ostream &os, const dynarray &array) {
    for (std::size_t i = 0; i < array.size(); ++i) {
        os << array[i] << " ";
    }
    os << std::endl;
    return os;
}

int main() {
    dynarray array(5);
    dynarray copy_arr = array;
    for (int i = 0; i < array.size(); ++i) {
        array[i] = i;
    }
    for (int i = 0; i < copy_arr.size(); ++i) {
        copy_arr[i] = i + 1;
    }
    std::cout << array;
    std::cout << copy_arr;
}