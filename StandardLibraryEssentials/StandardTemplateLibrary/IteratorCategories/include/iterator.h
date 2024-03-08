#ifndef CPPBASICS_ITERATOR_H
#define CPPBASICS_ITERATOR_H

#include <iostream>
#include <vector>

class VectorIterator {
public:
    using pointer = int *;
    using reference = int &;
    explicit VectorIterator(pointer ptr);
    reference operator*() const;
    pointer operator->();
    VectorIterator &operator++();
    VectorIterator operator++(int);
    VectorIterator &operator--();
    VectorIterator operator--(int);
    friend bool operator==(const VectorIterator &a, const VectorIterator &b);
    friend bool operator!=(const VectorIterator &a, const VectorIterator &b);

private:
    pointer ptr_;
};

#endif //CPPBASICS_ITERATOR_H
