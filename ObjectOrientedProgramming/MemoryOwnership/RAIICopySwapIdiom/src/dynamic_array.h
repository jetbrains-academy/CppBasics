#ifndef CPPBASICS_DYNAMIC_ARRAY_H
#define CPPBASICS_DYNAMIC_ARRAY_H

#include <iostream>

class dynamic_array {
private:
    int *m_data = nullptr;
    std::size_t m_size = 0;

public:
    dynamic_array();

    explicit dynamic_array(std::size_t size, int init);

    dynamic_array(const dynamic_array &other);

    dynamic_array(dynamic_array &&other);

    dynamic_array &operator=(const dynamic_array &other);

    dynamic_array &operator=(dynamic_array &&other);

    ~dynamic_array();

    std::size_t size() const;

    int &operator[](std::size_t i);

    const int &operator[](std::size_t i) const;

    void swap(dynamic_array &other);

    void print();

    void push_back(const int &value);

    void pop_back();
};

#endif //CPPBASICS_DYNAMIC_ARRAY_H
