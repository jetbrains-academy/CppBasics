#ifndef CPPBASICS_INT_ARRAY_HPP
#define CPPBASICS_INT_ARRAY_HPP

#include <cstddef>
#include <iostream>

class int_array {
public:
    int_array()
        : data_(nullptr)
        , size_(0)
    {};

    explicit int_array(std::size_t size)
        : data_(new int[size])
        , size_(size)
    {};

    ~int_array() {
        delete[] data_;
    }

    int_array(const int_array& other)
        : data_(new int[other.size_])
        , size_(other.size_)
    {
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    };

    int_array(int_array&& other)
        : data_(other.data_)
        , size_(other.size_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
    };

    int_array& operator=(int_array other) {
        swap(other);
        return *this;
    }

    std::size_t size() const {
        return size_;
    }

    int& operator[](std::size_t i) {
        return data_[i];
    }

    const int& operator[](std::size_t i) const {
        return data_[i];
    }

    void swap(int_array& other) {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
    }

    friend std::ostream& operator<<(std::ostream &os, const int_array& array) {
        if (array.size() == 0) {
            os << "[]";
            return os;
        }
        os << "[ ";
        for (std::size_t i = 0; i < array.size(); ++i) {
            os << array[i];
            if (i != array.size() - 1) {
                os << ", ";
            }
        }
        os << " ]";
        return os;
    }

private:
    int* data_;
    size_t size_;
};

#endif // CPPBASICS_INT_ARRAY_HPP
