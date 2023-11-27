#include <iostream>
#include "dynamic_array.h"

// implement dynamic_array here
dynamic_array::dynamic_array() : m_data(nullptr), m_size(0) {}

dynamic_array::dynamic_array(const std::size_t size, const int init = 0) : m_data(new int[size]), m_size(size) {
    for (std::size_t i = 0; i < size; ++i) {
        m_data[i] = init;
    }
}

dynamic_array::dynamic_array(const dynamic_array &other) : m_data(new int[other.m_size]), m_size(other.m_size) {
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

dynamic_array::dynamic_array(dynamic_array &&other) : m_data(other.m_data), m_size(other.m_size) {
    other.m_data = nullptr;
    other.m_size = 0;
}

void dynamic_array::swap(dynamic_array &other) {
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
}

dynamic_array & dynamic_array::operator=(const dynamic_array &other) {
    auto tmp = other;
    swap(tmp);
    return *this;
}

dynamic_array & dynamic_array::operator=(dynamic_array &&other) {
    auto tmp = std::move(other);
    swap(tmp);
    return *this;
}

dynamic_array::~dynamic_array() {
    delete[] m_data;
}

std::size_t dynamic_array::size() const {
    return m_size;
}

int & dynamic_array::operator[](const std::size_t i) {
    return m_data[i];
}

const int & dynamic_array::operator[](const std::size_t i) const {
    return m_data[i];
}

void dynamic_array::print() {
    for (std::size_t i = 0; i < m_size; ++i) {
        std::cout << m_data[i] << " ";
    }
    std::cout << std::endl;
}

void dynamic_array::push_back(const int &value) {
    dynamic_array tmp{m_size + 1};
    for (std::size_t i = 0; i < m_size; ++i) {
        tmp[i] = m_data[i];
    }
    tmp[m_size] = value;
    swap(tmp);
}

void dynamic_array::pop_back() {
    if (m_size > 0) {
        dynamic_array tmp{m_size - 1};
        for (std::size_t i = 0; i < m_size - 1; ++i) {
            tmp[i] = m_data[i];
        }
        swap(tmp);
    }
}

int main() {
    dynamic_array array(5, 3);
    dynamic_array copy_arr = array;
    array.pop_back();
    array.pop_back();
    copy_arr = array;
    array.push_back(7);
    array.print();
    copy_arr.print();
}