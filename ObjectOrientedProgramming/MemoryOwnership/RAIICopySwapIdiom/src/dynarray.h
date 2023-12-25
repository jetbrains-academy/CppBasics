#ifndef CPPBASICS_DYNARRAY_H
#define CPPBASICS_DYNARRAY_H

#include <iostream>

class dynarray {
private:
    int *m_data = nullptr;
    std::size_t m_size = 0;

public:
    dynarray();

    dynarray(std::size_t size);

    dynarray(const dynarray &other);

    dynarray(dynarray &&other);

    dynarray &operator=(dynarray other);

    ~dynarray();

    std::size_t size() const;

    int &operator[](std::size_t i);

    const int &operator[](std::size_t i) const;

    void swap(dynarray &other);

    friend std::ostream &operator<<(std::ostream &os, const dynarray &array);
};

#endif //CPPBASICS_DYNARRAY_H
